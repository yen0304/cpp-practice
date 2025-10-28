# C++ 智慧指標（Smart Pointers）學習筆記

## 什麼是智慧指標？

智慧指標是 C++ 標準庫提供的類別模板，用來**自動管理動態記憶體**。它們像指標一樣使用，但會在不需要時**自動釋放記憶體**。

## 為什麼需要智慧指標？

### 傳統指標的問題：

```cpp
Dog* dog = new Dog("Buddy", 3);
dog->bark();
// 忘記 delete dog; ← 記憶體洩漏！
```

問題：
1. 🐛 容易忘記 `delete`，造成記憶體洩漏
2. 🐛 可能重複 `delete`，造成程式崩潰
3. 🐛 例外發生時可能跳過 `delete`
4. 🐛 複雜的所有權管理

### 智慧指標的優點：

```cpp
unique_ptr<Dog> dog = make_unique<Dog>("Buddy", 3);
dog->bark();
// 離開作用域時自動刪除，不需要 delete！
```

優點：
1. ✅ 自動記憶體管理
2. ✅ 避免記憶體洩漏
3. ✅ 例外安全
4. ✅ 清晰的所有權語意

---

## 三種智慧指標

### 1. `unique_ptr` - 獨佔所有權

**特性：**
- 一個物件只能被一個 `unique_ptr` 擁有
- **不能複製**，只能**移動**
- 效能最好（零額外開銷）
- 最常用的智慧指標

**使用時機：**
- 預設選擇
- 不需要共享物件時
- 工廠函數的返回值

**範例：**

```cpp
// 創建
unique_ptr<Dog> dog1 = make_unique<Dog>("Charlie", 2);

// 使用
dog1->bark();
(*dog1).bark();

// ❌ 不能複製
unique_ptr<Dog> dog2 = dog1;  // 編譯錯誤！

// ✅ 可以移動
unique_ptr<Dog> dog2 = move(dog1);  // dog1 變成 nullptr
```

**常用方法：**

```cpp
unique_ptr<Dog> dog = make_unique<Dog>("Max", 5);

dog.get();        // 獲取原始指標
dog.reset();      // 刪除當前物件，設為 nullptr
dog.release();    // 釋放所有權，返回原始指標
if (dog) { }      // 檢查是否為 nullptr
```

---

### 2. `shared_ptr` - 共享所有權

**特性：**
- 多個 `shared_ptr` 可以指向同一個物件
- 使用**引用計數**（reference counting）
- 當最後一個 `shared_ptr` 被銷毀時，物件才被刪除
- 可以複製和賦值

**使用時機：**
- 需要在多處共享同一物件
- 不確定哪裡最後使用物件
- 物件需要在多個容器中存在

**範例：**

```cpp
// 創建
shared_ptr<Dog> dog1 = make_shared<Dog>("Rocky", 4);
cout << dog1.use_count() << endl;  // 輸出：1

{
    // 複製，引用計數增加
    shared_ptr<Dog> dog2 = dog1;
    cout << dog1.use_count() << endl;  // 輸出：2
    
    shared_ptr<Dog> dog3 = dog1;
    cout << dog1.use_count() << endl;  // 輸出：3
    
    // dog2 和 dog3 離開作用域，引用計數減少
}

cout << dog1.use_count() << endl;  // 輸出：1
// dog1 離開作用域，引用計數變 0，物件被刪除
```

**常用方法：**

```cpp
shared_ptr<Dog> dog = make_shared<Dog>("Bella", 3);

dog.use_count();  // 獲取引用計數
dog.unique();     // 檢查是否是唯一所有者
dog.reset();      // 減少引用計數，可能刪除物件
dog.get();        // 獲取原始指標
```

**引用計數示意圖：**

```
創建 dog1:              dog1 → [Dog物件 | 計數:1]

複製到 dog2:            dog1 → [Dog物件 | 計數:2] ← dog2

複製到 dog3:            dog1 → [Dog物件 | 計數:3] ← dog2
                                    ↑
                                  dog3

dog2 銷毀:              dog1 → [Dog物件 | 計數:2] ← dog3

dog3 銷毀:              dog1 → [Dog物件 | 計數:1]

dog1 銷毀:              [Dog物件被刪除]
```

---

### 3. `weak_ptr` - 弱引用

**特性：**
- 配合 `shared_ptr` 使用
- **不增加引用計數**
- 可以檢測物件是否還存在
- 使用前需要轉換成 `shared_ptr`

**使用時機：**
- 避免循環引用（circular reference）
- 需要觀察物件但不擁有它
- 快取機制

**範例：**

```cpp
weak_ptr<Dog> weak_dog;

{
    shared_ptr<Dog> dog1 = make_shared<Dog>("Luna", 3);
    cout << dog1.use_count() << endl;  // 輸出：1
    
    // 設置 weak_ptr，不增加引用計數
    weak_dog = dog1;
    cout << dog1.use_count() << endl;  // 輸出：1（沒變！）
    
    // 使用 weak_ptr 前需要先 lock
    if (auto locked_dog = weak_dog.lock()) {
        locked_dog->bark();  // 可以使用
        cout << dog1.use_count() << endl;  // 輸出：2
    }
    
    // dog1 離開作用域被刪除
}

// 檢查物件是否還存在
if (weak_dog.expired()) {
    cout << "物件已被刪除" << endl;
}

// 嘗試使用
if (auto locked_dog = weak_dog.lock()) {
    locked_dog->bark();
} else {
    cout << "無法使用，物件已不存在" << endl;
}
```

**常用方法：**

```cpp
weak_ptr<Dog> weak_dog = dog1;

weak_dog.expired();   // 檢查物件是否已被刪除
weak_dog.lock();      // 轉換成 shared_ptr，如果物件還存在
weak_dog.use_count(); // 獲取對應的引用計數
weak_dog.reset();     // 清空 weak_ptr
```

**循環引用問題：**

```cpp
// ❌ 問題：循環引用
class Parent {
    shared_ptr<Child> child;
};
class Child {
    shared_ptr<Parent> parent;  // 循環引用！記憶體洩漏！
};

// ✅ 解決：使用 weak_ptr
class Parent {
    shared_ptr<Child> child;
};
class Child {
    weak_ptr<Parent> parent;  // 不增加引用計數
};
```

---

## 快速對照表

| 特性 | `unique_ptr` | `shared_ptr` | `weak_ptr` |
|------|--------------|--------------|------------|
| 所有權 | 獨佔 | 共享 | 不擁有 |
| 可複製 | ❌ | ✅ | ✅ |
| 可移動 | ✅ | ✅ | ✅ |
| 引用計數 | 無 | 有 | 不增加計數 |
| 效能 | 最快 | 較慢（計數開銷） | 較慢 |
| 使用頻率 | 最常用 | 需要共享時 | 配合 shared_ptr |

---

## 最佳實踐

### 1. 創建智慧指標

```cpp
// ✅ 推薦：使用 make_unique 和 make_shared
auto dog1 = make_unique<Dog>("Max", 5);
auto dog2 = make_shared<Dog>("Bella", 3);

// ❌ 不推薦：直接用 new
unique_ptr<Dog> dog3(new Dog("Rex", 4));
```

為什麼？
- 更安全：避免記憶體洩漏
- 更高效：`make_shared` 只需一次記憶體配置
- 更簡潔：可以使用 `auto`

### 2. 選擇正確的智慧指標

```cpp
// ✅ 預設使用 unique_ptr
unique_ptr<Dog> create_dog() {
    return make_unique<Dog>("Buddy", 2);
}

// ✅ 需要共享時才用 shared_ptr
shared_ptr<Dog> shared_dog = make_shared<Dog>("Rocky", 4);
vector<shared_ptr<Dog>> dog_pack;
dog_pack.push_back(shared_dog);  // 多處共享
```

原則：
1. 預設使用 `unique_ptr`
2. 需要共享才用 `shared_ptr`
3. 避免循環引用時用 `weak_ptr`

### 3. 不要混用智慧指標和原始指標

```cpp
unique_ptr<Dog> dog = make_unique<Dog>("Max", 5);

// ✅ 可以獲取原始指標用於傳遞
Dog* raw_ptr = dog.get();
some_function(raw_ptr);  // 只是使用，不管理

// ❌ 絕對不要這樣做
delete raw_ptr;  // 錯誤！會導致 double free

// ❌ 不要從原始指標創建智慧指標
Dog* raw = new Dog("Bella", 3);
unique_ptr<Dog> dog1(raw);
unique_ptr<Dog> dog2(raw);  // 錯誤！兩個 unique_ptr 管理同一物件
```

### 4. 函數參數傳遞

```cpp
// ✅ 只使用物件，不轉移所有權：傳引用或原始指標
void use_dog(const Dog& dog) {
    dog.bark();
}
void use_dog(Dog* dog) {
    if (dog) dog->bark();
}

// ✅ 轉移所有權：傳 unique_ptr
void take_ownership(unique_ptr<Dog> dog) {
    // 現在這個函數擁有 dog
}

// ✅ 共享所有權：傳 shared_ptr（by value 或 const&）
void share_dog(shared_ptr<Dog> dog) {
    // 引用計數增加
}

// ❌ 不推薦：傳智慧指標的引用（除非要修改智慧指標本身）
void bad_example(unique_ptr<Dog>& dog) {
    // 不常見的使用方式
}
```

### 5. 容器中使用智慧指標

```cpp
// ✅ 使用 vector 儲存 unique_ptr
vector<unique_ptr<Dog>> dog_pack;
dog_pack.push_back(make_unique<Dog>("Rex", 5));
dog_pack.push_back(make_unique<Dog>("Max", 3));

// ✅ 使用 vector 儲存 shared_ptr（需要共享時）
vector<shared_ptr<Dog>> shared_pack;
shared_pack.push_back(make_shared<Dog>("Bella", 4));
```

---

## 常見錯誤

### 1. 忘記 move unique_ptr

```cpp
unique_ptr<Dog> dog1 = make_unique<Dog>("Max", 5);
unique_ptr<Dog> dog2 = dog1;        // ❌ 錯誤！不能複製
unique_ptr<Dog> dog2 = move(dog1);  // ✅ 正確！使用 move
```

### 2. 從同一個原始指標創建多個智慧指標

```cpp
Dog* raw = new Dog("Bella", 3);
unique_ptr<Dog> dog1(raw);
unique_ptr<Dog> dog2(raw);  // ❌ 錯誤！double free
```

### 3. 循環引用導致記憶體洩漏

```cpp
// ❌ 循環引用
class Node {
    shared_ptr<Node> next;
    shared_ptr<Node> prev;  // 循環引用！
};

// ✅ 使用 weak_ptr 打破循環
class Node {
    shared_ptr<Node> next;
    weak_ptr<Node> prev;  // 不增加引用計數
};
```

---

## 練習題

1. **基礎練習**：將下面的程式碼改用 `unique_ptr`
```cpp
Dog* dog = new Dog("Max", 5);
dog->bark();
delete dog;
```

2. **進階練習**：創建一個 `vector<shared_ptr<Dog>>`，加入 3 隻狗，然後遍歷它們
3. **挑戰題**：實作一個簡單的觀察者模式，使用 `weak_ptr` 避免循環引用

---

## 總結

| 情境 | 使用哪種智慧指標 |
|------|------------------|
| 獨佔資源，不需要共享 | `unique_ptr` |
| 多處需要共享同一資源 | `shared_ptr` |
| 觀察資源但不擁有 | `weak_ptr` |
| 避免循環引用 | `weak_ptr` |
| 工廠函數返回值 | `unique_ptr` |
| 快取機制 | `weak_ptr` |

**記住：預設使用 `unique_ptr`，需要共享時才用 `shared_ptr`！**


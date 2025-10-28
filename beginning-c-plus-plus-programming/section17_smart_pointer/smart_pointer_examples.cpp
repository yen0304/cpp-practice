#include <iostream>
#include <memory>  // 智慧指標的標頭檔
#include <vector>
#include <string>

using namespace std;

/*
 * 智慧指標（Smart Pointers）
 * 
 * 為什麼需要智慧指標？
 * 1. 自動記憶體管理 - 不需要手動 delete
 * 2. 避免記憶體洩漏（memory leak）
 * 3. 避免懸空指標（dangling pointer）
 * 4. 例外安全（exception safe）
 * 
 * C++ 提供三種智慧指標：
 * 1. unique_ptr - 獨佔所有權
 * 2. shared_ptr - 共享所有權（參考計數）
 * 3. weak_ptr - 弱引用（配合 shared_ptr 使用）
 */

class Dog {
private:
    string name;
    int age;
public:
    Dog(string n, int a) : name{n}, age{a} {
        cout << "🐕 Dog '" << name << "' 被創建了！" << endl;
    }
    ~Dog() {
        cout << "👋 Dog '" << name << "' 被銷毀了！" << endl;
    }
    void bark() {
        cout << name << " says: Woof! Woof!" << endl;
    }
    string get_name() { return name; }
};

// ========================================
// 範例 1: 傳統指標的問題
// ========================================
void example1_raw_pointer_problem() {
    cout << "\n=== 範例 1: 傳統指標的問題 ===" << endl;
    
    // 問題 1: 容易忘記釋放記憶體
    Dog* dog1 = new Dog("Buddy", 3);
    dog1->bark();
    // 忘記 delete dog1; ← 記憶體洩漏！
    
    // 問題 2: 例外安全問題
    Dog* dog2 = new Dog("Max", 5);
    try {
        // 如果這裡拋出例外，dog2 永遠不會被 delete
        // throw runtime_error("Something went wrong!");
        dog2->bark();
    } catch(...) {
        // 必須在這裡也 delete，容易出錯
        delete dog2;
        throw;
    }
    delete dog2;  // 正常情況下的 delete
    
    cout << "⚠️  傳統指標需要手動管理記憶體，容易出錯！" << endl;
}

// ========================================
// 範例 2: unique_ptr - 獨佔所有權
// ========================================
void example2_unique_ptr() {
    cout << "\n=== 範例 2: unique_ptr（獨佔所有權）===" << endl;
    
    // 使用 make_unique 創建 unique_ptr（C++14 以後）
    unique_ptr<Dog> dog1 = make_unique<Dog>("Charlie", 2);
    dog1->bark();
    
    // unique_ptr 特性：
    // 1. 離開作用域自動刪除物件
    // 2. 不能複製，只能移動
    
    // unique_ptr<Dog> dog2 = dog1;  // ❌ 錯誤！不能複製
    unique_ptr<Dog> dog2 = move(dog1);  // ✅ 可以移動
    
    if (dog1 == nullptr) {
        cout << "dog1 已經被移動，現在是 nullptr" << endl;
    }
    
    dog2->bark();
    
    cout << "✅ 離開作用域時，dog2 會自動被刪除" << endl;
}

// ========================================
// 範例 3: shared_ptr - 共享所有權
// ========================================
void example3_shared_ptr() {
    cout << "\n=== 範例 3: shared_ptr（共享所有權）===" << endl;
    
    // 使用 make_shared 創建 shared_ptr
    shared_ptr<Dog> dog1 = make_shared<Dog>("Rocky", 4);
    cout << "dog1 引用計數: " << dog1.use_count() << endl;
    
    {
        // 可以複製 shared_ptr，引用計數會增加
        shared_ptr<Dog> dog2 = dog1;
        cout << "dog1 引用計數: " << dog1.use_count() << endl;
        cout << "dog2 引用計數: " << dog2.use_count() << endl;
        
        shared_ptr<Dog> dog3 = dog1;
        cout << "現在有 3 個 shared_ptr 指向同一隻狗" << endl;
        cout << "dog1 引用計數: " << dog1.use_count() << endl;
        
        dog2->bark();
        dog3->bark();
        
        cout << "dog2 和 dog3 即將離開作用域..." << endl;
    }
    
    cout << "dog1 引用計數: " << dog1.use_count() << endl;
    cout << "✅ 當最後一個 shared_ptr 被銷毀時，物件才會被刪除" << endl;
}

// ========================================
// 範例 4: weak_ptr - 弱引用
// ========================================
void example4_weak_ptr() {
    cout << "\n=== 範例 4: weak_ptr（弱引用）===" << endl;
    
    weak_ptr<Dog> weak_dog;
    
    {
        shared_ptr<Dog> dog1 = make_shared<Dog>("Luna", 3);
        cout << "dog1 引用計數: " << dog1.use_count() << endl;
        
        // weak_ptr 不增加引用計數
        weak_dog = dog1;
        cout << "設置 weak_ptr 後，dog1 引用計數: " << dog1.use_count() << endl;
        
        // 使用 weak_ptr 前需要先轉換成 shared_ptr
        if (auto locked_dog = weak_dog.lock()) {
            cout << "weak_ptr 可以訪問物件: ";
            locked_dog->bark();
            cout << "lock 後引用計數: " << dog1.use_count() << endl;
        }
        
        cout << "dog1 即將離開作用域並被刪除..." << endl;
    }
    
    // 物件已被刪除，weak_ptr 會知道
    if (weak_dog.expired()) {
        cout << "✅ weak_ptr 知道物件已經被刪除了" << endl;
    }
    
    if (auto locked_dog = weak_dog.lock()) {
        locked_dog->bark();
    } else {
        cout << "⚠️  無法 lock，物件已不存在" << endl;
    }
}

// ========================================
// 範例 5: 智慧指標與容器
// ========================================
void example5_smart_pointers_with_containers() {
    cout << "\n=== 範例 5: 智慧指標與容器 ===" << endl;
    
    // 使用 vector 儲存智慧指標
    vector<shared_ptr<Dog>> dog_pack;
    
    dog_pack.push_back(make_shared<Dog>("Rex", 5));
    dog_pack.push_back(make_shared<Dog>("Bella", 3));
    dog_pack.push_back(make_shared<Dog>("Duke", 7));
    
    cout << "\n所有的狗都在叫：" << endl;
    for (const auto& dog : dog_pack) {
        dog->bark();
    }
    
    cout << "\n✅ vector 被銷毀時，所有狗都會自動被刪除" << endl;
}

// ========================================
// 範例 6: 智慧指標的最佳實踐
// ========================================
void example6_best_practices() {
    cout << "\n=== 範例 6: 智慧指標最佳實踐 ===" << endl;
    
    // 1. 優先使用 make_unique 和 make_shared
    auto dog1 = make_unique<Dog>("Ace", 2);
    
    // 2. 預設使用 unique_ptr，只在需要共享時才用 shared_ptr
    unique_ptr<Dog> dog2 = make_unique<Dog>("Max", 4);
    
    // 3. 不要混用智慧指標和原始指標
    Dog* raw_ptr = dog2.get();  // 可以獲取原始指標，但不要 delete
    raw_ptr->bark();
    
    // ❌ 不要這樣做：
    // delete raw_ptr;  // 錯誤！會導致 double free
    
    cout << "✅ 遵循最佳實踐，讓程式碼更安全！" << endl;
}

// ========================================
// 主程式
// ========================================
int main() {
    cout << "🎓 C++ 智慧指標教學" << endl;
    cout << "==========================================\n" << endl;
    
    example1_raw_pointer_problem();
    example2_unique_ptr();
    example3_shared_ptr();
    example4_weak_ptr();
    example5_smart_pointers_with_containers();
    example6_best_practices();
    
    cout << "\n==========================================" << endl;
    cout << "📚 總結：" << endl;
    cout << "1. unique_ptr: 獨佔所有權，不能複製，只能移動" << endl;
    cout << "2. shared_ptr: 共享所有權，使用引用計數" << endl;
    cout << "3. weak_ptr: 弱引用，不增加引用計數，需要配合 shared_ptr" << endl;
    cout << "4. 優先使用 make_unique 和 make_shared" << endl;
    cout << "5. 預設使用 unique_ptr，需要共享時才用 shared_ptr" << endl;
    cout << "==========================================\n" << endl;
    
    return 0;
}


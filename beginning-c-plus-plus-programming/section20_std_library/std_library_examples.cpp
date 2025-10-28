#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // sort, find, count, etc.
#include <numeric>    // accumulate, iota
#include <iterator>   // begin, end
#include <functional> // greater, less
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <list>

using namespace std;

// ========================================
// 1. Vector 常用函式
// ========================================
void example_vector() {
    cout << "\n=== 1. Vector 常用函式 ===" << endl;
    
    vector<int> nums = {5, 2, 8, 1, 9};
    
    // push_back - 在尾端加入元素
    nums.push_back(3);
    cout << "push_back(3): ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    
    // pop_back - 移除尾端元素
    nums.pop_back();
    cout << "pop_back(): ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    
    // size - 取得大小
    cout << "size(): " << nums.size() << endl;
    
    // empty - 檢查是否為空
    cout << "empty(): " << (nums.empty() ? "true" : "false") << endl;
    
    // front, back - 取得首尾元素
    cout << "front(): " << nums.front() << ", back(): " << nums.back() << endl;
    
    // at - 安全的存取（會檢查範圍）
    cout << "at(2): " << nums.at(2) << endl;
    
    // clear - 清空
    nums.clear();
    cout << "clear() 後 size: " << nums.size() << endl;
}

// ========================================
// 2. Algorithm - sort, reverse, find
// ========================================
void example_algorithm_basic() {
    cout << "\n=== 2. Algorithm - 基本操作 ===" << endl;
    
    vector<int> nums = {5, 2, 8, 1, 9, 3};
    
    // sort - 排序（升序）
    sort(nums.begin(), nums.end());
    cout << "sort(): ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    
    // sort - 降序排序
    sort(nums.begin(), nums.end(), greater<int>());
    cout << "sort(降序): ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    
    // reverse - 反轉
    reverse(nums.begin(), nums.end());
    cout << "reverse(): ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    
    // find - 尋找元素
    auto it = find(nums.begin(), nums.end(), 8);
    if (it != nums.end()) {
        cout << "find(8): 找到了，位置在 " << distance(nums.begin(), it) << endl;
    } else {
        cout << "find(8): 找不到" << endl;
    }
    
    // count - 計算出現次數
    int count_2 = count(nums.begin(), nums.end(), 2);
    cout << "count(2): " << count_2<< " 次" << endl;
}

// ========================================
// 3. Algorithm - min, max, minmax
// ========================================
void example_algorithm_minmax() {
    cout << "\n=== 3. Algorithm - min/max ===" << endl;
    
    vector<int> nums = {5, 2, 8, 1, 9, 3};
    
    // min_element - 找最小值
    auto min_it = min_element(nums.begin(), nums.end());
    cout << "min_element(): " << *min_it << endl;
    
    // max_element - 找最大值
    auto max_it = max_element(nums.begin(), nums.end());
    cout << "max_element(): " << *max_it << endl;
    
    // min, max - 比較兩個值
    cout << "min(5, 3): " << min(5, 3) << endl;
    cout << "max(5, 3): " << max(5, 3) << endl;
    
    // minmax_element - 同時找最小和最大值
    auto [min_val, max_val] = minmax_element(nums.begin(), nums.end());
    cout << "minmax_element(): min=" << *min_val << ", max=" << *max_val << endl;
}

// ========================================
// 4. Algorithm - accumulate, fill
// ========================================
void example_algorithm_numeric() {
    cout << "\n=== 4. Algorithm - 數值操作 ===" << endl;
    
    vector<int> nums = {1, 2, 3, 4, 5};
    
    // accumulate - 累加
    int sum = accumulate(nums.begin(), nums.end(), 0);
    cout << "accumulate(加總): " << sum << endl;
    
    // accumulate - 累乘
    int product = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
    cout << "accumulate(累乘): " << product << endl;
    
    // fill - 填充
    vector<int> vec(5);
    fill(vec.begin(), vec.end(), 7);
    cout << "fill(7): ";
    for (int n : vec) cout << n << " ";
    cout << endl;
    
    // iota - 填充遞增序列
    vector<int> seq(5);
    iota(seq.begin(), seq.end(), 1);
    cout << "iota(從1開始): ";
    for (int n : seq) cout << n << " ";
    cout << endl;
}

// ========================================
// 5. Algorithm - transform, for_each
// ========================================
void example_algorithm_transform() {
    cout << "\n=== 5. Algorithm - 轉換操作 ===" << endl;
    
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> result(5);
    
    // transform - 轉換元素（每個元素乘以2）
    transform(nums.begin(), nums.end(), result.begin(), 
              [](int n) { return n * 2; });
    cout << "transform(x*2): ";
    for (int n : result) cout << n << " ";
    cout << endl;
    
    // for_each - 對每個元素執行操作
    cout << "for_each(輸出): ";
    for_each(nums.begin(), nums.end(), 
             [](int n) { cout << n << " "; });
    cout << endl;
}

// ========================================
// 6. Algorithm - remove, unique, erase
// ========================================
void example_algorithm_remove() {
    cout << "\n=== 6. Algorithm - 移除操作 ===" << endl;
    
    vector<int> nums = {1, 2, 3, 2, 4, 2, 5};
    
    // remove - 移除指定值（需配合 erase）
    cout << "原始: ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    
    auto new_end = remove(nums.begin(), nums.end(), 2);
    nums.erase(new_end, nums.end());
    cout << "remove(2): ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    
    // unique - 移除連續重複元素
    vector<int> nums2 = {1, 1, 2, 2, 2, 3, 3, 4};
    cout << "\n原始: ";
    for (int n : nums2) cout << n << " ";
    cout << endl;
    
    auto new_end2 = unique(nums2.begin(), nums2.end());
    nums2.erase(new_end2, nums2.end());
    cout << "unique(): ";
    for (int n : nums2) cout << n << " ";
    cout << endl;
}

// ========================================
// 7. Algorithm - any_of, all_of, none_of
// ========================================
void example_algorithm_predicates() {
    cout << "\n=== 7. Algorithm - 條件判斷 ===" << endl;
    
    vector<int> nums = {2, 4, 6, 8, 10};
    
    // all_of - 是否全部滿足條件
    bool all_even = all_of(nums.begin(), nums.end(), 
                           [](int n) { return n % 2 == 0; });
    cout << "all_of(全是偶數): " << (all_even ? "true" : "false") << endl;
    
    // any_of - 是否有任何一個滿足條件
    bool has_greater_5 = any_of(nums.begin(), nums.end(), 
                                [](int n) { return n > 5; });
    cout << "any_of(有大於5): " << (has_greater_5 ? "true" : "false") << endl;
    
    // none_of - 是否全部不滿足條件
    bool none_odd = none_of(nums.begin(), nums.end(), 
                            [](int n) { return n % 2 == 1; });
    cout << "none_of(沒有奇數): " << (none_odd ? "true" : "false") << endl;
}

// ========================================
// 8. String 常用函式
// ========================================
void example_string() {
    cout << "\n=== 8. String 常用函式 ===" << endl;
    
    string str = "Hello World";
    
    // length, size - 取得長度
    cout << "length(): " << str.length() << endl;
    
    // substr - 取得子字串
    cout << "substr(0, 5): " << str.substr(0, 5) << endl;
    
    // find - 尋找子字串
    size_t pos = str.find("World");
    if (pos != string::npos) {
        cout << "find('World'): 位置 " << pos << endl;
    }
    
    // replace - 取代
    string str2 = str;
    str2.replace(6, 5, "C++");
    cout << "replace: " << str2 << endl;
    
    // append - 附加
    string str3 = "Hello";
    str3.append(" C++");
    cout << "append: " << str3 << endl;
    
    // compare - 比較
    string a = "apple", b = "banana";
    cout << "compare: " << (a.compare(b) < 0 ? "a < b" : "a >= b") << endl;
    
    // to_string - 數字轉字串
    int num = 123;
    string num_str = to_string(num);
    cout << "to_string(123): " << num_str << endl;
    
    // stoi - 字串轉整數
    string str_num = "456";
    int converted = stoi(str_num);
    cout << "stoi('456'): " << converted << endl;
}

// ========================================
// 9. Set 常用函式
// ========================================
void example_set() {
    cout << "\n=== 9. Set 常用函式 ===" << endl;
    
    set<int> s;
    
    // insert - 插入（自動排序、去重）
    s.insert(5);
    s.insert(2);
    s.insert(8);
    s.insert(2);  // 重複的不會被插入
    
    cout << "insert: ";
    for (int n : s) cout << n << " ";
    cout << endl;
    
    // find - 尋找
    auto it = s.find(5);
    cout << "find(5): " << (it != s.end() ? "找到了" : "找不到") << endl;
    
    // count - 計數（Set 中只會是 0 或 1）
    cout << "count(8): " << s.count(8) << endl;
    
    // erase - 刪除
    s.erase(2);
    cout << "erase(2): ";
    for (int n : s) cout << n << " ";
    cout << endl;
    
    // size - 大小
    cout << "size(): " << s.size() << endl;
}

// ========================================
// 10. Map 常用函式
// ========================================
void example_map() {
    cout << "\n=== 10. Map 常用函式 ===" << endl;
    
    map<string, int> scores;
    
    // insert - 插入
    scores.insert({"Alice", 95});
    scores.insert({"Bob", 87});
    
    // [] 運算子 - 插入或修改
    scores["Charlie"] = 92;
    scores["David"] = 88;
    
    // 遍歷
    cout << "遍歷 map:" << endl;
    for (const auto& [name, score] : scores) {
        cout << "  " << name << ": " << score << endl;
    }
    
    // find - 尋找
    auto it = scores.find("Bob");
    if (it != scores.end()) {
        cout << "find('Bob'): " << it->second << endl;
    }
    
    // count - 檢查是否存在
    cout << "count('Alice'): " << scores.count("Alice") << endl;
    
    // erase - 刪除
    scores.erase("David");
    cout << "erase('David') 後 size: " << scores.size() << endl;
    
    // at - 安全存取（會檢查是否存在）
    try {
        cout << "at('Charlie'): " << scores.at("Charlie") << endl;
    } catch (const out_of_range& e) {
        cout << "Key 不存在！" << endl;
    }
}

// ========================================
// 11. Stack 和 Queue
// ========================================
void example_stack_queue() {
    cout << "\n=== 11. Stack 和 Queue ===" << endl;
    
    // Stack - LIFO (後進先出)
    cout << "Stack (LIFO):" << endl;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    
    cout << "top(): " << st.top() << endl;
    st.pop();
    cout << "pop() 後 top(): " << st.top() << endl;
    cout << "size(): " << st.size() << endl;
    
    // Queue - FIFO (先進先出)
    cout << "\nQueue (FIFO):" << endl;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    cout << "front(): " << q.front() << endl;
    cout << "back(): " << q.back() << endl;
    q.pop();
    cout << "pop() 後 front(): " << q.front() << endl;
    cout << "size(): " << q.size() << endl;
}

// ========================================
// 12. Priority Queue（優先佇列）
// ========================================
void example_priority_queue() {
    cout << "\n=== 12. Priority Queue ===" << endl;
    
    // 預設是最大堆（max heap）
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);
    
    cout << "Priority Queue (最大堆):" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    // 最小堆（min heap）
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(5);
    min_pq.push(2);
    min_pq.push(8);
    min_pq.push(1);
    
    cout << "Priority Queue (最小堆):" << endl;
    while (!min_pq.empty()) {
        cout << min_pq.top() << " ";
        min_pq.pop();
    }
    cout << endl;
}

// ========================================
// 13. Deque（雙端佇列）
// ========================================
void example_deque() {
    cout << "\n=== 13. Deque（雙端佇列）===" << endl;
    
    deque<int> dq;
    
    // push_back, push_front
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(2);
    dq.push_front(1);
    
    cout << "deque: ";
    for (int n : dq) cout << n << " ";
    cout << endl;
    
    // pop_back, pop_front
    dq.pop_back();
    dq.pop_front();
    cout << "pop 後: ";
    for (int n : dq) cout << n << " ";
    cout << endl;
    
    // front, back
    cout << "front(): " << dq.front() << ", back(): " << dq.back() << endl;
}

// ========================================
// 14. List（雙向鏈結串列）
// ========================================
void example_list() {
    cout << "\n=== 14. List（雙向鏈結串列）===" << endl;
    
    list<int> lst = {3, 1, 4, 1, 5};
    
    // push_back, push_front
    lst.push_back(9);
    lst.push_front(2);
    
    cout << "list: ";
    for (int n : lst) cout << n << " ";
    cout << endl;
    
    // sort - List 有自己的 sort 方法
    lst.sort();
    cout << "sort(): ";
    for (int n : lst) cout << n << " ";
    cout << endl;
    
    // unique - 移除連續重複
    lst.unique();
    cout << "unique(): ";
    for (int n : lst) cout << n << " ";
    cout << endl;
    
    // reverse - 反轉
    lst.reverse();
    cout << "reverse(): ";
    for (int n : lst) cout << n << " ";
    cout << endl;
}

// ========================================
// 15. Lambda 表達式配合 STL
// ========================================
void example_lambda() {
    cout << "\n=== 15. Lambda 表達式配合 STL ===" << endl;
    
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // count_if - 計算滿足條件的元素數量
    int even_count = count_if(nums.begin(), nums.end(), 
                              [](int n) { return n % 2 == 0; });
    cout << "count_if(偶數): " << even_count << endl;
    
    // find_if - 尋找第一個滿足條件的元素
    auto it = find_if(nums.begin(), nums.end(), 
                      [](int n) { return n > 5; });
    if (it != nums.end()) {
        cout << "find_if(>5): " << *it << endl;
    }
    
    // sort with lambda - 自訂排序規則
    vector<string> words = {"apple", "pie", "zoo", "cat"};
    sort(words.begin(), words.end(), 
         [](const string& a, const string& b) { return a.length() < b.length(); });
    cout << "sort(依長度): ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;
}

// ========================================
// 主程式
// ========================================
int main() {
    cout << "🎓 C++ STL 常用函式範例" << endl;
    cout << "==========================================" << endl;
    
    example_vector();
    example_algorithm_basic();
    example_algorithm_minmax();
    example_algorithm_numeric();
    example_algorithm_transform();
    example_algorithm_remove();
    example_algorithm_predicates();
    example_string();
    example_set();
    example_map();
    example_stack_queue();
    example_priority_queue();
    example_deque();
    example_list();
    example_lambda();
    
    cout << "\n==========================================" << endl;
    cout << "📚 STL 四大組件：" << endl;
    cout << "1. 容器 (Containers): vector, set, map, stack, queue..." << endl;
    cout << "2. 演算法 (Algorithms): sort, find, count, transform..." << endl;
    cout << "3. 迭代器 (Iterators): begin(), end()..." << endl;
    cout << "4. 函式物件 (Function Objects): greater, less..." << endl;
    cout << "==========================================" << endl;
    
    return 0;
}


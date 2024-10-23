#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::sort;
// 使用std::sort对原生数组进行排序
int main() {
    int arr[] = {5, 8, 2, 4, 6, 9, 3, 7, 1};
    cout << "原始数组：";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << "排序后数组：";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    cout << "反向排序后数组：";
    sort(arr, arr + sizeof(arr) / sizeof(arr[0]), std::greater<int>());
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
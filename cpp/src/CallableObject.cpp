#include <iostream>
#include <functional>
#include <vector>
// 可调用对象:
// 1.函数指针
// 2.lambda表达式
// 3.std::bind
// 4.std::function
template <typename T>
void foo(T i, T j, T k) {
    std::cout << "foo: i=" << i << std::endl;
    std::cout << "foo: j=" << j << std::endl;
    std::cout << "foo: k=" << k << std::endl;
}
void CallableObject() {
    foo<int>(1, 2, 3);
    [](int n) {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res *= i;
        }
        std::cout << n << "的阶乘为:" << res << std::endl;
    }(5);
    std::bind(foo<int>, 9, 9, 9)();
    std::function<void(char)> f = std::bind(foo<char>, std::placeholders::_1, 'y', 'z');
    f('x');
}
int main() {
    CallableObject();
    std::vector<void *> v = {(void *)0x0000000000000000, (void *)0x0000000000000001};
    void (std::vector<void *>::*p)(size_t) = &std::vector<void *>::resize;
    (v.*p)(5);
    std::cout << "v.size()=" << v.size() << std::endl;
    std::function<void(void)> resize = std::bind(p, &v, 10);
    resize();
    std::cout << "v.size()=" << v.size() << std::endl;
    return 0;
}
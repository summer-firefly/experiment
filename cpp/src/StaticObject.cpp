#include <iostream>
// 局部对象与静态对象的作用域
class Foo {
public:
    Foo() {
        std::cout << "Foo构造函数被调用 - Foo()" << std::endl;
    }
    ~Foo() {
        std::cout << "Foo析构函数被调用 - ~Foo()" << std::endl;
    }
};
void experiment1() {
    // 在循环体内定义对象
    for (int i = 0; i < 3; ++i) {
        Foo foo;
    }
}
void experiment2() {
    // 在循环体内定义静态对象
    for (int i = 0; i < 3; ++i) {
        static Foo foo;
    }
}
void experiment3() {
    // 函数中定义对象
    Foo foo;
}
void experiment4() {
    // 函数中定义静态对象
    static Foo foo;
}
int main() {
    std::cout << "在循环体内定义对象,循环进行3次" << std::endl;
    experiment1();
    std::cout << "在循环体内定义静态对象,循环进行3次" << std::endl;
    experiment2();
    std::cout << "在函数中定义局部对象,调用3次该函数" << std::endl;
    for (size_t i = 0; i < 3; i++) {
        experiment3();
    }
    std::cout << "在函数中定义静态对象,调用3次该函数" << std::endl;
    for (size_t i = 0; i < 3; i++) {
        experiment4();
    }
    std::cout << "程序结束" << std::endl;
    return 0;
}
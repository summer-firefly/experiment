#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
// C语言获取随机数
void randomNumberC() {
    static bool isInit = false;
    if (!isInit) {
        srand((unsigned)time(NULL)); // srand设置全局变量的值
        isInit = true;
    }
    int randomNumber = rand(); // rand依据全局变量进行迭代更新
    printf("randomNumber: %d\n", randomNumber);
}
// Cpp获取随机数
void randomNumberCpp() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis;
    int randomNumber = dis(gen);
    printf("randomNumber: %d\n", randomNumber);
}
int main() {
    printf("使用C语言的srand与rand函数获取随机数:\n");
    for (size_t i = 0; i < 10; i++) {
        randomNumberC();
    }
    printf("使用C++的std::random_device,std::mt19937,std::uniform_int_distribution获取随机数:\n");
    for (size_t i = 0; i < 10; i++) {
        randomNumberCpp();
    }
    return 0;
}
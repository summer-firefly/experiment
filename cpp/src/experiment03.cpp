#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
// 创建n个线程,编号为1~n,交替打印,打印m轮
constexpr int n = 10;
constexpr int m = 10;
int total = m * n;
int currentThread = 0;
std::mutex mtx;
std::condition_variable cv;
int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < n; ++i) {
        threads.emplace_back([i] {
            std::unique_lock<std::mutex> lock(mtx);
        WAIT_TAG:
            cv.wait(lock, [i] { return currentThread == i; });
            while (total > 0) {
                currentThread = (currentThread + 1) % n;
                std::cout << "thread " << i << " has print , total rest : " << total-- << std::endl;
                cv.notify_all();
                goto WAIT_TAG;
            }
            currentThread = (currentThread + 1) % n;
            std::cout << "thread " << i << " has exit  , total rest : " << total << std::endl;
            cv.notify_all();
        });
    }
    for (auto &thread : threads) {
        thread.join();
    }
    return 0;
}
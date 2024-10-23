#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::greater;
using std::less;
// 比较器 std::greater与std::less
class Person {
    friend void compareCustomTypes();

public:
    Person() = default;
    Person(int age, int height) {
        this->age = age;
        this->height = height;
    }
    bool operator<(const Person &p) const {
        return this->age < p.age;
    }
    bool operator>(const Person &p) const {
        return this->height > p.height;
    }

private:
    int age = 0;
    int height = 0;
};
void compareBuildInTypes() {
    int x = 5;
    int y = 10;
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "std::greater<int>()(x,y) : " << std::greater<int>()(x, y) << endl;
    cout << "std::less<int>()(x,y) : " << std::less<int>()(x, y) << endl;
}
void compareCustomTypes() {
    Person p1(18, 180);
    Person p2(20, 170);
    printf("p1 message : age %d, height %d\n", p1.age, p1.height);
    printf("p2 message : age %d, height %d\n", p2.age, p2.height);
    cout << "std::greater<Person>()(p1,p2) : " << std::greater<Person>()(p1, p2) << endl;
    cout << "std::less<Person>()(p1,p2) : " << std::less<Person>()(p1, p2) << endl;
}
int main() {
    compareBuildInTypes();
    compareCustomTypes();
    return 0;
}
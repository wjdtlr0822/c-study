#include <iostream>
#include <memory>

using namespace std;

class Foo {
    int a, b;

    public:
    Foo(int a, int b) : a(a), b(b) { cout << "생성자 호출!" << endl; }
    void print() { cout << "a : " << a << ", b : " << b << endl; }
    ~Foo() { cout << "소멸자 호출!" << endl; }
};

int main() {
    auto ptr = make_unique<Foo>(3,5);
    ptr->print();
}
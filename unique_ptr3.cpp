#include <iostream>
#include <memory>

using namespace std;

class Foo {
    int a, b;

    public:
    Foo(int a, int b) : a(a), b(b) { cout << "������ ȣ��!" << endl; }
    void print() { cout << "a : " << a << ", b : " << b << endl; }
    ~Foo() { cout << "�Ҹ��� ȣ��!" << endl; }
};

int main() {
    auto ptr = make_unique<Foo>(3,5);
    ptr->print();
}
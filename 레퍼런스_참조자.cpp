#include <iostream>

using namespace std;

class A{
    public:
    virtual void show() {cout << "Parnet"<<endl;}
};

class B:public A{
    void show() override {cout << "Child" << endl;}
};

void test(A& a){ a.show();}

int main()
{
    A a;
    B b;
    test(a);
    test(b);
    return 0;
}
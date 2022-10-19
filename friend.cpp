#include <iostream>

using namespace std;

class A{
    int private_a;
    void private_func(){}

    friend class B;
    friend void func();
};

class B{
    public:
    void b(){
        A a;
        a.private_func();
        a.private_a=2;
        cout << "b : " << a.private_a<<endl; 
    }
};

void func(){
    A a;
    a.private_func();
    a.private_a=3;
    cout << "func() : " <<a.private_a <<endl;
}

int main(){
    B classb;
    classb.b();
    func();
    return 0;
}

//friend선언 시 class A에 있는 private영역에 접근 가능하다.
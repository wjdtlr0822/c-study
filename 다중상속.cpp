#include <iostream>


using namespace std;


class A{
    public:
    int a;
    A(){cout << "A생성자 호출"<<endl;}
};

class B{
    public:
    B(){cout << "B생성자 호출"<<endl;}
};

class C:public B,public A{
    public:
    int c;
    C():A(),B(){cout << "C생성자 호출"<<endl;}
};

int main(){
    C c;
}

//실행시 상속 순서에 따라 생성자의 순서가 정해진다.
// public B,public A로 선언을 하였기 때문에 b생성자가 먼저 실행된다.
// 다중상속시 상속받은 변수명이 겹칠 경우 오류발생!
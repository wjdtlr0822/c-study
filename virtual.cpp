#include <iostream>
#include <string>

using namespace std;


class Base{
    public:
    Base(){cout << "기반클래스 생성자"<<endl;}

    virtual void what(){ cout << "기반클래스의 what()"<<endl;}
};

class Derived: public Base{
    public:
    Derived():Base(){ cout <<"파생 클래스 생성자"<<endl;}

    void what(){ cout << "파생 클래스의 what()"<<endl;}
};


int main()
{
    Base b;
    Derived d;

    Base *b_d = &d;
    Base *b_b = &b;
    cout << "b_d의 what출력은!!!!()!!!!"<<endl;
    b_d->what(); //이거또한 Base의 what()함수가 실행 되어야하는데 파생클래스의 what()이 실행된다.

    cout << "b_b의 what출력은!!!!()!!!!"<<endl;
    b_b->what();

    return 0;
}
#include <iostream>
#include <string>

using namespace std;


class Base{
    public:
    Base(){cout << "���Ŭ���� ������"<<endl;}

    virtual void what(){ cout << "���Ŭ������ what()"<<endl;}
};

class Derived: public Base{
    public:
    Derived():Base(){ cout <<"�Ļ� Ŭ���� ������"<<endl;}

    void what(){ cout << "�Ļ� Ŭ������ what()"<<endl;}
};


int main()
{
    Base b;
    Derived d;

    Base *b_d = &d;
    Base *b_b = &b;
    cout << "b_d�� what�����!!!!()!!!!"<<endl;
    b_d->what(); //�̰Ŷ��� Base�� what()�Լ��� ���� �Ǿ���ϴµ� �Ļ�Ŭ������ what()�� ����ȴ�.

    cout << "b_b�� what�����!!!!()!!!!"<<endl;
    b_b->what();

    return 0;
}
#include <iostream>


using namespace std;


class A{
    public:
    int a;
    A(){cout << "A������ ȣ��"<<endl;}
};

class B{
    public:
    B(){cout << "B������ ȣ��"<<endl;}
};

class C:public B,public A{
    public:
    int c;
    C():A(),B(){cout << "C������ ȣ��"<<endl;}
};

int main(){
    C c;
}

//����� ��� ������ ���� �������� ������ ��������.
// public B,public A�� ������ �Ͽ��� ������ b�����ڰ� ���� ����ȴ�.
// ���߻�ӽ� ��ӹ��� �������� ��ĥ ��� �����߻�!
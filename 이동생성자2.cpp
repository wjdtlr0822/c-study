#include <iostream>

using namespace std;

class A{
    public:
    A(){cout << "�Ϲ� ������ ȣ��"<<endl;}
    A(A &a){cout << "���� ������ ȣ��"<<endl;}
    A(A &&a){cout << "�̵� ������ ȣ��"<<endl;}
};

int main(){
    A a;
    A b(a);
    A c(move(a)); 
    //move�Լ��� ���ڷ� ���� ��ü�� ���������� ��ȯ�ؼ� �������ֱ� ������ �̵������ڰ� ȣ��ȴ�.
}
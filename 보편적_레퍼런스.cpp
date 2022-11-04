#include <iostream>

using namespace std;

template <typename T>
void wrapper(T&& u){
    g(forward<T>(u));
}

template <typename T>
void wrapper2(T& u){
    g(forward<T>(u));
}

class A{};

void g(A& a){cout << "������ ���۷��� ȣ��"<<endl;}
void g(const A& a){cout << "������ ��� ���۷��� ȣ��"<<endl;}
void g(A&& a){cout << "������ ���۷��� ȣ��"<<endl;}

int main(){
    A a;
    const A ca;

    cout <<"__________����________"<<endl;
    g(a);
    g(ca);
    g(A());
    cout << "Wrapper__________________"<<endl;
    wrapper(a); //������
    wrapper(ca); //��� ������
    wrapper(A()); // ������

}

//������ �������� Ȯ���� �˰ڴµ�
// forward<T>(u) �� ���ذ� �Ǵµ� ��Ȯ�� ���� ����ؾ����� �� �𸣰ڴ�...
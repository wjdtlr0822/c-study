#include <iostream>
#include <string>

using namespace std;


class Base{
    string a;

    public:
    Base():a("�θ�"){
        cout << "�θ�Ŭ���� ������" <<endl;
    }

    void print_a(){
        cout << a <<endl;
    }
};

class Derived:public Base{
    string a;
    public:
    Derived():a("�ڽ�"),Base(){
        cout << "�ڽ�Ŭ���� ������"<<endl;
    }

    void print_a(){
        cout << a << endl;
    }
};


int main(){
    Base p;
    Derived c;

    cout << "==========��ĳ����=========="<<endl;

    Base *p_c=&c; // ��ĳ����
    p_c->print_a(); // 
    return 0;
}

//�ٿ�ĳ������ �Ұ���
#include <iostream>
#include <string>

using namespace std;


class Base{
    string a;

    public:
    Base():a("부모"){
        cout << "부모클래스 생성자" <<endl;
    }

    void print_a(){
        cout << a <<endl;
    }
};

class Derived:public Base{
    string a;
    public:
    Derived():a("자식"),Base(){
        cout << "자식클래스 생성자"<<endl;
    }

    void print_a(){
        cout << a << endl;
    }
};


int main(){
    Base p;
    Derived c;

    cout << "==========업캐스팅=========="<<endl;

    Base *p_c=&c; // 업캐스팅
    p_c->print_a(); // 
    return 0;
}

//다운캐스팅은 불가능
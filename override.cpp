#include <iostream>
#include <string>

class Base {
    std::string s;

    public:
    Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }

    virtual void incorrect() { std::cout << "��� Ŭ���� " << std::endl; }
};

class Derived : public Base {
    std::string s;

    public:
    Derived() : Base(), s("�Ļ�") {}

    void incorrect() override { std::cout << "�Ļ� Ŭ���� " << std::endl; }
};

int main() {
    Base p;
    Derived c;

    Base* p_c = &c;
    Base* p_p = &p;

    std::cout << " == ���� ��ü�� Base == " << std::endl;
    p_p->incorrect();

    std::cout << " == ���� ��ü�� Derived == " << std::endl;
    p_c->incorrect();
    return 0;
}
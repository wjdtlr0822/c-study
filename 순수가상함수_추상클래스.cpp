#include <iostream>

using namespace std;

class Animal{
    public:
    Animal(){}
    virtual ~Animal(){}
    virtual void speak() = 0; //�ݵ�� �������̵� �Ǿ�߸� �ϴ� �Լ�(���������Լ�)
};

class Dog : public Animal{
    public:
    Dog() : Animal(){}
    void speak() override{
        cout << "�۸�!!" <<endl;
    }
};

class Cat : public Animal{
    public:
    Cat() : Animal(){}
    void speak() override{
        cout << "�߿˾߿�" <<endl;
    }
};



int main(){
    Animal* dog = new Dog();
    Animal *cat = new Cat();
    Dog a;
    
    a.speak();

    dog->speak();
    cat->speak();
    return 0;
}
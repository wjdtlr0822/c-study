#include <iostream>

using namespace std;

class Animal{
    public:
    Animal(){}
    virtual ~Animal(){}
    virtual void speak() = 0; //반드시 오버라이딩 되어야만 하는 함수(순수가상함수)
};

class Dog : public Animal{
    public:
    Dog() : Animal(){}
    void speak() override{
        cout << "멍멍!!" <<endl;
    }
};

class Cat : public Animal{
    public:
    Cat() : Animal(){}
    void speak() override{
        cout << "야옹야옹" <<endl;
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
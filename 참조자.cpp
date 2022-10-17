#include <iostream>

using namespace std;


class A{
    int x;

    public:
    A(int c) : x(c){}
    int get_x(){return x;}
    int& access_x(){return x;}
    void show_x(){cout << x << endl;}
};


int main(){
    A a(10);
    int c= a.get_x();

    c=11;
    a.show_x();
    
    int& d = a.access_x();
    d=11;
    a.show_x();

    a.access_x()=3;
    a.show_x();

    return 0;
}
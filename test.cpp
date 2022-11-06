#include <iostream>
#include<functional>
using namespace std;

int main(){
    int a=5;
    cout << &a<<endl;
    cout << ref(a)<<endl;
}
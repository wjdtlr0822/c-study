#include <iostream>

using namespace std;

int foo() noexcept{}
int bar() noexcept{throw 1;}

int main(){
    foo();
    try{
        bar();
    }catch(int x){
        cout << "Error " << x <<endl;
    }
}
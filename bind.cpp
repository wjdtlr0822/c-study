#include <iostream>
#include <functional>

using namespace std;

void add(int x, int y){
    cout << x << " + " << y << " = "<<x+y<<endl;
}

int main(){
    auto add_bind = bind(add,placeholders::_1,placeholders::_2);
    add_bind(1,3);
}
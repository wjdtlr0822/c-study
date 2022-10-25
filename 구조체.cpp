#include <iostream>

using namespace std;

struct Address
{
    int level;
    char name;
};

ostream& operator<<(ostream& os,Address a){
    os<<a.level <<endl;
    os<<a.name<<endl;
}

int main(){
    Address a;
    a.level=10;
    a.name='c';

    cout << a<<endl;
}
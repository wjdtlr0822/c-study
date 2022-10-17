#include <iostream>

using namespace std;



class teste{
    const static int a;
    public:
    void count();
};

int teste::a=10;

void teste::count(){
    a++;
    cout<<a<<endl;
}

int main(){
    teste a;
    a.count();
    a.count();    
}
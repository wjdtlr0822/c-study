#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char *a;
    a=new char[5];
    strcpy(a,"test");
    char *c;
    strcpy(c,a);
    strcpy(a,"1111");
    cout << a << " " << c << endl;
}
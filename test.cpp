#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main(){
    string str= R"(awef
    awejflk
    awejflkawjelkf
    //awefjlkawjeflk
    \n\nawefjlkawefjlk
    awewjlkawe
    )";

    cout << str;

    int &&a = 3;
    int &b = 4;
    cout << a << endl;
}
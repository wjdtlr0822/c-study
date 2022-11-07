#include<iostream>
#include<type_traits>

using namespace std;

template <typename T>
void show_value(T t){
    if constexpr (is_pointer<T>::value){
        cout <<"포인터!" << *t<<endl;
    }
    else{
        cout <<"포인터 아니다!"<< t <<endl;
    }
}


int main(){
    int x=3;
    show_value(x);

    int *p = &x;
    show_value(p);
}
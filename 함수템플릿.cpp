#include <iostream>
#include <string>
#include <array>

using namespace std;

template <typename T>
T max(T &a,T &b){
    return a>b?a:b;
}

template <typename T,int num>
T add_num(T t){
    return t+num;
}


template <typename T,int num=5>
T add_num2(T &t){
    return t+num;
}

template <typename a>
void print_array(const a arr){
    cout << "arr 의 크기 " << sizeof(arr) <<endl;
    for(int i=0;i<arr.size();i++){
        cout << arr[i]<<endl;
    }
}


int main(){
    int a=1, b=2;
    cout << max(a,b) << endl; // 원래는 max<int>(a,b)를 해야하지만 컴파일러가 알아서 인스턴스화 해준다.
    int x=add_num<int,5>(a);
    cout << x<<endl;

    array<int,5> arr ={1,2,3,4,5};
    array<int,7> arr1={1,2,3,4,5,6,7};
    print_array(arr);
    print_array(arr1);    
    int y = add_num2(a);
    cout << y <<endl;
}
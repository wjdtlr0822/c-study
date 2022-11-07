#include<iostream>

using namespace std;


//constexpr을 사용했기 때문에 main함수에서 A<3628800>으로 인식되어
// 오류가 나지 않는다
constexpr int Factorial(int n){
    int total = 1;
    for(int i=1;i<=n;i++){
        total*=i;
    }
    return total;
}


template <int N>
struct A
{
    int operator()(){return N;}
};

int main(){
    A<Factorial(10)> a;
    cout << a() <<endl;
}

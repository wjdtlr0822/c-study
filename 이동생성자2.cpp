#include <iostream>

using namespace std;

class A{
    public:
    A(){cout << "일반 생성자 호출"<<endl;}
    A(A &a){cout << "복사 생성자 호출"<<endl;}
    A(A &&a){cout << "이동 생성자 호출"<<endl;}
};

int main(){
    A a;
    A b(a);
    A c(move(a)); 
    //move함수는 인자로 받은 객체를 우측값으로 변환해서 리턴해주기 떄문에 이동생성자가 호출된다.
}
#include <iostream>

using namespace std;

template <typename T>
void wrapper(T&& u){
    g(forward<T>(u));
}

template <typename T>
void wrapper2(T& u){
    g(forward<T>(u));
}

class A{};

void g(A& a){cout << "좌측값 레퍼런스 호출"<<endl;}
void g(const A& a){cout << "좌측값 상수 레퍼런스 호출"<<endl;}
void g(A&& a){cout << "우측값 레퍼런스 호출"<<endl;}

int main(){
    A a;
    const A ca;

    cout <<"__________원본________"<<endl;
    g(a);
    g(ca);
    g(A());
    cout << "Wrapper__________________"<<endl;
    wrapper(a); //좌측값
    wrapper(ca); //상수 좌측값
    wrapper(A()); // 우측값

}

//좌측값 우측값은 확실히 알겠는데
// forward<T>(u) 도 이해가 되는데 정확히 언제 사용해야할지 잘 모르겠다...
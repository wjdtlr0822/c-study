#include <iostream>

using namespace std;

template <int n>
struct  Factorial
{
    static const int result = n * Factorial<n-1> :: result;
}; // static const를 사용한 이유 = 초기화를 할 수 있는 멤버타입 이기 때문
// 두번째로는 static const야 말로 이클래스는 이것이다 라고 나타내는 것이기 때문.


template<>
struct Factorial<1>
{
    static const int result = 1;
};

int main(){
    cout << "6! : "<<Factorial<6>::result<<endl;
}
//프로그램 실행 속도를 향상 시킬수 있어 TMP를 사용하지만 컴파일 시간은 늘어난다.
//그리고 템플릿메타 프로그래밍은 매우 복잡하다.
//템플릿 메타 프로그래밍으로 작성된 코드는 버그를 찾기 어렵다.

//컴파일 타임에 모든 연산이 끝난다.
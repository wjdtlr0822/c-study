//메모리 관리 실수 2가지
//1.메모리 사용 후 해제하지 않은 경우
//2.메모리 해제 후 참조하는 경우

// Data *data = new Data();
// Data *data2 = data
// delete data
// .... data2사용
// delete data2

// 이렇게 이미 소멸된 객체를 다시 소멸시켜서 발생하는 버그를 double free버그라고 불린다.


// C++ 에서는 이렇게, 특정 객체에 유일한 소유권을 부여하는 포인터 객체를 unique_ptr 라고 합니다.

//RAII패턴
#include <iostream>
#include <memory>

using namespace std;

class A{
    int *data;

    public:
    A(){
        cout << "자원할당 100"<<endl;
        data = new int[100];
    }
    A(const A& a)=delete; //프로그래머가 명시적으로 이 함수는 쓰지못하게 한다.
    //혹시나 사용하더라도 컴파일 오류가 발생한다.
    void some(){cout <<"일반 포인터와 동일하게 사용 가능"<<endl;}
    ~A(){
        cout <<"자원 해제 100"<<endl;
        delete[] data;
    }
};

void do_something(){
    unique_ptr<A> pa(new A());
    cout << "pa : ";
    pa->some();
    cout << "메모리 이전 전 pa.get()"<<pa.get()<<endl;
    // unique_ptr<A> pb =pa; // 오류발생
    //unique_ptr도 오류가 나는 이유는 명시적으로 복사 생성자를 막아놨기 때문.

    unique_ptr<A> pb = move(pa);
    cout << "메모리 이전 후 pa.get()"<<pa.get()<<endl;
    cout << "pb : ";
    pb->some();
    //다음과 같이 소유권 이전은 가능.
    //객체의 소유권을 갖게 되고, pa는 아무것도 아리키고 있지 않아 가능.
}

int main(){
    do_something();
}

//pa는 스택에 정의된 객체이기 때문에 do_something 함수가 종료될 때 자동으로 소멸자가 호출된다.


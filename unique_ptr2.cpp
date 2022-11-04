#include <iostream>
#include<memory>

using namespace std;


class A{
    int *data;

    public:
    A(){
        data = new int[100];
        cout << "자원 100 할당 "<<endl;
    }
    void some(){cout << "일반 포인터와 동일하게 사용 가능!!!"<<endl;}
    void do_sth(int a){
        cout <<"무언가를 한다!"<<endl;
        data[0] = a;
    }
    ~A(){
        cout <<"자원을 해제함!"<<endl;
        delete[] data;
    }
};

void do_something(A *a){a->do_sth(3);}
// void do_something(unique_ptr<A>& pa){pa->do_sth(3);}

int main(){
    unique_ptr<A> pa(new A());
    do_something(pa.get()); 
    // do_something(pa);
    //다음과 같이 사용해도 오류는 없지만 소유권을 의미한다는 원칙에 위배된다.
}
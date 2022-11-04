#include<iostream>
#include<memory>


using namespace std;

class A: public enable_shared_from_this<A>{
    int *data;
    public:
    A(){
        data= new int[100];
        cout <<"데이터 할당"<<endl;
    }
    ~A(){
        delete[] data;
        cout<<"데이터 제거"<<endl;
    }

    shared_ptr<A> get_shared_ptr(){return shared_from_this();}
    //다음과 같이 하면 객체 자신을 가리키는 shared_ptr를 만들수있다.
    //shared_from_this는 제어블록이 있는지 확인만 할 뿐 만들지는 않는다.
};

int main(){
    A *a = new A();
    // shared_ptr<A> sa(new A()) -> 
    // shared_ptr<A> sa = make_shared<A>(a);
    // shared_ptr<A> sa2 = make_shared<A>(a);
    shared_ptr<A> sa(a); 
    shared_ptr<A> sa2 =sa->get_shared_ptr();
    
    //인자로 주소값이 전달되면 객체를 첫번째로 소유하는것처럼 행동한다.
    //그렇기에 shared_ptr를 주소값을 통해서 생성하는 것을 지양해야한다.
    cout<<sa.use_count()<<endl;
}
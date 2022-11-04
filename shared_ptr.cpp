//때에 따라서는 여러 개의 스마트 포인터가 하나의 객체를 같이 소유 해야 하는 경우가 발생합니다
//특정 자원을 몇 개의 객체에서 가리키는지를 추적한 다음에, 그 수가 0 이 되야만 비로소 해제를 시켜주는 방식의 포인터가 필요합니다.

#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class A{
    int *data;

    public:
    A(){
        cout << "메모리 할당"<<endl;
        data = new int[100];
    }
    ~A(){
        delete[] data;
        cout <<"메모리 해제"<<endl;
    }
};

int main(){
    shared_ptr<A> p1(new A());
    shared_ptr<A> p2(p1);

    cout << p1.use_count()<<endl;
    cout << p2.use_count()<<endl;
    // unique_ptr<A> p3(new A());
    // unique_ptr<A> p4(p3); //error


cout <<endl << "vector test"<<endl;
    vector<shared_ptr<A>> vec;
    vec.push_back(shared_ptr<A>(new A()));
    vec.push_back(shared_ptr<A>(vec[0]));
    vec.push_back(shared_ptr<A>(vec[1]));

    cout << "첫번째 소멸"<<endl;
    vec.erase(vec.begin());
    cout << "2번째 소멸"<<endl;
    vec.erase(vec.begin());
    cout << "3번째 소멸"<<endl;
    vec.erase(vec.begin());
    
}
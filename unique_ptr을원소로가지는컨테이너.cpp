#include<iostream>
#include<memory>
#include <vector>


using namespace std;

class A{
    int *data;
    public:
    A(){
        data = new int[100];
        cout << "메모리 할당"<<endl;
    }
    ~A(){
        cout << "메모리 제거"<<endl;
        delete[] data;
    }
    void some(){cout << "일반포인터와 동일하게 사용 가능!!!!"<<endl;}
};

int main(){
    vector<unique_ptr<A>> vec;
    unique_ptr<A> pa(new A());

    vec.push_back(move(pa));
    vec.back()->some();
}
#include<iostream>
#include<memory>
#include <vector>


using namespace std;

class A{
    int *data;
    public:
    A(){
        data = new int[100];
        cout << "�޸� �Ҵ�"<<endl;
    }
    ~A(){
        cout << "�޸� ����"<<endl;
        delete[] data;
    }
    void some(){cout << "�Ϲ������Ϳ� �����ϰ� ��� ����!!!!"<<endl;}
};

int main(){
    vector<unique_ptr<A>> vec;
    unique_ptr<A> pa(new A());

    vec.push_back(move(pa));
    vec.back()->some();
}
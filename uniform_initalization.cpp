#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<typeinfo>

using namespace std;

class A{
    public:
    A(){cout << "A�� ������ ȣ��!!"<<endl;}
    A(int x){cout <<"A������ ȣ�� : "<<x<<endl;}
    A(int x,double y){cout <<"A������ ȣ�� : "<< x <<" "<< y <<endl;}
};


A func(){
    return {1,2.3}; //A(1,2.3)�� ����
}

A func1(){
    return (1,2.3);
}

int main(){
    A a(3.5); //�Ͻ��� Ÿ�Ժ�ȯ ����
    A b{}; //�Ͻ��� Ÿ�Ժ�ȯ �Ұ���
    func();
    func1();
    vector<int> vec={1,2,3,4,5};
    map<string,int> m = {
        {"abc",1},{"hi",3},{"hello",5},{"c++",2},{"java",6}
    };
    for(auto itr = vec.begin();itr!=vec.end();itr++){
        cout << *itr<<endl;
    }

    for(auto itr : m){
        cout << itr.first << " " << itr.second<<endl;
    }

    auto list ={"ABC","CDC"};
    for(auto a : list){
        cout << typeid(a).name()<<endl;
    }
    string c="123";
    cout << typeid(c).name()<<endl;
}
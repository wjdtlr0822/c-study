#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<typeinfo>

using namespace std;

class A{
    public:
    A(){cout << "A의 생성자 호출!!"<<endl;}
    A(int x){cout <<"A생성자 호출 : "<<x<<endl;}
    A(int x,double y){cout <<"A생성자 호출 : "<< x <<" "<< y <<endl;}
};


A func(){
    return {1,2.3}; //A(1,2.3)과 동일
}

A func1(){
    return (1,2.3);
}

int main(){
    A a(3.5); //암시적 타입변환 가능
    A b{}; //암시적 타입변환 불가능
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
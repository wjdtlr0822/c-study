#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class A{
    string s;
    weak_ptr<A> other;

    public:
    A(const string &s):s(s) {cout <<"자원을 획득함"<<endl;}
    ~A(){cout << "소멸자 호출 "<<endl;}

    void set_other(weak_ptr<A> o) { other= o;}
    void access_other(){
        shared_ptr<A> o = other.lock();
        //weak_ptr은 자체로 원소를 참조할 수 없기 떄문에 shared_ptr로 변환하기 위해 lock함수 사용
        //shared_ptr의 참조개수가 0개면 빈shared_ptr을 반환
        //1개 이상이면 shared_ptr을 반환
        if(o){
            cout << "접근 : "<<o->name()<<endl;
        }
        else{
            cout << "이미 소멸됨 ㅠ"<<endl;
        }
    }
    string name(){return s;}
};

int main(){
    vector<shared_ptr<A>> vec;
    vec.push_back(make_shared<A>("자원 1"));
    vec.push_back(make_shared<A>("자원 2"));
    
    vec[0]->set_other(vec[1]);
    vec[1]->set_other(vec[0]);

    cout << "vec[0] ref count : "<<vec[0].use_count()<<endl;
    cout << "vec[1] ref count : "<<vec[1].use_count()<<endl;

    vec[0]->access_other();
    vec.pop_back();
    vec[0]->access_other();
}
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class A{
    string s;
    weak_ptr<A> other;

    public:
    A(const string &s):s(s) {cout <<"ÀÚ¿øÀ» È¹µæÇÔ"<<endl;}
    ~A(){cout << "¼Ò¸êÀÚ È£Ãâ "<<endl;}

    void set_other(weak_ptr<A> o) { other= o;}
    void access_other(){
        shared_ptr<A> o = other.lock();
        if(o){
            cout << "Á¢±Ù : "<<o->name()<<endl;
        }
        else{
            cout << "ÀÌ¹Ì ¼Ò¸êµÊ ¤Ð"<<endl;
        }
    }
    string name(){return s;}
};

int main(){
    vector<shared_ptr<A>> vec;
    vec.push_back(make_shared<A>("ÀÚ¿ø 1"));
    vec.push_back(make_shared<A>("ÀÚ¿ø 2"));
    
    vec[0]->set_other(vec[1]);
    vec[1]->set_other(vec[0]);

    cout << "vec[0] ref count : "<<vec[0].use_count()<<endl;
    cout << "vec[1] ref count : "<<vec[1].use_count()<<endl;

    vec[0]->access_other();
    vec.pop_back();
    vec[0]->access_other();
}
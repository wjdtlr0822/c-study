#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main(){
    multiset<string> s;
    s.insert("abc");
    s.insert("abc");
    s.insert("bcd");

    for(auto itr = s.begin();itr!=s.end();itr++){
        cout << *itr <<endl;
    }

    multimap<int,string> m;
    m.insert(make_pair(1,"김정식"));
    m.insert(make_pair(1,"김정식2"));
    m.insert(make_pair(2,"김정순"));
    m.insert(make_pair(3,"김정신"));

    auto a = m.find(1);
    cout << a->first<< " " << a->second << endl;

    //멀티맵의 경우 []연산자를 제공하지 않는다
    // cout << m[1] << endl;  //error
    auto range = m.equal_range(1);
    for(auto itr = range.first; itr!=range.second;itr++){
        cout << itr->first << " " <<itr->second <<endl;
    }    
}
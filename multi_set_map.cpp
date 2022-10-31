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
    m.insert(make_pair(1,"������"));
    m.insert(make_pair(1,"������2"));
    m.insert(make_pair(2,"������"));
    m.insert(make_pair(3,"������"));

    auto a = m.find(1);
    cout << a->first<< " " << a->second << endl;

    //��Ƽ���� ��� []�����ڸ� �������� �ʴ´�
    // cout << m[1] << endl;  //error
    auto range = m.equal_range(1);
    for(auto itr = range.first; itr!=range.second;itr++){
        cout << itr->first << " " <<itr->second <<endl;
    }    
}
#include <iostream>
#include <unordered_set>
#include <unordered_map>


using namespace std;

template <typename K>
void print_unordered(unordered_set<K> &k){
    for(K i : k){
        cout << i << " ";
    }
    cout <<endl;
}

template <typename K>
void is_exist(unordered_set<K> s, K key){
    auto itr = s.find(key);
    if(itr == s.end()) cout << key << "는 존재하지 않습니다."<<endl;
    else cout << key << "는 존재한다."<<endl;
}

template <typename K,typename V>
void print_unordered(unordered_map<K,V> m){
    for(auto itr = m.begin();itr!=m.end();itr++){
        cout << itr->first << " " <<itr->second<<endl;
    }
}

template <typename K,typename V>
void is_exist(unordered_map<K,V> m, K key){
    auto itr = m.find(key);
    if(itr == m.end()) cout << key << "는 존재하지 않습니다."<<endl;
    else cout << key << " : " <<m[key]<<endl;
}

int main(){
    unordered_set<int> s;
    unordered_map<int,string> m;

    m.insert(make_pair(1,"1등"));
    m.insert(make_pair(3,"3등"));
    m.insert(make_pair(2,"2등"));
    m.insert(make_pair(4,"4등"));
    
    s.insert(1);
    s.insert(5);
    s.insert(4);

    print_unordered(s);
    is_exist(s,1);
    is_exist(s,9);
    
    print_unordered(m);
    is_exist(m,1);
    is_exist(m,9);
}


//unordered_set은 insert,erase,find가 모두 o(1)으로 수행된다
//원래 셋,맵은 o(logn)이다.
//unordered_set map 모두 o(1)로 가능한 이유는 해시 함수이기 때문
//하지만 최악의 경우 o(n)으로 실행된다.
//set,map은 무조건 o(logn)의 속도로 실행된다.
//최적화가 매우 필요한 작업일 경우에만 unordered_set,map을 사용하는 것을 추천

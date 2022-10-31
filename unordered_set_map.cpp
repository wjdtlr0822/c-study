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
    if(itr == s.end()) cout << key << "�� �������� �ʽ��ϴ�."<<endl;
    else cout << key << "�� �����Ѵ�."<<endl;
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
    if(itr == m.end()) cout << key << "�� �������� �ʽ��ϴ�."<<endl;
    else cout << key << " : " <<m[key]<<endl;
}

int main(){
    unordered_set<int> s;
    unordered_map<int,string> m;

    m.insert(make_pair(1,"1��"));
    m.insert(make_pair(3,"3��"));
    m.insert(make_pair(2,"2��"));
    m.insert(make_pair(4,"4��"));
    
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


//unordered_set�� insert,erase,find�� ��� o(1)���� ����ȴ�
//���� ��,���� o(logn)�̴�.
//unordered_set map ��� o(1)�� ������ ������ �ؽ� �Լ��̱� ����
//������ �־��� ��� o(n)���� ����ȴ�.
//set,map�� ������ o(logn)�� �ӵ��� ����ȴ�.
//����ȭ�� �ſ� �ʿ��� �۾��� ��쿡�� unordered_set,map�� ����ϴ� ���� ��õ

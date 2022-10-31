//맵은 셋과 거의 똑같은 자료구조이다.
//셋의 경우 키만 보관했지만, 맵의 경우 키에 대응되는 값까지 보관한다.
// 셋 - 키
// 맵  : 키 - value

#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename K,typename V>
void print_map(map<K,V> &m){
    for(auto itr = m.begin();itr!=m.end();itr++){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename K,typename V>
void search_and_print(map<K,V> &m,K key){
    auto itr = m.find(key);
    if(itr != m.end()){
        cout << itr->first << " " << itr->second << endl;
    }
    else{
        cout << key <<"(님) 값이 존재하지 않습니다"<<endl;
    }
}

int main(){
    map<string,double> picher_list;
    picher_list.insert(pair<string,double>("박세웅",2.23));
    picher_list.insert(make_pair("김정식",4.5));
    picher_list.insert(make_pair("박시현",1.5));
//map에는 pair를 사용해서 넣어줘야한다.
//하지만 매칭 값을 넣어주기 귀찮으므로 make_pair를 사용하면 편리하다.
    picher_list["김정현"]=3.33;
    
    print_map(picher_list);

    cout << "김정식의 학점은 : " <<picher_list["김정식"]<<endl;

    search_and_print(picher_list,string("김정식"));
    search_and_print(picher_list,string("박순자"));
}

//기본적으로 없는 키 값을 검색하면 디폴트로 double일 경우 0을 반환하기때문에 따로 처리해주는게 좋다.
//같은 키값이 insert될 경우 무시한다.

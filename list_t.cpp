//vector와는 달리 임의의 위치에 있는 원소레 접근을 바로 할 수 없다.
// 임의의 위치에 있는 원소에 접근하기 위해서는 하나씩 링크를 따라가야 한다.
// 리스트에는 []와 at함수가 아예 정의되어 있지 않다.
//리스트의 장점은 임의의 위치에 원소를 추가하거나 제거하는 작업이 o(1)로 매우 빠르다.
//왜냐하면 원하는 위치 앞과 뒤에 있는 링크값만 바꿔주면 되기 때문.

#include <iostream>
#include <list>

using namespace std;

template <typename T>
void print_lst(list<T> &lst){
    cout << "[ ";
    for(T i : lst){
        cout << i<<" ";
    }
    cout <<" ]"<<endl;
}

int main(){
    list<int> lst;

    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(4);

    cout <<"iterator : "<<endl;
    for(list<int>::iterator itr = lst.begin(); itr !=lst.end();itr++){
        cout << *itr <<endl;
        // itr+5와 같이 임의의값에 접근 불가능. 
        // 메모리에 순차적으로 저장하지 않기 떄문에..
    }

    cout << "처음 리스트 상태 " <<endl;
    print_lst(lst);
    for(list<int>::iterator itr = lst.begin(); itr != lst.end();itr++){
        if(*itr == 3) lst.insert(itr,2);
    }
    cout<<"insert 후 " <<endl;
    print_lst(lst);

    for(list<int>::iterator itr = lst.begin();itr!=lst.end();itr++){
        if(*itr == 3) {lst.erase(itr); break;}
    }
    cout <<"erase 후 "<<endl;
    print_lst(lst);

    return 0;
}
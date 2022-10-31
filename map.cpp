//���� �°� ���� �Ȱ��� �ڷᱸ���̴�.
//���� ��� Ű�� ����������, ���� ��� Ű�� �����Ǵ� ������ �����Ѵ�.
// �� - Ű
// ��  : Ű - value

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
        cout << key <<"(��) ���� �������� �ʽ��ϴ�"<<endl;
    }
}

int main(){
    map<string,double> picher_list;
    picher_list.insert(pair<string,double>("�ڼ���",2.23));
    picher_list.insert(make_pair("������",4.5));
    picher_list.insert(make_pair("�ڽ���",1.5));
//map���� pair�� ����ؼ� �־�����Ѵ�.
//������ ��Ī ���� �־��ֱ� �������Ƿ� make_pair�� ����ϸ� ���ϴ�.
    picher_list["������"]=3.33;
    
    print_map(picher_list);

    cout << "�������� ������ : " <<picher_list["������"]<<endl;

    search_and_print(picher_list,string("������"));
    search_and_print(picher_list,string("�ڼ���"));
}

//�⺻������ ���� Ű ���� �˻��ϸ� ����Ʈ�� double�� ��� 0�� ��ȯ�ϱ⶧���� ���� ó�����ִ°� ����.
//���� Ű���� insert�� ��� �����Ѵ�.

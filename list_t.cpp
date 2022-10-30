//vector�ʹ� �޸� ������ ��ġ�� �ִ� ���ҷ� ������ �ٷ� �� �� ����.
// ������ ��ġ�� �ִ� ���ҿ� �����ϱ� ���ؼ��� �ϳ��� ��ũ�� ���󰡾� �Ѵ�.
// ����Ʈ���� []�� at�Լ��� �ƿ� ���ǵǾ� ���� �ʴ�.
//����Ʈ�� ������ ������ ��ġ�� ���Ҹ� �߰��ϰų� �����ϴ� �۾��� o(1)�� �ſ� ������.
//�ֳ��ϸ� ���ϴ� ��ġ �հ� �ڿ� �ִ� ��ũ���� �ٲ��ָ� �Ǳ� ����.

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
        // itr+5�� ���� �����ǰ��� ���� �Ұ���. 
        // �޸𸮿� ���������� �������� �ʱ� ������..
    }

    cout << "ó�� ����Ʈ ���� " <<endl;
    print_lst(lst);
    for(list<int>::iterator itr = lst.begin(); itr != lst.end();itr++){
        if(*itr == 3) lst.insert(itr,2);
    }
    cout<<"insert �� " <<endl;
    print_lst(lst);

    for(list<int>::iterator itr = lst.begin();itr!=lst.end();itr++){
        if(*itr == 3) {lst.erase(itr); break;}
    }
    cout <<"erase �� "<<endl;
    print_lst(lst);

    return 0;
}
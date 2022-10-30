//Standard Template Library - STL / ǥ�� ���ø� ���̺귯��
// ���� C++ ���ø� ���̺귯��(STL)�� ���´´ٸ� ������ ���� �� ���� ���̺귯������ �ǹ��մϴ�.
// ���� Ÿ���� ��ü�� ������ �� �ִ� �����̳� (container)
// �����̳ʿ� ������ ���ҿ� ������ �� �ִ� �ݺ��� (iterator)
// �ݺ��ڵ��� ������ �Ϸ��� �۾��� �����ϴ� �˰��� (algorithm)

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    for(int i=0;i<vec.size();i++){
        cout << "vec�� "<<i<<"��° ���� :: "<<vec[i]<<endl;
    }

    cout << vec.at(2)<<endl; // Ư����ġ ����
    vec.push_back(4); //�ǵڿ� ����
    vec.pop_back();//�ǵڰ� pop
    vec.insert(vec.begin()+2,4);
    for(int i=0;i<vec.size();i++){
        cout << "vec�� "<<i<<"��° ���� :: "<<vec[i]<<endl;
    }

    cout << "vec begin() ����ϱ� !!! "<<endl;
    for(vector<int>::iterator itr = vec.begin();itr!=vec.end();itr++){
        cout << *itr << endl;

    }
    cout << "������ vec ����ϱ� !!! "<<endl;

    vector<int>::reverse_iterator r_iter = vec.rbegin();
    for(;r_iter!=vec.rend();r_iter++){
        cout << *r_iter << endl;
    }
    cout <<"const iterator ��� !!"<<endl;    
    vector<int>::const_iterator c_iter = vec.cbegin();
    for(;c_iter!=vec.cend();c_iter++){
        cout << *c_iter<<endl;
    }

    cout << "������ ���!!"<<endl;
    for(vector<int>::size_type i = vec.size() -1 ; i!=0; i--){
        cout << vec[i] <<endl;
    }

//size_type�� unsigned�� ����Ǿ��־� -1�� �� �������� ������ ����������.

    cout << "for�� range based for loop "<<endl;
    for(int i:vec){
        cout << i <<endl;
    }
}

//������ push,pop �� o(1)�� �ӵ��� ��������
//Ư����ġ�� �߰� ���Ŵ� o(n)���� �ӵ��� ������.
//https://modoocode.com/256 ���� �پ��� algorithm�Լ��� ����� �ִ�.
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

template <typename T>
void print_vector(vector<T> v){
    for(T i:v){
        cout << i<<" ";
    }
    cout <<endl;
}

template <typename T>
struct int_compare{
    bool operator()(const T &a,const T &b) const{
        return a>b;
    }
};

int main(){
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(8);
    
    cout << "-------------------���� ��-----------------"<<endl;
    print_vector(vec);

    sort(vec.begin(),vec.end());
    cout << "-------------------���� ��-----------------"<<endl;
    print_vector(vec);

    sort(vec.begin(),vec.end(),int_compare<int>());
    cout << "-------------------���� ��-----------------"<<endl;
    print_vector(vec);

    partial_sort(vec.begin(),vec.begin()+3,vec.end());
    cout << "-------------------���� ��-----------------"<<endl;
    print_vector(vec);

// sort : �Ϲ����� ���� �Լ��� �����Ͻø� �˴ϴ�. (list�Ұ���)
// stable_sort : ������ �ϵ� ���ҵ� ���� ������ �����մϴ�.
// �� ���� ���� ���̳ĸ�, ���࿡ ���Ϳ� [a, b] ������ �־��µ�, a �� b �� ũ�Ⱑ ���ٸ� ������ [a,b] Ȥ�� [b,a] �� �� �� �ֽ��ϴ�. sort �� ��� �� ������ �������� �������ϴ�. 
// ������ stable_sort �� ��� �� ������ �ݵ�� �����մϴ�. 
// �� �����̳� �󿡼� [a,b] ������ �־��ٸ� ���� �ÿ��� (ũ�Ⱑ ���ٸ�) [a,b] ������ ������ �˴ϴ�. 
// �� ������ sort ���� �� �� �����ϴ�.

// partial_sort : �迭�� �Ϻκи� �����մϴ� (�Ʒ� �ڼ��� �����ϰڽ��ϴ�)
    

    return 0;
}
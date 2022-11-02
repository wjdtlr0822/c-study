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

// struct is_odd{
//     int *num_delete;

//     is_odd(int *num_delete):num_delete(num_delete){}

//     bool operator()(const int &i) {
//         if(*num_delete >=2) return false;
//         if(i%2==1){
//             *num_delete+=1;
//             return true;
//         }
//         return false;
//         }
// };


int main(){
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(8);
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
    
    // vec.erase(vec.begin()+3); // 3��°�� �ִ� ���� ����
    vec.erase(remove(vec.begin(),vec.end(),8),vec.end()); // 8�̶�� ���� �ڷ� �������� �� ����.
    cout<<"___________________���� �� _____________________"<<endl;
    print_vector(vec);


    cout<<"________________Ȧ���� ���� ���� 2�� ���� �� _____________________"<<endl;
    // int num_delete=0;
    // vec.erase(remove_if(vec.begin(),vec.end(),is_odd(&num_delete)),vec.end());
    //��ó���ϸ� ������ ��� ���������ؼ� ������ �򰥸� �� �ִ�.

///���ٻ��
    int num_delete=0;
    vec.erase(remove_if(vec.begin(),vec.end(),
                        [&num_delete](int i)->bool{ //������ ���� &num_delete��� �����ִ°��� capture list����Ѵ�.
                            if(num_delete>=2){ //���� num_delete��� ������ ������ �������� const�� �־��� �� ������ �Ұ����ϴ�.
                                return false; //���� Ŭ�����ȿ��� ���� ���� this�� ����ؾ��Ѵ�.
                            }
                            if(i%2==1){
                                num_delete+=1;
                                return true;
                                }
                            return false;
                            }), vec.end());
    print_vector(vec);

// [] : �ƹ��͵� ĸ�� ����

// [&a, b] : a �� ���۷����� ĸ���ϰ� b �� (���� �Ұ�����) ���纻���� ĸ��

// [&] : �ܺ��� ��� �������� ���۷����� ĸ��

// [=] : �ܺ��� ��� �������� ���纻���� ĸ��

    cout << "__________��ü ���Ϳ� 1�� ���Ѵ�___________"<<endl;
    transform(vec.begin(),vec.end(),vec.begin(),[](int i){return i+1;});
    vec.push_back(3);
    //���۹ݺ���,�� �ݺ���, ������ �����̳��� ���۹ݺ���, pred
    print_vector(vec);

    cout << "__________��ü ���Ϳ��� 3�� ã�´�___________"<<endl;
    auto current = vec.begin();
    while(true){
        current = find(current,vec.end(),3);
        if(current == vec.end()) break;
        cout << distance(vec.begin(),current)<<" ";
        current++;
    }

    cout << endl<< "__________��ü ���Ϳ� i%3==2�� ã�´�___________"<<endl;

    current = vec.begin();
    while (true)
    {
        current = find_if(current,vec.end(),[](int i){return i%3==2;});
        if(current==vec.end()) break;
        cout << *current<<endl;
        current++;
    }
    // all_of(vec.begin(),vec.end(),[](int i){return i>10;}) ��ü
    // any_of(vec.begin(),vec.end(),[](int i){return i>10;}) �ϳ���
    return 0;
}
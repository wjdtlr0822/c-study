//https://modoocode.com/256 에는 다양한 algorithm함수들 목록이 있다.
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
    
    cout << "-------------------정렬 전-----------------"<<endl;
    print_vector(vec);

    sort(vec.begin(),vec.end());
    cout << "-------------------정렬 후-----------------"<<endl;
    print_vector(vec);

    sort(vec.begin(),vec.end(),int_compare<int>());
    cout << "-------------------정렬 후-----------------"<<endl;
    print_vector(vec);

    partial_sort(vec.begin(),vec.begin()+3,vec.end());
    cout << "-------------------정렬 후-----------------"<<endl;
    print_vector(vec);

// sort : 일반적인 정렬 함수라 생각하시면 됩니다. (list불가능)
// stable_sort : 정렬을 하되 원소들 간의 순서를 보존합니다.
// 이 말이 무슨 말이냐면, 만약에 벡터에 [a, b] 순으로 있었는데, a 와 b 가 크기가 같다면 정렬을 [a,b] 혹은 [b,a] 로 할 수 있습니다. sort 의 경우 그 순서가 랜덤으로 정해집니다. 
// 하지만 stable_sort 의 경우 그 순서를 반드시 보존합니다. 
// 즉 컨테이너 상에서 [a,b] 순으로 있엇다면 정렬 시에도 (크기가 같다면) [a,b] 순으로 나오게 됩니다. 
// 이 때문에 sort 보다 좀 더 느립니다.

// partial_sort : 배열의 일부분만 정렬합니다 (아래 자세히 설명하겠습니다)
    

    return 0;
}
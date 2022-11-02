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
    
    // vec.erase(vec.begin()+3); // 3번째에 있는 값을 제거
    vec.erase(remove(vec.begin(),vec.end(),8),vec.end()); // 8이라는 전부 뒤로 보내버린 후 삭제.
    cout<<"___________________제거 후 _____________________"<<endl;
    print_vector(vec);


    cout<<"________________홀수인 원소 앞의 2개 제거 후 _____________________"<<endl;
    // int num_delete=0;
    // vec.erase(remove_if(vec.begin(),vec.end(),is_odd(&num_delete)),vec.end());
    //위처럼하면 변수를 계속 만들어줘야해서 협업시 헷갈릴 수 있다.

///람다사용
    int num_delete=0;
    vec.erase(remove_if(vec.begin(),vec.end(),
                        [&num_delete](int i)->bool{ //다음과 같이 &num_delete라고 적어주는것을 capture list라고한다.
                            if(num_delete>=2){ //만약 num_delete라고만 적으면 변수를 가져오고 const를 넣어줘 값 변경이 불가능하다.
                                return false; //만약 클래스안에서 람다 사용시 this를 사용해야한다.
                            }
                            if(i%2==1){
                                num_delete+=1;
                                return true;
                                }
                            return false;
                            }), vec.end());
    print_vector(vec);

// [] : 아무것도 캡쳐 안함

// [&a, b] : a 는 레퍼런스로 캡쳐하고 b 는 (변경 불가능한) 복사본으로 캡쳐

// [&] : 외부의 모든 변수들을 레퍼런스로 캡쳐

// [=] : 외부의 모든 변수들을 복사본으로 캡쳐

    cout << "__________전체 백터에 1을 더한다___________"<<endl;
    transform(vec.begin(),vec.end(),vec.begin(),[](int i){return i+1;});
    vec.push_back(3);
    //시작반복자,끝 반복자, 저장할 컨테이너의 시작반복자, pred
    print_vector(vec);

    cout << "__________전체 백터에서 3을 찾는다___________"<<endl;
    auto current = vec.begin();
    while(true){
        current = find(current,vec.end(),3);
        if(current == vec.end()) break;
        cout << distance(vec.begin(),current)<<" ";
        current++;
    }

    cout << endl<< "__________전체 백터에 i%3==2를 찾는다___________"<<endl;

    current = vec.begin();
    while (true)
    {
        current = find_if(current,vec.end(),[](int i){return i%3==2;});
        if(current==vec.end()) break;
        cout << *current<<endl;
        current++;
    }
    // all_of(vec.begin(),vec.end(),[](int i){return i>10;}) 전체
    // any_of(vec.begin(),vec.end(),[](int i){return i>10;}) 하나라도
    return 0;
}
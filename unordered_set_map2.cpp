//unordered_map set에 class넣기
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

template <typename K>
void print_unordered_set(unordered_set<K> &s){
    for(const auto i : s)cout << i;
    cout <<endl;
}


class Todo{
    int priority;
    string job_desc;

    public:
    Todo(int priority,string job_desc):priority(priority),job_desc(job_desc){}

    bool operator==(const Todo &t) const{
        if(priority==t.priority && job_desc == t.job_desc) return true;
        return false;
    }

    friend ostream& operator<<(ostream &o,const Todo &t);
    friend struct hash<Todo>;
};

//using namespace std;를 했음에도 namespace std안에 정의되어 있냐면
// 특정 namespace안에 새로우ㅡㄴ 클래스/함수를 추가하기 위해서는 
//명시적으로 namespace를 써줘야만 하기 때문이다.
namespace std{
    template <>
    struct hash<Todo>{
        size_t operator()(const Todo& t) const{
            hash<string> hash_func; //string을 해시값으로 만들기위해
            //priority는 int값 이므로 그냥 해시값 자체로 쓴다.

            return t.priority ^ (hash_func(t.job_desc)); // 해시값 xor연산
        }
    };
}

ostream& operator<<(ostream &o,const Todo &t){
    o<<"중요도 : "<<t.priority<<" : "<<t.job_desc<<endl;
    return o;
}

int main(){
    unordered_set<Todo> s;

    s.insert(Todo(1,"농구하기"));
    s.insert(Todo(2,"발표준비"));
    s.insert(Todo(3,"소켓 공부하기"));
    s.insert(Todo(3,"mfc 공부하기"));
    s.insert(Todo(2,"눕기"));
    print_unordered_set(s);
    
}
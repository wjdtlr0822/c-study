//클래스 자체에 operator<를 두지 않더라도 셋을 사용하는 방법
//외부 라이브러리를 사용할 때 <연산자가 없을 경우
#include <iostream>
#include <set>
#include <string>

using namespace std;

template <typename T, typename C>
void print_set(set<T,C> &s){
    for(T i : s){
        cout << i <<endl;
    }
}

class Todo{
    int priority;
    string job_desc;

    public:
    Todo(int priority,string job_desc) : priority(priority), job_desc(job_desc){}

    friend struct TodoCmp;
    friend ostream& operator<<(ostream& o,const Todo &t);
};

struct TodoCmp{
    bool operator()(const Todo& t1,const Todo& t2)const{
        if(t1.priority == t2.priority) return t1.job_desc < t2.job_desc;
        return t1.priority > t2.priority;
    }
};

ostream& operator<<(ostream& o,const Todo &t){
    o<<"[중요도 : "<<t.priority <<"] "<<t.job_desc<<endl;
    return o;
}


int main(){
    set<Todo,TodoCmp> todos;
    //셋에서는 기본적으로 키,compare를 받는다.

    todos.insert(Todo(1, "농구 하기"));
    todos.insert(Todo(2, "수학 숙제 하기"));
    todos.insert(Todo(1, "프로그래밍 프로젝트"));
    todos.insert(Todo(3, "친구 만나기"));
    todos.insert(Todo(2, "영화 보기"));

    print_set(todos);

}
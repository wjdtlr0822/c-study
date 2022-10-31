#include <iostream>
#include <set>
#include <string>

using namespace std;

template <typename T>
void print_set(set<T> &s){
    for(T i :s){
        cout << i<<" "<<endl;
    }
}

class Todo{
    int priority;
    string job_desc;

    public:
    Todo(int priority,string job_desc):priority(priority),job_desc(job_desc){}

    bool operator<(const Todo &t) const{
        if (priority == t.priority) return job_desc< t.job_desc;
        return priority>t.priority;
    }
    friend ostream& operator<<(ostream &o,const Todo &t);
};

ostream& operator<<(ostream &o,const Todo &t){
        o<<"[중요도 : "<<t.priority <<"] "<<t.job_desc;
        return o;
    }

int main(){
    set<Todo> todos;

    todos.insert(Todo(1,"놀기"));
    todos.insert(Todo(3,"공부하기"));
    todos.insert(Todo(2,"중빔 얻어먹기"));
    todos.insert(Todo(3,"다이아 프로젝트"));

    print_set(todos);

    cout << "중빔 얻어먹기 끝!!"<<endl<<endl;

    todos.erase(todos.find(Todo(2,"중빔 얻어먹기")));

    print_set(todos);
    



    // set<int> s;
    // s.insert(10);
    // s.insert(30);
    // s.insert(20);
    // s.insert(40);

    // cout << "순서대로 정렬되서 나온다"<<endl;
    // print_set(s);

    // cout << "20이 s의 원소인가요?"<<endl;
    // auto itr = s.find(20);
    // if(itr != s.end()){ cout << "YES "<< *itr <<endl;}
    // else{cout << "NO"<<endl;}

    // cout << "25이 s의 원소인가요?"<<endl;
    // itr = s.find(25);
    // if(itr !=s.end()){ cout << "YES  "<< *itr <<endl;}
    // else{cout << "NO "<< *itr <<endl;}
}

//find를 하는 경우 set은 o(logn) vector는 o(n)
//이것이 가능한 이유는 내부적으로 원소들이 정렬된 상태를 유지하기 때문
//내부적으로 트리 구조로 구성되어 있다.
//왼쪽은 나보다 작고 오른쪽은 나보다 크다와 같은 방식


///셋에는 중복된 원소가 없다.
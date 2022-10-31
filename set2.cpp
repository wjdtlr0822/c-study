//Ŭ���� ��ü�� operator<�� ���� �ʴ��� ���� ����ϴ� ���
//�ܺ� ���̺귯���� ����� �� <�����ڰ� ���� ���
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
    o<<"[�߿䵵 : "<<t.priority <<"] "<<t.job_desc<<endl;
    return o;
}


int main(){
    set<Todo,TodoCmp> todos;
    //�¿����� �⺻������ Ű,compare�� �޴´�.

    todos.insert(Todo(1, "�� �ϱ�"));
    todos.insert(Todo(2, "���� ���� �ϱ�"));
    todos.insert(Todo(1, "���α׷��� ������Ʈ"));
    todos.insert(Todo(3, "ģ�� ������"));
    todos.insert(Todo(2, "��ȭ ����"));

    print_set(todos);

}
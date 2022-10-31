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
        o<<"[�߿䵵 : "<<t.priority <<"] "<<t.job_desc;
        return o;
    }

int main(){
    set<Todo> todos;

    todos.insert(Todo(1,"���"));
    todos.insert(Todo(3,"�����ϱ�"));
    todos.insert(Todo(2,"�ߺ� ���Ա�"));
    todos.insert(Todo(3,"���̾� ������Ʈ"));

    print_set(todos);

    cout << "�ߺ� ���Ա� ��!!"<<endl<<endl;

    todos.erase(todos.find(Todo(2,"�ߺ� ���Ա�")));

    print_set(todos);
    



    // set<int> s;
    // s.insert(10);
    // s.insert(30);
    // s.insert(20);
    // s.insert(40);

    // cout << "������� ���ĵǼ� ���´�"<<endl;
    // print_set(s);

    // cout << "20�� s�� �����ΰ���?"<<endl;
    // auto itr = s.find(20);
    // if(itr != s.end()){ cout << "YES "<< *itr <<endl;}
    // else{cout << "NO"<<endl;}

    // cout << "25�� s�� �����ΰ���?"<<endl;
    // itr = s.find(25);
    // if(itr !=s.end()){ cout << "YES  "<< *itr <<endl;}
    // else{cout << "NO "<< *itr <<endl;}
}

//find�� �ϴ� ��� set�� o(logn) vector�� o(n)
//�̰��� ������ ������ ���������� ���ҵ��� ���ĵ� ���¸� �����ϱ� ����
//���������� Ʈ�� ������ �����Ǿ� �ִ�.
//������ ������ �۰� �������� ������ ũ�ٿ� ���� ���


///�¿��� �ߺ��� ���Ұ� ����.
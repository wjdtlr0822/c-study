//unordered_map set�� class�ֱ�
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

//using namespace std;�� �������� namespace std�ȿ� ���ǵǾ� �ֳĸ�
// Ư�� namespace�ȿ� ���ο�Ѥ� Ŭ����/�Լ��� �߰��ϱ� ���ؼ��� 
//��������� namespace�� ����߸� �ϱ� �����̴�.
namespace std{
    template <>
    struct hash<Todo>{
        size_t operator()(const Todo& t) const{
            hash<string> hash_func; //string�� �ؽð����� ���������
            //priority�� int�� �̹Ƿ� �׳� �ؽð� ��ü�� ����.

            return t.priority ^ (hash_func(t.job_desc)); // �ؽð� xor����
        }
    };
}

ostream& operator<<(ostream &o,const Todo &t){
    o<<"�߿䵵 : "<<t.priority<<" : "<<t.job_desc<<endl;
    return o;
}

int main(){
    unordered_set<Todo> s;

    s.insert(Todo(1,"���ϱ�"));
    s.insert(Todo(2,"��ǥ�غ�"));
    s.insert(Todo(3,"���� �����ϱ�"));
    s.insert(Todo(3,"mfc �����ϱ�"));
    s.insert(Todo(2,"����"));
    print_unordered_set(s);
    
}
//���� ���󼭴� ���� ���� ����Ʈ �����Ͱ� �ϳ��� ��ü�� ���� ���� �ؾ� �ϴ� ��찡 �߻��մϴ�
//Ư�� �ڿ��� �� ���� ��ü���� ����Ű������ ������ ������, �� ���� 0 �� �Ǿ߸� ��μ� ������ �����ִ� ����� �����Ͱ� �ʿ��մϴ�.

#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class A{
    int *data;

    public:
    A(){
        cout << "�޸� �Ҵ�"<<endl;
        data = new int[100];
    }
    ~A(){
        delete[] data;
        cout <<"�޸� ����"<<endl;
    }
};

int main(){
    shared_ptr<A> p1(new A());
    shared_ptr<A> p2(p1);

    cout << p1.use_count()<<endl;
    cout << p2.use_count()<<endl;
    // unique_ptr<A> p3(new A());
    // unique_ptr<A> p4(p3); //error


cout <<endl << "vector test"<<endl;
    vector<shared_ptr<A>> vec;
    vec.push_back(shared_ptr<A>(new A()));
    vec.push_back(shared_ptr<A>(vec[0]));
    vec.push_back(shared_ptr<A>(vec[1]));

    cout << "ù��° �Ҹ�"<<endl;
    vec.erase(vec.begin());
    cout << "2��° �Ҹ�"<<endl;
    vec.erase(vec.begin());
    cout << "3��° �Ҹ�"<<endl;
    vec.erase(vec.begin());
    
}
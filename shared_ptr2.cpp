#include<iostream>
#include<memory>


using namespace std;

class A: public enable_shared_from_this<A>{
    int *data;
    public:
    A(){
        data= new int[100];
        cout <<"������ �Ҵ�"<<endl;
    }
    ~A(){
        delete[] data;
        cout<<"������ ����"<<endl;
    }

    shared_ptr<A> get_shared_ptr(){return shared_from_this();}
    //������ ���� �ϸ� ��ü �ڽ��� ����Ű�� shared_ptr�� ������ִ�.
    //shared_from_this�� �������� �ִ��� Ȯ�θ� �� �� �������� �ʴ´�.
};

int main(){
    A *a = new A();
    // shared_ptr<A> sa(new A()) -> 
    // shared_ptr<A> sa = make_shared<A>(a);
    // shared_ptr<A> sa2 = make_shared<A>(a);
    shared_ptr<A> sa(a); 
    shared_ptr<A> sa2 =sa->get_shared_ptr();
    
    //���ڷ� �ּҰ��� ���޵Ǹ� ��ü�� ù��°�� �����ϴ°�ó�� �ൿ�Ѵ�.
    //�׷��⿡ shared_ptr�� �ּҰ��� ���ؼ� �����ϴ� ���� �����ؾ��Ѵ�.
    cout<<sa.use_count()<<endl;
}
//�޸� ���� �Ǽ� 2����
//1.�޸� ��� �� �������� ���� ���
//2.�޸� ���� �� �����ϴ� ���

// Data *data = new Data();
// Data *data2 = data
// delete data
// .... data2���
// delete data2

// �̷��� �̹� �Ҹ�� ��ü�� �ٽ� �Ҹ���Ѽ� �߻��ϴ� ���׸� double free���׶�� �Ҹ���.


// C++ ������ �̷���, Ư�� ��ü�� ������ �������� �ο��ϴ� ������ ��ü�� unique_ptr ��� �մϴ�.

//RAII����
#include <iostream>
#include <memory>

using namespace std;

class A{
    int *data;

    public:
    A(){
        cout << "�ڿ��Ҵ� 100"<<endl;
        data = new int[100];
    }
    A(const A& a)=delete; //���α׷��Ӱ� ��������� �� �Լ��� �������ϰ� �Ѵ�.
    //Ȥ�ó� ����ϴ��� ������ ������ �߻��Ѵ�.
    void some(){cout <<"�Ϲ� �����Ϳ� �����ϰ� ��� ����"<<endl;}
    ~A(){
        cout <<"�ڿ� ���� 100"<<endl;
        delete[] data;
    }
};

void do_something(){
    unique_ptr<A> pa(new A());
    cout << "pa : ";
    pa->some();
    cout << "�޸� ���� �� pa.get()"<<pa.get()<<endl;
    // unique_ptr<A> pb =pa; // �����߻�
    //unique_ptr�� ������ ���� ������ ��������� ���� �����ڸ� ���Ƴ��� ����.

    unique_ptr<A> pb = move(pa);
    cout << "�޸� ���� �� pa.get()"<<pa.get()<<endl;
    cout << "pb : ";
    pb->some();
    //������ ���� ������ ������ ����.
    //��ü�� �������� ���� �ǰ�, pa�� �ƹ��͵� �Ƹ�Ű�� ���� �ʾ� ����.
}

int main(){
    do_something();
}

//pa�� ���ÿ� ���ǵ� ��ü�̱� ������ do_something �Լ��� ����� �� �ڵ����� �Ҹ��ڰ� ȣ��ȴ�.


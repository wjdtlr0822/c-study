//deque�� ���Ϳ� ����ϰ� ������ ��ġ�� ���ҿ� o(1)�� �ӵ��� ����/�߰�/���� ����
// ���Ҹ� �߰�/�����ϴ� �۾������� o(1)���� ���� ����
//���Ϳʹ� �ٸ��� �� �տ� ���Ҹ� �߰�/�����ϴ� �۾������� o(1)�� ���డ��
// ������ ��ġ�� �ִ� ���Ҹ� ����/�߰� �ϴ� �۾��� ���Ϳ� ���������� o(n)
//��ġ�� ���ͺ��� ���� �� ������.

//���Ϳ��� ���� : 
// ���ʹ� ���ӵ� �޸𸮿� ����
// deque�� �޸� �󿡼� ���������� ���� x
//�� ������ ���ҵ��� ������ �����ϱ� ���� �߰����� �޸𸮰� �� �ʿ��ϴ�.
//�� deque�� �ӵ��� ���� �޸𸮸� �����Ѵ�!!!

#include <iostream>
#include <deque>

using namespace std;

template <typename T>
void print_deque(deque<T> &dep){
    cout << "[ ";
    for(T i : dep){
        cout << i<<" ";
    }
    cout <<" ]"<<endl;
}

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    cout << "�ʱ� dq���� "<<endl;
    print_deque(dq);
    cout << " �� ���� �������� "<<endl;
    dq.pop_front();
    print_deque(dq);
}
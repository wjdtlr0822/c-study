//deque는 벡터와 비슷하게 임의의 위치의 원소에 o(1)의 속도로 접근/추가/제거 가능
// 원소를 추가/제거하는 작업까지도 o(1)으로 수행 가능
//벡터와는 다르게 맨 앞에 원소를 추가/제거하는 작업까지도 o(1)로 수행가능
// 임의의 위치에 있는 원소를 제거/추가 하는 작업은 벡터와 마찬가지로 o(n)
//그치만 벡터보다 조금 더 빠르다.

//벡터와의 차이 : 
// 벡터는 연속된 메모리에 저장
// deque는 메모리 상에서 연속적으로 존재 x
//이 때문에 원소들의 정보를 보관하기 위해 추가적인 메모리가 더 필요하다.
//즉 deque는 속도를 위해 메모리를 포기한다!!!

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
    cout << "초기 dq상태 "<<endl;
    print_deque(dq);
    cout << " 맨 앞의 원소제거 "<<endl;
    dq.pop_front();
    print_deque(dq);
}
#include<atomic>
#include<iostream>
#include<thread>
#include<vector>

using namespace std;

void producer(atomic<bool> *is_ready,int *data){
    *data=10;
    is_ready->store(true,memory_order_release);
}


void consumer(atomic<bool> *is_ready,int *data){
    while(!is_ready->load(memory_order_acquire)){}
    cout << "DATA : "<<*data<<endl;
}
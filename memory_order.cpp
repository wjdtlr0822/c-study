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

int main(){
    vector<thread> vec;

    atomic<bool> is_ready(false);
    int data=0;
    vec.push_back(thread(producer,&is_ready,&data));
    vec.push_back(thread(consumer,&is_ready,&data));
    for (int i = 0; i < 2; i++) {
        vec[i].join();
    }

}
#include<iostream>
#include<memory>

using namespace std;

int main(){
    shared_ptr<int> sp = make_shared<int>();
    auto up = make_unique<int>();
}
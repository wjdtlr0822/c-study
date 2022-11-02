#include <iostream>

using namespace std;

template <typename T>
class Vector{
    public:
    Vector(size_t size) : size_(size){
        data_ = new T[size];
        for(int i=0;i<size_;i++) data_[i]=3;
    }

    T &at(size_t index) const{
        if(index>=size_){
            throw out_of_range("vector의 index가 범위를 초과하였습니다.");
        }
        return data_[index];
    }

    ~Vector() { delete[] data_;}

    private:
    T* data_;
    size_t size_;
};


int main(){
    Vector<int> vec(10);
    int data=0;
    try{
        data=vec.at(11);
    }catch(out_of_range& e){
        cout <<"예외 발생 : " <<e.what() <<endl;
        vec.~Vector();
    }
    cout << "읽은 데이터 : "<<data <<endl;
    //catch에 소멸자를 꼭 넣어줘야한다.

}
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
            throw out_of_range("vector�� index�� ������ �ʰ��Ͽ����ϴ�.");
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
        cout <<"���� �߻� : " <<e.what() <<endl;
        vec.~Vector();
    }
    cout << "���� ������ : "<<data <<endl;
    //catch�� �Ҹ��ڸ� �� �־�����Ѵ�.

}
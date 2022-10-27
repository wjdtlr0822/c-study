#include <iostream>
#include <string>

using namespace std;
template <typename T>
class Vector{
    T *data;
    int capacity;
    int length;

    public:
    Vector(int n=1) : data(new T[n]),capacity(n),length(0){}
    void push_back(T s){
        if(capacity<=length){
            T *temp = new T[capacity*2];
            for(int i=0;i<length;i++) temp[i] = data[i];
            delete[] data;
            data=temp;
            capacity*=2;
        }
        data[length] = s;
        length++;
    }

    T operator[](int i){return data[i];}

    void remove(int x){
        for(int i=x+1;i<length;i++) data[i-1]=data[i];
        length--;
    }
    int size() { return length;}
    ~Vector(){
        if(data) delete[] data;
    }
};


int main(){
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);
    for(int i=0;i<int_vec.size();i++){
        cout << int_vec[i]<<endl;
    }

    Vector<string> string_vec;
    string_vec.push_back("abc");
    string_vec.push_back("qwe");
    for(int i = 0;i<string_vec.size();i++){
        cout << string_vec[i]<<endl;
    }
    
}

//template <typename T>
//아래에 정의되는 클래스에 대해 템플릿을 정의하고, 템플릿 인자로 T를 받게 되며
//T 는 반드시 어떠한 타입의 이름임을 명시하고 있습니다.
//template <class T>라고 쓰는 경우도 있는데 위와 동일하다.
//class T라고 해서 T자리에 꼭 클래스가 와야하는 건 아니다. int,char 등도 가능
//하지만 class T보다는 typename T를 쓰는걸 권장한다.

//클래스 템플릿에 인자를 전달해서 실제 코드를 생성하는 것을 클래스 템플릿 인스턴스화 (class template instantiation)

//
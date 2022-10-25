#include <iostream>
#include <vector>

using namespace std;

class Int {
int data;
  // some other data

    public:
    Int(int data) : data(data) {}
    Int(const Int& i) : data(i.data) {}

    operator int() { return data; }

    Int& operator++(){
        data++;
        cout << "++Int" <<endl;
        return *this;
    }

  // 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를
  // 받지만 실제로는 아무것도 전달되지 않는다.
    Int operator++(int){
        Int a(*this);
        data++;
        cout << "Int++"<<endl;
        return a;
    }
};

ostream& operator<<(ostream& os, const vector<int> vec){
    for(int i=0;i<vec.size();i++){
        os<<vec[i]<<endl;
    }
    return os;
}


int main(){
    vector<int> a={1,2,3,4,5};
    cout << a << "test end"<<endl;

    Int x=10;
    int b= x + 10;
    cout << b<< endl;

    cout << ++x << endl;
    cout << x++<<endl;
    cout << x <<endl;
}
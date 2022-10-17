#include <iostream>

using namespace std;

int main(){

    int ar[10]={1,3,5,4,5,6,7,8,9,10};
    int *p;
    p=ar;
    //ar은 배열의 첫번째 주소를 가르킨다.
    //*p는 값을 나타내고 p는 주소를 가르치고 있고 &p는 포인터의 주소를 가지고있다.
    //int *p=ar;과 같이 선언을 할 때는 p=ar과 같은 의미이다.
    //int *p; p=ar; 이런식으로 선언 하는것과 같다.
    cout << *p<<endl;
}
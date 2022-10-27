#include <iostream>

using namespace std;

template <typename T>
void print(T arg){
    cout << arg << endl;
}

template <typename T, typename... Types>
void print(T arg,Types... args){
    cout << arg <<", ";
    print(args...);
}

int main(){
    print(1,2,3);
}

//typename... 을 템플릿 파라미터 팩이라고 부른다.
//템플릿 파라미터 팩의 경우 0개 이상의 템플릿 인자들을 나타낸다.
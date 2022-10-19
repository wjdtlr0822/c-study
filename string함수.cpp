#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string a="abcde";
    string b="abcde";
    
    a.length(); //길이 찾는 함수
    a.assign("abc"); /// 대입 함수
    a.capacity(); //할당된 크기 알아오는 함수
    a.at(3); //3번째에 있는 문자열 리턴함수
    a.insert(3,"hello"); // 3번째에 hello 삽입함수
    a.compare(b); //사전순 비교 함수  a가 앞이면 -1 b가 앞이면 1 같으면 0 리턴
    a.find("hello",0); // 0번째부터 hello를 찾아서 값 리턴
    a.erase(3,1); // 3번째부터 1개 지운다는 의미
    

}

//Standard Template Library - STL / 표준 템플릿 라이브러리
// 보통 C++ 템플릿 라이브러리(STL)를 일컫는다면 다음과 같은 세 개의 라이브러리들을 의미합니다.
// 임의 타입의 객체를 보관할 수 있는 컨테이너 (container)
// 컨테이너에 보관된 원소에 접근할 수 있는 반복자 (iterator)
// 반복자들을 가지고 일련의 작업을 수행하는 알고리즘 (algorithm)

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    for(int i=0;i<vec.size();i++){
        cout << "vec의 "<<i<<"번째 원소 :: "<<vec[i]<<endl;
    }

    cout << vec.at(2)<<endl; // 특정위치 접근
    vec.push_back(4); //맨뒤에 삽입
    vec.pop_back();//맨뒤값 pop
    vec.insert(vec.begin()+2,4);
    for(int i=0;i<vec.size();i++){
        cout << "vec의 "<<i<<"번째 원소 :: "<<vec[i]<<endl;
    }

    cout << "vec begin() 출력하기 !!! "<<endl;
    for(vector<int>::iterator itr = vec.begin();itr!=vec.end();itr++){
        cout << *itr << endl;

    }
    cout << "역으로 vec 출력하기 !!! "<<endl;

    vector<int>::reverse_iterator r_iter = vec.rbegin();
    for(;r_iter!=vec.rend();r_iter++){
        cout << *r_iter << endl;
    }
    cout <<"const iterator 출력 !!"<<endl;    
    vector<int>::const_iterator c_iter = vec.cbegin();
    for(;c_iter!=vec.cend();c_iter++){
        cout << *c_iter<<endl;
    }

    cout << "역으로 출력!!"<<endl;
    for(vector<int>::size_type i = vec.size() -1 ; i!=0; i--){
        cout << vec[i] <<endl;
    }

//size_type은 unsigned로 선언되어있어 -1을 갈 수가없기 때문에 오류가난다.

    cout << "for문 range based for loop "<<endl;
    for(int i:vec){
        cout << i <<endl;
    }
}

//벡터의 push,pop 은 o(1)의 속도로 빠르지만
//특정위치의 추가 제거는 o(n)으로 속도가 느리다.
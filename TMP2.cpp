#include <iostream>


using namespace std;

// int gcd(int a,int b){
//     if(b==0) return a;
//     return gcd(b,a%b);
// }

template <int x,int y>
struct gcd
{
    static const int value = gcd<y,x%y>::value;
};

template <int x>
struct gcd<x,0>
{
    static const int value = x;
};

template <int N,int D=1>
struct Ratio{
    typedef Ratio<N,D> type;
    static const int num = N;
    static const int den = D;
};

template <class R1, class R2>
struct _Ratio_add{
    typedef Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
};

template <class R1,class R2>
struct Ratio_add : _Ratio_add<R1,R2>::type{};

int main(){
    // typedef Ratio<2,3> rat;
    // typedef Ratio<3,2> rat2;
    using rat = Ratio<2,3>;
    using rat2 = Ratio<3,2>;
    typedef Ratio_add<rat,rat2> rat3;
    using rat4 = Ratio_add<rat,rat2>;
    cout << rat3::num << ", " <<rat3::den<<endl;
    cout << rat4::num <<", " <<rat4::den<<endl;
}
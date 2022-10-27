#include <iostream>

using namespace std;

template <typename... Ints>
int sum_all(Ints... nums){
    return(... + nums); ///()로 감싸는거 필수
}

template <typename Int, typename... Ints>
Int diff_form(Int start,Ints... nums){
    return (start-...-nums);
}

class A{
    public:
    void do_something(int x) const{
        cout << "Do something with" << x <<endl;
    }
};

template <typename T,typename... Ints>
void do_many_things(T &t,Ints... nums){
    (t.do_something(nums),...);
}

int main(){
    cout << sum_all(1,2,3,4,5,6) << endl;
    cout << diff_form(100,1,2,3)<<endl;
    A a;
    do_many_things(a,1,2,3,4,5);
    return 0;
}
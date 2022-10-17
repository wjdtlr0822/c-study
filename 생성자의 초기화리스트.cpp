#include <iostream>

using namespace std;


class Marine{
    int hp;
    int coord_x,coord_y;
    int damage;
    bool is_dead;

    public:
    Marine();
    Marine(int x, int y);

    int attack();
};


Marine::Marine() : hp(50), coord_x(0),coord_y(0),damage(5),is_dead(false){}

Marine::Marine(int x,int y) : coord_x(x),coord_y(y),hp(50),damage(5),is_dead(false){}


int main(){
    return 0;
}

// Marine::Marine() : hp(50), coord_x(0),coord_y(0),damage(5),is_dead(false){}
// Marine::Marine(){
//     hp=50;
//     coord_x=coord_y=0;
//     damage=5;
//     is_dead=false;
// } 
//두가지의 차이점은 생성자의 초기화리스트는 int a=10;
// 아래 생성자는 int a; a=10; 과 같은 식으로 처리가 된다.
// 상수와 레퍼런스들은 생성과 동시에 초기화가 되어있어야 하므로 첫번째 방식에서만 작동한다.
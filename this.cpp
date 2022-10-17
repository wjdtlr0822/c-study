#include <iostream>

using namespace std;

class Marine{
    static int total_marine_num;
    int hp;
    int coord_x,coord_y;
    const int damage;
    bool is_dead;

    public:
    Marine();
    Marine(int x,int y);
    Marine(int x,int y,int damage);

    int attack();
    Marine& be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
    static void show_total_marine();
    ~Marine();
};

int Marine::total_marine_num=0;

Marine::Marine() 
: hp(50),coord_x(0),coord_y(0),damage(5),is_dead(false){
    total_marine_num++;
    }

Marine::Marine(int x, int y)
: hp(50),coord_x(x),coord_y(y),damage(5),is_dead(false){
    total_marine_num++;
    }

Marine::Marine(int x, int y,int damage)
: hp(50),coord_x(x),coord_y(y),damage(damage),is_dead(false){
    total_marine_num++;
    }

int Marine::attack(){
    return damage;
}

Marine& Marine::be_attacked(int damage_earn){ //레퍼런스(참조자) 리턴
    hp-=damage_earn;
    if(hp<=0) is_dead=true;
    
    // this->hp-=damage_earn;
    // if(this->hp<=0) this->is_dead=true;
    //와 같은 의미

    return *this; //객체 자신을 가리키는 포인터의 역할을 한다.
}

void Marine::move(int x,int y){
    coord_x=x;
    coord_y=y;
}

void Marine::show_status(){
    cout << "hp : " <<hp<<endl;
    cout << "coord x : "<<coord_x << " coord_y : "<<coord_y<<endl;
    cout << "damage : " << damage <<endl;
    cout << "is_dead : "<< is_dead<<endl;
    show_total_marine();
}

void Marine::show_total_marine(){
    cout << "totla marine : "<<total_marine_num << endl;
}

Marine::~Marine(){
    cout << "delete marine "<< coord_x<<" : "<<coord_y<<endl;
    total_marine_num--;
    cout << "totla marine del : "<< total_marine_num << endl;
}

void createMarine(){
    Marine marine3(3,4);
    Marine::show_total_marine();
}

int main(){
Marine marine1(2, 3, 5);
marine1.show_status();

Marine marine2(3, 5, 10);
marine2.show_status();

cout << endl << "마린 1 이 마린 2 를 두 번 공격! " << endl;
marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
/// 리턴타입이 객체 자체여서 .be_attacked를 두번해도 가능한거!!

marine1.show_status();
marine2.show_status();


    return 0;
}
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
    void be_attacked(int damage_earn);
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

void Marine::be_attacked(int damage_earn){
    hp-=damage_earn;
    if(hp<=0) is_dead=true;
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
    Marine marine1(1,1);
    Marine::show_total_marine();

    Marine marine2(2,2);
    Marine::show_total_marine();

    createMarine();


    return 0;
}
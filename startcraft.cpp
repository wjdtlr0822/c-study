#include <iostream>
#include <string.h>

using namespace std;

class Marine{
    char* name;
    int hp;
    int coord_x,coord_y;
    int damage;
    bool is_dead;

    public:
    Marine();
    Marine(int x, int y,const char* marine_name);
    Marine(const Marine *Marine);

    ~Marine();
    int attack();
    void be_attacked(int damage_earn);
    void move(int x,int y);

    void show_status();
};

Marine::Marine(){
    hp=50;
    coord_x=coord_y=0;
    damage=5;
    is_dead=false;
}

Marine::Marine(int x, int y,const char* marine_name){
    name = new char[strlen(marine_name)+1];
    strcpy(name,marine_name);

    coord_x=x;
    coord_y=y;
    hp=50;
    damage=5;
    is_dead=false;
}

Marine::Marine(const Marine *Marine){
    cout << "copy marine"<<endl;
    name = new char[strlen(Marine->name)+1];
    strcpy(name,Marine->name);
    hp=Marine->hp;
    coord_x=Marine->coord_x;
    coord_y=Marine->coord_y;
    damage=Marine->damage;
    is_dead=Marine->is_dead;
}


void Marine::move(int x, int y){
    coord_x=x;
    coord_y=y;
}

int Marine::attack(){return damage;}
void Marine::be_attacked(int damage_earn){
    hp-=damage_earn;
    if(hp<=0) is_dead=true;
}

void Marine::show_status(){
    cout<<"*** "<<name<<" ***"<<endl;
    cout << "Location : ("<<coord_x<<" , "<<coord_y<<")"<<endl;
    cout << "HP : "<<hp<<endl;
}

Marine::~Marine(){
    cout << name << " delete "<<endl;
    if(name!=NULL) delete[] name;
}

int main(){
    /////////////////////////////////////////////////////
    Marine *marine[100];

    Marine a(1,2,"a");
    Marine b(a);
    b.show_status();
    a.show_status();
    marine[0] = new Marine(2,3,"Kim");
    marine[1] = new Marine(3,5,"Park");
    marine[2] = new Marine(marine[1]);
    marine[3] = new Marine(a);

    marine[0]->show_status();
    marine[1]->show_status();
    marine[2]->show_status();
    marine[3]->show_status();

    cout << "marine[0] : "<<marine[0]<<endl;
    cout << "a : "<<&a<<endl;

    cout << endl <<"marine1 is attack marine2"<<endl;

    // marine[0]->be_attacked(marine[1]->attack());

    // marine[0]->show_status();
    // marine[1]->show_status();

    // delete marine[0];
    // delete marine[1];

    /////////////////////////////////////////////////////
    // Marine marine1(2,3);
    // Marine marine2(3,5);

    // marine1.show_status();
    // marine2.show_status();

    // cout<<endl<<"marine1 is attack marine2"<<endl;
    // marine2.be_attacked(marine1.attack());

    // marine1.show_status();
    // marine2.show_status();
}
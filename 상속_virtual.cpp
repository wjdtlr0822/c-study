#include <iostream>
#include <string>


using namespace std;


class Employee{
    protected:
    string name;
    int age;
    string position;
    int rank;

    public:
    Employee(string name,int age,string position,int rank)
        :name(name),age(age),position(position),rank(rank){}

    Employee(const Employee& employee){
        name = employee.name;
        age = employee.age;
        position = employee.position;
        rank = employee.rank;
    }
    Employee(){}

    virtual void print_info(){
        cout << name << " ("<<position<<" , "<<age<<") ==>"<< calculate_pay()<<"����"<<endl;
    }

    virtual int calculate_pay(){return 200+rank*50;}
};

class Manager : public Employee{
    int year_of_service;

    public:
    Manager(string name,int age,string position,int rank,int year_of_service)
        :year_of_service(year_of_service),Employee(name,age,position,rank){}
    Manager(const Manager& manager){
        name = manager.name;
        age = manager.age;
        position = manager.position;
        rank = manager.rank;
        year_of_service = manager.year_of_service;
    }
    Manager() : Employee(){}

    void print_info() override{
    cout << name << " ("<<position<<" , "<<age<<", "<< year_of_service<<"����) ==>"<< calculate_pay()<<"����"<<endl;
    }

    int calculate_pay() override{return 200+rank*50 + 5*year_of_service;}
};

class EmployeeList{
    int alloc_employee;
    int current_employee;

    Employee **employee_list;

    public:
    EmployeeList(int alloc_employee):alloc_employee(alloc_employee){
        employee_list = new Employee*[alloc_employee];
        current_employee=0;
    }
    
    void chage_alloc(int alloc){
        Employee **employee_list_tmp = new Employee*[alloc_employee];
        for(int i=0;i<current_employee;i++){
            employee_list_tmp[i]=employee_list[i];
        }
        
        delete[] employee_list;

        employee_list = new Employee*[alloc];
        for(int i=0;i<current_employee;i++){
            employee_list[i]=employee_list_tmp[i];
        }

        delete[] employee_list_tmp;
        alloc_employee = alloc;

    }

    void add_employee(Employee* Employee){
        employee_list[current_employee]=Employee;
        current_employee++;
        
        if(current_employee>alloc_employee){
            chage_alloc(alloc_employee*2);
        }

    }

    void print_employee_info(){
        int total_pay = 0;
        for(int i=0;i<current_employee;i++){
            employee_list[i]->print_info();
            total_pay+=employee_list[i]->calculate_pay();
        }
        cout << "�� ��� " << total_pay <<"���� "<<endl;
    }

    void alloc(){cout << "alloc_employee : "<< alloc_employee<<" �Դϴ�"<<endl;}

    ~EmployeeList(){
        for(int i=0;i<current_employee;i++){
            delete employee_list[i];
        }
        delete[] employee_list;
    }
};



int main(){
    EmployeeList emp_list(5);
    emp_list.add_employee(new Manager("������",27,"�̻�",20,30));
    emp_list.add_employee(new Employee("����",34,"���",5));
    emp_list.add_employee(new Employee("ȫö",34,"�븮",5));
    emp_list.add_employee(new Manager("����",41,"����",8,13));
    emp_list.add_employee(new Manager("���",45,"����",9,16));
    emp_list.print_employee_info();
    emp_list.alloc();
    emp_list.add_employee(new Employee("����",39,"�븮",5));
    emp_list.add_employee(new Employee("����2",39,"�븮",5));
    emp_list.print_employee_info();
    emp_list.alloc();
    return 0;
}
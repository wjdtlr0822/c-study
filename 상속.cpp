#include <iostream>
#include <string>

using namespace std;


class Employee{
    protected:
    string name;
    int age;
    string position;//��å
    int rank; //����



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

    void print_info(){
        cout << name << " (" <<position<<" , "<<age<<") ==>" <<calculate_pay()<<"����"<<endl;
    }

    int calculate_pay(){return 200+rank*50;}
};

class Manager : public Employee{
    int year_of_service;

    public:
    Manager(string name,int age,string position,int rank,int year_of_service)
        :year_of_service(year_of_service),Employee(name,age,position,rank){}

    Manager(const Manager& manager)
        :Employee(manager.name, manager.age, manager.position, manager.rank){
            year_of_service=manager.year_of_service;
        }

    Manager():Employee(){}


    int calculate_pay(){return 200+rank*50+5*year_of_service;}
    void print_info(){
            cout << name << " (" <<position<<" , "<<age<<", "<< year_of_service <<"���� ) ==>" <<calculate_pay()<<"����"<<endl;
    }

};


class EmployeeList{

    int alloc_employee; //�Ҵ��� �� ������

    int current_employee; //���� ���� ��
    int current_manager;

    Employee **employee_list; //���� ������
    Manager **manager_list; //�Ŵ��� ������
    // employee_list �� Employee** Ÿ������ �Ǿ� �ִ� ������, �츮�� �̸� Employee* ��ü�� ��� �迭�� ����� ���̱� �����Դϴ�.
    
    public:
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee){
        employee_list = new Employee*[alloc_employee];
        manager_list = new Manager*[alloc_employee];
        current_employee=0;
        current_manager=0;
    }

    EmployeeList(int alloc_employee,int current_employee,int current_manager) : alloc_employee(alloc_employee){
        employee_list = new Employee*[alloc_employee];
        current_employee=current_employee;
        current_manager=current_manager;
    }

    void add_employee(Employee* employee){
   // ��� current_employee ���� alloc_employee �� ��
  // �������� ��� �ݵ�� ���Ҵ��� �ؾ� ������, ���⼭��
  // �ִ��� �ܼ��ϰ� �����ؼ� alloc_employee ��
  // ������ current_employee ���� ũ�ٰ� �����Ѵ�.
  // (�� �Ҵ�� ũ��� ���� �� ������ ���� ����)
        if(current_employee+current_manager >= alloc_employee){
            EmployeeList(alloc_employee*2,current_employee,current_manager);
        }
        employee_list[current_employee]=employee;
        current_employee++;
    }

    void add_manager(Manager *manager){
        if(current_employee+current_manager >= alloc_employee){
            EmployeeList(alloc_employee*2,current_employee,current_manager);
        }
        manager_list[current_manager]=manager;
        current_manager++;
    }

    int current_employee_num(){return current_employee;}
    int current_manager_num(){return current_manager;}

    void print_add_employee_info(){
        int total_pay = 0;
        for(int i=0;i<current_employee;i++){
            employee_list[i]->print_info();
            total_pay+=employee_list[i]->calculate_pay();
        }
        for(int i=0;i<current_manager;i++){
            manager_list[i]->print_info();
            total_pay+=manager_list[i]->calculate_pay();
        }
        cout << "�� ��� : "<<total_pay <<"����"<<endl;
    }

    ~EmployeeList(){
        for(int i=0;i<current_employee;i++){
            delete employee_list[i];
        }
        for(int i=0;i<current_manager;i++){
            delete manager_list[i];
        }
        delete[] employee_list;
        delete[] manager_list;
    }
};


int main(){
    EmployeeList emp_list(10);
    emp_list.add_manager(new Manager("������",27,"�̻�",20,30));
    emp_list.add_employee(new Employee("����",34,"���",5));
    emp_list.add_employee(new Employee("ȫö",34,"�븮",5));
    emp_list.add_manager(new Manager("����",41,"����",8,13));
    emp_list.add_manager(new Manager("���",45,"����",9,16));
    emp_list.print_add_employee_info();
}


///private�� �ش� Ŭ���������� ���ٰ���
///protected�� �ڽ� Ŭ�������� ���� ����
///public�� ��� ���ٰ���
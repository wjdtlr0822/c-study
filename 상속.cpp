#include <iostream>
#include <string>

using namespace std;


class Employee{
    protected:
    string name;
    int age;
    string position;//직책
    int rank; //순위



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
        cout << name << " (" <<position<<" , "<<age<<") ==>" <<calculate_pay()<<"만원"<<endl;
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
            cout << name << " (" <<position<<" , "<<age<<", "<< year_of_service <<"년차 ) ==>" <<calculate_pay()<<"만원"<<endl;
    }

};


class EmployeeList{

    int alloc_employee; //할당한 총 직원수

    int current_employee; //현재 직원 수
    int current_manager;

    Employee **employee_list; //직원 데이터
    Manager **manager_list; //매니저 데이터
    // employee_list 가 Employee** 타입으로 되어 있는 이유는, 우리가 이를 Employee* 객체를 담는 배열로 사용할 것이기 때문입니다.
    
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
   // 사실 current_employee 보다 alloc_employee 가 더
  // 많아지는 경우 반드시 재할당을 해야 하지만, 여기서는
  // 최대한 단순하게 생각해서 alloc_employee 는
  // 언제나 current_employee 보다 크다고 생각한다.
  // (즉 할당된 크기는 현재 총 직원수 보다 많음)
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
        cout << "총 비용 : "<<total_pay <<"만원"<<endl;
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
    emp_list.add_manager(new Manager("김정식",27,"이사",20,30));
    emp_list.add_employee(new Employee("하하",34,"사원",5));
    emp_list.add_employee(new Employee("홍철",34,"대리",5));
    emp_list.add_manager(new Manager("준하",41,"부장",8,13));
    emp_list.add_manager(new Manager("명수",45,"차장",9,16));
    emp_list.print_add_employee_info();
}


///private는 해당 클래스에서만 접근가능
///protected는 자식 클래스까지 접근 가능
///public은 모두 접근가능
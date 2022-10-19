#include <iostream>
#include <string.h>

using namespace std;

class MyString{
    char *string_content; // 문자열 데이터를 가리키는 포인터
    int string_length;   //문자열 길이
    int memory_capacity; //현재 할당된 용량

    public:
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();

    int length() const; //const함수는 읽기만 하는 함수
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;
    char at(int i) const;
    
    MyString& insert(int loc,const MyString& str);
    MyString& insert(int loc,const char* str);
    MyString& insert(int loc,char c);
    MyString& assign(const MyString& str);
    MyString& assign(const char* str);
};

MyString::MyString(char c){
    string_content = new char[1];
    string_content[0]=c;
    memory_capacity=1;
    string_length=1;
}

MyString::MyString(const char* str){
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for(int i=0;i<string_length;i++){
        string_content[i]=str[i];
    }
}

MyString::MyString(const MyString& str){
    string_length=str.length();
    memory_capacity = str.length();
    string_content= new char[memory_capacity];
    for(int i=0;i<string_length;i++){
        string_content[i]=str.string_content[i];
    }
}

MyString::~MyString(){
    delete[] string_content;
    cout << "delete success"<<endl;
}

int MyString::length() const{
    return string_length;
}

int MyString::capacity() const{
    return memory_capacity;
}

void MyString::reserve(int size){
    if(memory_capacity<size){
        char* pre=string_content;
        string_content = new char[size];
        for(int i=0;i<size;i++) string_content[i]=pre[i];
        delete[] pre;
        memory_capacity=size;
    }
}

void MyString::print() const{
    for(int i=0;i<string_length;i++){
        cout << string_content[i];
    }
}

void MyString::println() const{
    for(int i=0;i<string_length;i++){
        cout << string_content[i];
    }
    cout << endl;
}

MyString& MyString::assign(const MyString& str){
    if(str.length()>string_length){
        delete[] string_content;
        memory_capacity = str.length();
        string_content = new char[memory_capacity];
    }
    for(int i=0;i<string_length;i++) string_content[i]=str.string_content[i];
    string_length = str.length();

    return *this;
}

MyString& MyString::assign(const char* str){
    int str_length = strlen(str);
    if(str_length>memory_capacity){
        delete[] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for(int i=0;i<str_length;i++) string_content[i]=str[i];
    string_length = str_length;

    return *this;
}

char MyString::at(int i) const{
    if(i>=string_length || i<0) 
        return NULL;
    else 
        return string_content[i];
}


MyString& MyString::insert(int loc,const MyString& str){
    if(loc <0 || loc >string_length) return *this;

    if(string_length + str.string_length > memory_capacity){

        if(memory_capacity*2 >string_length + str.string_length) memory_capacity*=2;
        else memory_capacity=string_length+str.string_length;

        ///잦은 메모리 할당과 해제를 반복하지 않기 위해 애초에 적당한 크기의 메모리를 준다.


        char *pre = string_content;
        string_content = new char[memory_capacity];

        int i;
        for (i=0;i<loc;i++) 
            string_content[i]=pre[i];

        for (int j=0;j!=str.string_length;j++) 
            string_content[i+j]=str.string_content[j];

        for(;i<string_length;i++)
            string_content[str.string_length+i]=pre[i];

        delete[] pre;

        string_length = string_length+str.string_length;
        return *this;
    }

    //초과하지 않을 경우
    for(int i=string_length-1;i>=loc;i--){
        string_content[i+str.string_length]=string_content[i];
    }
    for(int i=0;i<str.string_length;i++)
        string_content[i + loc] = str.string_content[i];

    string_length = string_length + str.string_length;
    return *this;
}

MyString& MyString::insert(int loc,const char* str){
    MyString temp(str);
    return insert(loc,temp);
}
MyString& MyString::insert(int loc,char c){
    MyString temp(c);
    return insert(loc,temp);
}

int main(){
    MyString str1("very very very long string");
    str1.reserve(30);

    cout <<"Capacity : "<<str1.capacity()<<endl;
    cout << "String length : "<<str1.length()<<endl;
    str1.println();

    cout << "3 string : "<<str1.at(3)<<endl;
    return 0;
}
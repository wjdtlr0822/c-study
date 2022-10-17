#include <iostream>
#include <string.h>

using namespace std;

class MyString{
    char* string_content;
    int string_len;

    public:
    MyString(char a);
    //문자열로 부터 생성
    MyString(const char* str);
    //문자열 복사
    MyString(const MyString& str);
    ~MyString(){delete[] string_content;}

    int length() const{return string_len;}
    char* content() const{return string_content;}
    void print();
    void pluscon(const MyString& mystring);

};

MyString::MyString(char a){
    string_content = new char[1];
    string_content[0]=a;
    string_len=1;
}

MyString::MyString(const char* str){
    string_len = strlen(str);
    string_content = new char[string_len+1];
    for(int i=0;i<string_len;i++) string_content[i]=str[i];
}

MyString::MyString(const MyString& str){
    string_len = str.string_len;
    string_content = new char[string_len+1];
    strcpy(string_content,str.string_content);
}

void MyString::print(){
    for(int i=0;i<string_len+1;i++) cout << string_content[i];
    cout <<endl;
}

void MyString::pluscon(const MyString& string){
    char* tmp = new char[string_len];
    strcpy(tmp,string_content);
    string_len+=string.length();
    delete[] string_content;
    string_content = new char[string_len];

    strcpy(string_content,tmp);
    strcat(string_content,string.content());

}


int main(){
    char* name = new char[10];
    strcpy(name,"qwertasdf");
    MyString test1(name);
    test1.print();


    char* nameq = new char[10];
    strcpy(nameq,"qqqqqqqqqqqqqqq");
    MyString test2(nameq);
    test2.pluscon(test1);
    test2.print();
}
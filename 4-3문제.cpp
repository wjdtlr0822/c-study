#include <iostream>
#include <string.h>


using namespace std;


class String{
    char *str;
    int len;

    public:
    String(char c,int n); //문자 c가 n개 있는 문자열로 정의
    String(const char *s);
    String(const String &s);
    ~String();

    void show();
    void add_string(const String &s); //str뒤에 s를 붙인다.
    void copy_string(const String &s); //str에 s를 복사한다.
    int strlen(); //문자 길이 리턴
};

String::String(char c,int n){
    str=new char[n+1];
    len=n;
    for(int i=0;i<n;i++) str[i]=c;
    str[n]='\0';
}

String::String(const char *s){
    for(len=0;s[len]!='\0';len++);
    str=new char[len+1];
    for(int i=0;i<=len;i++) str[i]=s[i];
}

String::String(const String &s){
    str= new char[s.len+1];
    for(int i=0;i<s.len+1;i++) str[i]=s.str[i];
    len=s.len;
}

void String::add_string(const String &s){
    char *tmp=new char[len];
    strcpy(tmp,str);
    len+=s.len;
    delete[] str;
    str=new char[len];
    strcpy(str,tmp);
    delete[] tmp;
    strcat(str,s.str);    
}

void String::copy_string(const String &s){
    delete[] str;
    str = new char[s.len+1];
    strcpy(str,s.str);
    len = s.len;
}

int String::strlen(){
    return len;
}

void String::show(){
    cout << "str : "<<str<<endl;
    cout << "len : "<<len<<endl;
}

String::~String(){
    if(str!=NULL) delete[] str;
}

int main(){
    String s('a',5);
    s.show();

    String c(s);
    c.show();

    char *ss;
    ss=new char[8];
    strcpy(ss,"testcod");
    String d(ss);
    d.show();

    d.add_string(s);
    d.show();

    d.copy_string(s);
    d.show();
}
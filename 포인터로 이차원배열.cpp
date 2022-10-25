#include <iostream>
#include <string.h>

using namespace std;



int main(){
    //2차원 배열일 경우 다음과 같이 사용 할 수 있다.
    int **arr;
    int x,y;
    
    cin >> x;
    cin >> y;

    arr = new int*[x];
    for(int i=0;i<x;i++) arr[i]= new int[y];
    //
    int aa[5][5];
    aa[0][0]=1;
    cout << aa[0][0];
}
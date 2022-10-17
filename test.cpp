#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> numbers {10,20,30};

    for(auto n:numbers){
        cout << n <<endl;
    }
}
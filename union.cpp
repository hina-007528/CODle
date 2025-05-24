#include<iostream>

using namespace std;
 
union money
 {int rice;
//  4
 char car;
//  1
 float pounds;
//  4
};
int main(){
    union money m1;
    m1.rice=34;
    m1.car='C';
    cout<<m1.rice<<endl;
    cout<<m1.car;
    return 0;}
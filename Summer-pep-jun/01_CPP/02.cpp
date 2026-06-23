// Fnncitons

#include<iostream>
using namespace std;

void doubleTheNumber(int n){
    n *=2 ;
    cout<<"Number in function: "<<n;
} 


int main(){
    int n = 5;
    doubleTheNumber(n);
    cout<<"Number in main: "<<n;

    return 0;
}
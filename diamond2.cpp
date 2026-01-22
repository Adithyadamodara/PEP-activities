#include<iostream> 
using namespace std;

int main(){
    int n = 5;

    for(int i=0;i<2*n-1;i++){
        int spaces = abs(n-i-1);
        int stars = 2*(n-spaces) -1;
        cout<<string(spaces, ' ');
        cout<<string(stars, '*')<<endl;
    }
    return 0;
}
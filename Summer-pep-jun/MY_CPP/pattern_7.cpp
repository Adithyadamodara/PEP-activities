// Concentric square pattern
// https://www.geeksforgeeks.org/problems/square-pattern-1662666141


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ls = 2*n-1;
    int targetNum = n;
    int printNum;
    bool flag = 1;
    for(int i=0;i<ls;i++){
        printNum = n;
        while(printNum > targetNum){
            cout<<printNum<<" ";
            printNum--;
        }
        int lim = 2*targetNum - 1;
        while(lim){
            cout<<printNum<<" ";
            lim--;
        }
        while(printNum<n){
            printNum++;
            cout<<printNum<<" ";
        }
        if(flag){
            targetNum--;
            if(targetNum == 0){
                targetNum = 2;
                flag = 0;
            }
        } else {
            targetNum++;
        }
        cout<<endl;
    }

    return 0;
}

#include<iostream>
using namespace std;

// All elements present 3 times, find the element with frequeny 4;
// Without using extra space 

// HINT : integer is represeneted using 32 bits

// Answer:
// Constructing the answer by creating a bit array of size 32, counting the set bits in each position for every element,
// checking if the count of set bits are divisible by 3, if not then that particular bit is 'set' in the result, hence the result is constructed

int main(){
    int n;
    cin>>n;
    int res=0;
    int* arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<32;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j] & (1<<i)){
                count++;
            }
        }
        if(count%3){
            res |= 1<<i;
        }
    }

/*      

        int bit[32]={0};        
        for(int i=0;i<n;i++){
        int a = arr[i];
        for(int j=0;j<32;j++){
            if(a & (1<<j)){
                bit[j]++;
            }
        }
    }
    for(int i=0;i<32;i++){
        if(bit[i]%3!=0){
            res |= (1 << i);
        }
    } */ 
    cout<<"\nOutput: "<<res;
    delete arr;
    return 0;
}
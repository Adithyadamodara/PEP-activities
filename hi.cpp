#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<char,int> freq;
    freq['A']++;
    freq['A']++;
    cout<<freq.size();
    return 0;
}
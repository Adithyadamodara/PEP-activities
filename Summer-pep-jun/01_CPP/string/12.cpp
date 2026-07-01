#include<iostream>
using namespace std;

string reverseString(string& str){
    int i = 0;
    int j = str.size()-1;
    int s = str.size();
    string res = "";
    
    while(i<s){
        res+=str[j--];
        i++;
    }
    return res;
}


int main(){
    
    // char arr[5] = {'h', 'e', 'l', 'l', 'o'};
    
    string str1 = "hello";
    cout<<"Original String: "<<str1<<endl;
    cout<<"Reversed String: "<<reverseString(str1);
    return 0;
}
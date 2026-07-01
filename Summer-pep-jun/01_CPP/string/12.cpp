#include<iostream>
using namespace std;

string reverseString(string& str){
    int left = 0;
    int right = str.size()-1;
    
    
    while(left<=right){
        swap(str[left++], str[right--]);
    }
    return str;
}


int main(){
    
    // char arr[5] = {'h', 'e', 'l', 'l', 'o'};
    
    string str1 = "hello";
    cout<<"Original String: "<<str1<<endl;
    cout<<"Reversed String: "<<reverseString(str1);
    return 0;
}
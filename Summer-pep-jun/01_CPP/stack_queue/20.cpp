#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverse(string str){
    stack<string> stk;

    for(int i=0;i<str.size();i++){
        string s = "";
        while(i<str.size() && str[i]!=' '){
            s += str[i];
            i++;
        }
        stk.push(s);
    }
    
    string ans = "";
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return ans;
}

int main(){
    string str = "Hello world!";
    cout<<reverse(str);
    return 0;
}


// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c:s){
            if(stk.empty() || c=='(' || c=='{' || c=='['){
                stk.push(c);
            } else {        
                char p = stk.top();
                if(p=='('){
                    if(c==')') stk.pop();
                    else return false;
                } else if(p=='['){
                    if(c==']') stk.pop();
                    else return false;
                } else if(p=='{'){
                    if(c=='}') stk.pop();
                    else return false;
                }
            }
        }
        if(stk.size()>0) return false;
        return true;
    }
};
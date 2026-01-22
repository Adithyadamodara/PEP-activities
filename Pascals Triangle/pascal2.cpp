#include<iostream>
#include<vector>
using namespace std;

// Leetcode problem 118. Solution 
// Pascal's Triangle 

/*
            1
          1   1
        1   2   1
      1   3   3   1
    1   4   6   4   1
*/

vector<vector<int>> getPascal(int numRows){
    vector<vector<int>> res;
    res.push_back({1});
    if(numRows==1) return res;
    for(int i=1;i<numRows;i++){
        vector<int> sub(i+1,1);
        for(int j=1;j<i;j++){
            sub[j] = res[i-1][j-1] + res[i-1][j];
        }
        res.push_back(sub);
    }
    return res;
}

int main(){
    int numRows;
    cin>>numRows;
    vector<vector<int>> res = getPascal(numRows);
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numRows-i-1;j++) cout<<" ";
        for(int j:res[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
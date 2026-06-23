// Vectors 

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);

    // pop_back
    vec1.pop_back();
    
    // size
    cout<<"Size after pop_bacK: "<<vec1.size()<<endl;

    // clear
    vec1.clear();
    cout<<"Size after clear(): "<<vec1.size();
    return 0;
}
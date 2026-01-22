
#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr,int e){
    int n = arr.size();
    int count[10]={0};
    vector<int> obj(n);
    for(int i=0;i<n;i++){
        int digit = (arr[i]/e) % 10;
        count[digit]++;
    }
    for(int i=1;i<10;i++){
        count[i] += count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        int digit = (arr[i]/e) % 10;
        obj[count[digit]-1] = arr[i];
        count[digit]--;
    }
    arr = obj;
}
void sortNonNeg(vector<int>& arr){
    if(arr.empty()) return;
    int mx = *max_element(arr.begin(),arr.end());
    for(int e=1;(mx/e)>0;e*=10){
        countingSort(arr,e);
    }
}
void radix_sort(vector<int>& arr){
    vector<int> neg,pos;
    for(int x:arr){
        if(x<0) neg.push_back(-x);
        else pos.push_back(x);
    }
    
    sortNonNeg(neg);
    sortNonNeg(pos);
    reverse(neg.begin(),neg.end());
    
    int idx=0;
    for(int x:neg) arr[idx++] = -x;
    for(int x:pos) arr[idx++] = x;
}

int main()
{   
    vector<int> arr={170,45,75,-90,802,-24,2,66};
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    radix_sort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;

    Node(int v): value(v), next(nullptr) {}
};


Node* createList(vector<int>& arr){
    if(arr.size()<=0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* nod = new Node(arr[i]);
        temp->next = nod;
        temp = temp->next;
    }
    return head;
}

void traverse(Node* head){
    cout<<"Head -> ";
    while(head!=nullptr){
        cout<<head->value<<" -> ";
        head = head->next;
    }
    cout<<" END";
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head = createList(arr);
    traverse(head);
    return 0;
}
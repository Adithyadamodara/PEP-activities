// Cyclic Linked LIst


#include <iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;

    Node(): data(0), next(nullptr) {}

    Node(int data): data(data), next(nullptr) {}

    Node(int data, Node* next): data(data), next(next) {}
};


class cycleList{
public:
    Node* head;
    int size;
    cycleList(){
        Node* node = new Node();
        if(size==0){
            head = node;
        } else {
            insertAtEnd(node);
        }
        size++;
    }
    cycleList(int data){
        Node* node = new Node(data);
        if(size==0){
            head = node;
        } else {
            insertAtEnd(node);
        }
    }
    void insertAtEnd(Node* head, Node* node) {
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
    }
};

int main(){
    Node* head = new Node(1);
    cout<<head->data<<" "<<head->next->data;
}


// https://leetcode.com/problems/middle-of-the-linked-list/description/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
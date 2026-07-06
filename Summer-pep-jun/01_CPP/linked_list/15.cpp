/* 
Types of questions:
1. Fast and slow
2. reversal
3. Two pointers
4. dummy nodes


*/





// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/happy-number/description/

class Solution {
public:
    int getNum(int t){
        int res = 0;
        while(t){
            int sq = t%10;
            res += (sq*sq);
            t/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = getNum(slow);
            fast = getNum(getNum(fast));
            if(fast==1) return true;
        } while(slow!=fast);
        return false;
    }
};


// https://www.geeksforgeeks.org/problems/deletion-at-the-end-of-a-linked-list/1

/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        // code here
        if(head==nullptr) return head;
        Node* temp = head;
        if(!temp->next){
            delete head;
            return nullptr;
        }
        while(temp->next->next){
            temp = temp->next;
        }
        
        Node* del = temp->next;
        temp->next = nullptr;
        delete del;
        return head;
    }
};


// https://www.geeksforgeeks.org/problems/delete-head-of-linked-list/1


/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node *deleteHead(Node *head) {
        // code here
        if(!head->next){
            delete head;
            return nullptr;
        }
        Node* temp = head->next;
        delete head;
        head = temp;
        return head;
    }
};

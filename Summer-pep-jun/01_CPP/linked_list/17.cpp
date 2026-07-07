// https://leetcode.com/problems/reverse-linked-list/
// https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* nxt = temp->next;
    
        while(temp){
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
};

// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        } 

        ListNode* middle = slow->next;

        ListNode* curr = middle;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;            
        }

        middle = prev;

        ListNode* temp = head;
        while(middle){
            if(middle->val != temp->val) return false;
            middle = middle->next;
            temp = temp->next;   
        }
        return true;
    }
};



// https://www.geeksforgeeks.org/problems/insert-in-a-sorted-list/1

/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        Node* temp = head;
        Node* node = new Node(key);
        
        if(key<head->data) {
            node->next = head;
            return node;
        }
        Node* prev = nullptr;
        while(temp && temp->data<key){
            prev = temp;
            temp = temp->next;
        }
        
        node->next = temp;
        prev->next = node;
        return head;
    }
};



// https://leetcode.com/problems/intersection-of-two-linked-lists/


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
    int getLength(ListNode* head){
        int n = 0;
        while(head){
            head = head->next;
            n++;
        }
        return n;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        
        int len1 = getLength(headA);
        int len2 = getLength(headB);
        int dif = abs(len2 - len1);

        if(len2 > len1){
            while(dif--){
                b = b->next;
            }
        } else {
            while(dif--){
                a = a->next;
            }
        }
        while(a && b){
            if(a==b){
                return a;
            }
            a = a->next;
            b = b->next;
        }
        
        return nullptr;
    }
};



// https://leetcode.com/problems/linked-list-cycle/


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
            if(slow==fast) return true;
        }
        return false;
    }
};


// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        // floyyd loop detection
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        slow = head;
        while(fast && fast->next){
            if(slow==fast) return slow;
            slow = slow->next; 
            fast = fast->next;
        }
        return nullptr;
    }
};


// https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1


/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        Node* fast = head;
        Node* slow = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
    
        if(slow==fast){
            slow = head;
            
            if(slow==fast){
                while(fast->next != slow){
                    fast = fast->next;
                }
            } else {
                while(fast->next != slow->next){
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            fast->next = nullptr;
        }
    }
};


// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* t1 = &dummy;
        ListNode* t2 = &dummy;
        while(n-- >= 0 && t2){
            t2 = t2->next;
        }
        while(t2){
            t2 = t2->next;
            t1 = t1->next;
        }

        ListNode* del = t1->next;
        t1->next = t1->next->next;
        delete del;
        return dummy.next;
    }
};


// https://leetcode.com/problems/partition-list/
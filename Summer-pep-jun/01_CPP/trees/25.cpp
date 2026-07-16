// https://www.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/1

class Solution {
  public:
    int countLeft(Node* root){
        int h = 0;
        while(root){
            h++;
            root = root->left;
        }
        return h;
    }
    
    int countRight(Node* root){
        int h = 0; 
        while(root){
            h++;
            root = root->right;
        }
        return h;
    }
    int countNodes(Node* root) {
        if(!root) return 0;
        
        int lh = countLeft(root);
        int rh = countRight(root);
        
        if(lh == rh){
            return (1<<lh) - 1;
        }
        
        
        int l = countNodes(root->left);
        int r = countNodes(root->right);
        return l + r + 1;
    }
};


// https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        if(!root) return 0;
        if(!root->left && !root->right){
            return 1;
        }
        return countLeaves(root->left) + countLeaves(root->right);
    }
};



// https://leetcode.com/problems/sum-of-left-leaves/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool a = 0) {
        if(!root) return 0;
        if(!root->left && !root->right && a){
            return root->val;
        }
        int l = sumOfLeftLeaves(root->left, 1);
        int r = sumOfLeftLeaves(root->right, 0);
        return l+r;
    }
};


// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int maxH = 0;
    void dfs(Node* root, int h){
        if(!root) return;
        maxH = max(maxH, h);
        dfs(root->left, h+1);
        dfs(root->right, h+1);
    }
    int height(Node* root) {
        if(!root) return 0;
        dfs(root, 0);
        return maxH;
    }
};


class Solution {
  public:
    int height(Node* root) {
        if(!root) return -1;
        return 1 + max(height(root->left), height(root->right));
    }
};


// https://www.geeksforgeeks.org/problems/sum-of-binary-tree/


class Solution {
  public:
    int sumBT(Node* root) {
        if(!root) return 0;
        return root->data + sumBT(root->left) + sumBT(root->right);
    }
};

// https://leetcode.com/problems/same-tree/
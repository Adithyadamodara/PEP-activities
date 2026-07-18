// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1



// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        if(!root) return {};
        vector<int> res;
        queue<pair<Node*,int>> qu;
        map<int,int> seen;
        qu.push({root, 0});
        while(!qu.empty()){
            int s = qu.size();
            for(int i=0;i<s;i++){
                auto [node, c] = qu.front();
                qu.pop();
                if(!seen.count(c)) {
                    seen[c] = node->data;
                } 
                if(node->left) qu.push({node->left, c-1});
                if(node->right) qu.push({node->right, c+1});
            }
        }
        
        for(auto& i:seen){
            res.push_back(i.second);
        }
        return res;
    }
};






// http://geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void traverseLeft(Node* root, vector<int>& res){
        if(!root || !root->left && !root->right) return;    
        res.push_back(root->data);
        if(root->left) traverseLeft(root->left, res);
        else traverseLeft(root->right, res);
    }
    
    void traverseLeaf(Node* root, vector<int>& res){
        if(!root) return;
        if(!root->left && !root->right){
            res.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, res);
        traverseLeaf(root->right, res);
    }

    void traverseRight(Node* root, vector<int>& res){
        if(!root || !root->right && !root->left) return;
        if(root->right) traverseRight(root->right, res);
        else traverseRight(root->left, res);
        res.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root) {
        if(!root) return {};
        vector<int> res;
        res.push_back(root->data);
        traverseLeft(root->left, res);
        traverseLeaf(root->left, res);
        traverseLeaf(root->right, res);
        traverseRight(root->right, res);
        return res;        
    }
};


// https://www.geeksforgeeks.org/problems/k-distance-from-root/1


/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> kdistance(int k, Node *root) {
        // code here
        vector<int> res;
        if(!root) return res;
        queue<Node*> qu;
        qu.push(root);
        int p = -1;
        while(!qu.empty()){
            int s = qu.size();
            p++;
            if(p>k)break;
            for(int i=0;i<s;i++){
                Node* node = qu.front();
                qu.pop();
                if(p==k){
                    res.push_back(node->data);
                }
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
        }
        return res;
    }
};


// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root == p || root == q){
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l && r){
            return root;
        } else if(l){
            return l;
        } else {
            return r;
        }
        return nullptr;
    }
};
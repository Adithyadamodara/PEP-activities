// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return -1;
        vector<long long> res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int s = qu.size();
            long long sum = 0;
            for(int i=0;i<s;i++){
                TreeNode* node = qu.front();
                qu.pop();
                sum += node->val;
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);    
            }
            res.push_back(sum);
        }
        int n = res.size();
        if(n<k) return -1;
        sort(res.begin(), res.end());
        return res[res.size() - k];
    }
};


// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> qu;
        qu.push(root);
        bool flip = 0;
        while(!qu.empty()){
            int s = qu.size();
            vector<int> sub;
            for(int i=0;i<s;i++){
                TreeNode* node = qu.front();
                qu.pop();
                sub.push_back(node->val);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);    
            }
            if(flip){
                reverse(sub.begin(), sub.end());
            }
            flip = !flip;
            res.push_back(sub);
        }
        return res;
    }
};


// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int s = qu.size();
            for(int i=0;i<s;i++){
                TreeNode* node = qu.front();
                qu.pop();
                if(i==s-1){
                    res.push_back(node->val);
                }
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
        }
        return res;
    }
};


// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int s = qu.size();
            Node* prev = nullptr;
            for(int i=0;i<s;i++){
                Node* node = qu.front();    
                if(prev) prev->next = node;
                prev = node;
                if(i==s-1) node->next = nullptr;
                qu.pop();
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
        }
        return root;
    }
};
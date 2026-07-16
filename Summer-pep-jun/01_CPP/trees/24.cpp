// https://www.geeksforgeeks.org/problems/preorder-traversal/1

/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void traverse(Node* root, vector<int>& res){
        if(!root) return;
        res.push_back(root->data);
        traverse(root->left, res);
        traverse(root->right, res);
    }
    vector<int> preOrder(Node* root) {
        if(!root) return {};
        vector<int> res;
        traverse(root, res);
        return res;
    }
};


// https://www.geeksforgeeks.org/problems/inorder-traversal/1

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void dfs(Node* root, vector<int>& res){
        if(!root) return;
        dfs(root->left, res);
        res.push_back(root->data);
        dfs(root->right, res);
    }
    vector<int> inOrder(Node* root) {
        if(!root) return {};
        vector<int> res;
        
        dfs(root, res);
        return res;
    }
};


// https://www.geeksforgeeks.org/problems/postorder-traversal/1

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void dfs(Node* root, vector<int>& res){
        if(!root) return;
        if(root->left) dfs(root->left, res);
        if(root->right) dfs(root->right, res);
        res.push_back(root->data);
    }
  
    vector<int> postOrder(Node* root) {
        if(!root) return {};
        vector<int> res;
        dfs(root, res);
        return res;
    }
};


// http://geeksforgeeks.org/problems/level-order-traversal/1


/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        vector<int> res;
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int s = qu.size();
            for(int i=0;i<s;i++){
                Node* node = qu.front();    
                qu.pop();
                res.push_back(node->data);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
        }
        return res;
    }
};


// https://www.geeksforgeeks.org/problems/preorder-traversal-iterative/1

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        if(!root) return {}; 
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* node = stk.top();
            stk.pop();
            res.push_back(node->data);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
        return res;
    }
};


// https://www.geeksforgeeks.org/problems/inorder-traversal-iterative/1


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
    vector<int> inOrder(Node* root) {
        if(!root) return {};
        vector<int> res;
        stack<Node*> stk;
        
        Node* node = root;
        while(true){
            if(node){
                stk.push(node);
                node = node->left;
            } else {
                if(stk.empty()) break;
                node = stk.top();
                stk.pop();
                res.push_back(node->data);
                node = node->right; 
            }
        }
        return res;
    }
};
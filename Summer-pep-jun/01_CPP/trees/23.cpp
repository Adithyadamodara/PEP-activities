#include<iostream>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        data = -1;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);


}


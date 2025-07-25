//
// Created by yang on 25-3-18.
//
#include <iostream>
using namespace std;

struct BstNode
{
    int val;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data)
{
    struct BstNode* new_node = new BstNode();
    new_node->val = data;
    new_node->left = new_node->right = nullptr;
    return new_node;
}

bool SearchVal(BstNode* root,int data)
{
    if(root == nullptr) return false;
    if(data == root->val) return true;
    if(data <= root->val) return SearchVal(root->left,data);
    else return SearchVal(root->right,data);
}
BstNode* Insert(BstNode* root,int data)
{
    // 数为空
    if(root == nullptr)
    {
        root = GetNewNode(data);
    }
    else if(data <= root->val)  // 插入左子树
    {
        root->left = Insert(root->left,data);
    }
    else        // 插入右子树
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

int GetMin(BstNode* root)
{
    if(root == nullptr)
        return -1;
    if(root->left == nullptr)
        return root->val;
    else
        return GetMin(root->left);
}
int main()
{
    BstNode* root = nullptr;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    bool flag;
    flag = SearchVal(root,10);
    if (flag)
        cout << "Value is found";
    else
        cout << "Value is not found";
}
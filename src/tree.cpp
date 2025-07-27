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
//递归实现寻找最小值
int GetMin(BstNode* root)
{
    if(root == nullptr)
        return -1;
    if(root->left == nullptr)
        return root->val;
    else
        return GetMin(root->left);
}

/*
 * 查找节点的高度
 * 节点的高度定义为从该节点到叶子节点的最长路径
 * 节点的深度定义为从该节点到根节点的最长路径
 * 树的高度= 根节点的高度= 从根结点出发到叶子节点最长的路径
 * 这里定义如果只有一个根节点，树的高度为0（也可以是1，定义不同）
 * 树为空，高度为-1
 * */
int GetHeight(BstNode* root){
    if(root == nullptr)
        return -1;
    else
    {
        int left_height = GetHeight(root->left);
        int right_height = GetHeight(root->right);
        return max(left_height,right_height) + 1;
    }
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
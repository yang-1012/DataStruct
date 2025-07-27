//
// Created by yang on 25-7-27.
//
/*
 * 树的遍历：访问树中的每一个节点，每个节点只能访问一次
 * 广度优先搜索：先访问同一级的节点，再访问下一级节点
 * 深度优先搜索：先完成一个子树，再完成下一个子树
 *      前序遍历：根节点->左子树->右子树      data->left->right
 *      中序遍历：左子树->根节点->右子树      left->data->right
 *      后序遍历：左子树->右子树->根节点      left->right->data
 * */
#include <iostream>
#include <queue>

class Node {
public:
    Node(char val) : data(val), left(nullptr), right(nullptr) {};
public:
    char data;
    Node* left;
    Node* right;
};

Node* Insert(Node* root,char data)
{
    // 数为空
    if(root == nullptr)
    {
        root = new Node(data);
    }
    else if(data <= root->data)  // 插入左子树
    {
        root->left = Insert(root->left,data);
    }
    else        // 插入右子树
    {
        root->right = Insert(root->right,data);
    }
    return root;
}
/*
 * 广度优先遍历：使用队列，保存每一个节点及其子树
 * */
void BFS(Node* root)
{
    if (root == nullptr)
            return;
    std::queue<Node*> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        Node* node = nodes.front();
        std::cout << node->data << " ";
        nodes.pop();
        if (node->left != nullptr)
            nodes.push(node->left);
        if (node->right != nullptr)
            nodes.push(node->right);
    }
}
/*
 * 深度优先遍历：前序、中序、后序
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * */
// 前序遍历
void PreOrder(Node* root)
{
    if (root == nullptr)
        return;
    std::cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// 中序遍历
void InOrder(Node* root)
{
    if (root == nullptr)
        return;
    InOrder(root->left);
    std::cout << root->data << " ";
    InOrder(root->right);
}

// 后序遍历
void PostOrder(Node* root)
{
    if (root == nullptr)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    std::cout << root->data << " ";
}
int main()
{
    Node* root = nullptr;
    root = Insert(root,'F');
    root = Insert(root,'D');
    root = Insert(root,'J');
    root = Insert(root,'B');
    root = Insert(root,'E');
    root = Insert(root,'G');
    root = Insert(root,'K');
    root = Insert(root,'A');
    root = Insert(root,'C');
    root = Insert(root,'I');
    root = Insert(root,'H');
    BFS(root);
    std::cout << std::endl;
    PreOrder(root);
    std::cout << std::endl;
    InOrder(root);
    std::cout << std::endl;
    PostOrder(root);
}
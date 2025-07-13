//
// Created by yang on 25-7-10.
//
#include <cstdio>
class Node{
public:
    Node(int x): val(x), prv(nullptr), next(nullptr){};
public:
    int val;
    Node* prv;
    Node* next;
};
// 定义head为全局变量
Node* head = nullptr;
/*
 * 头插法实现双向链表
 */
void frontInsert(int val)
{
    Node* newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    head->prv = newNode;
    newNode->next = head;
    head = newNode;
}

/*
 * void forwardPrint()
 * 实现前向打印
 */
void forwardPrint()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
}

 int main()
 {
     frontInsert(2);
     frontInsert(4);
     frontInsert(5);
     forwardPrint();
 }
//
// Created by yang on 25-3-13.
//
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void Push(int data)
{
    struct Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->next = top;
    top = temp;
}

void Pop()
{
    struct Node* temp = new Node();
    if (top == NULL)
    {
        return;
    }
    temp = top;         // 设置一个临时指针 = 指向头节点
    top = top->next;    // 截断第一个节点
    delete(temp);       // 释放第一个几点
}

void Print()
{
    if (top == NULL) return;
    struct Node* temp = new Node();
    temp = top;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    delete(temp);
}

int main(){

    Push(2);
    Push(2);
    Push(2);
    Print();
}
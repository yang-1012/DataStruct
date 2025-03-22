//
// Created by yang on 25-3-12.
//
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void backInsert(int data)
{
    // 新节点
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void indexDelete(int n)
{
    struct Node* temp = head;
    if (n == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }
    for(int i = 0;i < n-2;i++)
    {
        temp = temp->next;
    } // 循环到了第n-1个节点
    struct Node* temp1 = temp->next; // 让temp1指向第n个节点
    temp->next = temp1->next;       //  第n-1个节点的指针域指向第n+1个节点
    free(temp1);
}
void Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    head = NULL;
    backInsert(2);
    backInsert(5);
    backInsert(8);
    backInsert(0);
    backInsert(1);
    backInsert(9);

    Print();
    indexDelete(2);
    Print();
}
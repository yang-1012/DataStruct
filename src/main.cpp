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
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    head = NULL;
    backInsert(2);
    backInsert(3);
    backInsert(24);
    backInsert(25);
    Print();
}
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

void Insert(int data,int index)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    if(index == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node* temp2 = head;
    // 0 ~ n-3共n-2次，循环到了第1 + (n-2) = n-1个节点
    for(int i = 0;i < index-2;i++)
    {
        temp2 = temp2->next;
    }
    // 现在temp2指向第n-1个节点，temp2->next就是指向下一个节点
    temp1->next = temp2->next;  // 新建节点指向第n个节点
    temp2->next = temp1;        //  第n-1个节点的指针域指向新建节点

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
    Insert(2,1);// 2
    Insert(3,2);// 2 3
    Insert(5,1);// 5 2 3
    Insert(6,2);// 5 6 2 3

    Print();
    return 0;
}
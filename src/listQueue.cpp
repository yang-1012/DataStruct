//
// Created by yang on 25-3-16.
//
#include <iostream>
using namespace std;

class Node
{
public:
    Node(int data)
    {
        this->val = data;
        this->next = nullptr;
    }
public:
    int val;
    Node* next;
};

Node* front = nullptr;
Node* rear  = nullptr;

bool isEmpty()
{
    if (front == nullptr && rear == nullptr)
        return true;

    return false;
}
void Enqueue(int val)
{
   Node* new_node = new Node(val);
   // 判断是否为空
   if (isEmpty())    //front == NULL && rear == NULL
   {
       front = rear = new_node;
       return;
   }
   // 将新节点加到队尾
   rear->next = new_node;
   rear = new_node;
}

void Dequeue()
{
    Node* temp = front;
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else if(front == rear)  // 只有一个节点
    {
        front = rear = nullptr;
    }
    else
    {
        front = front->next;
    }
    delete(temp);
}

void printQueue()
{
    Node* cur = front;
    while(cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
int main()
{
    Enqueue(2);
    Enqueue(8);
    printQueue();   // 2 8
    Enqueue(4);
    Enqueue(5);
    printQueue();   // 2 8 4 5
    Dequeue();
    printQueue();   // 8 4 5
}
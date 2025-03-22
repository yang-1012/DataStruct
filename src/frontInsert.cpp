#include <iostream>
using namespace std;

class Node
{
public:
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
public:
    int val;
    Node* next;
};

Node* head = NULL;

void insert(int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int main()
{
    head = NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    Print();
}
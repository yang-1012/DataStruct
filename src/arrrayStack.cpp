//
// Created by yang on 25-3-13.
//
#include <iostream>
using namespace std;

#define MAX_SIZE 100
int A[MAX_SIZE];
int top = -1;   // 栈顶指针

void Push(int data)
{
    if (top == MAX_SIZE-1)  // MAX_SIZE个，0~MAX_SIZE-1
    {
        cout << "stack overflow" << endl;
    }
    top++;
    A[top] = data;
}

void Pop()
{
    if (top == -1)
    {
        cout << "stack is empty" << endl;
    }
    top--;
}

void stackPrint()
{
    for(int i=0;i<= top;i++ )
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void isEmpty()
{
    if (top == -1)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }

}
int main()
{
    Push(2);
    Push(2);
    Push(2);
    Push(2);
    stackPrint();
    isEmpty();
}
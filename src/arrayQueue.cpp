//
// Created by yang on 25-3-15.
//
#include <iostream>
using namespace std;

#define MAX_SIZE 10
int A[MAX_SIZE];

// 队尾进，队前出
int front = -1;
int rear = -1;

bool isEmpty()
{
    if (rear == -1 && front == -1)
        return true;
    else
        return false;
}

bool isFull()
{
    if ((rear+1)%MAX_SIZE == front)
        return true;
    else
        return false;
}
void Enqueue(int val)
{
    if (isFull())
    {
        cout << "Queue is full" << endl;
        return;
    }
    else if (isEmpty())
    {
        rear = front = 0;
    }
    else
    {
        rear = rear + 1;
    }
    A[rear] = val;
}

int Dequeue()
{
    int val;
    if (isEmpty()){

        cout << "Queue is empty" << endl;
        return -1;
    }
    else if (rear == 0 && front == 0){

        rear = front = -1;
    }
    else{
        val = A[front];
        front = (front + 1)%MAX_SIZE;
        return val;
    }
}

void Print(){

    int temp = front;
    if (isEmpty())
    {
        return;
    }
    else
    {
        while(temp <= rear)
        {
            cout << A[temp] << " ";
            temp = (temp+1)%MAX_SIZE;
        }
        cout << endl;
    }

}

int main()
{
    Enqueue(21);
    Enqueue(33);
    Enqueue(42);
    Print();
    int val = Dequeue();
    cout << val << endl;
    Print();
}
//
// Created by laptop on 24-Nov-24.
//

#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
template <class t>

class stack {
    int top;
    t item[MAX_SIZE];

public:
    stack():top(-1) {}

    void push(int e)
    {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack is full";
        } else {
            top++;
            item[top] = e;
        }
    }

    bool isEmpty()
    {
        return top < 0;
    }
    void pop()
    {
        if (isEmpty())
            cout << "Stack is empty on pop";
        else
            top--;
    }

    void pop(t &e)
    {
        if (isEmpty())
            cout << "Stack is empty on pop";
        else {
            e = item[top];
            top--;
        }
    }

    void getTop(t &st)
    {
        if (isEmpty())
            cout << "Stack is empty on getTop";
        else {
            st = item[top];
            // cout << st << endl;
        }
    }

    void print()
    {
        cout << "[ ";
        for (int i = top; i >= 0; i--) {
            cout << item[i] << " ";
        }
        cout << "]";
        cout << endl;
    }
};

int main()
{
    stack <int> s;

    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.pop();
    s.push(4);
    s.print();
}

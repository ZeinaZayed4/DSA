#include <cassert>
#include <iostream>

using namespace std;

// const int MAX_LENGTH = 100;

template <class t>

class ArrayQueueType
{
    int rear;
    int front;
    int length;
    t *arr;
    int maxSize;

public:
    ArrayQueueType(int size)
    {
        if (size <= 0) {
            maxSize = 100;
        } else {
            maxSize = size;
        }
        front = 0;
        arr = new t[maxSize];
        rear = maxSize - 1;
        length = 0;
    }

    int isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == maxSize;
    }

    void enqueue(t element)
    {
        if (isFull()) {
            cout << "Full queue can't enqueue!";
        } else {
            rear = (rear + 1) % maxSize;
            arr[rear] = element;
            length++;
        }
    }

    void dequeue()
    {
        if (isEmpty()) {
            cout << "Empty queue can't dequeue!";
        } else {
            front = (front + 1) % maxSize;
            length--;
        }
    }

    int getFront()
    {
        assert(!isEmpty());
        return arr[front];
    }

    int getRear()
    {
        assert(!isEmpty());
        return arr[rear];
    }

    void printQueue()
    {
        if (!isEmpty()) {
            for (size_t i = front; i != rear; i = (i + 1) % maxSize) {
                cout << arr[i] << ' ';
            }
            cout << arr[rear];
        } else {
            cout << "Empty queue!";
        }
    }

    int queueSearch(t element)
    {
        int pos = -1;
        if (!isEmpty()) {
            for (int i = front; i != rear; i = (i + 1) % maxSize) {
                if (arr[i] == element) {
                    pos = i;
                    break;
                }
                if (pos == -1) {
                    if (arr[rear] == element) {
                        pos = rear;
                    }
                }
            }
        } else {
            cout << "Queue is empty!" << '\n';
        }
        return pos;
    }
};

int main ()
{
    ArrayQueueType <int> q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.dequeue();
    q1.enqueue(80);
    cout << q1.queueSearch(80);

    return 0;
}

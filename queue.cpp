#include <iostream>
using namespace std;

bool isFull(int rear, int size) {
    return (rear == size - 1);
}

bool isEmpty(int front, int rear) {
    return (front == -1 || front > rear);
}

void enqueue(int queue[], int &front, int &rear, int size) {
    if (isFull(rear, size)) {
        cout << "Overflow" << endl;
    } else {
        int n;
        cout << "Enter value: ";
        cin >> n;
        if (front == -1) front = 0;
        rear++;
        queue[rear] = n;
        cout << n << " enqueued to queue" << endl;
        if (isFull(rear, size)) {
            cout << "Queue is now full" << endl;
        }
    }
}

void dequeue(int queue[], int &front, int &rear) {
    if (isEmpty(front, rear)) {
        cout << "Underflow" << endl;
    } else {
        cout << "Deleted value: " << queue[front] << endl;
        front++;
        if (front > rear) {
            front = rear = -1;
            cout << "Queue is now empty" << endl;
        }
    }
}

void display(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int size;
    cout << "Enter queue size: ";
    cin >> size;
    int queue[size];
    int front = -1, rear = -1;

    enqueue(queue, front, rear, size);
    enqueue(queue, front, rear, size);
    display(queue, front, rear);
    enqueue(queue, front, rear, size);
    dequeue(queue, front, rear);
    enqueue(queue, front, rear, size);
    display(queue, front, rear);
    enqueue(queue, front, rear, size);
    display(queue, front, rear);

    return 0;
}

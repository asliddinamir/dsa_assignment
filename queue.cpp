#include <iostream>
#define MAX 5 // Define a smaller maximum size of the queue for easier demonstration

using namespace std;

int queue[MAX]; // Array to store queue elements
int front = -1; // Index of the front element in the queue
int rear = -1;  // Index of the rear element in the queue

// Function to add an element to the queue
void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        cout << "Queue Overflow! Cannot add " << x << " to the queue." << endl;
    } else {
        if (front == -1) front = 0; // Update front if the queue was empty
        rear = (rear + 1) % MAX; // Circular increment
        queue[rear] = x;
        cout << x << " added to the queue." << endl;
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow! Cannot remove an element from the queue." << endl;
    } else {
        cout << queue[front] << " removed from the queue." << endl;
        if (front == rear) {
            front = -1; // Queue becomes empty
            rear = -1;
        } else {
            front = (front + 1) % MAX; // Circular increment
        }
    }
}

// Function to display the current contents and status of the queue
void display() {
    if (front == -1) {
        cout << "The queue is empty." << endl;
    } else {
        cout << "Queue contents (front to rear): ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add an element to the queue" << endl;
        cout << "2. Remove an element from the queue" << endl;
        cout << "3. Display the current contents and status of the queue" << endl;
        cout << "4. Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be added: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}


#include <iostream>
#define MAX 100 // Define the maximum size of the stack

using namespace std;

int stack[MAX]; // Array to store stack elements
int top = -1; // Index of the top element in the stack

// Function to push an element onto the stack
void push(int x) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow! Cannot push " << x << " onto the stack." << endl;
    } else {
        stack[++top] = x;
        cout << x << " pushed onto the stack." << endl;
    }
}

// Function to pop an element from the stack
void pop() {
    if (top < 0) {
        cout << "Stack Underflow! Cannot pop an element from the stack." << endl;
    } else {
        cout << stack[top--] << " popped from the stack." << endl;
    }
}

// Function to display the current status and contents of the stack
void display() {
    if (top < 0) {
        cout << "The stack is empty." << endl;
    } else {
        cout << "Stack contents (top to bottom): ";
        for (int i = top; i >= 0; --i) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Push an element onto the stack" << endl;
        cout << "2. Pop an element from the stack" << endl;
        cout << "3. Show the current status and contents of the stack" << endl;
        cout << "4. Terminate the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be pushed: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Terminating the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

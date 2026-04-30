#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    cout << "Popped: " << temp->data << endl;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << top->data << endl;
}

void isEmpty() {
    if (top == NULL)
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();
    peek();
    pop();
    display();
    isEmpty();

    return 0;
}

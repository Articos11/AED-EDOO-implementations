#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value = 0){
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue(){
        front = rear = new Node();
        size = 0;
    }

    void enqueue(int value){
        Node* newNode = new Node(value);
        rear->next = newNode;
        rear = newNode;
        size++;
    }

    int dequeue() {
        if (isEmpty()){
            cout << "Fila vazia" << endl;
            return -1;
        }
        Node* temp = front->next;
        int removedValue = temp->data;
        front->next = temp->next;
        if (rear == temp) {
            rear = front;
        }
        delete temp;
        size--;
        return removedValue;
    }

    int peek(){
        if (isEmpty()){
            cout << "Fila Vazia!";
            return -1;
        }
        return front->next->data;
    }

    bool isEmpty(){
        return front == rear;
    }

    int getSize(){
        return size;
    }

    void clear(){
        while(!isEmpty()){
            dequeue();
        }
    }
};

int main() {

    Queue fila;

    fila.enqueue(10);
    cout << fila.peek() << endl;
    fila.dequeue();
    fila.peek();
    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);
    fila.enqueue(40);
    cout << fila.peek();
    fila.dequeue();
    cout << fila.peek();

    return 0;
}
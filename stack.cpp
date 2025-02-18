#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop(){
        if (isEmpty()){
            cout << "A pilha tá vazia" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        size--;
        return poppedValue;
    }

    int Top(){
        if (isEmpty()){
            cout << "Pilha vazia" << endl;
            return -1;
        }
        return top->data;
    }

    void clear() {
        while(!isEmpty()){
            pop();
        }
    }

    bool isEmpty(){
        return top == nullptr;
    }

    int getSize(){
        return size;
    }
};

int main(){

    Stack stack;
    stack.Top();
    stack.push(10);
    cout << stack.Top() << endl;
    stack.pop();
    stack.Top();

    return 0;
}
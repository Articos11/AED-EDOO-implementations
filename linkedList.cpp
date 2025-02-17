#include <iostream>
using namespace std;

template <typename E>
class Node {
public:
    E element;
    Node* next;
    Node(E value, Node* nextvalue = nullptr) {
        element = value;
        next = nextvalue;
    }
};

template <typename E>
class LinkedList {
private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* current;
    int counter;
public:
    LinkedList() {
        tail = head = current = new Node(0);
        counter = 0;
    }

    void insert(E value) {
        current -> next = new Node<E>(value, current->next);
        if (tail == current) {
            tail = current->next;
        }
        current = current -> next;
        counter++;
    }

    E remove() {
        if (current->next == nullptr) {
            return E();
        }
        E it = current->next->element;

        if (tail == current->next) {
            tail = current;
        }

        Node<E>* temp = current->next;
        current->next = current->next->next;
        delete temp;
        counter --;

        return it;
    }


    void clear() {
        current = head-> next;
        while(current != nullptr) {
            Node<E>* temp = current;
            current = current->next;
            delete temp;
        }
        head -> next = nullptr;
        tail = head;
        counter = 0;
    }

    void moveToFront() {
        current = head;
    }

    void moveToEnd() {
        current = tail;
    }

    void printList() {
        Node<E> *temp = head->next;

        while(temp != nullptr) {
            cout << temp->element << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
};


int main() {

    LinkedList<int> list;
    list.moveToFront();
    list.insert(10);
    list.moveToFront();
    list.insert(20);
    list.printList();
    list.insert(30);
    list.printList();
    list.clear();

    return 0;
}
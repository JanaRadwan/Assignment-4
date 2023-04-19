#include<iostream> 
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    int count;

    Node(int data, int count) {
        this->data = data;
        this->next = nullptr;
        this->count = count;
    }
};

class LinkedList {
public:
    Node* head;


    LinkedList() {
        this->head = nullptr;
    }

    void add_node(int data) {
        if (this->head == nullptr) {
            this->head = new Node(data, 1);
        }
        else {
            Node* current = this->head;
            while (current->next != nullptr) {
                if (current->data == data) {
                    current->count += 1;
                    return;
                }
                current = current->next;
            }
            if (current->data == data) {
                current->count += 1;
            }
            else {
                current->next = new Node(data, 1);
            }
        }
    }

    void removeNode(int data) {
        if (this->head == nullptr) {
            return;
        }

        if (this->head->data == data) {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
            return;
        }

        Node* current = this->head;
        while (current->next != nullptr) {
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void printList() {
        Node* current = this->head;
        while (current != nullptr) {
            for (int i = 0; i < current->count; i++) {
                cout << current->data << " ";
            }
            current = current->next;
        }
        cout << endl;
    }
    int sumNodes() {
        int sum = 0;
        Node* current = this->head;
        while (current != nullptr) {
            sum += current->data;
            current = current->next;
        }
        return sum;
    }
   
};

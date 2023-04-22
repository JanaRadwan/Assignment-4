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

   void addNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->count = 1;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
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
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " with count (" << current->count << ") ";
            current = current->next;
        }
        cout << endl;
    }
    void createList(vector<int> v) {
        for (int i = 0; i < v.size(); i++) {
            int value = v[i];
            bool found = false;

            Node* current = head;
            while (current != nullptr) {
                if (current->data == value) {
                    current->count++;
                    found = true;
                    break;
                }
                current = current->next;
            }

            if (!found) {
                addNode(value);
            }
        }
    }
    int sumNodes() {
        int sum = 0;
        Node* current = this->head;
        while (current != nullptr) {
            sum += current->data * current->count;
            current = current->next;
        }
        return sum;
    }
   
};

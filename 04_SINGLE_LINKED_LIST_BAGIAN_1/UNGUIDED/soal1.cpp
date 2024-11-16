#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Kelas Linked List
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambah node di depan
    void insertAtFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambah node di belakang
    void insertAtBack(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode; 
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next; 
            }
            temp->next = newNode; 
        }
    }

    // Fungsi untuk mencetak linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Contoh operasi
    list.insertAtFront(10); 
    list.insertAtBack(20);   
    list.insertAtFront(5);   

    // Cetak linked list
    cout << "Linked List: ";
    list.printList(); 

    return 0;
}
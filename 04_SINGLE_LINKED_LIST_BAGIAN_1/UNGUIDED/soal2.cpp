#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

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

    // Fungsi untuk menghapus node dengan nilai tertentu
    void deleteNode(int value) {
        if (head == nullptr) return; 
        if (head->data == value) {
            Node* temp = head;
            head = head->next; 
            delete temp;
            return;
        }

        // Menelusuri list untuk menemukan node yang akan dihapus
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        // Jika node ditemukan
        if (current != nullptr) {
            previous->next = current->next; 
            delete current; 
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

    // Cetak linked list sebelum penghapusan
    cout << "Linked List sebelum penghapusan: ";
    list.printList(); // Output: 5 -> 10 -> 20

    // Hapus node dengan nilai 10
    list.deleteNode(10);

    // Cetak linked list setelah penghapusan
    cout << "Linked List setelah penghapusan: ";
    list.printList(); 

    return 0;
}
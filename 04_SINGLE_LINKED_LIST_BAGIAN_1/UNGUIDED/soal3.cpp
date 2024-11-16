#include <iostream>

using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

// Kelas Linked List
class LinkedList {
private:
    Node* head;

public:
    // Konstruktor
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

    // Fungsi untuk mencari node dengan nilai tertentu
    bool searchNode(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true; 
            }
            current = current->next;
        }
        return false; 
    }

    // Fungsi untuk menghitung panjang linked list
    int countLength() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count; 
    }

    
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

    list.insertAtFront(10); 
    list.insertAtBack(20);   
    list.insertAtFront(5);   

    // Mencari node dengan nilai 20
    int searchValue = 20;
    if (list.searchNode(searchValue)) {
        cout << "Node dengan nilai " << searchValue << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << searchValue << " tidak ditemukan." << endl;
    }

    // Menghitung panjang linked list
    int length = list.countLength();
    cout << "Panjang linked list: " << length << endl; // Output: 3

    return 0;
}
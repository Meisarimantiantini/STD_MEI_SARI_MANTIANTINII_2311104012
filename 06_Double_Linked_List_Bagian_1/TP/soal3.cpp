#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Fungsi untuk menambahkan node ke awal list
Node* insertFirst_2311104012(Node* head, int data) {
    Node* node = newNode(data);
    if (head == NULL) {
        return node;
    }
    node->next = head;
    head->prev = node;
    return node;
}

// Fungsi untuk menampilkan elemen dari depan ke belakang
void printForward_2311104012(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Fungsi untuk menampilkan elemen dari belakang ke depan
void printBackward_2311104012(Node* head) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n = 4;
    int data;
    cout << "Masukkan " << n << " elemen secara berurutan: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        head = insertFirst_2311104012(head, data);
    }
    cout << "Daftar elemen dari depan ke belakang: ";
    printForward_2311104012(head);
    cout << "Daftar elemen dari belakang ke depan: ";
    printBackward_2311104012(head);
    return 0;
}
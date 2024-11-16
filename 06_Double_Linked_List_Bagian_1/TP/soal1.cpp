#include <iostream>
using namespace std;

// Struktur Node untuk menyimpan data doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Fungsi untuk menambahkan elemen di awal list
void insertFirst_2311104012(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = *head;

    if (*head != nullptr) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// Fungsi untuk menambahkan elemen di akhir list
void insertLast_2311104012(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Fungsi untuk menampilkan elemen dari depan ke belakang
void printList_2311104012(Node* node) {
    Node* last = nullptr;
    cout << "DAFTAR ANGGOTA LIST: ";
    while (node != nullptr) {
        cout << node->data;
        last = node;
        node = node->next;
        if (node != nullptr) {
            cout << " <-> ";
        }
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Input berdasarkan contoh pada soal
    insertFirst_2311104012(&head, 10); // Elemen pertama = 10
    insertFirst_2311104012(&head, 5);  // Elemen kedua di awal = 5
    insertLast_2311104012(&head, 20);  // Elemen ketiga di akhir = 20

    // Menampilkan daftar elemen dalam list
    printList_2311104012(head);

    return 0;
}

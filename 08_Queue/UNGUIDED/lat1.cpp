#include <iostream>
using namespace std;

struct Node {
    int data;       // Elemen data pada node
    Node* next;     // Pointer ke node berikutnya
};

struct Queue {
    Node* front;    // Pointer ke elemen paling depan (depan antrian)
    Node* back;     // Pointer ke elemen paling belakang (belakang antrian)
};

// Inisialisasi queue kosong
void initQueue(Queue &q) {
    q.front = nullptr;
    q.back = nullptr;
}

// Mengecek apakah queue kosong
bool isEmpty(const Queue &q) {
    return q.front == nullptr;
}

// Menambah elemen ke belakang antrian
void enqueue(Queue &q, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty(q)) {
        q.front = newNode;
        q.back = newNode;
    } else {
        q.back->next = newNode;
        q.back = newNode;
    }
}

// Menghapus elemen dari depan antrian
void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = q.front;
        q.front = q.front->next;
        delete temp;

        if (q.front == nullptr) { 
            q.back = nullptr;
        }
    }
}

// Menghitung jumlah elemen dalam antrian
int countQueue(const Queue &q) {
    int count = 0;
    Node* current = q.front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Menghapus semua elemen dalam antrian
void clearQueue(Queue &q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

// Melihat isi antrian
void viewQueue(const Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* current = q.front;
        cout << "Isi Antrian:" << endl;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    Queue q;
    initQueue(q);

    int choice, data;

    do {
        cout << "\nMenu Queue:\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Hapus Antrian\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Hapus Semua Antrian\n";
        cout << "5. Jumlah Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data (angka): ";
                cin >> data;
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                viewQueue(q);
                break;
            case 4:
                clearQueue(q);
                cout << "Semua antrian telah dihapus." << endl;
                break;
            case 5:
                cout << "Jumlah antrian: " << countQueue(q) << endl;
                break;
            case 0:
                cout << "Keluar program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 0);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// Definisi struktur untuk data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
};

// Definisi struktur untuk elemen list
struct Node {
    Mahasiswa data;    
    Node* next;        
};

// Fungsi untuk alokasi node baru
Node* alokasi(string nama, string nim) {
    Node* newNode = new Node;
    if (newNode != nullptr) {
        newNode->data.nama = nama;
        newNode->data.nim = nim;
        newNode->next = nullptr;
    }
    return newNode;
}

// Fungsi untuk dealokasi node
void dealokasi(Node* node) {
    delete node;
}

// Fungsi untuk mengecek apakah list kosong
bool isListEmpty(Node* head) {
    return head == nullptr;
}

// Fungsi untuk mengecek apakah antrian penuh (maksimal 5)
bool isListFull(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count >= 5;
}

// Fungsi untuk menambah antrian dengan prioritas berdasarkan NIM
void enqueueAntrian(Node* &head, string nama, string nim) {
    if (isListFull(head)) {
        cout << "Antrian penuh" << endl;
        return;
    }

    Node* newNode = alokasi(nama, nim);
    if (newNode == nullptr) return;

    // Jika list kosong atau NIM baru lebih kecil dari head
    if (isListEmpty(head) || nim < head->data.nim) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Mencari posisi yang tepat berdasarkan NIM
    Node* current = head;
    while (current->next != nullptr && current->next->data.nim < nim) {
        current = current->next;
    }

    // Menyisipkan node baru
    newNode->next = current->next;
    current->next = newNode;
}

// Fungsi untuk mengurangi antrian (dequeue)
void dequeueAntrian(Node* &head) {
    if (isListEmpty(head)) {
        cout << "Antrian kosong" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    cout << "\nMahasiswa yang keluar dari antrian:" << endl;
    cout << "Nama: " << temp->data.nama << endl;
    cout << "NIM : " << temp->data.nim << endl;
    dealokasi(temp);
}

// Fungsi untuk menghitung jumlah antrian
int countQueue(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi untuk menghapus semua antrian
void clearQueue(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        dealokasi(temp);
    }
}

// Fungsi untuk menampilkan antrian
void viewQueue(Node* head) {
    cout << "\nData antrian Mahasiswa (Diurutkan berdasarkan NIM):" << endl;
    cout << "=================================================" << endl;
    if (isListEmpty(head)) {
        cout << "Antrian kosong!" << endl;
    } else {
        Node* temp = head;
        int i = 1;
        while (temp != nullptr && i <= 5) {
            cout << i << ". Nama: " << temp->data.nama 
                 << "\n   NIM : " << temp->data.nim << endl;
            cout << "-------------------------------------------------" << endl;
            temp = temp->next;
            i++;
        }
        while (i <= 5) {
            cout << i << ". (kosong)" << endl;
            cout << "-------------------------------------------------" << endl;
            i++;
        }
    }
}

int main() {
    Node* head = nullptr;
    string nama, nim;

    cout << "=== Program Antrian Mahasiswa ===" << endl;
    
    // Input data mahasiswa
    cout << "\nMasukkan data mahasiswa ke-1:" << endl;
    cout << "Nama: ";
    getline(cin, nama);
    cout << "NIM : ";
    getline(cin, nim);
    enqueueAntrian(head, nama, nim);

    cout << "\nMasukkan data mahasiswa ke-2:" << endl;
    cout << "Nama: ";
    getline(cin, nama);
    cout << "NIM : ";
    getline(cin, nim);
    enqueueAntrian(head, nama, nim);

    cout << "\nMasukkan data mahasiswa ke-3:" << endl;
    cout << "Nama: ";
    getline(cin, nama);
    cout << "NIM : ";
    getline(cin, nim);
    enqueueAntrian(head, nama, nim);

    // Menampilkan antrian awal
    cout << "\nAntrian Awal:" << endl;
    viewQueue(head);
    cout << "Jumlah antrian: " << countQueue(head) << " mahasiswa" << endl;

    return 0;
}
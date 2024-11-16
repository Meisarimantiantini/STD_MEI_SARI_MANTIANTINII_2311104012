#include <iostream>
#include <string>
using namespace std;

// struktur nodenya
struct Mahasiswa {
    string nama;
    string nim;
};

// struktur elemen listnya
struct Node {
    Mahasiswa data;    // Menyimpan data mahasiswa 
    Node* next;        // Pointer ke elemen berikutnya
};

// Fungsi buat alokasi node baru
Node* alokasi(string nama, string nim) {
    Node* newNode = new Node;
    if (newNode != nullptr) {
        newNode->data.nama = nama; //data new node diisi sama data nama dan nim
        newNode->data.nim = nim;
        newNode->next = nullptr; //nextnya null
    }
    return newNode;
}

// Fungsi buat dealokasi node
void dealokasi(Node* node) {
    delete node;
}

// Fungsi buat ngecek apakah list kosong
bool isListEmpty(Node* head) {
    return head == nullptr;
}

// Fungsi buat ngecek apakah Mhs penuh (maksimal 5)
bool isListFull(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count >= 5;  // Maksimal 5 Mhs
}

// Fungsi buat menambah Mhs (enqueue)
void enqueueMhs(Node* &head, string nama, string nim) {
    if (isListFull(head)) {
        cout << "Mhs penuh" << endl;
        return;
    }

    Node* newNode = alokasi(nama, nim); //bikin obj baru trus manggil fungsi alokasi dgn param nama dn nim dikirim
    if (newNode != nullptr) {
        if (isListEmpty(head)) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Fungsi buat mengurangi Mhs (dequeue)
void dequeueMhs(Node* &head) {
    if (isListEmpty(head)) {
        cout << "Mhs kosong" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    cout << "Mahasiswa dengan nama " << temp->data.nama 
         << " dan NIM " << temp->data.nim 
         << " telah selesai dalam Mhs." << endl;
    dealokasi(temp);
}

// Fungsi buat menghitung jumlah Mhs
int countQueue(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi buat menghapus semua Mhs
void clearQueue(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        dealokasi(temp);
    }
    cout << "Semua Mhs telah dihapus." << endl;
}

// Fungsi buat menampilkan Mhs
void viewQueue(Node* head) {
    cout << "\nData Mhs Mahasiswa:" << endl;
    cout << "=================================" << endl;
    Node* temp = head;
    for (int i = 0; i < 5; i++) {  // Maksimal 5 Mhs
        if (temp != nullptr) {
            cout << i + 1 << ". Nama: " << temp->data.nama 
                 << "\n   NIM : " << temp->data.nim << endl;
            temp = temp->next;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
        cout << "---------------------------------" << endl;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi list kosong
    
    // Test fungsi-fungsi
    cout << "=== Program Mahasiswa ===" << endl;
    
    // Menambah beberapa mahasiswa ke Mhs
    enqueueMhs(head, "mei sari", "22001");
    enqueueMhs(head, "prajna", "22002");
    enqueueMhs(head, "sofia", "22003");
    
    // Menampilkan Mhs awal
    cout << "\nData mahasiswa:" << endl;
    viewQueue(head);
    cout << "Jumlah mahasiswa: " << countQueue(head) << " mahasiswa" << endl;
    
    // Menambah mahasiswa baru
    cout << "\nMenambah mahasiswa baru:" << endl;
    enqueueMhs(head, "David Lee", "22004");
    viewQueue(head);
    cout << "Jumlah Mhs: " << countQueue(head) << " mahasiswa" << endl;
    
    return 0;
}
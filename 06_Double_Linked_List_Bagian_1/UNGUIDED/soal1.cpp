#include <iostream>
#include <string>

using namespace std;

// Struktur untuk Node
struct Node {
    int idBuku;
    string judulBuku;
    string penulisBuku;
    Node* prev;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* buatNode(int id, string judul, string penulis) {
    Node* newNode = new Node();
    newNode->idBuku = id;
    newNode->judulBuku = judul;
    newNode->penulisBuku = penulis;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan buku di akhir linked list
void tambahBuku(Node*& head, Node*& tail, int id, string judul, string penulis) {
    Node* bukuBaru = buatNode(id, judul, penulis);
    if (head == nullptr) {  // Jika linked list kosong
        head = tail = bukuBaru;
    } else {
        tail->next = bukuBaru;
        bukuBaru->prev = tail;
        tail = bukuBaru;
    }
    cout << "Buku berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan semua buku dari awal ke akhir
void tampilkanBukuDariAwal(Node* head) {
    if (head == nullptr) {
        cout << "Daftar buku kosong!" << endl;
        return;
    }
    Node* temp = head;
    cout << "Daftar buku dari awal ke akhir:" << endl;
    while (temp != nullptr) {
        cout << "ID Buku: " << temp->idBuku << ", Judul: " << temp->judulBuku
             << ", Penulis: " << temp->penulisBuku << endl;
        temp = temp->next;
    }
}

// Fungsi untuk menampilkan semua buku dari akhir ke awal
void tampilkanBukuDariAkhir(Node* tail) {
    if (tail == nullptr) {
        cout << "Daftar buku kosong!" << endl;
        return;
    }
    Node* temp = tail;
    cout << "Daftar buku dari akhir ke awal:" << endl;
    while (temp != nullptr) {
        cout << "ID Buku: " << temp->idBuku << ", Judul: " << temp->judulBuku
             << ", Penulis: " << temp->penulisBuku << endl;
        temp = temp->prev;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int pilihan, id;
    string judul, penulis;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku dari Awal ke Akhir\n";
        cout << "3. Tampilkan Buku dari Akhir ke Awal\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID Buku: ";
                cin >> id;
                cin.ignore();  // Mengabaikan karakter '\n'
                cout << "Masukkan Judul Buku: ";
                getline(cin, judul);
                cout << "Masukkan Penulis Buku: ";
                getline(cin, penulis);
                tambahBuku(head, tail, id, judul, penulis);
                break;

            case 2:
                tampilkanBukuDariAwal(head);
                break;

            case 3:
                tampilkanBukuDariAkhir(tail);
                break;

            case 4:
                cout << "Keluar dari program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}

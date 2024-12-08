#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judulBuku;
    string tanggalPengembalian;
    Buku* next;
};

struct Anggota {
    string namaAnggota;
    string idAnggota;
    Buku* headBuku;
    Anggota* next;
};

Anggota* headAnggota = nullptr;

void tambahAnggota(string nama, string id) {
    Anggota* anggotaBaru = new Anggota{nama, id, nullptr, nullptr};
    if (!headAnggota) {
        headAnggota = anggotaBaru;
    } else {
        Anggota* temp = headAnggota;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = anggotaBaru;
    }
}

Anggota* cariAnggota(string id) {
    Anggota* temp = headAnggota;
    while (temp) {
        if (temp->idAnggota == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void tambahBuku(string idAnggota, string judul, string tanggal) {
    Anggota* anggota = cariAnggota(idAnggota);
    if (anggota) {
        Buku* bukuBaru = new Buku{judul, tanggal, nullptr};
        if (!anggota->headBuku) {
            anggota->headBuku = bukuBaru;
        } else {
            Buku* temp = anggota->headBuku;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = bukuBaru;
        }
    }
}

void tampilkanData() {
    Anggota* tempAnggota = headAnggota;
    while (tempAnggota) {
        cout << "Anggota: " << tempAnggota->namaAnggota << " (ID: " << tempAnggota->idAnggota << ")\n";
        Buku* tempBuku = tempAnggota->headBuku;
        while (tempBuku) {
            cout << "  - Buku: " << tempBuku->judulBuku << ", Pengembalian: " << tempBuku->tanggalPengembalian << endl;
            tempBuku = tempBuku->next;
        }
        tempAnggota = tempAnggota->next;
        cout << endl;
    }
}

int main() {
    // Tambah anggota
    tambahAnggota("Rani", "A001");
    tambahAnggota("Dito", "A002");
    tambahAnggota("Vina", "A003");

    // Tambah buku dipinjam
    tambahBuku("A001", "Pemrograman C++", "01/12/2024");
    tambahBuku("A002", "Algoritma Pemrograman", "15/12/2024");

    // Tambah buku baru
    tambahBuku("A001", "Struktur Data", "10/12/2024");

    // Tampilkan data
    tampilkanData();

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct Proyek {
    string namaProyek;
    int durasi;
    Proyek* next;
};

struct Pegawai {
    string namaPegawai;
    string idPegawai;
    Proyek* headProyek;
    Pegawai* next;
};

Pegawai* headPegawai = nullptr;

void tambahPegawai(string nama, string id) {
    Pegawai* pegawaiBaru = new Pegawai{nama, id, nullptr, nullptr};
    if (!headPegawai) {
        headPegawai = pegawaiBaru;
    } else {
        Pegawai* temp = headPegawai;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = pegawaiBaru;
    }
}

Pegawai* cariPegawai(string id) {
    Pegawai* temp = headPegawai;
    while (temp) {
        if (temp->idPegawai == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void tambahProyek(string idPegawai, string namaProyek, int durasi) {
    Pegawai* pegawai = cariPegawai(idPegawai);
    if (pegawai) {
        Proyek* proyekBaru = new Proyek{namaProyek, durasi, nullptr};
        if (!pegawai->headProyek) {
            pegawai->headProyek = proyekBaru;
        } else {
            Proyek* temp = pegawai->headProyek;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = proyekBaru;
        }
    }
}

void hapusProyek(string idPegawai, string namaProyek) {
    Pegawai* pegawai = cariPegawai(idPegawai);
    if (pegawai) {
        Proyek* temp = pegawai->headProyek;
        Proyek* prev = nullptr;
        while (temp && temp->namaProyek != namaProyek) {
            prev = temp;
            temp = temp->next;
        }
        if (temp) {
            if (prev) {
                prev->next = temp->next;
            } else {
                pegawai->headProyek = temp->next;
            }
            delete temp;
        }
    }
}

void tampilkanData() {
    Pegawai* tempPegawai = headPegawai;
    while (tempPegawai) {
        cout << "Pegawai: " << tempPegawai->namaPegawai << " (ID: " << tempPegawai->idPegawai << ")\n";
        Proyek* tempProyek = tempPegawai->headProyek;
        while (tempProyek) {
            cout << "  - Proyek: " << tempProyek->namaProyek << ", Durasi: " << tempProyek->durasi << " bulan\n";
            tempProyek = tempProyek->next;
        }
        tempPegawai = tempPegawai->next;
        cout << endl;
    }
}

int main() {
    // Tambah data pegawai
    tambahPegawai("Andi", "P001");
    tambahPegawai("Budi", "P002");
    tambahPegawai("Citra", "P003");

    // Tambah proyek ke pegawai
    tambahProyek("P001", "Aplikasi Mobile", 12);
    tambahProyek("P002", "Sistem Akuntansi", 8);
    tambahProyek("P003", "E-commerce", 10);

    // Tambah proyek baru
    tambahProyek("P001", "Analisis Data", 6);

    // Hapus proyek
    hapusProyek("P001", "Aplikasi Mobile");

    // Tampilkan data
    tampilkanData();

    return 0;
}

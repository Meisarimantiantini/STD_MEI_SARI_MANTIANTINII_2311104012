#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    float uts, uas, tugas, nilaiAkhir;
};

void inputData(Mahasiswa& mhs) {
    cout << "Masukkan nama mahasiswa: ";
    cin >> mhs.nama;
    cout << "Masukkan nilai UTS: ";
    cin >> mhs.uts;
    cout << "Masukkan nilai UAS: ";
    cin >> mhs.uas;
    cout << "Masukkan nilai Tugas: ";
    cin >> mhs.tugas;
    
    mhs.nilaiAkhir = (0.3 * mhs.uts) + (0.4 * mhs.uas) + (0.3 * mhs.tugas);
}

void tampilData(Mahasiswa mhs) {
    cout << "Nama: " << mhs.nama << endl;
    cout << "Nilai Akhir: " << mhs.nilaiAkhir << endl;
}

int main() {
    Mahasiswa mahasiswa[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        inputData(mahasiswa[i]);
    }

    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < jumlah; i++) {
        tampilData(mahasiswa[i]);
        cout << endl;
    }

    return 0;
}
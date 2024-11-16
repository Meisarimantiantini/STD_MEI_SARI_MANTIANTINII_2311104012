#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // Add this library

using namespace std;

void cariMaksMinRata() {
    int jumlahElemen;
    cout << "Masukkan jumlah elemen: ";
    cin >> jumlahElemen;

    vector<double> array;
    for (int i = 0; i < jumlahElemen; i++) {
        double elemen;
        cout << "Masukkan elemen " << i + 1 << ": ";
        cin >> elemen;
        array.push_back(elemen);
    }

    // Cari nilai maksimum
    double nilaiMaks = *max_element(array.begin(), array.end());
    cout << "Nilai maksimum: " << nilaiMaks << endl;

    // Cari nilai minimum
    double nilaiMin = *min_element(array.begin(), array.end());
    cout << "Nilai minimum: " << nilaiMin << endl;

    // Cari nilai rata-rata
    double sum = 0.0;
    for (double elemen : array) {
        sum += elemen;
    }
    double nilaiRata = sum / jumlahElemen;
    cout << "Nilai rata-rata: " << fixed << std::setprecision(2) << nilaiRata << endl; // Fix the setprecision
}

int main() {
    while (true) {
        cout << "Menu Program:" << endl;
        cout << "1. Cari nilai maksimum, minimum, dan rata-rata" << endl;
        cout << "2. Keluar" << endl;
        int pilihan;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        if (pilihan == 1) {
            cariMaksMinRata();
        } else if (pilihan == 2) {
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
    return 0;
}
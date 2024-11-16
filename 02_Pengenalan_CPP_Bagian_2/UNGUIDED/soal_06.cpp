#include <iostream>
using namespace std;

int main() {
    int dimensi1, dimensi2, dimensi3;
    cout << "Masukkan ukuran dimensi 1: ";
    cin >> dimensi1;
    cout << "Masukkan ukuran dimensi 2: ";
    cin >> dimensi2;
    cout << "Masukkan ukuran dimensi 3: ";
    cin >> dimensi3;

    int ***array = new int**[dimensi1];
    for (int i = 0; i < dimensi1; i++) {
        array[i] = new int*[dimensi2];
        for (int j = 0; j < dimensi2; j++) {
            array[i][j] = new int[dimensi3];
        }
    }

    for (int i = 0; i < dimensi1; i++) {
        for (int j = 0; j < dimensi2; j++) {
            for (int k = 0; k < dimensi3; k++) {
                cout << "Masukkan elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array[i][j][k];
            }
        }
    }

    cout << endl;
    cout << "Array 3D: " << endl;
    for (int i = 0; i < dimensi1; i++) {
        for (int j = 0; j < dimensi2; j++) {
            for (int k = 0; k < dimensi3; k++) {
                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < dimensi1; i++) {
        for (int j = 0; j < dimensi2; j++) {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
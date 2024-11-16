#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen " << i + 1 << ": ";
        cin >> array[i];
    }

    cout << endl;
    cout << "Bilangan genap: ";
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            cout << array[i] << " ";
        }
    }

    cout << endl;
    cout << "Bilangan ganjil: ";
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 != 0) {
            cout << array[i] << " ";
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int jumlahSimpul;

    // Meminta jumlah simpul
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> simpul(jumlahSimpul);

    cout << "Silakan masukkan nama simpul:\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    vector<vector<int>> jarak(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Silakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            if (i != j) {
                cout << simpul[i] << " --> " << simpul[j] << ": ";
                cin >> jarak[i][j];
            }
        }
    }
 
    cout << "\nMatriks Jarak:\n     ";
    for (const string& s : simpul) {
        cout << s << "  ";
    }
    cout << "\n";

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << simpul[i] << "  ";
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << jarak[i][j] << "    ";
        }
        cout << "\n";
    }

    return 0;
}

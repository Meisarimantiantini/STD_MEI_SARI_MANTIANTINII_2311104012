#include <iostream>
#include "stack.h"
using namespace std;

void printStackMessage(stack &S, const char* message);

int main() {
    stack S;
    createStack(S);

    int nimLastDigit;
    cout << "Masukkan digit terakhir NIM Anda: ";
    cin >> nimLastDigit;
    nimLastDigit %= 4;

    // Menentukan kata berdasarkan digit terakhir NIM MOD 4
    switch(nimLastDigit) {
        case 0: // Digit terakhir NIM MOD 4 sisa 0
            // Masukkan "I F L A B J A Y A"
            push(S, 'I');
            push(S, 'F');
            push(S, 'L');
            push(S, 'A');
            push(S, 'B');
            push(S, 'J');
            push(S, 'A');
            push(S, 'Y');
            push(S, 'A');
            printStackMessage(S, "Isi stack awal: ");
            
            // Pop untuk meninggalkan kata "J A Y A"
            for (int i = 0; i < 5; i++) pop(S);
            printStackMessage(S, "Isi stack sesudah pop: ");
            break;

        case 1: // Digit terakhir NIM MOD 4 sisa 1
            // Masukkan "H A L O B A N D U N G"
            push(S, 'H');
            push(S, 'A');
            push(S, 'L');
            push(S, 'O');
            push(S, 'B');
            push(S, 'A');
            push(S, 'N');
            push(S, 'D');
            push(S, 'U');
            push(S, 'N');
            push(S, 'G');
            printStackMessage(S, "Isi stack awal: ");

            // Pop untuk meninggalkan kata "B A N D U N G"
            for (int i = 0; i < 4; i++) pop(S);
            printStackMessage(S, "Isi stack sesudah pop: ");
            break;

        case 2: // Digit terakhir NIM MOD 4 sisa 2
            // Masukkan "P E R C A Y A D I R I"
            push(S, 'P');
            push(S, 'E');
            push(S, 'R');
            push(S, 'C');
            push(S, 'A');
            push(S, 'Y');
            push(S, 'A');
            push(S, 'D');
            push(S, 'I');
            push(S, 'R');
            push(S, 'I');
            printStackMessage(S, "Isi stack awal: ");

            // Pop untuk meninggalkan kata "D I R I"
            for (int i = 0; i < 7; i++) pop(S);  // Perbaiki menjadi 7 kali
            printStackMessage(S, "Isi stack sesudah pop: ");
            break;

        case 3: // Digit terakhir NIM MOD 4 sisa 3
            // Masukkan "S T R U K T U R D A T A"
            push(S, 'S');
            push(S, 'T');
            push(S, 'R');
            push(S, 'U');
            push(S, 'K');
            push(S, 'T');
            push(S, 'U');
            push(S, 'R');
            push(S, 'D');
            push(S, 'A');
            push(S, 'T');
            push(S, 'A');
            printStackMessage(S, "Isi stack awal: ");

            // Pop untuk meninggalkan kata "D A T A"
            for (int i = 0; i < 8; i++) pop(S);  // Perbaiki menjadi 8 kali
            printStackMessage(S, "Isi stack sesudah pop: ");
            break;

        default:
            cout << "Digit terakhir NIM tidak valid." << endl;
            break;
    }

    return 0;
}

// Fungsi untuk mencetak pesan dan isi stack
void printStackMessage(stack &S, const char* message) {
    cout << message;
    printInfo(S);
}

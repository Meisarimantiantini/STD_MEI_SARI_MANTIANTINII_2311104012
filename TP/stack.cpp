#include "stack.h"
#include <iostream>
using namespace std;

// Inisialisasi stack (membuat stack kosong)
void createStack(stack &S) {
    S.Top = 0;  
}

// Mengecek apakah stack kosong
bool isEmpty(stack S) {
    return S.Top == 0;  
}

// Mengecek apakah stack penuh
bool isFull(stack S) {
    return S.Top == 15;  
}

// Menambahkan elemen ke stack (push)
void push(stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh, tidak bisa menambahkan elemen baru." << endl;
    } else {
        S.info[S.Top] = x; 
        S.Top++;            
    }
}

// Menghapus elemen dari stack (pop)
int pop(stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong, tidak ada elemen yang bisa dihapus." << endl;
        return -1;  // Mengembalikan -1 jika stack kosong
    } else {
        S.Top--;                   // Menurunkan Top
        infotype x = S.info[S.Top]; // Simpan elemen yang dihapus
        S.info[S.Top] = '\0';       // Hapus elemen dari stack
        return x;                   // Mengembalikan elemen yang dihapus
    }
}



// Mencetak semua elemen dalam stack
void printInfo(stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Isi stack: ";
        for (int i = 0; i < S.Top; i++) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

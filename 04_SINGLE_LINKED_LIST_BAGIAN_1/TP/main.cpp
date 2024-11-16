#include <iostream>
#include "list.h"
using namespace std;

// int main() {
//     List L;
//     createList(L); // 1. Memanggil createList
    
//     // 2. Memanggil allocate untuk 3 digit terakhir NIM dan masukkan ke dalam list
//     address P1 = allocate(0);   
//     address P2 = allocate(1);   
//     address P3 = allocate(2);   

//     // 3. Memanggil insertFirst agar elemen masuk ke list di urutan terbalik
//     insertFirst(L, P1);
//     insertFirst(L, P2);
//     insertFirst(L, P3);

//     // 4. Memanggil procedure printInfo untuk menampilkan isi List
//     cout << "Isi List (harus terbalik): ";
//     printInfo(L);

//     return 0;
// }


int main() {
    List L;
    createList(L); 
    int nim[10] = {2, 3, 1, 1, 1, 0, 4, 0, 1, 2}; 

    // 2. Menggunakan looping untuk memasukkan setiap digit NIM
    for (int i = 0; i < 10; i++) {
        address P = allocate(nim[i]); 
        insertLast(L, P); 
    }

    // 3. Memanggil procedure printInfo untuk menampilkan isi List
    cout << "Isi List: ";
    printInfo(L); // Output: 2 3 1 1 1 0 4 0 1 2

    return 0;
}

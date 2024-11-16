#include "pelajaran.h"
#include <iostream>

using namespace std;

int main() {
    // Mendeklarasikan nama pelajaran dan kode pelajaran
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    // Membuat ADT pelajaran
    pelajaran pel = create_pelajaran(namaPel, kodePel);

    // Menampilkan informasi pelajaran
    tampil_pelajaran(pel);

    return 0;
}

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>

using namespace std;

// ADT pelajaran
typedef struct {
    string namaPel;   
    string kodePel;   
} pelajaran;

// Fungsi untuk membuat pelajaran baru
pelajaran create_pelajaran(string namaPel, string kodePel);

// Prosedur untuk menampilkan pelajaran
void tampil_pelajaran(pelajaran pel);

#endif

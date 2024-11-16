#include "pelajaran.h"
#include <iostream>

using namespace std;

pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran pel;
    pel.namaPel = namaPel;
    pel.kodePel = kodePel;
    return pel;
}

// Implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaPel << endl;
    cout << "nilai : " << pel.kodePel << endl;
}

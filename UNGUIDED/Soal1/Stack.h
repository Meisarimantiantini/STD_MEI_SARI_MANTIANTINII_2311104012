#ifndef STACK_H
#define STACK_H

const int MAKS = 20;
typedef int Infotype;

struct Tumpukan {
    Infotype info[MAKS];
    int atas;
};

void buatTumpukan(Tumpukan &S);
bool kosong(const Tumpukan &S);
bool penuh(const Tumpukan &S);
void push(Tumpukan &S, Infotype x);
Infotype pop(Tumpukan &S);
void cetakInfo(const Tumpukan &S);
void balikTumpukan(Tumpukan &S);

#endif

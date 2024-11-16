#include "stack.h"
#include <iostream>
using namespace std;

void buatTumpukan(Tumpukan &S) {
    S.atas = -1;
}

bool kosong(const Tumpukan &S) {
    return S.atas == -1;
}

bool penuh(const Tumpukan &S) {
    return S.atas == MAKS - 1;
}

void push(Tumpukan &S, Infotype x) {
    if (!penuh(S)) {
        S.info[++S.atas] = x;
    } else {
        cout << "Tumpukan penuh" << endl;
    }
}

Infotype pop(Tumpukan &S) {
    if (!kosong(S)) {
        return S.info[S.atas--];
    } else {
        cout << "Tumpukan kosong" << endl;
        return -1; // nilai penanda saat tumpukan kosong
    }
}

void cetakInfo(const Tumpukan &S) {
    if (!kosong(S)) {
        for (int i = S.atas; i >= 0; i--) {
            cout << "[ATAS] " << S.info[i] << endl;
        }
    } else {
        cout << "Tumpukan kosong" << endl;
    }
}

void balikTumpukan(Tumpukan &S) {
    Tumpukan temp;
    buatTumpukan(temp);
    
    while (!kosong(S)) {
        push(temp, pop(S));
    }
    
    S = temp;
}

void pushAscending(Tumpukan &S, Infotype x) {
    if (kosong(S) || x >= S.info[S.atas]) {
        push(S, x);
    } else {
        Infotype temp = pop(S);
        pushAscending(S, x);
        push(S, temp);
    }
}

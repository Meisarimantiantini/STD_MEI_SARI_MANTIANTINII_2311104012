#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Tumpukan S;
    buatTumpukan(S);

    push(S, 3);
    push(S, 4);
    push(S, 9);

    cout << "balik tumpukan" << endl;
    balikTumpukan(S);
    cetakInfo(S);

    return 0;
}

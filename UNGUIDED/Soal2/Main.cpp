#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Tumpukan S;
    buatTumpukan(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 3);
    pushAscending(S, 9);
    pushAscending(S, 2);
    pushAscending(S, 5);
    pushAscending(S, 8);
    pushAscending(S, 9);

    cetakInfo(S);
    
    cout << "balik stack" << endl;
    balikTumpukan(S);
    cetakInfo(S);

    return 0;
}

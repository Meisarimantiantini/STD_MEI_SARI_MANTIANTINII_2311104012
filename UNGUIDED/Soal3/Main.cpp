#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Tumpukan S;
    buatTumpukan(S);

    getInputStream(S);
    cetakInfo(S);
    
    cout << "balik stack" << endl;
    balikTumpukan(S);
    cetakInfo(S);

    return 0;
}

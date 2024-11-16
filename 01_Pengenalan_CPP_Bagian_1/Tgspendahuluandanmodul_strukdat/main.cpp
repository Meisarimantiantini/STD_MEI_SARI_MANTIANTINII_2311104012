//#include <iostream>

//using namespace std;

//int main(){
//    string nama, nim;
//    cout << "Siapa nama anda? ";
//    cin >> nama;
//    cout << "Berapa nim anda? ";
//    cin >> nim;
//    cout << "Nama saya:" << nama << endl;
//    cout << "NIM saya:" << nim << endl;
//    return 0;

//-------------------------------------------------//

//int bil1 = 3, bil2 = 4, hasil1;
//    float bil3 = 3.0, bil4 = 4.0, hasil2;
//    hasil1 = bil1 + bil2;
//    cout << hasil1 << endl;
//    hasil1 = bil1 - bil2;
//    cout << hasil1 << endl;
//    hasil1 = bil1 * bil2;   // integer division
//    cout << hasil1 << endl;
//    hasil1 = bil2 / bil1;   // integer division
//    cout << hasil1 << endl;
//    hasil1 = bil1 % bil2;   // modulo
//    cout << hasil1 << endl;
//    hasil1 = bil2 % bil1;   // modulo
//    cout << hasil1 << endl;
//    hasil2 = bil3 / bil4;
//    cout << hasil2 << endl;
//    return 0;

//-------------------------------------------------------//


//    int bil1 = 2, bil2 = 3, hasil;
//    hasil = bil1 > bil2;
//    cout << hasil << endl;
//    hasil = bil1 >= bil2;
//    cout << hasil << endl;
//    hasil = bil1 < bil2;
//    cout << hasil << endl;
//    hasil = bil1 <= bil2;
//    cout << hasil << endl;
//    hasil = bil1 == bil2;
//    cout << hasil << endl;
//    hasil = bil1 != bil2;
//    cout << hasil << endl;
//    return 0;

//----------------------------------------------------------//

//    int bil1 = 2, bil2 = 3, hasil;
//    hasil = bil1 <= bil2 and bil1 < bil2;
//    cout << hasil << endl;
//      hasil = bil1 >= bil2 or bil1 < bil2;
//      cout << hasil << endl;
//    hasil = not(bil1 >= bil2) or bil1 < bil2;
//    cout << hasil << endl;
//    return 0;

//-----------------------------------------------------------//

//    int nilai;
//    cin >> nilai;
//    if (nilai > 80) {
//        cout << "A" << endl;
//    } else {
//        cout << "Bukan A" << endl;
//    }
//    return 0;

//------------------------------------------------------------//

//    int a, b, bilangan;
//    cout << "Masukkan batas bawah: ";
//    cin >> a;
//    cout << "Masukkan batas atas: ";
//    cin >> b;
//    for (bilangan = a; bilangan <= b; bilangan++) {
//            cout << "bilangan " << bilangan << endl;
//    }
//    return 0;

//--------------------------------------------------------------//

//    int bilangan, asli, jumlah;

//    cout << "masukkan bilangan asli: ";
//    cin >> asli;

//    bilangan = 1;
//    jumlah = 0;
//    while (bilangan <= asli) {
//        if (bilangan % 2 == 0) {
//            jumlah += bilangan;
//        }
//        bilangan++;
//    }
//    cout << "jumlah bilangan genap: " <<jumlah << endl;
//    return 0;

//-------------------------------------------------------------//
// latihan modul



//    float num1, num2;

//    cout << "Masukkan dua bilangan (float): ";
//    cin >> num1 >> num2;

    // Perform calculations
//    float penjumlahan = num1 + num2;
//    float pengurangan = num1 - num2;
//    float perkalian = num1 * num2;
//    float pembagian = num1 / num2;


//    cout << "Hasil Penjumlahan: " << penjumlahan << endl;
//    cout << "Hasil Pengurangan: " << pengurangan << endl;
//    cout << "Hasil Perkalian: " << perkalian << endl;
//   cout << "Hasil Pembagian: " << pembagian << endl;

//    return 0;

//------------------------------------------------------------------//


#include <string>

using namespace std;

string ones[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string tens[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
string hundreds[] = {"", "seratus"};

string convertNumberToWords(int num) {
    if (num < 10) {
        return ones[num];
    } else if (num < 20) {
        switch (num) {
            case 10:
                return "sepuluh";
            case 11:
                return "sebelas";
            case 12:
                return "dua belas";
            case 13:
                return "tiga belas";
            case 14:
                return "empat belas";
            case 15:
                return "lima belas";
            case 16:
                return "enam belas";
            case 17:
                return "tujuh belas";
            case 18:
                return "delapan belas";
            case 19:
                return "sembilan belas";
        }
    } else if (num < 100) {
        return tens[num / 10] + (num % 10 > 0 ? " " + ones[num % 10] : "");
    } else if (num == 100) {
        return "seratus";
    }
    return "";
}

int main() {
    int num;
    cout << "Enter a number between 0 and 100: ";
    cin >> num;
    if (num >= 0 && num <= 100) {
        cout << "The written form of " << num << " is: " << convertNumberToWords(num) << endl;
    } else {
        cout << "Invalid input. Please enter a number between 0 and 100." << endl;
    }
    return 0;
}








//------------------------------------------------------------------//


//    int n;
//    cout << "Input: ";
//    cin >> n;

    // Loop untuk baris
//    for (int i = n; i >= 1; i--) {
        // Loop untuk bagian kiri
//        for (int j = i; j >= 1; j--) {
//            cout << j;
//        }

        // Cetak tanda *
//        cout << "*";

        // Loop untuk bagian kanan
//        for (int j = 1; j <= i; j++) {
//            cout << j;
//        }

//        cout << endl;
//    }

//    return 0;

//}





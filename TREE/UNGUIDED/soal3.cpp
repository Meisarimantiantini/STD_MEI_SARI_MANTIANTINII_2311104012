#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};


Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Fungsi rekursif untuk menghitung jumlah simpul daun
int cari_simpul_daun(Node* node) {
    // Jika node kosong, maka tidak ada simpul daun
    if (!node) return 0;

    // Jika node adalah simpul daun 
    if (!node->left && !node->right) return 1;

    // Rekursif ke subtree kiri dan kanan, jumlahkan hasilnya
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

// Pengujian fungsi
int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(7);
    root->right->right = newNode(20);

    cout << "Jumlah simpul daun dalam pohon: " << cari_simpul_daun(root) << endl;

    return 0;
}

#include <iostream>
#include <limits.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Fungsi untuk membuat node baru
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Fungsi rekursif untuk memeriksa apakah pohon adalah BST yang valid
bool is_valid_bst(Node* node, int min_val, int max_val) {
    if (!node) return true; // Node kosong dianggap valid sebagai BST

    // Periksa apakah data node melanggar batasan min/max
    if (node->data <= min_val || node->data >= max_val) return false;

    // Periksa subtree kiri dan kanan dengan batasan yang diperbarui
    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

// Fungsi pembungkus untuk menyederhanakan pemanggilan awal
bool is_valid_bst(Node* root) {
    return is_valid_bst(root, INT_MIN, INT_MAX);
}

// Pengujian kasus
int main() {
    // Pohon BST yang valid
    Node* root1 = newNode(10);
    root1->left = newNode(5);
    root1->right = newNode(15);
    root1->left->left = newNode(2);
    root1->left->right = newNode(7);
    root1->right->right = newNode(20);

    // Pohon yang tidak valid sebagai BST (node 12 salah tempat)
    Node* root2 = newNode(10);
    root2->left = newNode(5);
    root2->right = newNode(15);
    root2->left->left = newNode(2);
    root2->left->right = newNode(12); // Melanggar aturan BST
    root2->right->right = newNode(20);

    cout << "Pohon 1 adalah " << (is_valid_bst(root1) ? "BST yang valid" : "bukan BST yang valid") << endl;
    cout << "Pohon 2 adalah " << (is_valid_bst(root2) ? "BST yang valid" : "bukan BST yang valid") << endl;

    return 0;
}

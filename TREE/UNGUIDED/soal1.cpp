#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat jadi root" << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

Pohon* insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree dulu." << endl;
        return NULL;
    }

    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri." << endl;
        return NULL;
    }

    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

Pohon* insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree dulu!" << endl;
        return NULL;
    }

    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan." << endl;
        return NULL;
    }

    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree dulu!" << endl;
        return;
    }

    if (!node) {
        cout << "\nNode yang ingin diganti tidak ada." << endl;
        return;
    }

    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah jadi " << data << endl;
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree dulu." << endl;
        return;
    }

    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada." << endl;
        return;
    }
    cout << "\nData node: " << node->data << endl;
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree dulu." << endl;
        return;
    }

    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada." << endl;
        return;
    }

    cout << "\nData Node : " << node->data << endl;
    cout << "Root : " << root->data << endl;

    if (node->parent) {
        cout << "Parent : " << node->parent->data << endl;
    } else {
        cout << "Parent : (Tidak ada parent)" << endl;
    }
    if (node->parent) {
        if (node->parent->left == node && node->parent->right)
            cout << "Sibling : " << node->parent->right->data << endl;
        else if (node->parent->right == node && node->parent->left)
            cout << "Sibling : " << node->parent->left->data << endl;
        else
            cout << "Sibling : (Tidak ada sibling)" << endl;
    }
}

void showChildren(Pohon *node) {
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada." << endl;
        return;
    }

    cout << "\nAnak dari node " << node->data << ": ";
    if (node->left)
        cout << "Kiri: " << node->left->data << " ";
    else
        cout << "Kiri: (Tidak ada) ";
    if (node->right)
        cout << "Kanan: " << node->right->data << " ";
    else
        cout << "Kanan: (Tidak ada) ";
    cout << endl;
}

void showDescendants(Pohon *node) {
    if (!node) return;

    if (node->left) {
        cout << node->left->data << " ";
        showDescendants(node->left);
    }
    if (node->right) {
        cout << node->right->data << " ";
        showDescendants(node->right);
    }
}

void menu() {
    int choice;
    char data;
    Pohon *node = nullptr;

    do {
        cout << "\nMenu:\n";
        cout << "1. Buat Root\n";
        cout << "2. Tambah Kiri\n";
        cout << "3. Tambah Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Tampilkan Data Node\n";
        cout << "6. Tampilkan Anak Node\n";
        cout << "7. Tampilkan Semua Keturunan Node\n";
        cout << "8. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data node kiri: ";
                cin >> data;
                cout << "Masukkan node parent: ";
                cin >> node->data;
                node = insertLeft(data, root);
                break;
            case 3:
                cout << "Masukkan data node kanan: ";
                cin >> data;
                cout << "Masukkan node parent: ";
                cin >> node->data;
                node = insertRight(data, root);
                break;
            case 4:
                cout << "Masukkan data baru: ";
                cin >> data;
                update(data, node);
                break;
            case 5:
                cout << "Masukkan data node untuk ditampilkan: ";
                cin >> node->data;
                retrieve(node);
                break;
            case 6:
                cout << "Masukkan data node untuk tampilkan anak-anak: ";
                cin >> node->data;
                showChildren(node);
                break;
            case 7:
                cout << "Masukkan data node untuk tampilkan keturunan: ";
                cin >> node->data;
                cout << "Keturunan dari node " << node->data << ": ";
                showDescendants(node);
                cout << endl;
                break;
            case 8:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (choice != 8);
}

int main() {
    init();
    menu();
    return 0;
}

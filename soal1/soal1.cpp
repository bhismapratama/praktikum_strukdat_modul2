#include <iostream>
using namespace std;

// desk class dulu
class Node {
public:
    int datas;
    Node* kiri;
    Node* kanan;
    Node(int nilai) {
        this->datas = nilai;
        this->kiri = this->kanan = NULL;
    }
};

// fungsi insert node ke BST
Node* insertNode(Node* root, int nilai) {
    if (root == NULL) {
        return new Node(nilai);
    }

    if (nilai < root->datas) {
        root->kiri = insertNode(root->kiri, nilai);
    } else {
        root->kanan = insertNode(root->kanan, nilai);
    }

    return root;
}

// Traversal Inorder fungsi
void cetakInorder(Node* node) {
    if (node == NULL)
        return;
    // kiri subtree
    cetakInorder(node->kiri);
    // lihat node + space
    cout << node->datas << " ";
    // kanan subtree
    cetakInorder(node->kanan);
}

// Initialisasi fungsi main
int main() {
    // buat tree dulu
    Node* root = NULL;

    for (int i = 0; i < 10; i++) {
        int output;
        cin >> output;

        // pokonya angka ga dimulai dengan nol
        if (output < 1 || (output >= 10 && output % 10 == 0)) {
            cout << "jangan nol bang, ketik lagi: ";
            cin >> output;
        }

        root = insertNode(root, output);
    }

    // hasil
    cetakInorder(root);

    return 0;
}

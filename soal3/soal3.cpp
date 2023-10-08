#include <iostream>
using namespace std;

// desk class dulu
class Node {
public:
    string datas;
    Node* kiri;
    Node* kanan;
    Node(string nama) {
        this->datas = nama;
        this->kiri = this->kanan = NULL;
    }
};

// Inorder Traversal
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

// fungsi insertNode node ke BST
Node* insertNode(Node* root, string nama) {
    if (root == NULL)
        return new Node(nama);

    if (nama < root->datas)
        root->kiri = insertNode(root->kiri, nama);
    else if (nama > root->datas)
        root->kanan = insertNode(root->kanan, nama);

    return root;
}

// Initialisasi fungsi main
int main() {
    // nama dari input
    string nama;
    Node* root = NULL;

    // membaca input satu per satu dan masukkan ke dalam BST
    while (cin >> nama) {
        root = insertNode(root, nama);
    }

    // hasil
    cetakInorder(root);

    return 0;
}

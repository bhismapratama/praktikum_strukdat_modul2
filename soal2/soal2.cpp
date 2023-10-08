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

// fungsi insert node
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

// cek kalau node tidak ada child
bool check(Node* node) {
    return (node->kiri == NULL && node->kanan == NULL);
}

void nodeNoChild(Node* node) {
    if (node == NULL)
        return;

    if (check(node))
        cout << node->datas << " ";

    nodeNoChild(node->kiri);
    nodeNoChild(node->kanan);
}


int main() {
    int angka;
    cin >> angka;

    // check constraint
    if (angka > 1000) {
        cout << "bang udah bang" << endl;
        return 0;
    }

    Node* root = NULL;

    for (int i = 0; i < angka; i++) {
        int nilai;
        cin >> nilai;
        root = insertNode(root, nilai);
    }

    // cetak hasil tanpa child
    nodeNoChild(root);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// desk class dulu
class Node {
public:
    string datas;
    Node* kiri;
    Node* kanan;
    Node(string value) {
        this->datas = value;
        this->kiri = this->kanan = NULL;
    }
};

// fungsi insertNode node ke BST
void insertNode(Node*& root, string value) {
    if (root == NULL) {
        root = new Node(value);
        return;
    }
    if (value < root->datas) {
        insertNode(root->kiri, value);
    } else {
        insertNode(root->kanan, value);
    }
}

// fungsi preOrderTraversal
void preorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    cout << node->datas << " ";
    preorderTraversal(node->kiri);
    preorderTraversal(node->kanan);
}

// Initialisasi fungsi main
int main() {
    string info;
    getline(cin, info);

    Node* root = NULL;

    for (int i = 0; i < info.length(); i += 2) {
        string value = info.substr(i, 1);
        insertNode(root, value);
    }

    preorderTraversal(root);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    int nilai;
    Node* left;
    Node* right;

    Node(string n, int v) : nama(n), nilai(v), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, string nama, int nilai) {
    if (!root) return new Node(nama, nilai);
    if (nilai < root->nilai)
        root->left = insertNode(root->left, nama, nilai);
    else
        root->right = insertNode(root->right, nama, nilai);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << "Nama: " << root->nama << " | Nilai: " << root->nilai << endl;
    inorder(root->right);
}

Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

int sumNodes(Node* root) {
    if (!root) return 0;
    return root->nilai + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih, nilai;
    string nama;

    do {
        cout << "\n=== SISTEM NILAI AKADEMIK (BST) ===\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Semua Data (Urut Nilai)\n";
        cout << "3. Tampilkan Nilai Tertinggi\n";
        cout << "4. Tampilkan Nilai Terendah\n";
        cout << "5. Hitung Total Nilai Semua Siswa\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan Nilai: ";
            cin >> nilai;
            root = insertNode(root, nama, nilai);
            cout << "Data berhasil ditambahkan!\n";
        } 
        else if (pilih == 2) {
            cout << "\n=== DAFTAR NILAI SISWA (TERURUT) ===\n";
            inorder(root);
        } 
        else if (pilih == 3) {
            Node* maxNode = findMax(root);
            if (maxNode)
                cout << "Nilai tertinggi: " << maxNode->nilai 
                     << " (" << maxNode->nama << ")\n";
            else
                cout << "Data kosong.\n";
        } 
        else if (pilih == 4) {
            Node* minNode = findMin(root);
            if (minNode)
                cout << "Nilai terendah: " << minNode->nilai 
                     << " (" << minNode->nama << ")\n";
            else
                cout << "Data kosong.\n";
        } 
        else if (pilih == 5) {
            int total = sumNodes(root);
            cout << "Total nilai seluruh siswa: " << total << endl;
        } 
        else if (pilih == 6) {
        } 
        else {
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 6);

    return 0;
}

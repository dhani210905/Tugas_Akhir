#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* front = nullptr; 
Node* rear = nullptr;  


void enqueue(string nama) {
    Node* baru = new Node();
    baru->nama = nama;
    baru->next = nullptr;

    if (rear == nullptr) { 
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    cout << "Pelanggan " << nama << " masuk ke antrian.\n";
}


void dequeue() {
    if (front == nullptr) {
        cout << "Antrian kosong. Tidak ada pelanggan yang dilayani.\n";
        return;
    }
    Node* hapus = front;
    cout << "Pelanggan " << hapus->nama << " telah dilayani.\n";
    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete hapus;
}

void peek() {
    if (front == nullptr)
        cout << "Antrian kosong.\n";
    else
        cout << "Pelanggan yang sedang dilayani: " << front->nama << endl;
}

void tampilkan() {
    if (front == nullptr) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "Daftar pelanggan dalam antrian:\n";
    Node* bantu = front;
    int i = 1;
    while (bantu != nullptr) {
        cout << i++ << ". " << bantu->nama << endl;
        bantu = bantu->next;
    }
}

int main() {
    int pilih;
    string nama;

    do {
        cout << "\n=== SISTEM ANTRIAN RESTORAN ===\n";
        cout << "1. Tambah pelanggan (Enqueue)\n";
        cout << "2. Layani pelanggan (Dequeue)\n";
        cout << "3. Lihat pelanggan terdepan (Peek)\n";
        cout << "4. Tampilkan semua antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "Masukkan nama pelanggan: ";
            cin >> nama;
            enqueue(nama);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            tampilkan();
            break;
        case 5:
            cout << "Program selesai. Terima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);

    return 0;
}

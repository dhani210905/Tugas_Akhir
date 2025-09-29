#include <iostream>
#include <string>
using namespace std;

struct Tugas {
    string nama;
    Tugas* next;
};

Tugas* head = nullptr;

void tambahTugas(string nama) {
    Tugas* baru = new Tugas();
    baru->nama = nama;
    baru->next = nullptr;

    if (!head) {
        head = baru;
    } else {
        Tugas* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Tugas \"" << nama << "\" ditambahkan.\n";
}

void hapusTugas(string nama) {
    if (!head) {
        cout << "Daftar kosong.\n";
        return;
    }

    if (head->nama == nama) {
        Tugas* temp = head;
        head = head->next;
        delete temp;
        cout << "Tugas \"" << nama << "\" dihapus.\n";
        return;
    }

    Tugas* temp = head;
    while (temp->next && temp->next->nama != nama) {
        temp = temp->next;
    }

    if (!temp->next) {
        cout << "Tugas \"" << nama << "\" tidak ditemukan.\n";
        return;
    }

    Tugas* hapus = temp->next;
    temp->next = hapus->next;
    delete hapus;
    cout << "Tugas \"" << nama << "\" dihapus.\n";
}

void tampilkanTugas() {
    if (!head) {
        cout << "Daftar kosong.\n";
        return;
    }

    cout << "Daftar Tugas:\n";
    Tugas* temp = head;
    int i = 1;
    while (temp) {
        cout << i++ << ". " << temp->nama << "\n";
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    string nama;

    do {
        cout << "\n=== MENU TO-DO LIST ===\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Hapus Tugas\n";
        cout << "3. Tampilkan Semua Tugas\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            cout << "Masukkan nama tugas: ";
            getline(cin, nama);
            tambahTugas(nama);
        } else if (pilihan == 2) {
            cout << "Masukkan nama tugas yang ingin dihapus: ";
            getline(cin, nama);
            hapusTugas(nama);
        } else if (pilihan == 3) {
            tampilkanTugas();
        } else if (pilihan == 4) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}

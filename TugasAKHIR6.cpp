#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Mahasiswa {
    string nim;
    string nama;
    string status;
};

Mahasiswa dataAbsensi[SIZE];

int hashFunc(string nim) {
    int total = 0;
    for (char c : nim)
        total += c;
    return total % SIZE;
}

void tambahMahasiswa(string nim, string nama) {
    int index = hashFunc(nim);
    dataAbsensi[index].nim = nim;
    dataAbsensi[index].nama = nama;
    dataAbsensi[index].status = "Belum Absen";
}

void isiAbsensi(string nim, string status) {
    int index = hashFunc(nim);
    if (dataAbsensi[index].nim == nim) {
        dataAbsensi[index].status = status;
        cout << "Absensi " << dataAbsensi[index].nama << " berhasil diubah menjadi " << status << endl;
    } else {
        cout << "Data dengan NIM " << nim << " tidak ditemukan!\n";
    }
}

void cariMahasiswa(string nim) {
    int index = hashFunc(nim);
    if (dataAbsensi[index].nim == nim) {
        cout << "NIM   : " << dataAbsensi[index].nim << endl;
        cout << "Nama  : " << dataAbsensi[index].nama << endl;
        cout << "Status: " << dataAbsensi[index].status << endl;
    } else {
        cout << "Data tidak ditemukan!\n";
    }
}

void tampilkanSemua() {
    cout << "\n=== DATA ABSENSI MAHASISWA ===\n";
    for (int i = 0; i < SIZE; i++) {
        if (dataAbsensi[i].nim != "") {
            cout << "NIM: " << dataAbsensi[i].nim
                 << " | Nama: " << dataAbsensi[i].nama
                 << " | Status: " << dataAbsensi[i].status << endl;
        }
    }
}

int main() {
    int pilihan = 0;
    string nim, nama, status;

    tambahMahasiswa("2310001", "Andi");
    tambahMahasiswa("2310002", "Budi");
    tambahMahasiswa("2310003", "Citra");

    do {
        cout << "\n===== MENU ABSENSI MAHASISWA =====\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Isi Absensi\n";
        cout << "3. Cari Mahasiswa\n";
        cout << "4. Tampilkan Semua Data\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan NIM  : ";
            cin >> nim;
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            tambahMahasiswa(nim, nama);
            cout << "Data berhasil ditambahkan!\n";
        } 
        else if (pilihan == 2) {
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Status (Hadir/Izin/Sakit/Alpha): ";
            cin >> status;
            isiAbsensi(nim, status);
        } 
        else if (pilihan == 3) {
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> nim;
            cariMahasiswa(nim);
        } 
        else if (pilihan == 4) {
            tampilkanSemua();
        } 
        else if (pilihan == 5) {
            cout << "Program selesai. Terima kasih!\n";
        } 
        else {
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }

    } while (pilihan != 5);

    return 0;
}

#include <iostream>
using namespace std;

int cariHarga(string nama[], int harga[], int jumlah, string target) {
    int l = 0, r = jumlah - 1;

    while (l <= r) {
        int pos = (l+ r) / 2;

        if (nama[pos] == target) {
            cout << "Harga " << nama[pos] << " adalah Rp " << harga[pos] << endl;
            return 1;
        } 
        else if (nama[pos] < target) {
            l = pos + 1;
        } 
        else {
            r = pos - 1;
        }
    }

    cout << "Barang dengan nama \"" << target << "\" tidak ditemukan." << endl;
    return 0; 
}

int main() {
    string namaBarang[] = {"Buku Tulis", "Kotak Pensil", "Pulpen", "Sepatu", "Tas Sekolah"};
    int hargaBarang[]   = {12000, 20000, 5000, 75000, 45000};
    int jumlah = 5;

    string namaCari;
    cout << "Masukkan nama barang yang ingin dicari: ";
    getline(cin, namaCari);

    cariHarga(namaBarang, hargaBarang, jumlah, namaCari);

    return 0;
}

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Jadwal {
    int jam;        // format 24 jam (contoh: 7 untuk 07:00, 13 untuk 13:00)
    string kegiatan;
};

void bubbleSort(Jadwal arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].jam > arr[j + 1].jam) {
                // tukar posisi
                Jadwal temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah kegiatan hari ini: ";
    cin >> n;
    cin.ignore(); // membersihkan buffer

    Jadwal daftar[n];

    // input kegiatan
    for (int i = 0; i < n; i++) {
        cout << "Masukkan jam kegiatan ke-" << i + 1 << " (format 24 jam, hanya angka): ";
        cin >> daftar[i].jam;
        cin.ignore();
        cout << "Masukkan nama kegiatan: ";
        getline(cin, daftar[i].kegiatan);
    }

    // urutkan jadwal berdasarkan jam
    bubbleSort(daftar, n);

    // tampilkan jadwal terurut
    cout << "\n=== Jadwal Harian Anda ===\n";
    for (int i = 0; i < n; i++) {
        cout << daftar[i].jam << ":00 - " << daftar[i].kegiatan << endl;
    }

    return 0;
}
```

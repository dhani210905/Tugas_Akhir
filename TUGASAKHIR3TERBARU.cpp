#include <iostream>
#include <string>
using namespace std;

void tukarNilai(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void tukarNama(string *a, string *b) {
    string z = *a;
    *a = *b;
    *b = z;
}

int main() {
    int n;
    cout << "Masukkan jumlah siswa: ";
    cin >> n;

    string siswa[n];
    int nilai[n];

    for (int i = 0; i < n; i++) {
        cout << "Nama siswa ke-" << i + 1 << ": ";
        cin >> siswa[i];
        cout << "Nilai rata-rata: ";
        cin >> nilai[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nilai[j] > nilai[j + 1]) {
                tukarNilai(&nilai[j], &nilai[j + 1]);
                tukarNama(&siswa[j], &siswa[j + 1]);
            }
        }
    }

    cout << "Hasil pengurutan nilai rata-rata siswa (terendah ke tertinggi):" << endl;
    for (int i = 0; i < n; i++) {
        cout << siswa[i] << " : " << nilai[i] << endl;
    }

    return 0;
}

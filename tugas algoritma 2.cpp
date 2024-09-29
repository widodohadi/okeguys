#include <iostream>

using namespace std;

// Fungsi untuk menghitung komisi seorang salesman
double hitung_komisi(double penjualan) {
    if (penjualan <= 500000) {
        return penjualan * 0.1; // Komisi 10%
    } else {
        return 500000 * 0.1 + (penjualan - 500000) * 0.15; // Komisi gabungan
    }
}

int main() {
    const int JUMLAH_SALESMAN = 10;
    double penjualan[JUMLAH_SALESMAN];
    double total_komisi = 0;

    // Input data penjualan dari pengguna
    cout << "Masukkan jumlah penjualan masing-masing salesman:\n";
    for (int i = 0; i < JUMLAH_SALESMAN; i++) {
        cout << "Salesman " << i + 1 << ": ";
        cin >> penjualan[i];
    }

   // Hitung dan tampilkan komisi masing-masing salesman
    cout << "\nKomisi masing-masing salesman:\n";
    for (int i = 0; i < JUMLAH_SALESMAN; i++) {
        double komisi = hitung_komisi(penjualan[i]);
        cout << "Salesman " << i + 1 << ": Rp " << komisi << endl;
        total_komisi += komisi;
    
    }

    // Hitung dan tampilkan total komisi
    cout << "\nTotal komisi yang dibayarkan PT. MURAH HARI: Rp " << total_komisi << endl;

    return 0;
}

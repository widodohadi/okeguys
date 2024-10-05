#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Barang {
    string nama;
    double harga;
    int jumlah;
    double totalPendapatan;
};

int main() {
    const int MAX_BARANG = 100; // Batas maksimal barang yang bisa diinput
    Barang barang[MAX_BARANG];
    int jumlahBarang = 0;
    char lagi;

    do {
        cout << "Nama barang: ";
        getline(cin, barang[jumlahBarang].nama);

        cout << "Harga per barang: Rp ";
        cin >> barang[jumlahBarang].harga;

        cout << "Jumlah barang terjual: ";
        cin >> barang[jumlahBarang].jumlah;

        // Hitung total pendapatan per barang
        barang[jumlahBarang].totalPendapatan = barang[jumlahBarang].harga * barang[jumlahBarang].jumlah;

        jumlahBarang++;

        cout << "Apakah ingin menambah data lagi? (y/n): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    // Tampilkan laporan
    cout << "\n=============================================\n";
    cout << "Laporan Penjualan\n";
    cout << "=============================================\n";
    cout << left << setw(10) << "No" << setw(20) << "Nama Barang" << setw(15) << "Harga/Unit"
         << setw(15) << "Jumlah Terjual" << setw(20) << "Total Pendapatan\n";
    cout << "=============================================\n";

    for (int i = 0; i < jumlahBarang; i++) {
        cout << left << setw(10) << i+1 << setw(20) << barang[i].nama << setw(15) << fixed << setprecision(2) << barang[i].harga
             << setw(15) << barang[i].jumlah << setw(20) << fixed << setprecision(2) << barang[i].totalPendapatan << endl;
    }

    // Hitung total pendapatan keseluruhan
    double totalPendapatanKeseluruhan = 0;
    for (int i = 0; i < jumlahBarang; i++) {
        totalPendapatanKeseluruhan += barang[i].totalPendapatan;
    }

    cout << "=============================================\n";
    cout << "Total Pendapatan Keseluruhan: Rp " << fixed << setprecision(2) << totalPendapatanKeseluruhan << endl;
    cout << "=============================================\n";

    return 0;
}

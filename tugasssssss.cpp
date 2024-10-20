#include <iostream>
#include <string>

using namespace std;

struct Jurusan {
    string kode;
    string nama;
    int pembayaranAwal;
    int jumlahCicilan;
    int besarCicilan;
};

// Function to display all available majors
void tampilkanDataJurusan(Jurusan jurusan[], int jumlahJurusan) {
    cout << "Kode | Jurusan                | Pembayaran Awal | Jumlah Cicilan | Besar Cicilan\n";
    cout << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < jumlahJurusan; i++) {
        cout << jurusan[i].kode << "   | "
             << jurusan[i].nama << "  | Rp "
             << jurusan[i].pembayaranAwal << "           | "
             << jurusan[i].jumlahCicilan << "             | Rp "
             << jurusan[i].besarCicilan << "\n";
    }
}

int main() {
    // List of majors with tuition details
    Jurusan jurusan[] = {
        {"SI", "Sistem Informasi", 2100000, 7, 300000},
        {"TI", "Teknik Informatika", 2500000, 7, 300000},
        {"KA", "Komputer Akutansi", 1750000, 6, 200000},
        {"MI", "Manajemen Informatika", 1500000, 6, 2500000}
    };

    const int jumlahJurusan = sizeof(jurusan) / sizeof(jurusan[0]);
    char lagi;

    // Header for the application
    cout << "+----------------------------------------------------------------+\n";
    cout << "|      Aplikasi Pembayaran Uang Kuliah Universitas Pelita Nusantara     |\n";
    cout << "+----------------------------------------------------------------+\n";

    do {
        // Input student details
        string namaMahasiswa, npm, kodeJurusan;
        int pembayaranAwal, jumlahCicilan, besarCicilan;

        cout << "Nama Mahasiswa: ";
        getline(cin, namaMahasiswa);
        cout << "NPM: ";
        getline(cin, npm);
        cout << endl;

        // Display the available majors
        tampilkanDataJurusan(jurusan, jumlahJurusan);
        cout << endl;

        // Input and validate major code
        cout << "Kode Jurusan: ";
        cin >> kodeJurusan;

        bool ditemukan = false;
        string namaJurusan;
        for (int i = 0; i < jumlahJurusan; i++) {
            if (jurusan[i].kode == kodeJurusan) {
                pembayaranAwal = jurusan[i].pembayaranAwal;
                jumlahCicilan = jurusan[i].jumlahCicilan;
                besarCicilan = jurusan[i].besarCicilan;
                namaJurusan = jurusan[i].nama;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Kode Jurusan tidak ditemukan!\n";
            continue;
        }

        // Display major name
        cout << "Jurusan: " << namaJurusan << endl;

        // Calculate total tuition fee
        int uangKuliah = pembayaranAwal + (jumlahCicilan * besarCicilan);
        cout << "Uang Kuliah: Rp " << uangKuliah << endl;

        // Input the installment number and validate
        cout << "Masukkan Pembayaran Ke-i (1 s/d " << jumlahCicilan << "): ";
        int pembayaranKe;
        cin >> pembayaranKe;

        if (pembayaranKe < 1 || pembayaranKe > jumlahCicilan) {
            cout << "Pembayaran Ke-i tidak valid!\n";
            continue;
        }

        // Calculate the total paid amount
        int uangKuliahTerbayar = pembayaranAwal + ((pembayaranKe - 1) * besarCicilan);
        cout << "Uang Kuliah Terbayar setelah " << pembayaranKe << " kali cicilan: Rp " << uangKuliahTerbayar << endl;

        // Calculate remaining balance
        int sisaUangKuliah = uangKuliah - uangKuliahTerbayar;
        cout << "Sisa Uang Kuliah: Rp " << sisaUangKuliah << endl;

        // Ask if the user wants to calculate again
        cout << "Masih ingin menghitung? (Y/T): ";
        cin >> lagi;
        cin.ignore();  // Ignore newline character after 'cin'
        
        cout << "+----------------------------------------------------------------+\n";
        cout << endl;

    } while (lagi == 'Y' || lagi == 'y');

    cout << "Terima kasih telah menggunakan aplikasi ini!\n";
    return 0;
}


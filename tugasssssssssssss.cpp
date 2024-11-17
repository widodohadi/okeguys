#include <iostream>
#include <iomanip>
using namespace std;

struct Karyawan {
    string nik;
    string nama;
    string alamat;
    int jamKerja;
    int gajiPokok;
    int uangLembur;
    int uangMakan;
    int uangJasa;
    int totalGaji;
};

int hitungGajiPokok(int jamKerja) {
    return jamKerja * 2000;
}

int hitungUangLembur(int jamKerja) {
    if (jamKerja > 7) {
        return (jamKerja - 7) * 3000;
    }
    return 0;
}

int hitungUangMakan(int jamKerja) {
    if (jamKerja >= 8) {
        return 1500;
    }
    return 0;
}

int hitungUangJasa(int jamKerja) {
    if (jamKerja >= 9) {
        return 3000;
    }
    return 0;
}

int main() {
    Karyawan karyawan[100];
    int jumlahKaryawan = 0;
    char lanjut;

    do {
        cout << "===== [ Data Karyawan ] =====" << endl;
        cout << "NIK            : ";
        cin >> karyawan[jumlahKaryawan].nik;
        cout << "Nama Karyawan  : ";
        cin >> karyawan[jumlahKaryawan].nama;
        cout << "Alamat         : ";
        cin >> karyawan[jumlahKaryawan].alamat;
        cout << "Jumlah Jam Kerja : ";
        cin >> karyawan[jumlahKaryawan].jamKerja;

        // Hitung gaji
        karyawan[jumlahKaryawan].gajiPokok = hitungGajiPokok(karyawan[jumlahKaryawan].jamKerja);
        karyawan[jumlahKaryawan].uangLembur = hitungUangLembur(karyawan[jumlahKaryawan].jamKerja);
        karyawan[jumlahKaryawan].uangMakan = hitungUangMakan(karyawan[jumlahKaryawan].jamKerja);
        karyawan[jumlahKaryawan].uangJasa = hitungUangJasa(karyawan[jumlahKaryawan].jamKerja);
        karyawan[jumlahKaryawan].totalGaji = karyawan[jumlahKaryawan].gajiPokok +
                                             karyawan[jumlahKaryawan].uangLembur +
                                             karyawan[jumlahKaryawan].uangMakan +
                                             karyawan[jumlahKaryawan].uangJasa;

        jumlahKaryawan++;
        cout << "Lanjut (y) atau selesai (x)? ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    // Cetak hasil
    cout << "\n\n================= [ Rekap Gaji Karyawan ] =================\n";
    cout << left << setw(10) << "NIK" 
         << setw(15) << "Nama" 
         << setw(15) << "Alamat" 
         << setw(10) << "Jam Kerja" 
         << setw(15) << "Gaji Pokok" 
         << setw(15) << "Uang Lembur" 
         << setw(15) << "Uang Makan" 
         << setw(15) << "Uang Jasa" 
         << setw(15) << "Total Gaji" << endl;

    for (int i = 0; i < jumlahKaryawan; i++) {
        cout << left << setw(10) << karyawan[i].nik 
             << setw(15) << karyawan[i].nama 
             << setw(15) << karyawan[i].alamat 
             << setw(10) << karyawan[i].jamKerja 
             << setw(15) << karyawan[i].gajiPokok 
             << setw(15) << karyawan[i].uangLembur 
             << setw(15) << karyawan[i].uangMakan 
             << setw(15) << karyawan[i].uangJasa 
             << setw(15) << karyawan[i].totalGaji << endl;
    }
    return 0;
}

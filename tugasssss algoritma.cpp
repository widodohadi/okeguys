#include <iostream>
#include <string>
using namespace std;



struct Mahasiswa {
    string nama;
    int npm;
    float nilaiMid;
    float nilaiSemester;
    float nilaiAkhir;
    char nilaiHuruf;
 
};

char tentukanNilaiHuruf(float nilaiAkhir) {
    if (nilaiAkhir >= 80) return 'A';
    else if (nilaiAkhir >= 70) return 'B';
    else if (nilaiAkhir >= 55) return 'C';
    else if (nilaiAkhir >= 40) return 'D';
    else return 'E';
}

float hitungNilaiAkhir(float nilaiMid, float nilaiSemester) {
    return (0.4 * nilaiMid) + (0.6 * nilaiSemester);
}




int main() {
	string name;
    Mahasiswa data[100];
    int jumlahData;
    



    cout<<"Nama kampus:";
//	cin>>STMIKPELITANUSANTARA; 
    getline(cin,name);
    cout << "Masukkan jumlah data mahasiswa Pelita Nusantara (maksimal 100): ";
    cin >> jumlahData;
    if (jumlahData > 100) {
        cout << "Jumlah data melebihi batas maksimum 100." << endl;
        return 1;
    }
//menampilkan nilai dalam bentuk tabel

cout<<"\n==================================================\n";

    for (int i = 0; i < jumlahData; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, data[i].nama);
        cout << "NPM: ";
        cin >> data[i].npm;
        cout << "Nilai Mid: ";
        cin >> data[i].nilaiMid;
        cout << "Nilai Semester: ";
        cin >> data[i].nilaiSemester;

        data[i].nilaiAkhir = hitungNilaiAkhir(data[i].nilaiMid, data[i].nilaiSemester);
        data[i].nilaiHuruf = tentukanNilaiHuruf(data[i].nilaiAkhir);
        
        
        cout << "Nilai Akhir: " << data[i].nilaiAkhir << endl;
        cout << "Nilai Huruf: " << data[i].nilaiHuruf << endl;
        cout << "----------------------" << endl;
        cout<<"===========================================================================\n";
    }

    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << "Nama: " << data[i].nama << ", NPM: " << data[i].npm << endl;
        cout << "Nilai Mid: " << data[i].nilaiMid << ", Nilai Semester: " << data[i].nilaiSemester << endl;
        cout << "Nilai Akhir: " << data[i].nilaiAkhir << ", Nilai Huruf: " << data[i].nilaiHuruf << endl;
        cout << "----------------------------"<< endl;
        cout<<"==========================================================================\n";

	}
    
    







    return 0;
}

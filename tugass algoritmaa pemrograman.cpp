#include<iostream>

using namespace std;

int main() {





     char tiperumahwidodohadi,jenispembayaran;
     int hargatunai,angsuranperbulan;

//input tipe rumah dan jenis pembayaran

cout<<"masukkan tipe rumah widodo hadi (A,B,C,D):";
cin>>tiperumahwidodohadi;
cout<<"masukkanjenis pembayaran(T = Tunai, K=Kredit):";
cin>>jenispembayaran;

//tentukan harga sesuai tipe rumah
 switch (tiperumahwidodohadi) {
	case 'A':
		hargatunai=50000000;//asumsikan harga tunai
		angsuranperbulan= 500000;
		break;
  	case'B':
		hargatunai=75000000;//asumsikan harga tunai
		angsuranperbulan= 750000;
		break;
    	case'C':
	 hargatunai=85000000;//asumsikan harga tunai
    	angsuranperbulan= 850000;
	  break;
	 case'D':
	 hargatunai=100000000;//asumsikan harga tunai
	 angsuranperbulan= 1000000;
	 break;
	
	
}
		
//tampilkan hasil
cout <<"harga tunai: RP"<< hargatunai<< endl;
cout <<"angsuranperbulan: RP"<< angsuranperbulan<< endl;

return 0;


}



#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include "sha26.cpp"
using namespace std;
int main() {
    time_t now = time(0);
    char* dt = ctime(&now);
	int jumlah_barang;
	char mad;
	string barang[50];
	awal:
	    system("cls");
        cout<<"---------------------------"<<endl;
        cout<<"E-KASIR V.1.0.0"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<endl;
        cout<<"Input Jumlah Barang : ";
        cin>>jumlah_barang;
        for (int i=0;i<jumlah_barang;i++){
            cout<<endl;
            cout<<"Input Barang Ke-"<<i+1<<endl;
            cout<<endl;
            cout<<"Nama Barang : ";
            cin>>barang[i]; //Pengguna input nama barang disimpan pada array nama_barang

        }
        cout<<endl;
        int i=0;
        cout<<"Transaksi ke-"<<i+1<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"No   Barang"<<endl;
        for (int i=0;i<jumlah_barang;i++){
            cout<<i+1<<setw(8)<<barang[i]<<endl;
        }
        cout<< "Transaction created at :" << dt << endl;
        string x = barang[i]+dt;
        string hasil = sha256(x);
        cout<< hasil <<endl;
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"Ingin Transaksi lagi ? [Y/T]";
        cin>>mad;
        if(mad=='y' || mad=='Y'){
            goto awal;
        }
        if (mad=='T' || mad=='t'){
            goto selesai;
        }
        selesai:
            system("cls");
            cout<<"Terima Kasih atas kunjungan anda"<<endl;

            return 0;
}

#include<iostream>
#include<string>
using namespace std;

int main(){
	char tbn;
	int nomor=0, databah, pinmasuk, coba, pilmen, pinew, salah, nomin;
    string data[10000];
    float norek[10000];
    int pinput[10000];
    float saldo[10000];
    
    cout << "PROGRAM UJIKOM SMT 2\n";
    cout << endl;
    cout << endl;
    // masukkan data atau menambahkan 
     
    do{
    cout << "Masukkan akun anda!!\n";
    	cout << "Data Nasabah" << endl;
    	cout <<" 1. Masukkan Nama :";
    	cin >> data[nomor];
    	cout <<" 2. Masukkan No Rekening :";
    	cin >> norek[nomor];
    	cout <<" 3. Masukkan Pin :";
    	cin >> pinput[nomor];
    	cout <<" 4. Saldo :";
    	cin >> saldo[nomor];
    	nomor++;
    	
    	cout <<"   Tambah Data Nasabah? (y/n)  :" ;
    	cin >> tbn;
	} while( tbn == 'y' || tbn == 'Y');
	system ("cls");
	
	// jika user memilih t = memilih akun mana yang ingin di pilih
	if( tbn == 'n' || tbn == 'N' ){
		cout << " masukkan kartu(data) :";
		cin >> databah;
		cout << endl;
		
		if(databah==1){
			
			databah=0;
		}else{
			databah = databah - 1;
		}
		cout << " kamu memilih kartu : " << data[databah] << endl;
		cout << endl;
		
		while( coba != 3){
			cout <<    " Masukkan Pin :";
			cin >> pinmasuk;
		
		if( pinmasuk != pinput[databah]){
			system ("cls");
			cout << " Pin Salah !!";
			coba=coba+1;
		}
	    else {
	    	system ("cls");
	    	
	    	cout << " Menu " << endl;
	    	cout << " 1. Informasi saldo " << endl;
	    	cout << " 2. Ganti Pin " << endl;
	    	cout << " 3. Transfer " << endl;
	    	cout << " 4. Tarik tunai" << endl;
	    	cout << " pilih: ";
	    	cin >> pilmen;
	    	
	    	cout << endl;
	    	cout << endl;
	    	switch (pilmen){
	    		case 1: 
	    		cout << " 1. Informasi saldo " << endl;
	    		cout << "   *saldo anda saat ini: " << saldo[databah];
	    		cout << endl;
	    		break ;
	    	
	    		
	    		// ganti pin
	    		case 2:
	    		cout << " 2. Ganti pin " << endl;
	    		while (coba!=3){	
			    cout << " masukkan pin sebelumnya: ";
				cin >> pinmasuk;
				if(pinmasuk != pinput[databah]){
					cout << " pin yang anda masukkan salah " << endl;
					coba = coba + 1;
						
					}
					else{
			
				
				system("cls");
				cout << " masukkan pin baru ";
				cin >> pinew;
				system("cls");
                cout << "pin anda berhasil di ubah\n";
                cout << "pin anda skrg:" << pinew << endl;
		        cout << " terimakasih telah mempercayai ATM kami\n";
		        coba = 3;
				}
		        }
                break;

				case 3:
				cout << "3. transfer \n";
				cout << " masukkan nominal";
				
				case 4:
				cout << "4. tarik tunai \n";
				cout << "  masukkan nominal yang ingin anda tarik \n";
				cout << " *masukkan nominal dengan (ribuan) Rp.";
				cin >> nomin;
				system("cls");
				if( nomin > saldo[databah]){
					cout << " saldo anda tidak cukup \n";
					return 0;
					
				}
				else{
					saldo[databah] = saldo[databah] - nomin;
					cout << " total isi saldo anda sekarang :" << saldo[databah] << endl;
					cout << endl;
					cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
				    cout << " trimakasih telah mempercayai ATM kami :) \n ";
				    cout << endl;
				    cout << " masukkin pin anda untuk kembali ke tampilan menu \n";
				}
				
	
			}
		} 
	    
	     
		 }
		}
	}
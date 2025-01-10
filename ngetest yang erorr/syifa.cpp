#include <iostream>
#include <string>
using namespace std;

int main()
{

	int no = 0 , cobapin = 0, cobaganti = 0 ,datanasa , berandapil , inputpin, gantipin, pinbaru, transpil, nomtarik;
    int pindata[10000];
    float norek[10000];
    float saldo[10000];
    char tambahdat;
    string data[10000];

	cout << "====== ATM BANK JALI ======" << endl;
    cout << endl;
	//NO1 = MEMASUKKAN DATA AKUN NASABAH
    do{
    cout << "Masukkan data " << endl;
    cout << "    Nama : ";
    cin >> data[no];
    cout << "    No rekening : ";
    cin >> norek[no];
    cout << "    Pin : ";
    cin >> pindata[no];
    cout << "    Jumlah Saldo anda :";
    cin >> saldo[no];
    no++;
    cout << "Tambah data lagi? (Y/T) : ";
    cin >> tambahdat;
    cout << endl;
    }while( tambahdat == 'y' || tambahdat == 'Y');

    //PILIH AKUN/DATA ATM
    
    if (tambahdat == 't' || tambahdat == 'T' )
    {
    	system("cls");
        cout << "Pilih data akun ke : ";
        cin >> datanasa;
        //UNTUK MENJADIKAN INPUT MENJADI TERBACA OLEH ARRAY
        if (datanasa == 1)
        {
            datanasa = 0;
        }else
        {
            datanasa = datanasa - 1;
        }
        system("cls");
         
        cout << "kamu memilih akun  : " << data[datanasa] << endl;

        while (cobapin != 3)
        {
            cout << "\nmasukan pin  : ";
            cin >> inputpin;
            
            if(inputpin != pindata[datanasa]){
                system("cls");
                cout << "pin yang dimasukkan salah! ";
                cobapin = cobapin + 1;
            }
            
            else
            {system("cls");

            //NO2 = MENU BERANDA ATM
            cout << "pilih " << endl;
            cout << "1. informasi saldo " << endl;
            cout << "2. ganti pin " << endl;
            cout << "3. transfer " << endl;
            cout << "4. tarik tunai " << endl; 
            cin >> berandapil;
            switch (berandapil)
            {
            case 1:
                cout << "informasi saldo " << endl;
                cout << "saldo anda adalah : " << saldo[datanasa];
                break;
            case 2:
				cout << "Ganti pin " << endl;
         while(cobaganti != 3) {
				cout << "Masukkan pin sebelumnya :";
				cin >> gantipin;
				if(gantipin != pindata[datanasa]){
					cout << " pin yang anda masukkan salah " << endl;
					cobaganti = cobaganti + 1;
                }else{
                cout << "Masukkan pin baru :";
				cin >> pinbaru;
                pindata[datanasa] = pinbaru;
				system("cls");
                cout << "Pin berhasil diperbarui" << endl;
                cout << "pin anda sekarang :" << pinbaru << endl;
                cobaganti = 3;
		        }
            	
            }
           break;
            	
            case 3:
            	cout << "Transfer";
            	cout << "Pilih opsi dibawah :" << endl;
				cout << "1. Bank ini\n 2. Antar Bank" << endl;
				cout << "pilih: ";
				cin >> transpil;
				
				if(transpil == 1){
					cout << "Kamu memilih transfer dengan sesama bank\n";
					cout << "Masukkan no rekening tujuan anda :\n";
					cout << "Masukkan nominal saldo yang akan di transfer :";	
				}
				break;
					
			case 4:
				cout << "tarik tunai\n";
				cout << "Masukkan nominal saldo yang akan ditarik :";
				cin >> nomtarik;
				system("cls");
				 
				cout << "Terimakasih sudah mempercayai BANK JALI!";
            
            default:
                break;
            }
            }

            if (cobapin == 3)
            {
                cout << "Mohon maaf kartumu ditelan";
            } 	
            }
            
        }   
		return 0; 
    }

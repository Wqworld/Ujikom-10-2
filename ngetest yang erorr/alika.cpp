#include <iostream>
#include <string>
using namespace std;

int main(){

    char tambahdata, enter;
    int no = 0 , datano , tarik , pincoba , opsi , coba = 0, saldo, wrong= 0, nomor, transf;
    int pinew;
    float norek[100];
    string data[100];
    int pininput[100];
    float saldoawal[100];
    
    
cout << "                                        +-----------------------------+"<<endl;   
cout << "                                        |SELAMAT DATANG DI BANK ALIKA |"<<endl;
cout << "                                        |MENABUNG DI BANK ALIKA       | "<<endl;
cout << "                                        |DIJAMIN AMAN DAN NYAMAN :)   |"<<endl;
cout << "                                        +-----------------------------+"<<endl;
cout <<"Klik Y untuk melanjutkan : ";
cin >>enter;

system ("cls");
    
     do{
     	
    cout << "ISI DATA TERLEBIH DAHULU YA!"<<endl;

    cout << "Masukan nama        : ";
    cin >> data[no];
    cout << "Masukan no rekening : ";
    cin >> norek[no];
    cout << "Masukan pin         : ";
    cin >> pininput[no];
    cout << "Saldo anda          :";
    cin >> saldoawal[no];
    no++;
    cout << "Tambah data(y/t)?    : ";
    cin >> tambahdata;
    }while( tambahdata == 'y' || tambahdata == 'Y');
    
    if (tambahdata == 't' || tambahdata == 'T' )
    {
	
        cout << "Masukan kartu : ";
        cin >> datano;
        
        if (datano == 1)
        {
            datano = 0;
        }else
        {
            datano = datano - 1;
        }
        
         system ("cls");
        cout << "Kamu memilih data ke : " << data[datano] << endl;

        while (coba != 3)
        {
        	
        	  cout << "\nMasukan PIN  : ";
            cin >> pincoba;
            
            if(pincoba != pininput[datano]){
                system("cls");
                cout << "PIN anda salah !! ";
                coba = coba + 1;
            }
            
            else 
            {    
                 
            system("cls");

            
            cout << "Pilihan " << endl;
            cout << "1. Cek saldo " << endl;
            cout << "2. Ganti pin " << endl;
            cout << "3. Transfer " << endl;
            cout << "4. Tarik tunai " << endl;
			cout << "PILIH APA YANG ANDA BUTUHKAN : "; 
            cin >> opsi;
        
            
            switch (opsi){
        
		// Cek Informasi Saldo 
            case 1:
            system ("cls") ;
                cout << "Informasi Saldo Anda " << endl;
                cout << "saldo anda adalah : " << saldoawal[datano] <<endl;
            
                break;
         
		//Proses Mengganti PIN       
            case 2 :
            
            	while (wrong != 3){
            	cout << "Masukkan PIN awal : ";
            	cin >> pincoba;
            	
            	if (pincoba != pininput[datano]){
            		cout << "Maaf PIN kamu salah :("<<endl;
            		wrong = wrong + 1;
				}
				else {
					wrong = wrong + 3;
				}
        }
        	cout << "Masukkan PIN baru anda : ";
        	cin >> pinew;
        	
        system ("cls");
        cout << " PIN anda telah diubah otomatis oleh system "<< endl;
        cout << "Masukkan PIN baru anda : "<< pinew << endl;
        cout << "Thank you"<<endl;
        
        if( pincoba != pinew){
                    cout << " PIN anda Salah !!";
			        coba=coba+1;
		        }
	            else {
	    	    system ("cls");
	    	    cout << " Menu " << endl;
	    	    cout << " 1. Cek saldo " << endl;
	    	    cout << " 2. Ganti Pin " << endl;
	    	    cout << " 3. Transfer " << endl;
	    	    cout << " 4. Tarik tunai" << endl;
	    	    cout << "PILIH APA YANG ANDA BUTUHKAN : ";
	    	    cin >> opsi;
                system("pause");
                system("cls");
                }
                
                break;
                
        //Transfer
            case 3 :
            	system("cls");
                cout << "Masukkan Nomor Rekening yang anda tuju :";
                cin >> nomor;
                cout << "masukan nomial uang:";
                cin >> transf;
                saldoawal[datano] = saldoawal[datano] - transf;
                cout << "Saldo Anda Sekarang yaitu Rp. " << saldoawal[datano] << endl;
                system("cls");
                break;
            	
        //Tarik tunai 
            case 4 :
                cout << "Masukan jumlah uang yang akan anda ambil :";
                cin >> tarik;
                if (tarik%10000!=0 || tarik<0){
                    cout << "Masukan uang dengan pecahan 10000\n";
                    
                    
                }
                else {
                if (tarik > saldoawal[datano]){
                    cout << "Saldo Anda tidak cukup \n";
                }
                else {
                saldoawal[datano] = saldoawal[datano] - tarik;
                cout << "Silahkan hitung kembali uang yang telah Anda tarik\n";
                cout << "Total saldo anda sekarang Rp." << saldoawal[datano] << endl;
                system("cls");
			}
	}
        }
    }
}
}
}

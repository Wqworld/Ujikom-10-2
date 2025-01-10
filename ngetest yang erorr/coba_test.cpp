#include <iostream>
using namespace std;

int main()
{
    char tambahdat , kembaliberanda;
    int nomor = 0 , datake , pin ,  pincoba , coba = 0 , ulang = 0 , pinulang , pinbaru, nominaltf , saldotf , hasiltf , hasilgantipin ,validasinorek ,wrong;
    int pilopsi , piltrans;
    bool beranda;
    string data[10000];
    float norek[10000];
    int pininput[10000];
    float saldo[10000];
    int ganti_pin(int baru , int lama);

    do{
    cout << "    masukan pin     : ";
    cin >> pininput[nomor];
    nomor++;
    cout << "  tambah data(y/n)  : ";
    cin >> tambahdat;
    }while( tambahdat == 'y' || tambahdat == 'Y');

    if (tambahdat == 'n' || tambahdat == 'N' )
    {
        cout << "masukan kartu : ";
        cin >> datake;
        //UNTUK MENJADIKAN INPUT MENJADI TERBACA OLEH ARRAY
        if (datake == 1)
        {
            datake = 0;
        }else
        {
            datake = datake - 1;
        }
        

        while (coba != 3)
        {
            cout << "kamu memilih data : " << pininput[datake] << endl;
            cout << "\nmasukan pin  : ";
            cin >> pincoba;
            
            if(pincoba != pininput[datake]){
                cout << "\npin salah !! ";
                coba++;
            }else if (coba == 3)
            {
                cout << "mangap kartu kamu di telan";
            }
            else
            {            
                //UNTUK MEREFRESH TAMPILAN
            system("cls");
            cout << "PIN BENAR.\n\n";

            
            do{
            //MEMASUKI BERANDA ATM SESUAI DATA YANG DIPILIH
            cout << "pilih " << endl;
            cout << "1. informasi saldo " << endl;
            cout << "2. ganti pin " << endl;
            cout << "3. transfer " << endl;
            cout << "4. tarik tunai " << endl; 
            cin >> pilopsi;       

            if(pilopsi == 2){
                cout << "ganti pin  " << endl << endl;
                cout << "akun yang sedang kamu pakai : " << data[datake];
                //KONFIRMASI PIN DULU
                
                do{
                    cout << endl << pininput[datake];
                cout << "\nmasukan pin dulu : ";
                cin >> pinulang;
                if (pinulang == pininput[datake])
                {
                    cout << "masukan pin baru : ";
                    cin >> pinbaru;
                    pininput[datake] = pinbaru;
                    ulang = 30;
                }
                ulang++;
                }while(ulang <= 3);


                }
            // //UNTUK DEKLARASI KE SELURUH PROGRAM (GANTI PIN)
            // pininput[datake] = hasilgantipin;
            // //UNTUK DEKLARASI KE SELURUH PROGRAM (TRANSFER)
            // saldo[datake]=hasiltf;

            }while (beranda == true);
            }            
        }    
    }
    return 0;
}

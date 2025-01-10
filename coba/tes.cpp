 #include <iostream>
#include <string>
using namespace std;

void gantipin(int baru , int lama);
void tf_antarbank(int bankpilihan , int nominal);

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

    //menambahkan data nasabah
    
    cout << "tambahkan data " << endl;
    do{
    cout << "    masukan nama    : ";
    cin >> data[nomor];
    cout << "masukan no rekening : ";
    cin >> norek[nomor];
    cout << "    masukan pin     : ";
    cin >> pininput[nomor];
    cout << "    saldo anda      :";
    cin >> saldo[nomor];
    nomor++;
    cout << "  tambah data(y/n)  : ";
    cin >> tambahdat;
    }while( tambahdat == 'y' || tambahdat == 'Y');

    //PILIH AKUN/DATA ATM

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
        
         
        cout << "kamu memilih data : " << data[datake] << endl;

        while (coba != 3)
        {
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


            if(pilopsi == 1){
                cout << "informasi saldo " << endl;
                cout << "saldo anda adalah : " << saldo[datake];
                cout << "\nkembali ke beranda (y/n) : ";
                cin >> kembaliberanda;
                if (kembaliberanda == 'y' || kembaliberanda == 'Y' )
                {
                    beranda = true;
                }else{
                    return 0;
                }
                }


            else if(pilopsi == 2){
                cout << "ganti pin  " << endl << endl;
                cout << "akun yang sedang kamu pakai : " << data[datake];
                //KONFIRMASI PIN DULU
                
                do{
                    cout << endl << pininput[datake];
                cout << "\nmasukan pin dulu : ";
                cin >> pinulang;
                if(pinulang == pininput[datake]){
                    cout << "masukan pin baru : ";
                    cin >> pinbaru;
                    gantipin(pinbaru, pininput[datake]);
                    hasilgantipin = pinbaru;
                }else if (ulang == 3)
                {
                    cout << "kamu salah 3 kali !!" << endl;
                }                
                else{
                    cout << "\npin salah !! ";
                    ulang++;
                }
                }while(ulang != 3);


                }


            else if(pilopsi == 3){
                cout << "transfer" << endl;
                cout << "1. transfer anter bank" << endl;
                cout << "2. tansfer sesama bank" << endl;
                cin >> piltrans;
                switch (piltrans)
                {
                case 1:
                    cout << "antar bank " << endl;
                    cout << "1. bni\n2. bjb\n3. mandiri\n4. bri ";
                    cin >> piltrans;
                    if (piltrans == 1)
                    {
                        piltrans = 0;
                    }else
                    {
                        piltrans = piltrans - 1;
                    }   
                    cout << "masukan nominal : ";
                    cin >> nominaltf;
                    tf_antarbank(piltrans  , nominaltf);
                    hasiltf = saldo[datake] - nominaltf;
                    cout << "\n\n" << hasiltf;
                    cout << "\nkembali ke beranda (y/n) : ";
                     cin >> kembaliberanda;
                        if (kembaliberanda == 'y' || kembaliberanda == 'Y' )
                            {
                                beranda = true;
                            }else{
                                return 0;
                            }      
                    break;
                case 2:
                    cout << "sesama bank " << endl;
                    cout << "masukan nomor karu tujuan : ";
                    cin >> datake;
                    while (wrong != 3)
                    {
                        cout << "masukan nomor rekening tujuan : ";
                        cin >> validasinorek;
                        if (validasinorek != norek[datake])
                        {
                            cout << "norek tidak di temukan ";
                            wrong = wrong + 1;
                        }else
                        {
                            cout << "kamu memasukan rekening atas nama : " << data[datake];
                            cout << "nominal yang kamu mau trasfer : ";
                            cin >> nominaltf;
                            norek[datake] = norek[datake] - nominaltf;
                            cout << "kamu berasil mentransfer ke " << data[datake] << " sebesar : " << nominaltf;
                        }
                        
                        
                    }
                    break;
                default:
                    cout << "error input !! ";
                    beranda = true;
                    break;
                }
                }


            // //UNTUK DEKLARASI KE SELURUH PROGRAM (GANTI PIN)
            // pininput[datake] = hasilgantipin;
            // //UNTUK DEKLARASI KE SELURUH PROGRAM (TRANSFER)
            // saldo[datake]=hasiltf;

            }while (beranda == true);














            }            
        }    
    }
    system("cls");
    cout << " erorr input ";
    return 0;
}

void gantipin(int baru , int lama){
    cout << "pin dulu : " << lama << endl;
    cout << "pin baru : " << baru; 
    cout << "\nkamu berasil mengubah pin " << baru;
}

void tf_antarbank(int bankpilihan , int nominal){
    string bank[4]{"bni","bjb","mandiri","bri"};
    cout << "kamu berasil mentransfer ke " << bank[bankpilihan];
    cout << " sebesar : " << nominal;
}
 #include <iostream>
#include <string>
using namespace std;

void gantipin(int baru , int lama);
void tf_antarbank(int bankpilihan , int nominal , int admin_bumn , int admin_non , int norek);
void tf_sesama(float norek , string data , int nominal);
void saldotakcukup();


int main()
{

    char tambahdat , kembaliberanda;
    int nomor = 0 , datake , pin ,  pincoba , coba = 0 , ulang = 0 , pinulang , pinbaru, nominaltf , saldotf , hasiltf , hasilgantipin ,wrong , nominaladmin , hasiltarik;
    bool ketemu , akuntidakada = false;
    float validasinorek , norekketemu;
    int pilopsi , piltrans , piloptar , norektujuan;
    int beranda , bank_bumn = 4500 , bank_non_bumn = 6000 , tarikinput; 
    string data[10000];
    string dataketemu;
    float norek[10000];
    int pininput[10000];
    int saldo[10000];
    int ganti_pin(int baru , int lama);

    //menambahkan data nasabah
    
    cout << "=-=-=-=++tambahkan data++=-=-=-= " << endl;
    do{
    cout << "+-=||    masukan nama    : ";
    cin >> data[nomor];
    cout << "+-=||masukan no rekening : ";
    cin >> norek[nomor];
    cout << "+-=||    masukan pin     : ";
    cin >> pininput[nomor];
    cout << "+-=||    saldo anda      :";
    cin >> saldo[nomor];
    nomor++;
    cout << "+-=||  tambah data(y/n)  : ";
    cin >> tambahdat;
    }while( tambahdat == 'y' || tambahdat == 'Y');

    //PILIH AKUN/DATA ATM

    if (tambahdat == 'n' || tambahdat == 'N' )
    {
        cout << "masukan kartu : ";
        cin >> datake;
        if (datake > nomor)
        {
            system("cls");
            cout << "\nakun tidak ada ";
            return 0;
        }
        
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
                if (coba == 3)
            {
                system("cls");
                cout << "mangap kartu kamu di telan";
            }
            }
            else
            {       
                    //UNTUK MEREFRESH TAMPILAN
                system("cls");
                cout << "PIN BENAR.\n\n";

                
                while (beranda != 5){
                
                //MEMASUKI BERANDA ATM SESUAI DATA YANG DIPILIH
                system("cls");
                    cout << "=+=+=+====selamat datang" << data[datake] << "====+=+=+=\n\n";
                    cout << "pilih " << endl;
                    cout << "1. informasi saldo " << endl;
                    cout << "2. ganti pin " << endl;
                    cout << "3. transfer " << endl;
                    cout << "4. tarik tunai " << endl; 
                    cin >> pilopsi;       

                    system("cls");
                    //pilih opsi melihat saldo
                    if(pilopsi == 1){
                        cout << "=+=+=+====informasi saldo====+=+=+= " << endl;
                        cout << "saldo anda adalah : " << saldo[datake];
                        cout << "\nkembali ke beranda (y/n) : ";
                        cin >> kembaliberanda;
                        if (kembaliberanda == 'y' || kembaliberanda == 'Y' )
                        {
                            beranda = 1;
                        }else{
                            return 0;
                        }
                        }


                    //pilih opsi ganti pin
                    else if(pilopsi == 2){
                        cout << "=+=+=+====ganti pin====+=+=+=  " << endl;
                        cout << "akun yang sedang kamu pakai : " << data[datake];
                        ulang = 0;
                        //KONFIRMASI PIN DULU
                        
                        while(ulang != 3){
                            cout << "\nmasukan pin dulu : ";
                            cin >> pinulang;
                            //verifikasi pin dulu
                            if(pinulang != pininput[datake]){
                                cout << "\npin salah !! ";
                                ulang++;
                                if (ulang == 3)
                                {
                                    return 0;
                                    system("cls");
                                    cout << "kamu salah memasukan pin";
                                }
                            }
                            else{
                                cout << "masukan pin baru : ";
                                cin >> pinbaru;
                                gantipin(pinbaru, pininput[datake]);
                                pininput[datake] = pinbaru;
                                cout << "\nkembali ke beranda (y/n) : ";
                                cin >> kembaliberanda;
                                    if (kembaliberanda == 'y' || kembaliberanda == 'Y' )
                                        {
                                            ulang = 3;
                                            beranda = 1;
                                        }else
                                        {
                                            system("cls");
                                            cout << "terimaksih >< " << endl;
 
                                            return 0;
                                        }      
                                }
                            }
                        }

                    //pilih opsi transfer bank
                    else if(pilopsi == 3){
                        cout << "=+=+=+====transfer====+=+=+=" << endl;
                        cout << "1. transfer antar bank" << endl;
                        cout << "2. tansfer sesama bank" << endl;
                        cin >> piltrans;
                        switch (piltrans)
                        {
                        case 1:
                            cout << "antar bank " << endl;
                            cout << "1. bni\n2. bjb\n3. mandiri\n4. bri ";
                            cout << "\npilih opsi : ";
                            cin >> piltrans;
                            if (piltrans == 1)
                            {
                                piltrans = 0;
                            }else
                            {
                                piltrans = piltrans - 1;
                            }   
                            cout << "masukan nomor rekening tujuan : ";
                            cin >> norektujuan;
                            cout << "masukan nominal : ";
                            cin >> nominaltf;
                            if (piltrans == 1 || piltrans == 3 || piltrans == 4)
                            {
                                nominaladmin = nominaltf + bank_bumn; 
                            }
                            else
                            {
                                nominaladmin = nominaltf + bank_non_bumn;
                            }
                            
            
                            tf_antarbank(piltrans  , nominaltf , bank_bumn , bank_non_bumn , norektujuan);
                            hasiltf = saldo[datake] - nominaladmin;
                            saldo[datake] = hasiltf;
                            cout << "\nkembali ke beranda (y/n) : ";
                            cin >> kembaliberanda;
                                if (kembaliberanda == 'y' || kembaliberanda == 'Y' )
                                    {
                                        beranda = 1;
                                    }else{
                                        return 0;
                                    }      
                            break;

                        case 2:
                                cout << "sesama bank " << endl;
                                
                                
                                
                                //tambah while buat ngulang bila tidak ada di sini

                                cout << "masukan nomor rekening tujuan : ";
                                cin >> validasinorek;
                                if (validasinorek == norek[datake])
                                {
                                    system("cls");
                                    cout << "\n\nnomor rekening yang kamu masukan adalah nomor rekening sendiri\n\n";
                                    return 0;
                                }
                                
                                for (int i = 0; i <= 10; i++)
                                {
                                    if (validasinorek == norek[i])
                                    {
                                        ketemu = true;
                                        system("cls");
                                        
                                        cout << "kamu memasukan nomer rekening : " << norek[i] << endl;
                                        norekketemu  = norek[i];
                                        cout << "atas nama : " << data[i] << endl;
                                        dataketemu = data[i];
                                        cout << "masukan nominal transfer : ";
                                        cin >> nominaltf;
                                        hasiltf = saldo[datake] - nominaltf;
                                        saldo[datake] = hasiltf;
                                        tf_sesama(norekketemu , dataketemu , nominaltf);
                                        
                                        akuntidakada = false;
                                        break;
                                    }
                                    
                                    akuntidakada = true;
                                }
                                
                                if (akuntidakada == false || ketemu == true)
                                {
                                    
                                    cout << "\nkembali ke beranda (y/n) : ";
                                    cin >> kembaliberanda;
                                        if (kembaliberanda == 'y' || kembaliberanda == 'Y' )
                                            {
                                                beranda = 1;
                                            }else{
                                                cout << "terima kasih >< ";
                                                return 0;
                                            }

                                }
                                else if(akuntidakada == true || ketemu == false){
                                    cout << "nomor rekening tidak di temukan !! " << endl;
                                }
                                
                            break;
                        }
                    }


                    //pilih opsi tarik tunai
                    else if (pilopsi == 4)
                    {
                        system("cls");
                        cout << "============tarik tunai============" << endl;
                        cout << "       pilih opsi tarik tunai       " << endl << endl;
                        cout << "1. 100.000                50.000 .2"<< endl << endl;
                        cout << "3. 1.000.000       jumlah lainya .4" << endl;
                        cout << "pilih : ";
                        cin >> piloptar;
                        if (piloptar == 1)
                        {   
                            if (saldo[datake] < 100000)
                            {
                                cout << "saldo tidak mencukupi ";
                                saldotakcukup;
                            }
                            else
                            {
                                cout << "kamu berasil menarik sebesar : Rp. 100000";
                                hasiltarik = saldo[datake] - 100000;
                                saldo[datake] = hasiltarik;
                            }
                                cout << "\nkembali ke beranda (y/n) : ";
                                        cin >> kembaliberanda;
                                            if (kembaliberanda == 'y' || kembaliberanda == 'Y' )
                                                {
                                                    beranda = 1;
                                                }else{
                                                    cout << "terima kasih >< ";
                                                    return 0;
                                                }
                        }else if (piloptar == 2)
                        {
                            if (saldo[datake] < 50000)
                            {
                                cout << "saldo tidak mencukupi ";
                                cout << saldotakcukup;
                            }
                            else
                            {
                                hasiltarik = saldo[datake] - 50000;
                                cout << "kamu berasil menarik sebesar : Rp. 50000";
                                saldo[datake] = hasiltarik;
                            }
                                cout << "\nkembali ke beranda (y/n) : ";
                                        cin >> kembaliberanda;
                                            if (kembaliberanda == 'y' || kembaliberanda == 'Y' )
                                                {
                                                    beranda = 1;
                                                }else{
                                                    cout << "terima kasih >< ";
                                                    return 0;
                                                }
                            
                        }else if (piloptar == 3)
                        {
                            if (saldo[datake] < 1000000)
                            {
                                cout << "saldo tidak mencukupi ";
                                cout << saldotakcukup;
                            }
                            else
                            {
                                hasiltarik = saldo[datake] - 1000000;
                                cout << "kamu berasil menarik sebesar : Rp. 10000000";
                                saldo[datake] = hasiltarik;
                            }
                                cout << "\nkembali ke beranda (y/n) : ";
                                        cin >> kembaliberanda;
                                            if (kembaliberanda == 'y' || kembaliberanda == 'Y' )
                                                {
                                                    beranda = 1;
                                                }else{
                                                    cout << "terima kasih >< ";
                                                    return 0;
                                                }
                            
                        }else if (piloptar == 4)
                        {
                            cout << "masukan nominal tarik : ";
                            cin >> tarikinput;
                            if (tarikinput > saldo[datake])
                            {
                                cout << "saldo tidak mencukupi ";
                                cout << saldotakcukup;
                            }else{
                            hasiltarik = saldo[datake] - tarikinput;
                            cout << "kamu berasil menarik sebesar : Rp." << tarikinput;
                            saldo[datake] = hasiltarik;
                            }
                            cout << "\nkembali ke beranda (y/n) : ";
                                        cin >> kembaliberanda;
                                            if (kembaliberanda == 'y' || kembaliberanda == 'Y' )
                                                {
                                                    beranda = 1;
                                                }else{
                                                    cout << "terima kasih >< ";
                                                    return 0;
                                                }
                            
                        }
                    }
                }
            }            
        }    
    }
}

void gantipin(int baru , int lama){
    cout << "pin dulu : " << lama << endl;
    cout << "pin baru : " << baru; 
    cout << "\nkamu berasil mengubah pin " << baru;
}

void tf_antarbank(int bankpilihan , int nominal , int admin_bumn , int admin_non , int norek){
    string bank[4]{"bni","bjb","mandiri","bri"};
    cout << "kamu berasil mentransfer ke " << norek << " \nmelalui bank "  << bank [bankpilihan];
    if (nominal == 1 || nominal == 3 || nominal == 4)
    {
            cout << "\ndengan biaya admin sebesar : " << admin_bumn<< endl;
    }
    else
    {
            cout << "\ndengan biaya admin sebesar : " << admin_non << endl;
    }
    cout << " \n nominal yang kamu transfer sebesar : " << nominal;

}

void tf_sesama(float norek , string data , int nominal){
    system("cls");
    cout << "kamu berasil mentransfer ke nomor rekening : " << norek << endl;
    cout << " atas nama : " << data << endl;
    cout << "  sebesar  : " <<  nominal << endl;
}

void saldotakcukup(){
    cout << "saldo anda tidak mencukupi " << endl;
}
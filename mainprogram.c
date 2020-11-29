#include <stdio.h>
#include <time.h>
#include "parser.h"
#include "map.h"
#include "mainphase/mainphase.h"
#include "globalvariable.h"


#include "preparation.h"
#include "loadfileexternal.h"
/*
TULIS URUTAN FUNGSI DI PROGRAM UTAMA KAYA APA,
Dikasih komen ya biar paham

CreatePlayer();

// LOAD MAP
MAP M1,M2,M3,M4;
LoadMap(M1,M2,M3,M4);

while (true)    // LOOP PROGRAMMNYA
    TulisMap();                   // Print Map
    Tulis_Nama_Money_dll();       // Print attribute kaya nama, money, waktu dll
    Minta_input_perintah(KATA input);  // baca kata/huruf, misal "buy","w","a","upgrade",dll
    
    if ( input = W/A/S/D )        // berarti ingin pindah di map
        FMap();                   // fungsi dimap, pindah posisi, ubah map, dll
        cls();                    // clear screen
        
    else if (misal input "upgrade", "buy", dll)
        Contoh();
    else misal input "upgrade", "buy", dll)
        Contoh();
    cls();
*/


MAP M1,M2,M3,M4;
daftarwahana InfoWahana;

int main(){
    Kata input;

    printf("Welcome to Willy wangky's fun factory!!\n");
    printf(" - New Game  [ Query: new.  ]\n");
    printf(" - Load Game [ Query: load. ]\n");
    printf(" - Exit      [ Query: exit. ]\n > ");
    InputKata(&input);
    
    if(IsSama(input, "new")){
        
        boolean exit = false;
        
        PLAYER P;
        int day = 1;
        
        Antrian A;
        MakeEmptyAntrian(&A, 15); //Set maksimum antrian
        JAM J, Buka, Tutup;
        TabProses TabProses;
        MakeTabProses(&TabProses);
        AllWahana L;
        CreateEmptyWahana(&L);

        srand(time(0)); //Set random seed

        Buka = MakeJAM(9,0);
        J = MakeJAM(21,0);
        Tutup = MakeJAM(21,0);

        LoadAllMap(&M1,&M2,&M3,&M4);
        CreatePlayer(&P,M1,3,3); // assign player di x,y = (3,3), ini bebas nanti ganti
        Money(P) = 5000; //Sesuaiin aja uang awalnya berapa
        //scanf("Masukkan nama : %s",&Name(P));
        //scanf("Masukkan jumlah uang : ",&Money(P));
        UbahMap(&P,true);
        cls();

        printf("Memulai permainan baru......\n");
        
        Stack SAksi;
        CreateEmptyStack(&SAksi);
        material MAT = LoadMaterial("data/material.txt");
        InfoWahana = LoadWahana("data/wahana.txt");

        while(!exit){
            Prepare(&A,&TabProses,&L);
            printf("Preparation phase day %d\n", day);
            PrintMap(CMap(P));
            PrintStatPlayer(SAksi,J,Buka,Money(P),MAT,L);
            printf("\nMasukan Perintah:\n > ");
            InputKata(&input);

            if(IsSama(input,"build")){
                build(&SAksi,Money(P),J,Buka,MAT,InfoWahana,&L,&P);
            } else if(IsSama(input, "upgrade")){
                upgrade(&SAksi, Money(P), J, MAT, InfoWahana, P,&L);
            } else if(IsSama(input, "buy")){
                buy(&SAksi,Money(P),J,Buka,MAT,L);
            } else if(IsSama(input, "undo")){
                UndoAksi(&SAksi,&L);
            } else if(IsSama(input, "w") || IsSama(input, "a") || IsSama(input,"s") || IsSama(input,"d")){
                char C = input.TabKata[0];
                FMap(&P, C, M1, M2, M3, M4);
            } else if(IsSama(input, "main")){
                //Masukan Program loop untuk main phase
                /*dalam loop prepare
                else if (IsSama(input, "prepare")) {
                    Prepare(&A,&TabProses,&L);
                    day++;
                    break;
                }*/
                J = Buka;
                while (JLT(J, Tutup)){
                    printf("Main phase day %d\n", day);
                    PrintMap(CMap(P));
                    PrintStatus(J, Tutup, Money(P), A);
                    printf("Masukan Perintah:\n");
                    InputKata(&input);

                    if (IsSama(input, "serve")){
                        
                        if (CGedung(P) == 'A'){
                            Serve(&A, &L, &J, &Money(P), &TabProses);
                        }
                        else{
                            printf("Harus berada di dekat antrian untung menggunakan command ini\n");
                        }
                    }
                    else if (IsSama(input, "repair")){
                        repair(P.POS, Kode(CMap(P)), &J, &TabProses, &A, &L);

                    }
                    else if(IsSama(input, "w") || IsSama(input, "a") || IsSama(input,"s") || IsSama(input,"d")){
                    char C = input.TabKata[0];
                    FMap(&P, C, M1, M2, M3, M4);
                    AdvTime(&J, 1, &TabProses, &A, &L);
                    }
                    else if(IsSama(input, "prepare")){
                        Prepare(&A, &TabProses, &L);
                        J = Tutup;
                    }

                    

                }

            } else if(IsSama(input, "exit")){
                exit = true;
            }

        }

        cls();

    }
    else if (IsSama(input, "load"))
    {
        printf("\nMasukkan nama file save-an:\n > ");
        InputKata(&input);
    }
    else if (IsSama(input, "exit"))
    {
        printf("\nThanks for playing!\n");
    }
    else
    {
        printf("\nInput Anda tidak valid.\n");
    }

    return 0;
}
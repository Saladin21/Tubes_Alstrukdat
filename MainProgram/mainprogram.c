#include <stdio.h>
#include <time.h>
#include "../MesinKarakter_MesinKata/parser.h"
#include "map.h"
#include "mainphase.h"
#include "globalvariable.h"


#include "preparation.h"
#include "../ADTLain/loadfileexternal.h"
#include "saver.h"
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

    printf("\n .  . ..     .  .         .      *   \n");
    printf(" |  |*||  .  |  | _.._  _ ;_/  . ' __\n");
    printf(" |/\\||||\\_|  |/\\|(_][ )(_]| \\\\_|  _) \n");
    printf("        ._|            ._|   ._|     \n");
    printf("         .  .      .  .              \n");
    printf("         |  | _ ._.| _|              \n");
    printf("         |/\\|(_)[  |(_]             \n\n\n");
    
    printf("     New Game  [ Query: new.  ]\n");
    printf("     Load Game [ Query: load. ]\n");
    printf("     Exit      [ Query: exit. ]\n > ");
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
        J = MakeJAM(12,0);
        Tutup = MakeJAM(21,0);

        LoadAllMap(&M1,&M2,&M3,&M4);
        CreatePlayer(&P,M1,3,3); // assign player di x,y = (3,3), ini bebas nanti ganti
        Money(P) = 5000; //Sesuaiin aja uang awalnya berapa
        
        printf("Masukkan username: ");
        char input2[50];
        fgets(input2, sizeof(input2), stdin);
        input2[strlen(input2)-2] = '\0';
        // scanf("Masukkan jumlah uang : ",&Money(P));
        UbahMap(&P,true);
        cls();

        printf("Memulai permainan baru......\n");
        
        
        Stack SAksi, STarget;
        CreateEmptyStack(&SAksi); CreateEmptyStack(&STarget);
        material MAT = LoadMaterial("data/material.txt");
        for(int z=0;z<NMaterial;z++)
        {
            MAT.T[z].jumlah = 0;
        }
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
                upgrade(&SAksi, Money(P), J, Buka, MAT, InfoWahana, P,&L);
            } else if(IsSama(input, "buy")){
                buy(&SAksi,Money(P),J,Buka,MAT,L);
            } else if(IsSama(input, "undo")){
                UndoAksi(&SAksi,&L,&P);
            } else if(IsSama(input, "w") || IsSama(input, "a") || IsSama(input,"s") || IsSama(input,"d")){
                char C = input.TabKata[0];
                FMap(&P, C);
            } else if(IsSama(input, "main")||IsSama(input, "execute")){
                //Masukan Program loop untuk main phase
                if(IsSama(input, "execute"))
                {
                    // Proses Stack
                    // Push ke target
                    infotype X;
                    while(!IsEmptyStack(SAksi))
                    {
                        Pop(&SAksi,&X);
                        Push(&STarget,X);
                    }
                    
                    // Lakukan aksi di target
                    ProsesStack(&STarget,&P,&MAT);
                }
                else
                {
                    // Jika "main"
                    // Hapus semua isi stackavail
                    while(!IsEmptyStack(SAksi))
                    {
                        UndoAksi(&SAksi,&L,&P);
                    }
                }

                J = Buka;
                while (JLT(J, Tutup)){
                    printf("\nMain phase day %d\n", day);
                    PrintMap(CMap(P));
                    
                    PrintStatus(J, Tutup, Money(P), A);
                    printf("Masukan Perintah:\n > ");
                    InputKata(&input);

                    if (IsSama(input, "serve")){
                        
                        if (CGedung(P) == 'A'){
                            Serve(&A, &L, &J, &Money(P), &TabProses);
                        }
                        else{
                            printf("Harus berada di dekat antrian untuk menggunakan command ini.\n");
                        }
                    }
                    else if (IsSama(input, "repair")){
                        repair(P.POS, Kode(CMap(P)), &J, &TabProses, &A, &L);

                    }
                    else if(IsSama(input, "w") || IsSama(input, "a") || IsSama(input,"s") || IsSama(input,"d")){
                        char C = input.TabKata[0];
                        FMap(&P, C);
                        AdvTime(&J, 1, &TabProses, &A, &L);
                    }
                    else if(IsSama(input, "office")){
                        if (CGedung(P) = 'O') {
                            Office(L);
                        }
                        else {
                            printf("Harus berada di dalam Office untuk menggunakan command ini.\n");
                        }
                    }
                    else if(IsSama(input, "detail")){
                        if(isWahana(P)) {
                            //Nyari wahana yang di sebelah
                            POINT atas = MakePOINT(P.POS.X,P.POS.Y-1);
                            POINT kiri = MakePOINT(P.POS.X-1,P.POS.Y);
                            POINT kanan = MakePOINT(P.POS.X+1,P.POS.Y);
                            POINT bawah = MakePOINT(P.POS.X,P.POS.Y+1);
                            boolean temu = false;
                            boolean isatas, isbawah, iskiri, iskanan;
                            
                            address P2 = FirstWahana(L);
                            while(P2!=Nil && !temu)
                            {
                                isatas = ((*P2).info.lokasi.X == atas.X) && ((*P2).info.lokasi.Y == atas.Y);
                                isbawah = ((*P2).info.lokasi.X == bawah.X) && ((*P2).info.lokasi.Y == bawah.Y);
                                iskiri = ((*P2).info.lokasi.X == kiri.X) && ((*P2).info.lokasi.Y == kiri.Y);
                                iskanan = ((*P2).info.lokasi.X == kanan.X) && ((*P2).info.lokasi.Y == kanan.Y);
                                
                                if(isatas||isbawah||iskiri||iskanan)
                                {
                                    temu = true;
                                }
                                else
                                {
                                    P2 = NextWahana(P2);
                                }
                            }
                            Detail(InfoWahana(P2)); 
                        }
                        else { 
                            printf("Harus berada di dekat wahana untuk menggunakan command ini\n");
                        }
                    }
                    else if(IsSama(input, "prepare")){
                        Prepare(&A, &TabProses, &L);
                        J = Tutup;
                    } 

                }
                day++;

            } else if(IsSama(input, "exit")){
                exit = true;
            } else if(IsSama(input, "save"))
            {
                SaveGame(SAksi, P, J, M1, M2, M3, M4, L, MAT, day);
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
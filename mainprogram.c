#include <stdio.h>
#include "parser.h"
#include "mapplayer.h"
#include "map.h"


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

int main(){
    Kata input;

    printf("Welcome to Willy wangky's fun factory!!\n");
    printf("New Game/Load Game/Exit?\n");
    InputKata(&input);
    
    if(IsSama(input, "new") && !IsSama(input, "exit")){
        
        boolean exit = false;
        MAP M1,M2,M3,M4;
        PLAYER P;

        LoadAllMap(&M1,&M2,&M3,&M4);
        CreatePlayer(&P,M1,3,3); // assign player di x,y = (3,3), ini bebas nanti ganti
        UbahMap(&P,true);
        cls();

        printf("Memulai permainan baru......\n");
        

        while(!exit){
            PrintMap(CMap(P));
            printf("Masukan Perintah:\n");
            InputKata(&input);

            if(IsSama(input,"build")){
                //Build()
            } else if(IsSama(input, "upgrade")){
                //upgrade()
            } else if(IsSama(input, "buy")){
                //buy()
            } else if(IsSama(input, "w") || IsSama(input, "a") || IsSama(input,"s") || IsSama(input,"d")){
                char C = input.TabKata[0];
                FMap(&P, C, M1, M2, M3, M4);
            } else if(IsSama(input, "main")){
                //Masukan Program loop untuk main phase
            } else if(IsSama(input, "exit")){
                exit = true;
            }

        }

        cls();

    }

    printf("Thanks for playing!!\n");

    return 0;
}
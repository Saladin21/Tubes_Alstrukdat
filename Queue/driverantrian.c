#include <stdio.h>
#include "antrian.h"


int main(){
    Antrian Q;
    MakeEmptyAntrian(&Q, 10); //Membuat antrian berukuran 10
    //pengunjung P = MakePengunjung()
    Lwahana LW;
    LW.Nb = 2;
    for(int i=0; i<2;  i++){
        LW.TabID[i][0] = 'a'*i;
        LW.TabID[i][1] = 'b'*i;
        LW.TabID[i][2] = 'c'*i;
        LW.TabID[i][3] = 'd'*i;
    }
    for(int i =0; i<9; i++){
        pengunjung P = MakePengunjung(50-i, LW, 90-i, -1);
        Enqueue(&Q, P);
    }
    PrintAntrian(Q);
    ReduceKesabaran(&Q, 5);
    PrintAntrian(Q);
    printf("Banyak elemen antrian: %d\n", NBElmtAntrian(Q));
    printf("Mengecek antrian kosong atau tidak: \n");
    if (IsEmptyAntrian(Q)){
        printf("Antrian kosong\n");
    } else{
        if(IsFullAntrian(Q)){
            printf("Q tidak kosong dan full\n");
        } else{
            printf("Q tidak kosong tapi tidak full\n");
        }
    }
    pengunjung X;
    Dequeue(&Q, &X);
    printf("Menghapus antrian: \n");
    PrintAntrian(Q);
    return 0;
    
}

// gcc driverantrian.c antrian.c ../ADTLain/build.c ../List/listupgrade.c ../MainProgram/map.c -o driverantrian
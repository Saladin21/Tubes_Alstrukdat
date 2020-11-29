#include "jam.h"
#include <stdio.h>
int main()
{
    JAM J1, J2;
    BacaJAM(&J1);
    BacaJAM(&J2);
    
    printf("J1: "); TulisJAM(J1);
    printf("\nJ2: "); TulisJAM(J2);
    
    printf("\n\nMenit berikutnya dari J1 adalah "); TulisJAM(NextMenit(J1));
    printf("\n5 Menit berikutnya dari J1 adalah "); TulisJAM(NextNMenit(J1,5));
    printf("\nMenit sebelumnya dari J2 adalah "); TulisJAM(PrevMenit(J2));
    printf("\n10 Menit sebelumnya dari J2 adalah "); TulisJAM(PrevNMenit(J2,10));
    
    if(JEQ(J1,J2))
    {
        printf("\n\nJam J1 dan J2 sama.\n");
    }
    
    if(JNEQ(J1,J2))
    {
        printf("\n\nJam J1 dan J2 tidak sama.\n");
    }
    
    if(JLT(J1,J2))
    {
        printf("\n\nJam J1 lebih kecil dari J2.\n");
    }
    
    if(JGT(J1,J2))
    {
        printf("\n\nJam J1 lebih besar dari J2.\n");
    }
    
    printf("Jarak antara J1 dan J2 adalah %ld menit.\n",Durasi(J1,J2));
}
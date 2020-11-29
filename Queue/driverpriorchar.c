#include <stdio.h>
#include "prioqueuechar.h"

int main(){
    PrioQueueChar Q;
    MakeEmpty(&Q, 5);
    printf("Cek apakah Q kosong atau tidak: ");
    if (IsEmpty(Q)){
        printf("Q masih kosong\n");
    } else{
        printf("Q tidak kosong\n");
    }
    printf("\nMenginputkan Q dengan elemen 1..4\n");
    infotype p;
    for(int i=1; i<5;i++){
        Prio(p) = 5-i;
        Info(p) = i;
        Enqueue(&Q, p);
    }
    PrintPrioQueueChar(Q);
    printf("\nJumlah elemen pada Q adalah %d\n", NBElmt(Q));
    printf("Mengecek full atau tidak\n");
    if (IsFull(Q)){
        printf("Q sudah penuh\n");
    } else{
        printf("Q belum penuh\n");
    }
    infotype temp;
    Dequeue(&Q, &temp);
    printf("Elemen yang dihapus adalah (%d,%d)\n", Prio(temp), Info(temp));
    printf("Elemen Q sekarang: \n");
    PrintPrioQueueChar(Q);

}

// gcc driverpriorchar.c prioqueuechar.c -o driverprioqueue
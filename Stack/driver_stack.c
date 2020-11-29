#include "stackt.h"
#include <stdio.h>
int main()
{
    Stack S;
    infotype X;
    CreateEmptyStack(&S);
    if(IsEmptyStack(S))
    {
        printf("Saat ini Stack kosong.\n");
    }
    printf("Push ke Stack sampai penuh.\n");
    X.kodeaksi = 1;
    X.kodebarang = 1;
    X.jumlah = 5;
    X.reqtime = 30;
    
    for(int i=0;i<MaxElStack;i++)
    {
        Push(&S,X);
    }
    
    if(IsFullStack(S))
    {
        printf("Sekarang Stack penuh.\n");
    }
    
    infotype Y;
    Pop(&S,&Y);
    
    printf("Info kodeaksi Y: %d\n",Y.kodeaksi);
    for(int i=1;i<MaxElStack;i++)
    {
        Pop(&S,&Y);
    }
    
    if(IsEmptyStack(S))
    {
        printf("Sekarang Stack kosong lagi.\n");
    }
}
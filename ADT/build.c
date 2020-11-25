#include "build.h"
#include <stdio.h>
void PrintDaftarMaterial(material M)
// Mencetak daftar material beserta harganya, untuk fungsi BUY
{
    for(int i=0;i<NMaterial;i++)
    {
        printf(" - %s (%d gold/buah)\n",JenisM(M,i),HargaM(M,i));
    }
}

boolean IsMaterial(char *s, material M)
// Mengembalikan true jika s merupakan salah satu material yang ada
{
    boolean temu = false;
    int i = 0;
    while(!temu && i<NMaterial)
    {
        if(IsStringSame(s,JenisM(M,i)))
        {
            temu = true;
        }
        else
        {
            i++;
        }
    }
    return temu;
}

int IdxMaterial(char *s, material M)
// Mengembalikan index material s. Asumsi s ada.
{
    boolean temu = false;
    int i = 0;
    while(!temu && i<NMaterial)
    {
        if(IsStringSame(s,JenisM(M,i)))
        {
            temu = true;
        }
        else
        {
            i++;
        }
    }
    return i;
} 

boolean IsStringSame(char a[], char b[])
{
    boolean sama = true;
    int i = 0;
    while(a[i]!='\0' && b[i]!='\0' && sama)
    {
        if(a[i]!=b[i])
        {
            sama = false;
        }
        else
        {
            i++;
        }
    }
    return sama;
}

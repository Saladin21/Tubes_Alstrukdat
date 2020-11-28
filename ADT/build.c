#include "build.h"
#include <stdio.h>

/*****************/
/* FUNGSI BUILD */
/***************/
void PrintDaftarBuild(infowahana W[], material M)
// Mencetak daftar wahana yang bisa di-build beserta cost-nya
{
    // Kamus Lokal
    int banyakwahana;
    
    // Algoritma
    printf("Berikut adalah daftar wahana yang bisa dibangun.\n");
    for(int i=0;i<NWahana;i++)
    {
        if(IsStringSame(W[i].asalwahana,"None"))
        {
            printf(" - ");
            NamaWahana(W[i].IDawal,W);
            printf(" | %d gold ",W[i].moneyreq);
            
            // Material requirements
            for(int j=0;j<NMaterial;j++)
            {
                printf("| %d %s ",W[i].matreq[j],JenisM(M,j));
            }
            
            // Build time
            printf("| %d menit\n",W[i].durasibuild);
        }
    }
}

/********************/
/* FUNGSI MATERIAL */
/******************/
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

/***********************************/
/* FUNGSI PENGAMBILAN DATA WAHANA */
/*********************************/
void NamaWahana(char IDAwal[], infowahana W[])
// Mengembalikan nama wahana dengan ID IDAwal
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,W[i].IDawal))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    printf("%s",W[i].namawahana);
}

void DeskripsiWahana(char IDAwal[], infowahana W[])
// Mencetak deskripsi wahana dengan ID IDAwal
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,W[i].IDawal))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    printf("%s",W[i].deskripsi);
}

int KapasitasWahana(char IDAwal[], infowahana W[])
// Mengembalikan kapasistas wahana dengan ID IDAwal
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,W[i].IDawal))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return W[i].kapasitas;
}

int DurasiNaik(char IDAwal[], infowahana W[])
// Mengembalikan durasi naik wahana dengan ID IDAwal dalam menit
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,W[i].IDawal))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return W[i].durasinaik;
}

int DurasiBuild(char IDAwal[], infowahana W[])
// Mengembalikan durasi build wahana dengan ID IDAwal dalam menit
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,W[i].IDawal))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return W[i].durasibuild;
}

int HargaTiket(char IDAwal[], infowahana W[])
// Mengembalikan harga tiket wahana dengan ID IDAwal
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,W[i].IDawal))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return W[i].hargatiket;
}
#include "build.h"
#include <stdio.h>

/*****************/
/* FUNGSI BUILD */
/***************/
void PrintDaftarBuild(daftarwahana W, material M)
// Mencetak daftar wahana yang bisa di-build beserta cost-nya
{
    // Kamus Lokal
    int banyakwahana;
    
    // Algoritma
    printf("Berikut adalah daftar wahana yang bisa dibangun.\n");
    printf("  Kode | Nama Wahana | Biaya | Waktu Build\n");
    for(int i=0;i<NWahana;i++)
    {
        if(IsStringSame(AsalW(W,i),"None"))
        {
            printf(" - %s | ",IDw(W,i));
            NamaWahana(IDw(W,i),W);
            printf(" | %d gold ",MoneyreqW(W,i));
            
            // Material requirements
            for(int j=0;j<NMaterial;j++)
            {
                printf("| %d %s ",W.T[i].matreq[j],JenisM(M,j));
            }
            
            // Build time
            printf("| %d menit\n",DurasiBW(W,i));
        }
    }
}

boolean IsWahanaAwal(char *s, daftarwahana W)
// Mengembalikan true jika a adalah nama wahana yang bukan hasil upgrade
{
    boolean temu = false;
    int i = 0;
    while(!temu && i<NWahana)
    {
        if(IsStringSame(s,IDw(W,i)) && IsStringSame("None",AsalW(W,i)))
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



/*******************/
/* FUNGSI UPGRADE */
/*****************/
void PrintWahanaSekitar(PLAYER P, daftarwahana W, AllWahana L)
// Mencetak daftar wahana yang ada di kiri, atas, kanan, bawah Player P
{
    // ...
}

boolean IsWahanaNear(ID, PLAYER P, AllWahana L)
// Mengembalikan true jika wahana ID ada di sebelah P
{
    //
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
// Mengembalikan true jika 2 string a b sama
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
    
    if((a[i]=='\0' && b[i]!='\0')||(a[i]!='\0' && b[i]=='\0'))
    {
        sama = false;
    }
    
    return sama;
}

/***********************************/
/* FUNGSI PENGAMBILAN DATA WAHANA */
/*********************************/
void NamaWahana(char IDAwal[], daftarwahana W)
// Mengembalikan nama wahana dengan ID IDAwal
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,IDw(W,i)))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    printf("%s",NamaW(W,i));
}

void DeskripsiWahana(char IDAwal[], daftarwahana W)
// Mencetak deskripsi wahana dengan ID IDAwal
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,IDw(W,i)))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    printf("%s",DeskripsiW(W,i));
}

int KapasitasWahana(char IDAwal[], daftarwahana W)
// Mengembalikan kapasistas wahana dengan ID IDAwal
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,IDw(W,i)))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return KapasitasW(W,i);
}

int DurasiNaik(char IDAwal[], daftarwahana W)
// Mengembalikan durasi naik wahana dengan ID IDAwal dalam menit
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,IDw(W,i)))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return DurasiNW(W,i);
}

int DurasiBuild(char IDAwal[], daftarwahana W)
// Mengembalikan durasi build wahana dengan ID IDAwal dalam menit
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,IDw(W,i)))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return DurasiBW(W,i);
}

int HargaTiket(char IDAwal[], daftarwahana W)
// Mengembalikan harga tiket wahana dengan ID IDAwal
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,IDw(W,i)))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return HargaW(W,i);
}

int HargaBuild(char IDAwal[], daftarwahana W)
// Mengembalikan harga build wahana dengan ID IDAwal
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,IDw(W,i)))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return MoneyreqW(W,i);
}

int IdxWahana(char IDAwal[], daftarwahana W)
// Mengembalikan index wahana dengan ID IDAwal
{
    // Kamus Lokal
    boolean found = false;
    int i = 0;
    
    // Algoritma
    while(!found)
    {
        if(IsStringSame(IDAwal,IDw(W,i)))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    
    return i;
}
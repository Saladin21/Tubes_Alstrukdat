#include <stdio.h>
#include "ADT/build.h"
#include "ADT/stackt.h"
#include "ADT/jam.h"
#include <string.h>

void buy(Stack *aksi, int initialmoney, JAM initialtime, material M)
{
    // Dijalankan setelah command "buy"
    char input[20];
    int jumlah;
    int totalharga;
    int currmoney = initialmoney-500; // Belum, ceritanya ambil dari initialmoney-Stack -> buat fungsi?
    int timeremaining = 90;           // Belum, sama kaya yang atas
    int timebeli = 30;                // Waktu beli bahan apapun dan berapapun adalah 30 menit.
    infotype X;
    
    printf("Material apa yang ingin Anda beli?\n");
    PrintDaftarMaterial(M);
    printf(" > ");
    
    // Terima input
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = '\0';
    
    if(IsMaterial(input,M))
    {
        printf("\nBerapa banyak %s yang ingin Anda beli?\n > ",input);
        if(scanf("%d",&jumlah)==1 &&jumlah>0)
        {
            // Hitung total harga
            totalharga = HargaM(M,IdxMaterial(input,M))*jumlah;
            printf("\nTotal harga: %d",totalharga);
            
            // Cek jika sisa uang cukup
            if(totalharga<=currmoney)
            {
                // Cek jika sisa waktu cukup
                if(timeremaining>=timebeli)
                {
                    // Masukkan aksi ke Stack
                    X.kodeaksi = 1;
                    X.kodebarang = IdxMaterial(input,M);
                    X.jumlah = jumlah;
                    X.reqtime = timebeli;
                    Push(aksi,X);
                    printf("\nAnda berhasil membeli %d %s.\n",jumlah,input);
                }
                else
                {
                    printf("\nWaktu tidak cukup untuk melakukan aksi tersebut (BUY membutuhkan %d menit).\n",timebeli);
                }
            }
            else
            {
                printf("\nMaaf, uang Anda tidak cukup.\n");
            }
        }
        else
        {
            printf("\nAngka yang Anda masukkan tidak valid.\n");
        }
    }
    else
    {
        printf("\nMaterial yang Anda inginkan tidak tersedia.\n");
    }
}

void build(Stack *aksi, int initialmoney, JAM initialtime, material M, daftarwahana W)
{
    char input[4];
    infotype X;
    int i = 0;
    boolean matcukup = true;
    int currmoney = initialmoney-500; // Belum, ceritanya ambil dari initialmoney-Stack -> buat fungsi?
    int timeremaining = 240;           // Belum, sama kaya yang atas
    int currmat[NMaterial]; currmat[0] = 100; currmat[1] = 100; // Belum, sama kaya atas
    
    PrintDaftarBuild(W,M);
    printf("\nMasukkan kode wahana yang ingin Anda build:\n");
    printf(" > ");
    
    // Terima input
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = '\0';
    
    if(IsWahanaAwal(input,W))
    {
        // Nama wahana tersedia
        // Cek jika gold cukup
        if(currmoney>=HargaBuild(input,W))
        {
            // Cek jika material cukup
            while(matcukup && i<NMaterial)
            {
                if(currmat[i]<MaterialW(W,IdxWahana(input,W),i))
                {
                    matcukup = false;
                }
                i++;
            }
            if (matcukup)
            {
                // Cek jika waktu cukup
                if(timeremaining>=DurasiBuild(input,W))
                {
                    // Bangun wahana
                    X.kodeaksi = 2;
                    X.reqtime = DurasiBuild(input,W);
                    //X.kodebarang = GenerateIDUnik;   // Ini bikin kode unik baru buat wahana
                                                       // Addwahana
                    X.jumlah = 0;
                
                    Push(aksi,X);
                    printf("\nAnda berhasil membangun ");
                    NamaWahana(input,W);
                    printf(".\n");
                }
                else
                {
                    printf("\nWaktu tidak cukup untuk melakukan aksi tersebut.\n");
                }
                    
            }
            else
            {
                printf("\nMaaf, material Anda tidak cukup.\n");
            }                
        }
        else
        {
            printf("\nMaaf, uang Anda tidak cukup.\n");
        }
    }
    else
    {
        printf("\nWahana tersebut tidak tersedia.\n");
    }
}

void upgrade(Stack *aksi, int initialmoney, JAM initialtime, material M, daftarwahana W, PLAYER P) // plus lokasi player, Allwahna
{
    char input[4];
    infotype X;
    int i = 0;
    boolean matcukup = true;
    int currmoney = initialmoney-500; // Belum, ceritanya ambil dari initialmoney-Stack -> buat fungsi?
    int timeremaining = 240;           // Belum, sama kaya yang atas
    int currmat[NMaterial]; currmat[0] = 100; currmat[1] = 100; // Belum, sama kaya atas
    
    if(isWahana(P))
    {
        printf("\nDaftar wahana:\n");
        PrintWahanaSekitar();  //Belum
    }
    else
    {
        printf("\nTidak ada wahana di sekitar Anda.\n");
    }
    
}

// Untuk pengetesan
int main()
{
    Stack SAksi;                  // Ambil dari var program utama
    int uang = 1000; 
    JAM jamawal;
    material M;
    strcpy(M.T[0].jenis,"kayu");  // Nanti ini masukin dari file
    strcpy(M.T[1].jenis,"besi");
    M.T[0].harga = 10;
    M.T[1].harga = 15;
    CreateEmptyStack(&SAksi);
    
    // Isi data wahana
    //AllWahana L;CreateEmpty(&L);
    daftarwahana W;
    strcpy(W.T[0].IDawal,"ARS");
    strcpy(W.T[0].namawahana,"Arseille");
    strcpy(W.T[0].asalwahana,"None");
    strcpy(W.T[0].deskripsi,"Kora-kora mini dengan kapasitas maksimal 8 orang.");
    W.T[0].kapasitas = 8;
    W.T[0].hargatiket = 25;
    W.T[0].durasinaik = 10;
    W.T[0].moneyreq = 100;
    W.T[0].matreq[0] = 14;
    W.T[0].matreq[1] = 4;
    W.T[0].durasibuild = 180;
    
    strcpy(W.T[1].IDawal,"PTG");
    strcpy(W.T[1].namawahana,"Pantagruel");
    strcpy(W.T[1].asalwahana,"Arseille");
    strcpy(W.T[1].deskripsi,"Kora-kora dengan kapasitas 5 orang di tiap sisi.");
    W.T[1].kapasitas = 12;
    W.T[1].hargatiket = 40;
    W.T[1].durasinaik = 12;
    W.T[1].moneyreq = 250;
    W.T[1].matreq[0] = 5;
    W.T[1].matreq[1] = 10;
    W.T[1].durasibuild = 200;

    strcpy(W.T[2].asalwahana,"X");
    strcpy(W.T[3].asalwahana,"X");
    strcpy(W.T[4].asalwahana,"X");
    strcpy(W.T[5].asalwahana,"X");
    strcpy(W.T[6].asalwahana,"X");
    strcpy(W.T[7].asalwahana,"X");
    strcpy(W.T[8].asalwahana,"X");
    
    /*
    char kode[4] = "PTG";
    printf("Nama wahana: ");
    NamaWahana(kode,W);
    printf("\nDeskripsi  : ");
    DeskripsiWahana(kode,W);
    printf("\nKapasitas  : %d",KapasitasWahana(kode,W));
    printf("\nHarga tiket: %d",HargaTiket(kode,W));
    printf("\nDurasi naik: %d",DurasiNaik(kode,W));
    */
    
    // Tes build
    // PrintDaftarBuild(W,M);
    build(&SAksi,uang,jamawal,M,W);
    
    // Tes buy
    // buy(&SAksi,uang,jamawal,M);   // Call fungsi
    return 0;
}
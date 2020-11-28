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
        scanf("%d",&jumlah);
        if(jumlah>0)
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

void build(Stack *aksi, int initialmoney, JAM initialtime, material M, infowahana W[])
{
    char input[20];
    int currmoney = initialmoney-500; // Belum, ceritanya ambil dari initialmoney-Stack -> buat fungsi?
    int timeremaining = 90;           // Belum, sama kaya yang atas
    
    PrintDaftarBuild(W,M);
    printf("Wahana apa yang ingin Anda build?\n");
    printf(" > ");
    
    // Terima input
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = '\0';
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
    CreateEmpty(&SAksi);
    
    // Isi data wahana
    infowahana W[10];
    strcpy(W[0].IDawal,"ARS");
    strcpy(W[0].namawahana,"Arseille");
    strcpy(W[0].asalwahana,"None");
    strcpy(W[0].deskripsi,"Kora-kora mini dengan kapasitas maksimal 8 orang.");
    W[0].kapasitas = 8;
    W[0].hargatiket = 25;
    W[0].durasinaik = 10;
    W[0].moneyreq = 100;
    W[0].matreq[0] = 14;
    W[0].matreq[1] = 4;
    W[0].durasibuild = 180;
    
    strcpy(W[1].IDawal,"PTG");
    strcpy(W[1].namawahana,"Pantagruel");
    strcpy(W[1].asalwahana,"Arseille");
    strcpy(W[1].deskripsi,"Kora-kora dengan kapasitas 5 orang di tiap sisi.");
    W[1].kapasitas = 12;
    W[1].hargatiket = 40;
    W[1].durasinaik = 12;
    W[1].moneyreq = 250;
    W[1].matreq[0] = 5;
    W[1].matreq[1] = 10;
    W[1].durasibuild = 200;

    strcpy(W[2].asalwahana,"X");
    strcpy(W[3].asalwahana,"X");
    strcpy(W[4].asalwahana,"X");
    strcpy(W[5].asalwahana,"X");
    strcpy(W[6].asalwahana,"X");
    strcpy(W[7].asalwahana,"X");
    strcpy(W[8].asalwahana,"X");
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
    
    // Tes printdaftarbuild
    PrintDaftarBuild(W,M);
    
    //buy(&SAksi,uang,jamawal,M);   // Call fungsi
    return 0;
}
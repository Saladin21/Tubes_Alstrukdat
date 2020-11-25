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
    
    buy(&SAksi,uang,jamawal,M);   // Call fungsi
    return 0;
}
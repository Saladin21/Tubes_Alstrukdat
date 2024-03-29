#include "preparation.h"
#include "globalvariable.h"
void buy(Stack *aksi, int initialmoney, JAM initialtime, JAM optime, material M, AllWahana L)
{
    // Dijalankan setelah command "buy"
    char input[20]; char input2[20];
    int jumlah;
    int totalharga;
    int currmoney = initialmoney-CountReqMoney(*aksi,M,L);
    int timeremaining = Durasi(initialtime,optime)-CountReqTime(*aksi);
    int timebeli = 30;     // Waktu beli bahan apapun dan berapapun adalah 30 menit.
    infotype X;
    
    printf("\nMaterial apa yang ingin Anda beli?\n");
    PrintDaftarMaterial(M);
    printf(" > ");
    
    // Terima input
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-2] = '\0';
    
    if(IsMaterial(input,M))
    {
        printf("\nBerapa banyak %s yang ingin Anda beli?\n >> ",input);
        fgets(input2, sizeof(input2), stdin);
        input2[strlen(input2)-2] = '\0';
        jumlah = atoi(input2);
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

void build(Stack *aksi, int initialmoney, JAM initialtime, JAM optime, material M, daftarwahana W, AllWahana *L, PLAYER *Player)
{
    char input[10];
    infotype X;
    int i = 0;
    boolean matcukup = true;
    int currmoney = initialmoney-CountReqMoney(*aksi,M,*L);
    int timeremaining = Durasi(initialtime,optime)-CountReqTime(*aksi);
    int currmat[NMaterial];
    for(int j=0;j<NMaterial;j++)
    {
        currmat[j] = CountMaterialX(*aksi,M,j);
    }
    
    // Cari map player
    int map;
    if(EQ(RealMap(*Player),M1))
    {
        map = 1;
    }
    else if(EQ(RealMap(*Player),M2))
    {
        map = 2;
    }
    else if(EQ(RealMap(*Player),M3))
    {
        map = 3;
    }
    else
    {
        map = 4;
    }
        
    
    PrintDaftarBuild(W,M);
    printf("\nMasukkan kode wahana yang ingin Anda build:\n");
    printf(" >> ");
    
    // Terima input
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-2] = '\0';
    
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
                    X.jumlah = 0;
                    strcpy(X.ID,input);
                    AddWahana(input,Posisi(*Player),map,L,Player);
                    X.kodebarang = NbElmtWahana(*L);
                
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



void upgrade(Stack *aksi, int initialmoney, JAM initialtime, JAM optime, material M, daftarwahana W, PLAYER P, AllWahana *L)
{
    char input[10];
    int ID;
    infotype X;
    boolean matcukup = true;
    int currmoney = initialmoney-CountReqMoney(*aksi,M,*L);
    int timeremaining = Durasi(initialtime,optime)-CountReqTime(*aksi);
    int currmat[NMaterial];
    for(int j=0;j<NMaterial;j++)
    {
        currmat[j] = CountMaterialX(*aksi,M,j);
    }
    
    if(isWahana(P))
    {
        printf("\nDaftar wahana:\n");
        PrintWahanaSekitar(P,W,*L);  //Belum
        printf("\nMasukkan ID wahana yang ingin Anda upgrade:\n > ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input)-2] = '\0';
        ID = atoi(input);
        if(ID>0 && IsWahanaNear(ID,P,*L))
        {
            // Jika ID ada dan di sebelah P
            // Print pilihan upgrade jika ada
            address PW = FirstWahana(*L);
            boolean temu = false;
            while(PW!=Nil && !temu)
            {
                if((*PW).info.ID==ID)
                {
                    temu = true;
                }
                else
                {
                    PW = NextWahana(PW);
                }
            }
            
            
            if(IsAdaUpgrade((*PW).info.IDawal,W))
            {
                printf("\nPilihan upgrade:\n");
                PrintDaftarUpgrade((*PW).info.IDawal,W,M);
                printf("\nMasukkan kode wahana tujuan upgrade:\n");
                printf(" >> ");
    
                // Terima input
                fgets(input, sizeof(input), stdin);
                input[strlen(input)-2] = '\0';
                char nama[50];
                int k = 0;
                temu = false;
                while(k<NWahana && !temu)
                {
                    if(IsStringSame((*PW).info.IDawal,W.T[k].IDawal))
                    {
                        temu = true;
                    }
                    else
                    {
                        k++;
                    }
                }
                
                strcpy(nama,W.T[k].namawahana);
                
                if(IsWahanaUpgrade(input,nama,W))
                {
                    // Nama wahana tersedia
                    // Cek jika gold cukup
                    if(currmoney>=HargaBuild(input,W))
                    {
                        // Cek jika material cukup
                        int i =0;
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
                                X.kodeaksi = 3;
                                X.reqtime = DurasiBuild(input,W);
                                X.jumlah = 0;
                                X.kodebarang = (*PW).info.ID;
                                strcpy(X.ID,input);
                                // Ganti wahana
                                strcpy((*PW).info.IDawal,input);
                
                                Push(aksi,X);
                                printf("\nAnda berhasil meng-upgrade wahana menjadi ");
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
                    printf("\nUpgrade tersebut tidak tersedia.\n");
                }
            }
            else
            {
                printf("\nWahana ini tidak memiliki upgrade.\n");
            }
            
        }
        else
        {
            printf("\nID yang Anda masukkan tidak valid.\n");
        }
    }
    else
    {
        printf("\nTidak ada wahana di sekitar Anda.\n");
    }
    
}

/************************/
/* FUNGSI PROSES STACK */
/**********************/
int CountReqTime(Stack S)
// Mengembalikan total req time aksi stack S dalam menit
{
    int time = 0;
    infotype X;
    while(!IsEmptyStack(S))
    {
        Pop(&S,&X);
        time += X.reqtime;
    }
    return time;
}

int CountAksi(Stack S)
// Mengembalikan total aksi stack S
{
    int aksi = 0;
    infotype X;
    while(!IsEmptyStack(S))
    {
        Pop(&S,&X);
        aksi++;
    }
    return aksi;
}

int CountReqMoney(Stack S, material M, AllWahana L)
// Mengembalikan total req money waktu aksi stack S
{
    int money = 0;
    int kode;
    infotype X;
    while(!IsEmptyStack(S))
    {
        Pop(&S,&X);
        if(X.kodeaksi==1)
        {
            money += X.jumlah*HargaM(M,X.kodebarang);
        }
        else if(X.kodeaksi==2||X.kodeaksi==3)
        {
            // Jika build atau upgrade
            money += HargaBuild(X.ID,InfoWahana);
        }
    }
    return money;
}



int CountMaterialX(Stack S, material M, int i)
// Menghitung total material idx i yang dimiliki sekarang, termasuk stack
{
    int mat = M.T[i].jumlah;
    infotype X;
    while(!IsEmptyStack(S))
    {
        Pop(&S,&X);
        if(X.kodeaksi==1 && X.kodebarang==i)
        {
            mat += X.jumlah;
        }
        else if(X.kodeaksi==2 || X.kodeaksi==3)
        {
            // Jika build atua upgrade
            mat -= CostMat(X.ID,InfoWahana,i);
        }
    }
    return mat;
}

void PrintStatPlayer(Stack S,JAM inittime,JAM optime,int initmoney, material MAT, AllWahana L)
// Mencetak info seperti gold, waktu, dll.
{
    printf("Gold          : %d\n",initmoney);
    printf("Current Time  : "); TulisJAM(inittime);
    printf("\nOpening Time  : "); TulisJAM(optime);
    printf("\nTime Remaining: %ld jam %ld menit", Durasi(inittime,optime)/60,Durasi(inittime,optime)%60);
    printf("\nTotal aksi yang akan dilakukan: %d",CountAksi(S));
    printf("\nTotal waktu yang dibutuhkan   : %d jam %d menit",CountReqTime(S)/60,CountReqTime(S)%60);
    printf("\nTotal uang yang dibutuhkan    : %d gold",CountReqMoney(S,MAT,L));
    printf("\nTotal material yang dimiliki  : ");
    for(int i=0;i<NMaterial;i++)
    {
        printf("%d ",CountMaterialX(S,MAT,i));
        printf("%s ",JenisM(MAT,i));
    }
        
}

void UndoAksi(Stack *S, AllWahana *L, PLAYER *P)
// Melakukan Undo sebuah aksi
{
    infotype X;
    Wahana Y;
    if(!IsEmptyStack(*S))
    {
        Pop(S,&X);
        if(X.kodeaksi==2)
        {
            RemoveLastWahana(L,P);
        }
        else if(X.kodeaksi==3)
        {
            // Cari alamat ID wahana
            address P2 = FirstWahana(*L);
            boolean temu = false;
            while(P2!=Nil && !temu)
            {
                if((*P2).info.ID==X.kodebarang)
                {
                    temu = true;
                }
                else
                {
                    P2 = NextWahana(P2);
                }
            }
            
            // Ubah ID wahana jadi ID asal wahananya
            int index = IdxWahana((*P2).info.IDawal,InfoWahana);
            char namaasal[50];
            strcpy(namaasal,AsalW(InfoWahana,index));
            
            int i = 0;
            boolean temu2 = false;
            while(i<NWahana && !temu2)
            {
                if(IsStringSame(namaasal,NamaW(InfoWahana,i)))
                {
                    temu2 = true;
                }
                else
                {
                    i++;
                }
            }
            strcpy((*P2).info.IDawal,IDw(InfoWahana,i));
            
        }
        printf("\nAnda berhasil melakukan Undo.\n");
    }
    else
    {
        printf("\nTidak ada aksi untuk di-undo.\n");
    }
}

void ProsesStack(Stack *S, PLAYER *P, material *M)
// Melaksanakan semua aksi di stack
{
    infotype X;
    while(!IsEmptyStack(*S))
    {
        Pop(S,&X);
        if(X.kodeaksi==1)
        {
            // Jika buy
            Money(*P) -= HargaM(*M,X.kodebarang)*X.jumlah;
            JumlahM(*M,X.kodebarang) += X.jumlah;
        }
        else if(X.kodeaksi==2||X.kodeaksi==3)
        {
            // Jika build atau upgrade
            Money(*P) -= HargaBuild(X.ID,InfoWahana);
            JumlahM(*M,X.kodebarang) -= CostMat(X.ID,InfoWahana,X.kodebarang);
        }
    }
}

/*
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
    
    
    char kode[4] = "PTG";
    printf("Nama wahana: ");
    NamaWahana(kode,W);
    printf("\nDeskripsi  : ");
    DeskripsiWahana(kode,W);
    printf("\nKapasitas  : %d",KapasitasWahana(kode,W));
    printf("\nHarga tiket: %d",HargaTiket(kode,W));
    printf("\nDurasi naik: %d",DurasiNaik(kode,W));
    
    
    // Tes build
    // PrintDaftarBuild(W,M);
    build(&SAksi,uang,jamawal,M,W);
    
    // Tes buy
    // buy(&SAksi,uang,jamawal,M);   // Call fungsi
    return 0;
}
*/
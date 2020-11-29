#include "build.h"
#include <stdio.h>
#include "../globalvariable.h"
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

boolean IsWahanaNear(int ID, PLAYER P, AllWahana L)
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



// WAHANA.h

daftarwahana InfoWahana;


Wahana MakeWahana (char IDawal[], int ID, POINT lokasi, int map)
//Menghasilkan suatu wahana
{
    //KAMUS LOKAL
    Wahana W;
    ListUpgrade U;
    //ALGORITMA
    W.IDawal[0] = IDawal[0];
    W.IDawal[1] = IDawal[1];
    W.IDawal[2] = IDawal[2];
    W.IDawal[3] = IDawal[3];
    W.ID = ID;
    W.NbPengunjung = 0;
    W.dayride = 0;
    W.liferide = 0;
    W.lokasi = lokasi;
    W.map = map;

    CreateEmptyUpgrade(&U);
    InsertUpgrade(IDawal, &U);
    W.upgrade = U;


    return W;
}

boolean IsWahanaFull (Wahana W)
//Mengecek apakah kapasitas suatu wahana sudah penuh
{
    //KAMUS LOKAL

    //ALGORITMA
    return W.NbPengunjung == KapasitasWahana(W.IDawal,InfoWahana);
}

void AddWahana(char IDAwal[], POINT lokasi, int map, AllWahana *L)
//Membuat wahana baru dengan tipe IDAwal pada lokasi,
//Langsung dimasukkan ke dalam AllWahana
/*
    ID : ID terkecil yang belum ada dalam AllWahana
    NbPengunjung : 0
    status : 1
    dayride : 0
    liferide 0
*/
{
    //KAMUS LOKAL
    int ID;
    address P;
    Wahana w;
    //ALGORITMA
    ID = 1;
    P = FirstWahana(*L);

    while (P != Nil){
        if (InfoWahana(P).ID > ID){
            ID = InfoWahana(P).ID +1 ;
        }
        P = NextWahana(P);
    }

    w = MakeWahana(IDAwal, ID, lokasi, map);

    InsVLast(L, w);
}

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (AllWahana L)
/* Mengirim true jika  kosong */
{
    //KAMUS LOKAL

    //ALGORITMA
    return FirstWahana(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyWahana (AllWahana *L)
/* I.S. sembarang             */
/* F.S. Terbentuk AllWahana kosong */
{
    //KAMUS LOKAL

    //ALGORITMA
    FirstWahana(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address AlokWahana (Wahana X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    P = (address) malloc(sizeof(ElmtList));

    if (P != Nil){
        InfoWahana(P) = X;
        NextWahana(P) = Nil;
    }

    return P;
    
}
void DealokWahana (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    //KAMUS LOKAL

    //ALGORITMA
    free(P);
    
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchWahana (AllWahana L, int ID)
/* Mencari apakah ada elemen list dengan ID */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    /*KAMUS LOKAL*/
    address P;
    boolean found;
    /*ALGORITMA*/
    P = FirstWahana(L);
    found = false;
    while(P != Nil && !found){
        if (InfoWahana(P).ID==ID){
            found = true;
        }
        else{
            P = NextWahana(P);
        }
    }
    if (found){
        return P;
    }
    else{
        return Nil;
    }
    
}
boolean FSearchWahana (AllWahana L, int ID)
/* Mencari apakah ada elemen list dengan ID */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    //KAMUS LOKAL

    //ALGORITMA
    return SearchWahana(L, ID) != Nil;
}
address SearchWahanaKosong (AllWahana L, char IDAwal[])
//Mengembalikan address wahana dengan IDAwal yang pertama tidak penuh
//Jika tidak ada mengembalikan nil
{
    /*KAMUS LOKAL*/
    address P;
    boolean found;
    /*ALGORITMA*/
    P = FirstWahana(L);
    found = false;
    while(P != Nil && !found){
        if (IsStringSame(InfoWahana(P).IDawal, IDAwal)){
            if(!IsWahanaFull(InfoWahana(P)) && InfoWahana(P).status == 1 ){
                found = true;
            }
        }
        else{
            P = NextWahana(P);
        }
    }
    if (found){
        return P;
    }
    else{
        return Nil;
    }
    
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (AllWahana *L, Wahana X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    //KAMUS LOKAL

    //ALGORITMA
    InsertFirst(L, AlokWahana(X));
}
void InsVLast (AllWahana *L, Wahana X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    //KAMUS LOKAL

    //ALGORITMA
    InsertLast(L, AlokWahana(X));
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (AllWahana *L, Wahana *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    DelFirst(L, &P);
    *X = InfoWahana(P);
    DealokWahana(P);
    
}
void DelVLast (AllWahana *L, Wahana *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    DelLast(L, &P);
    *X = InfoWahana(P);
    DealokWahana(P);
    
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (AllWahana *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    //KAMUS LOKAL

    //ALGORITMA
    NextWahana(P) = FirstWahana(*L);
    FirstWahana(*L) = P;
    
}
void InsertAfter (AllWahana *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    //KAMUS LOKAL

    //ALGORITMA
    NextWahana(P) = NextWahana(Prec);
    NextWahana(Prec) = P;
}
void InsertLast (AllWahana *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    /*KAMUS LOKAL*/
    address P1;
    /*ALGORITMA*/
    if (FirstWahana(*L)==Nil){
        FirstWahana(*L) = P;
    }
        else{
        P1 = FirstWahana(*L);

        while (NextWahana(P1) != Nil){
            P1 = NextWahana(P1);
        }

        NextWahana(P1) = P;
    }
    
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (AllWahana *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    //KAMUS LOKAL

    //ALGORITMA
    *P = FirstWahana(*L);
    FirstWahana(*L) = NextWahana(*P);
    NextWahana(*P)= Nil;
}
void DelP (AllWahana *L, int ID)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
     /*KAMUS LOKAL*/
    address P, prec;
    /*ALGORITMA*/
    prec = Nil;
    P = FirstWahana(*L);

    if (P != Nil){
        while (InfoWahana(P).ID != ID && NextWahana(P) != Nil){
            prec = P;
            P = NextWahana(P);
        }

        if ( InfoWahana(P).ID == ID){
            if (prec == Nil){
                FirstWahana(*L) = NextWahana(P);
            }
            else{
                NextWahana(prec) = NextWahana(P);
            }
            DealokWahana(P);
        }

    }
    
}
void DelLast (AllWahana *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    /*KAMUS LOKAL*/
    address p1, prec;
    /*ALGORITMA*/
    prec = Nil;
    p1 = FirstWahana(*L);
    
    while (NextWahana(p1) != Nil){
        prec = p1;
        p1 = NextWahana(p1);
    }

    *P = p1;

    if (prec != Nil){    
        NextWahana(prec) = Nil;
    }
    else{
        FirstWahana(*L) = Nil;
    }
    
}
void DelAfter (AllWahana *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    //KAMUS LOKAL

    //ALGORITMA
    *Pdel = NextWahana(Prec);
    NextWahana(Prec) = NextWahana(*Pdel);
    NextWahana(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintAllWahana (AllWahana L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    
    P = FirstWahana(L);
    if (P != Nil){
        while(P != Nil){
            printf("%d ", InfoWahana(P).ID);
            NamaWahana(InfoWahana(P).IDawal, InfoWahana);
            printf("\n");
            P = NextWahana(P);
        }
    }
    
    
}


void PrintInfo (Wahana W)
//Menamppilkan detail wahana
{
    //KAMUS LOKAL

    //ALGORITMA
    NamaWahana(W.IDawal, InfoWahana);
    printf("\n");
    printf("Harga : %d\n", HargaTiket(W.IDawal, InfoWahana));
    printf("Lokasi:");
    TulisPOINT(W.lokasi);
    printf("\n");
    printf("Deskripsi :\n");
    DeskripsiWahana(W.IDawal, InfoWahana);
    printf("\n");
    printf("Kapasitas : %d\n", HargaTiket(W.IDawal, InfoWahana));
    printf("History upgrade: ");
    PrintUpgrade(W.upgrade);
    printf("\n");
    printf("Durasi : %d\n", HargaTiket(W.IDawal, InfoWahana));
}
int NbElmtWahana (AllWahana L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    /*KAMUS LOKAL*/
    int count;
    address P;
    /*ALGORITMA*/
    count = 0;
    P = FirstWahana(L);

    while(P != Nil){
        count++;
        P = NextWahana(P);
    }
    
    return count;
    
}
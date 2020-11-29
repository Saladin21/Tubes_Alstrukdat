#include "wahana.h"
#include "ADT/build.h"

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
    return W.NbPengunjung == KapasitasWahana(W.IDawal, InfoWahana);
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

    while (P != NilWahana){
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
boolean IsEmptyWahana (AllWahana L)
/* Mengirim true jika  kosong */
{
    //KAMUS LOKAL

    //ALGORITMA
    return FirstWahana(L) == NilWahana;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyWahana (AllWahana *L)
/* I.S. sembarang             */
/* F.S. Terbentuk AllWahana kosong */
{
    //KAMUS LOKAL

    //ALGORITMA
    FirstWahana(*L) = NilWahana;
}

/****************** Manajemen Memori ******************/
address AlokWahana (Wahana X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NilWahana, dan misalnya */
/* menghasilkan P, maka info(P)=X, NextWahana(P)=NilWahana */
/* Jika alokasi gagal, mengirimkan NilWahana */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    P = (address) malloc(sizeof(ElmtList));

    if (P != NilWahana){
        InfoWahana(P) = X;
        NextWahana(P) = NilWahana;
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
/* Jika tidak ada, mengirimkan NilWahana */
{
    /*KAMUS LOKAL*/
    address P;
    boolean found;
    /*ALGORITMA*/
    P = FirstWahana(L);
    found = false;
    while(P != NilWahana && !found){
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
        return NilWahana;
    }
    
}
boolean FSearchWahana (AllWahana L, int ID)
/* Mencari apakah ada elemen list dengan ID */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    //KAMUS LOKAL

    //ALGORITMA
    return SearchWahana(L, ID) != NilWahana;
}
address SearchWahanaKosong (AllWahana L, char IDAwal[])
//Mengembalikan address wahana dengan IDAwal yang pertama tidak penuh
//Jika tidak ada mengembalikan NilWahana
{
    /*KAMUS LOKAL*/
    address P;
    boolean found;
    /*ALGORITMA*/
    P = FirstWahana(L);
    found = false;
    while(P != NilWahana && !found){
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
        return NilWahana;
    }
    
}


/****************** PRIMITIF BERDASARKAN NilWahanaAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (AllWahana *L, Wahana X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilWahanaai X jika alokasi berhasil */
{
    //KAMUS LOKAL

    //ALGORITMA
    InsertFirst(L, AlokWahana(X));
}
void InsVLast (AllWahana *L, Wahana X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilWahanaai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    //KAMUS LOKAL

    //ALGORITMA
    InsertLast(L, AlokWahana(X));
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (AllWahana *L, Wahana *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilWahanaai info disimpan pada X */
/*      dan alamat elemen pertama di-DealokWahana */
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
/* F.S. Elemen terakhir list dihapus: NilWahanaai info disimpan pada X */
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
    if (FirstWahana(*L)==NilWahana){
        FirstWahana(*L) = P;
    }
        else{
        P1 = FirstWahana(*L);

        while (NextWahana(P1) != NilWahana){
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
    NextWahana(*P)= NilWahana;
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
    prec = NilWahana;
    P = FirstWahana(*L);

    if (P != NilWahana){
        while (InfoWahana(P).ID != ID && NextWahana(P) != NilWahana){
            prec = P;
            P = NextWahana(P);
        }

        if ( InfoWahana(P).ID == ID){
            if (prec == NilWahana){
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
    prec = NilWahana;
    p1 = FirstWahana(*L);
    
    while (NextWahana(p1) != NilWahana){
        prec = p1;
        p1 = NextWahana(p1);
    }

    *P = p1;

    if (prec != NilWahana){    
        NextWahana(prec) = NilWahana;
    }
    else{
        FirstWahana(*L) = NilWahana;
    }
    
}
void DelAfter (AllWahana *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus NextWahana(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    //KAMUS LOKAL

    //ALGORITMA
    *Pdel = NextWahana(Prec);
    NextWahana(Prec) = NextWahana(*Pdel);
    NextWahana(*Pdel) = NilWahana;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintAllWahana (AllWahana L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilWahanaai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    
    P = FirstWahana(L);
    if (P != NilWahana){
        while(P != NilWahana){
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

    while(P != NilWahana){
        count++;
        P = NextWahana(P);
    }
    
    return count;
    
}
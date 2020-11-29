//Nama/NIM : Ahmad Saladin/13519187
//Tanggal : 3 November 2020
//Topik : ADT List linier
//Deskripsi : realisasi ADT List linier
#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    P = (address) malloc(sizeof(ElmtList));

    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }

    return P;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    /*KAMUS LOKAL*/
    address P;
    boolean found;
    /*ALGORITMA*/
    P = First(L);
    found = false;
    while(P != Nil && !found){
        if (Info(P)==X){
            found = true;
        }
        else{
            P = Next(P);
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
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    InsertFirst(L, Alokasi(X));
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    InsertLast(L, Alokasi(X));
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
    
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    /*KAMUS LOKAL*/
    
    /*ALGORITMA*/
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    /*KAMUS LOKAL*/
    address P1;
    /*ALGORITMA*/
    if (First(*L)==Nil){
        First(*L) = P;
    }
        else{
        P1 = First(*L);

        while (Next(P1) != Nil){
            P1 = Next(P1);
        }

        Next(P1) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P)= Nil;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    /*KAMUS LOKAL*/
    address P, prec;
    /*ALGORITMA*/
    prec = Nil;
    P = First(*L);

    if (P != Nil){
        while (Info(P) != X && Next(P) != Nil){
            prec = P;
            P = Next(P);
        }

        if ( Info(P) == X){
            if (prec == Nil){
                First(*L) = Next(P);
            }
            else{
                Next(prec) = Next(P);
            }
            Dealokasi(&P);
        }

    }
    
}
void DelLast (List *L, address *P)
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
    p1 = First(*L);
    
    while (Next(p1) != Nil){
        prec = p1;
        p1 = Next(p1);
    }

    *P = p1;

    if (prec != Nil){    
        Next(prec) = Nil;
    }
    else{
        First(*L) = Nil;
    }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    printf("[");
    P = First(L);
    if (P != Nil){
        while(Next(P) != Nil){
            printf("%d,", Info(P));
            P = Next(P);
        }
        printf("%d", Info(P));
    }
    printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    /*KAMUS LOKAL*/
    int count;
    address P;
    /*ALGORITMA*/
    count = 0;
    P = First(L);

    while(P != Nil){
        count++;
        P = Next(P);
    }
    
    return count;
}

/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L)
/* Mengirimkan nilai Info(P) yang minimum */
{
    /*KAMUS LOKAL*/
    infotype min;
    address P;
    /*ALGORITMA*/
    P = First(L);
    min = Info(P);

    while(P != Nil){
        P = Next(P);
        if (P != Nil){
            if (Info(P) < min){
                min = Info(P);
            }
        }
    }

    return min;
    
}

/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    /*KAMUS LOKAL*/
    infotype max;
    address P;
    /*ALGORITMA*/
    P = First(L);
    max = Info(P);

    while(P != Nil){
        P = Next(P);
        if (P != Nil){
            if (Info(P) > max){
                max = Info(P);
            }
        }
    }

    return max;
    
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    /*KAMUS LOKAL*/
    address P;
    /*ALGORITMA*/
    First(*L3) = First(*L1);
    if (First(*L3)== Nil){
        First(*L3) = First(*L2);
    }else{
        P = First(*L2);
        InsertLast(L3, P);
    }

    First(*L1) = Nil;
    First(*L2) = Nil;
}
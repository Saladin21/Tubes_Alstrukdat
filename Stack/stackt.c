#include "stackt.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 0.. MaxElStack */
/* Ciri stack kosong : TOP berNilStackai NilStack */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    return Top(S) == NilStack;
}
boolean IsFull (Stack S)
/* Mengirim true jika tabel penampung NilStackai elemen stack penuh */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    return Top(S) == MaxElStack-1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilStackai elemen TOP yang lama, TOP berkurang 1 */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    *X = InfoTop(*S);
    if (Top(*S) != 0){
        Top(*S) -= 1;
    }
    else{
        Top(*S) = NilStack;
    }
}
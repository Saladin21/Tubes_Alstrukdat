#include "listupgrade.h"

daftarwahana InfoWahana;

boolean IsEmptyUpgrade (ListUpgrade L)
/* Mengirim true jika list kosong */
{
    //KAMUS LOKAL

    //ALGORITMA
    return L.First == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyUpgrade (ListUpgrade *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    //KAMUS LOKAL

    //ALGORITMA
    L->First = NULL;
}

/****************** Manajemen Memori ******************/
addrupgrade Alokupgrade (char X[])
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    //KAMUS LOKAL
    addrupgrade P;
    //ALGORITMA
    P = (addrupgrade) malloc(sizeof(ElmtListUpgrade));

    if (P != NULL){
        P->next = NULL;
        P->IDawal[0] = X[0];
        P->IDawal[1] = X[1];
        P->IDawal[2] = X[2];
        P->IDawal[3] = X[3];
    }
}

void Dealokupgrade (addrupgrade P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    //KAMUS LOKAL

    //ALGORITMA
    free(P);
}

void InsertUpgrade(char IDawal[], ListUpgrade *U)
//Menambahkan elemen berisi IDawal di akhir list
{
    /*KAMUS LOKAL*/
    addrupgrade P, P1;
    /*ALGORITMA*/
    P = Alokupgrade(IDawal);
    if (U->First == NULL){
        U->First = P;
    }
    else{
        P1 = U->First;

        while (P1->next != NULL){
            P1 = P->next;
        }

        P1->next = P;
    }

}

void PrintUpgrade(ListUpgrade U)
//Menampilkan History upgrade
{
    //KAMUS LOKAL
    addrupgrade P;
    //ALGORITMA
    P = U.First;
    
    if(!IsEmptyUpgrade(U)){
        while(P->next != NULL){
            NamaWahana(P->IDawal, InfoWahana);
            printf(" --> ");
            P = P->next;
        }
        NamaWahana(P->IDawal, InfoWahana);

    }

}
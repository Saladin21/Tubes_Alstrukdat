#ifndef listupgrade_H
#define listupgrade_H

#include "../ADTLain/boolean.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct tElmtlistUpgrade *addrupgrade;
typedef struct tElmtlistUpgrade {
	char IDawal[4];
	addrupgrade next;
} ElmtListUpgrade;

typedef struct {
	addrupgrade First;
} ListUpgrade;





/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyUpgrade (ListUpgrade L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyUpgrade (ListUpgrade *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addrupgrade Alokupgrade (char X[]);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokupgrade (addrupgrade P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

void InsertUpgrade(char IDawal[], ListUpgrade *U);
//Menambahkan elemen berisi IDawal di akhir list

void PrintUpgrade(ListUpgrade U);
//Menampilkan History upgrade



#endif
#include <stdio.h>
#include "ADT/build.h"
#include "ADT/stackt.h"
#include "ADT/jam.h"
#include <string.h>

void buy(Stack *aksi, int initialmoney, JAM initialtime, JAM optime, material M);

void build(Stack *aksi, int initialmoney, JAM initialtime, material M, daftarwahana W);

/************************/
/* FUNGSI PROSES STACK */
/**********************/
int CountReqTime(Stack S);
// Mengembalikan total req time aksi stack S dalam menit
int CountAksi(Stack S);
// Mengembalikan total aksi stack S
int CountReqMoney(Stack S, material M);
// Mengembalikan total req money waktu aksi stack S

void PrintStatPlayer(Stack S,JAM inittime,JAM optime,int initmoney, material MAT);
// Mencetak info seperti gold, waktu, dll.

void UndoAksi(Stack *S);
// Melakukan Undo sebuah aksi
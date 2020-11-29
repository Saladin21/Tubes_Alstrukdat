#include <stdio.h>
#include "ADT/build.h"
#include "ADT/stackt.h"
#include "ADT/jam.h"
#include <string.h>
#include "map.h"

void buy(Stack *aksi, int initialmoney, JAM initialtime, JAM optime, material M, AllWahana L);

void build(Stack *aksi, int initialmoney, JAM initialtime, JAM optime, material M, daftarwahana W, AllWahana *L, PLAYER *Player);

void upgrade(Stack *aksi, int initialmoney, JAM initialtime, material M, daftarwahana W, PLAYER P, AllWahana *L);

/************************/
/* FUNGSI PROSES STACK */
/**********************/
int CountReqTime(Stack S);
// Mengembalikan total req time aksi stack S dalam menit
int CountAksi(Stack S);
// Mengembalikan total aksi stack S

int CountReqMoney(Stack S, material M, AllWahana L);
// Mengembalikan total req money waktu aksi stack S
int CountMaterialX(Stack S, material M, int i);
// Menghitung total material idx i yang dimiliki sekarang, termasuk stack

void PrintStatPlayer(Stack S,JAM inittime,JAM optime,int initmoney, material MAT, AllWahana L);
// Mencetak info seperti gold, waktu, dll.

void UndoAksi(Stack *S, AllWahana *L);
// Melakukan Undo sebuah aksi

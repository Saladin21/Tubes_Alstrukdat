#include<stdio.h>
#include<stdlib.h>
#include "antrian.h"
#include "../ADT/arraypos.h"

daftarwahana InfoWahana;

int SearchLwahana(char IDawal[], Lwahana L){
    //Kamus LOKAL
    int i;
    //ALGORITMA
    for(i=0;i<L.Nb;i++){
        if (IsStringSame(IDawal, L.Nb)){
            return i;
        }
    }
    return -1;
}

void DelLwahana(Lwahana *L, int index){
    //KAMUS LOKAL
    int i;
    //ALGORITMA
    if (index < (L->Nb)-1){
        for (i==index;i<(L->Nb)-1;i++){
            L->TabID[i][0] = L->TabID[i+1][0];
            L->TabID[i][1] = L->TabID[i+1][1];
            L->TabID[i][2] = L->TabID[i+1][2];
            L->TabID[i][3] = L->TabID[i+1][3];
        }
    }
    L->Nb--;
}

/* ********* Prototype ********* */
boolean IsEmptyAntrian (Antrian Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    return Head(Q) == Nil && Tail(Q)==Nil;
}
boolean IsFullAntrian (Antrian Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    return Tail(Q) == ((Head(Q) - 1) + MaxEl(Q)) % MaxEl(Q);
}
int NBElmtAntrian (Antrian Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    /*KAMUS LOKAL*/
    int count = 0;
    int i;
    /*ALGORITMA*/
    i = Head(Q);
    while (i != Tail(Q)){
        if(i>=MaxEl(Q)){
            i = i % MaxEl(Q);
        }
        else{
            count++;
            i++;
        }
    }
    if (Tail(Q) != Nil){
        count++;
    }
    return count;
}
/* *** Kreator *** */

pengunjung MakePengunjung(int prio, Lwahana info, int kesabaran, int current){
    pengunjung P;

    P.prio = prio;
    P.current = current;
    P.info = info;
    P.kesabaran = kesabaran;

    return P;
}

void MakeEmptyAntrian (Antrian * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    (*Q).T = (pengunjung*) malloc ((Max) * sizeof(pengunjung));
    if ((*Q).T != NULL){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }else{
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(Antrian * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    free((*Q).T);
    MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Enqueue (Antrian * Q, pengunjung X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    /*KAMUS LOKAL*/
    int i;
    int j, k;
    boolean tukar;
    pengunjung temp;
    /*ALGORITMA*/
    if(IsEmptyAntrian(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        Elmt(*Q,0) = X;
    }
    else{
        i = (Tail(*Q) + 1);
        if (i>=MaxEl(*Q)){
            i = i % MaxEl(*Q);
        }
        Tail(*Q) = i;
        Elmt(*Q, i) = X;

        j = Tail(*Q);
        k = (j-1 + MaxEl(*Q)) % MaxEl(*Q);
        if (Prio(Elmt(*Q, j))<Prio(Elmt(*Q, k))){
            tukar = true;
        }

        while (j != Head(*Q) && tukar){
            if (Prio(Elmt(*Q, k))<=Prio(Elmt(*Q, j))){
                tukar = false;
            }
            else{
                temp = Elmt(*Q, j);
                Elmt(*Q, j) = Elmt(*Q, k);
                Elmt(*Q, k) = temp;

                j = (j-1 + MaxEl(*Q)) % MaxEl(*Q);
                k = (j-1 + MaxEl(*Q)) % MaxEl(*Q);

            }
        } 
    }
}
        
void Dequeue (Antrian * Q, pengunjung * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    *X = InfoHead(*Q);
    if (NBElmtAntrian(*Q)==1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else{
        i = (Head(*Q) + 1);
        if (i>=MaxEl(*Q)){
            i = i % MaxEl(*Q);
        }
        Head(*Q) = i;
    }
}

/* Operasi Tambahan */
void PrintAntrian (Antrian Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    /*KAMUS LOKAL*/
    int i,j;
    boolean tail=false;
    Lwahana Lwahana;
    /*ALGORITMA*/
    printf("Antrian [%d/%d]:\n", NBElmtAntrian(Q), Q.MaxEl);
    if (!IsEmptyAntrian(Q)){
        i = Head(Q);
        while (!tail){
            if(i>=MaxEl(Q)){
                i= i% MaxEl(Q);
            }
            if(i==Tail(Q)){
                tail = true;
            }
            Lwahana = Elmt(Q,i).info;
            for (j=0;j<Lwahana.Nb;j++){
                NamaWahana(Lwahana.TabID[i], InfoWahana);
                printf(", ");
            }

            printf("Prioritas: %d, ", Prio(Elmt(Q,i)));
            printf("Kesabaran: %d\n", Elmt(Q,i).kesabaran);
            i++;
        }
    }
    printf("\n");
}

void ReduceKesabaran(Antrian *Q, int X)
//Mengurangi kesabaran setiap pengunjung dalam antrian sebesar X
{
    //KAMUS LOKAL
    int i;
    boolean tail=false;
    //ALGORITMA
    if (!IsEmptyAntrian(*Q)){
        i = Head(*Q);
        while (!tail){
            if(i>=MaxEl(*Q)){
                i= i% MaxEl(*Q);
            }
            if(i==Tail(*Q)){
                tail = true;
            }
            Q->T[i].kesabaran = Q->T[i].kesabaran -X;
        }
    }
}
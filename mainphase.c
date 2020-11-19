#include "mainphase.h"




void Serve (Prioqueue *A, Wahana *W, JAM *T, int *money)
//I.S. Pemain berada di sebelah antrian
//F.S. Pengunjung pertama dalam antrian dilayani sesuai input wahana jika
//wahana tersebut ada di daftar milik pengunjung dan tidak penuh, waktu dan uang akan bertambah
{
    //KAMUS LOKAl
    infotype X;
    //ALGORITMA
    X = InfoHead(*A);
    if (SearchB(X.info, W->ID) && W->NbPengunjung<W->Kapasitas){
        Dequeue(A, &X);

    }
}

void repair (Wahana *W, JAM *T)
//I.S. pemain berada di sebelah wahana
//F.S. wahana rusak yang berada di sebelah posisi pemain diperbaiki dan waktu bertambah
{
    //KAMUS LOKAl

    //ALGORITMA
    W->status = 1;
    
}

void Detail ()
//I.S. pemain berada di sebelah wahana
//F.S. Menampilkan detail dari wahana yang berada di sebelah pemain
{
    //KAMUS LOKAl

    //ALGORITMA
    
}

void Office()
//I.S. Pemain berada di sebelah office
//Menampilkan tampilan office
{
    //KAMUS LOKAl

    //ALGORITMA
    
}

void Prepare()
//I.S. Sembarang
//F.S. Antrian kosong dan masuk ke preparation phase
{
    //KAMUS LOKAl

    //ALGORITMA
    
}

void AdvTime (JAM *J, int durasi, TabProses *P, Prioqueue *A, Wahana W)
//Memajukan jam sebanyak durasi detik
{
	//KAMUS LOKAl
    infotype P1;
    TabProses T2;
	//Algoritma
	*J = DetikToJAM(JAMToDetik(*J) + durasi);
    Proses(P, durasi);
    Sort(P);
    while (P->NbElmt>1 && P->Tab[0].durasi<=0){
        DelAt(P, 0, &P1);
        //Pengguna wahana -1
        P1.current = -1;
        P1.prio++;
        Enqueue(A, P1);
        
    }
}
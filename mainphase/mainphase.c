#include "mainphase.h"
#include "../parser.h"



void Serve (Antrian *A, Wahana *W, JAM *T, int *money, TabProses *Tab)
//I.S. Pemain berada di sebelah antrian
//F.S. Pengunjung pertama dalam antrian dilayani sesuai input wahana jika
//wahana tersebut ada di daftar milik pengunjung dan tidak penuh, waktu dan uang akan bertambah
{
    //KAMUS LOKAl
    pengunjung X;
    proses P;
    TabInt ListWahana;
    int n,i;
    //ALGORITMA
    X = InfoHead(*A);
    ListWahana = X.info;
    n = NbElmt(ListWahana);
    for (i==1;i<=n;i++){
        
    }


    if (SearchB(X.info, W->ID) && W->NbPengunjung<W->Kapasitas){
        Dequeue(A, &X);
        P = MakeProses(X, W->Durasi);
        insert(Tab, P);

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

void Detail (address P)
//I.S. pemain berada di sebelah wahana
//F.S. Menampilkan detail dari wahana yang berada di sebelah pemain
{
    //KAMUS LOKAl

    //ALGORITMA
    //PrintInfo(P);
}

void Office(AllWahana L)
//I.S. Pemain berada di sebelah office
//Menampilkan tampilan office
{
    //KAMUS LOKAl
    Kata input;
    int id;
    address P;
    boolean office = true;
    //ALGORITMA
    while (office) {
        printf("Masukkan perintah (Details / Report / Exit):\n");
        InputKata(&input);
        if(IsSama(input,"Details")) {
            //printAllWahana();
            printf("Pilih ID dari wahana yang ingin ditampilkan detailnya\n");
            scanf("%d", &id);
            P = SearchWahana(L,id);
            Detail(P);
        } else if(IsSama(input,"Report")) {
            //printAllWahana();
            printf("Pilih ID dari wahana yang ingin ditampilkan reportnya\n");
            scanf("%d", &id);
            P = SearchWahana(L,id);
            int hargalife = InfoWahana(P).liferide /* * HargaTiket() */ ;
            int hargaday = InfoWahana(P).dayride /* * HargaTiket() */ ;
            printf("Total wahana dinaiki keseluruhan : %d\n", InfoWahana(P).liferide);
            printf("Total penghasilan dari wahana keseluruhan : %d\n", hargalife);
            printf("Total wahana dinaiki hari ini : %d\n", InfoWahana(P).dayride);
            printf("Total penghasilan dari wahana hari ini : %d\n", hargaday);
        } else if(IsSama(input,"Exit")) {
            printf("Keluar dari office mode\n");
            office = false;
        }
    }
}

void Prepare(Antrian *A)
//I.S. Sembarang
//F.S. Antrian kosong dan masuk ke preparation phase
{
    //KAMUS LOKAl

    //ALGORITMA
    Head(*A) = Nil;
    Tail(*A) = Nil;
}

void AdvTime (JAM *J, int menit, TabProses *P, Antrian *A, Wahana W)
//Memajukan jam sebanyak durasi detik
{
	//KAMUS LOKAl
    pengunjung P1;
    TabProses T2;
	//Algoritma
	*J = DetikToJAM(JAMToDetik(*J) + menit*60);
    Proses(P, menit);
    SortProses(P);
    while (P->NbElmt>1 && P->Tab[0].durasi<=0){
        DelAt(P, 0, &P1);
        //Pengguna wahana -1
        P1.current = -1;
        P1.prio++;
        Enqueue(A, P1);
        
    }
}
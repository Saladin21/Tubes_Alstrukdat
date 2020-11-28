#include "mainphase.h"


infowahana InfoWahana[];

void Serve (Antrian *A, AllWahana *L, JAM *T, int *money, TabProses *Tab)
//I.S. Pemain berada di sebelah antrian
//F.S. Pengunjung pertama dalam antrian dilayani sesuai input wahana jika
//wahana tersebut ada di daftar milik pengunjung dan tidak penuh, waktu dan uang akan bertambah
{
    //KAMUS LOKAl
    pengunjung X;
    proses P;
    address a1;
    int i, a;
    //ALGORITMA
    X = InfoHead(*A);

    for (i=0;i<X.info.Nb;i++){
        printf("%d. ", i);
        NamaWahana(X.info.TabID[i], InfoWahana);
        printf("\n");
    }
    scanf("Pilih wahana: %d", &a);
    
    
    a1 = SearchWahanaKosong(*L, X.info.TabID[a]);

    if (a1 != Nil){
        InfoWahana(a1).NbPengunjung ++; //Update jumlah pengunjung dalam wahana
        InfoWahana(a1).dayride ++;
        InfoWahana(a1).liferide ++;

        *money = *money + HargaTiket(InfoWahana(a1).IDawal, InfoWahana); //tambah uang

        Dequeue(A, &X); //Mengeluarkan dari antrian
        
        /*Di sini hapus wahana yang akan dinaiki dari list pengunjung*/

        //masuk ke proses
        X.current = InfoWahana(a1).ID;
        P = MakeProses(X, DurasiNaik(InfoWahana(a1).IDawal, InfoWahana));

        insert(Tab, P);

        //Memajukan waktu 5 menit
        AdvTime(T, 5, Tab, A, L);

    }
    else{
        printf("Wahana penuh.\n");
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

void Detail (Antrian *A)
//I.S. pemain berada di sebelah wahana
//F.S. Menampilkan detail dari wahana yang berada di sebelah pemain
{
    //KAMUS LOKAl

    //ALGORITMA
    Head(*A) = Nil;
    Tail(*A) = Nil;
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

void AdvTime (JAM *J, int durasi, TabProses *Tab, Antrian *A, AllWahana *L)
//Memajukan jam sebanyak durasi menit
{
	//KAMUS LOKAl
    pengunjung P1;
    TabProses T2;
    address a1;
    int id;
	//Algoritma
	*J = DetikToJAM(JAMToDetik(*J) + durasi*60); //Memajukan waktu
     
    Proses(Tab, durasi); //Memproses pengunjung
    SortProses(Tab); //Menyortir

    //Mengembalikan pengunjung yang sudah selesai ke antrian
    while (Tab->NbElmt>1 && Tab->Tab[0].durasi<=0){
        DelAt(Tab, 0, &P1);
        //Pengguna wahana -1
        id = P1.current;
        a1 = SearchWahana(*L, id);
        InfoWahana(a1).NbPengunjung--;

        /*Di sini cek apakah pengunjung mau menaiki wahana lain*/
        
        P1.current = -1;
        P1.prio++;
        Enqueue(A, P1);

    }
}
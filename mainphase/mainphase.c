#include "mainphase.h"
#include "../parser.h"

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

void AdvTime (JAM *J, int durasi, TabProses *Tab, Antrian *A, AllWahana *L)
//Memajukan jam sebanyak durasi menit
{
	//KAMUS LOKAl
    pengunjung P1;
    TabProses T2;
    address a1;
    int id;
	//Algoritma
	*J = MenitToJAM(JAMToMenit(*J) + durasi); //Memajukan waktu
     
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
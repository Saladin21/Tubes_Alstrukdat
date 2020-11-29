#include "mainphase.h"
#include "../MesinKarakter_MesinKata/parser.h"

#include "globalvariable.h"

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
    char input[10];
    //ALGORITMA
    if (!IsEmptyAntrian(*A)){
        X = InfoHead(*A);

        if (X.kesabaran <= 0){
            printf("Pengunjung sudah pergi karena kesabarannya habis.\n");
            Dequeue(A, &X);
        }
        else{

            for (i=0;i<X.info.Nb;i++){
                printf("%d. ", (i+1));
                NamaWahana(X.info.TabID[i], InfoWahana);
                printf("\n");
            }
            printf("Pilih wahana: ");
            fgets(input, sizeof(input), stdin);
            input[strlen(input)-2] = '\0';
            a = atoi(input);
            //scanf("%d", &a);
            
            if (a>0 && a<=X.info.Nb){
                a1 = SearchWahanaKosong(*L, X.info.TabID[a-1]);

                    if (a1 != NULL){
                        InfoWahana(a1).NbPengunjung ++; //Update jumlah pengunjung dalam wahana
                        InfoWahana(a1).dayride ++;
                        InfoWahana(a1).liferide ++;

                        *money = *money + HargaTiket(InfoWahana(a1).IDawal, InfoWahana); //tambah uang

                        Dequeue(A, &X); //Mengeluarkan dari antrian
                        
                        DelLwahana(&X.info, a); //Menghapus wahana dari list pengunjung

                        //masuk ke proses
                        X.current = InfoWahana(a1).ID;
                        P = MakeProses(X, DurasiNaik(InfoWahana(a1).IDawal, InfoWahana));

                        insert(Tab, P);
                        printf("\nPengunjung berhasil dilayani!\n\n");

                        //Memajukan waktu 5 menit
                        AdvTime(T, 5, Tab, A, L);

                        

                    }
                    else{
                        printf("Wahana penuh.\n");
                    }

            }
            else{
                printf("Input salah.\n");
            }
        }
    }
    else{
        printf("Antrian kosong.\n");
    }
}

void repair (POINT Player, int map, JAM *J, TabProses *Tab, Antrian *A, AllWahana *L)
//I.S. pemain berada di sebelah wahana
//F.S. wahana rusak yang berada di sebelah posisi pemain diperbaiki dan waktu bertambah
{
    //KAMUS LOKAl
    int i, count;
    address P;
    Wahana w;
    //ALGORITMA
    count =0;
    
    P = FirstWahana(*L);

    while(P != NULL){
        w = InfoWahana(P);
        if(w.map == map && Panjang(Player, w.lokasi) == 1 && w.status==-1){
            w.status = 1;
            NamaWahana(w.IDawal, InfoWahana);
            printf(" berhasil diperbaiki\n");
            count++;
        }
        P = NextWahana(P);
    }
    if(count>0){
        AdvTime(J, (10*count), Tab, A, L);
    }
    else{
        printf("Tidak ada wahana rusak di sekitar player.\n");
    }
    
    
    
    
}

void Detail (Wahana W)
//I.S. pemain berada di sebelah wahana
//F.S. Menampilkan detail dari wahana yang berada di sebelah pemain
{
    //KAMUS LOKAl

    //ALGORITMA
    PrintInfo(W);
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
            PrintAllWahana(L);
            printf("Pilih ID dari wahana yang ingin ditampilkan detailnya\n");
            scanf("%d", &id);
            P = SearchWahana(L,id); //Cari wahana dari ID yang dipilih
            Detail(InfoWahana(P));
        } else if(IsSama(input,"Report")) {
            PrintAllWahana(L);
            printf("Pilih ID dari wahana yang ingin ditampilkan reportnya\n");
            scanf("%d", &id); 
            P = SearchWahana(L,id); //Cari wahana dari ID yang dipilih
            int hargalife = InfoWahana(P).liferide * HargaTiket(InfoWahana(P).IDawal, InfoWahana); //Menghitung penghasilan keseluruhan
            int hargaday = InfoWahana(P).dayride * HargaTiket(InfoWahana(P).IDawal, InfoWahana); //Menghitung penghasilan hari itu
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

void Prepare(Antrian *A, TabProses *Tab, AllWahana *L)
//I.S. Sembarang
//F.S. Antrian kosong dan masuk ke preparation phase
{
    //KAMUS LOKAl
    address P;
    //ALGORITMA
    Head(*A) = NilAntrian;
    Tail(*A) = NilAntrian;
    Tab->NbElmt = 0;
    P = FirstWahana(*L);
    while(P != NULL){
        InfoWahana(P).NbPengunjung = 0;
        P = NextWahana(P);
    }
}

void AdvTime (JAM *J, int durasi, TabProses *Tab, Antrian *A, AllWahana *L)
//Memajukan jam sebanyak durasi menit
{
	//KAMUS LOKAl
    pengunjung P1, P2;
    TabProses T2;
    address a1, a2;
    int id,a, i, j, b, c;
    Lwahana wahanaP;
	//Algoritma
    

	*J = MenitToJAM(JAMToMenit(*J) + durasi); //Memajukan waktu

    if (Tab->NbElmt >0){ 
        Proses(Tab, durasi); //Memproses pengunjung
        SortProses(Tab); //Menyortir

        //Mengembalikan pengunjung yang sudah selesai ke antrian
        while (Tab->NbElmt>1 && Tab->Tab[0].durasi<=0){
            DelAt(Tab, 0, &P1);
            //Pengguna wahana -1
            id = P1.current;
            a1 = SearchWahana(*L, id);
            InfoWahana(a1).NbPengunjung--;

            
            if (P1.info.Nb >0 && !IsEmptyAntrian(*A)){
                P1.current = -1;
                P1.prio--;
                Enqueue(A, P1);
            }

        }
    }
    
    if(NbElmtWahana(*L) > 0){
        //randomGenerator generate pengunjung
        if(!IsFullAntrian(*A)){
            a = randomGenerator(0, 100);

            if (a>50){

                wahanaP.Nb = 0;
                for (i=0;i<3;i++){
                    b = randomGenerator(1, NbElmtWahana(*L));
                    
                    a2 = SearchWahana(*L, b);
                    NamaWahana(InfoWahana(a2).IDawal, InfoWahana);
                    if (i==0){
                        wahanaP.TabID[0][0] = InfoWahana(a2).IDawal[0];
                        wahanaP.TabID[0][1] = InfoWahana(a2).IDawal[1]; 
                        wahanaP.TabID[0][2] = InfoWahana(a2).IDawal[2]; 
                        wahanaP.TabID[0][3] = InfoWahana(a2).IDawal[3]; 
                        wahanaP.Nb ++;
                    }
                    else{
                        if(!IsStringSame(wahanaP.TabID[0], InfoWahana(a2).IDawal)){
                            if(i == 1 || !IsStringSame(wahanaP.TabID[1], InfoWahana(a2).IDawal))
                                wahanaP.TabID[wahanaP.Nb][0] = InfoWahana(a2).IDawal[0];
                                wahanaP.TabID[wahanaP.Nb][1] = InfoWahana(a2).IDawal[1]; 
                                wahanaP.TabID[wahanaP.Nb][2] = InfoWahana(a2).IDawal[2]; 
                                wahanaP.TabID[wahanaP.Nb][3] = InfoWahana(a2).IDawal[3]; 
                                wahanaP.Nb ++;
                            }
                        }

                    }

                
                

                c = randomGenerator(1,5);
                P2 = MakePengunjung(c, wahanaP, 101, -1);

                Enqueue(A, P2);
                
            }
        }
        //randomGenerator wahana rusak
        b = randomGenerator(1,10);
        if (b >8){
            b = randomGenerator(0, NbElmtWahana(*L));
            a2 = SearchWahana(*L, b);

            if (InfoWahana(a2).status != -1){
                InfoWahana(a2).status = -1;
                printf("Wahana berikut rusak : ");
                NamaWahana(InfoWahana(a2).IDawal, InfoWahana);
                printf("\n");
            }
        }

    }

    ReduceKesabaran(A, 1);
}

int randomGenerator(int lower, int upper){ 
    return rand() % (upper-lower+1) + lower;;
}

void PrintStatus(JAM J, JAM Tutup, int money, Antrian A)
{
    //KAMUS LOKAL
    JAM J1;
    //ALGORITMA
    /*Di sini print nama kalo mau*/
    printf("Money: %d\n", money);
    printf("Current Time: ");
    TulisJAM(J);
    printf("\n");
    printf("Closing Time: ");
    TulisJAM(Tutup);
    printf("\n");
    J1 = MenitToJAM(Durasi(J, Tutup));
    printf("Time Remaining: %d hour(s) %d minute(s)\n", Hour(J1), Minute(J1));
    PrintAntrian(A);
    printf("\n");
}
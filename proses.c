#include "proses.h"


proses MakeProses(pengunjung p, int durasi)
//Menghasilkan sebuah proses
{
    //KAMUS LOKAL
    proses p2;
    //ALGORITMA
    p2.durasi = durasi;
    p2.pengunjung = p;

    return p2;

}

void MakeTabProses(TabProses *T)
//Membuat TabProses Kosong
{
    //KAMUS LOKAL

    //ALGORITMA
    T->NbElmt = 0;
}

void insert(TabProses *T, proses P)
//Menambahkan proses ke tabel
{
    //KAMUS LOKAL

    //ALGORITMA
    T->Tab[T->NbElmt] = P;
    
    T->NbElmt += 1;
}

void Proses(TabProses *T, int durasi)
//Memproses isi TabProses Selama durasi
{
    //KAMUS LOKAL

    //ALGORITMA
    for(int i =0; i<NbElmt; i++){
        T->Tab[i].durasi = T->Tab[i].durasi - durasi; 
    }
}

void DelAt(TabProses *T, int i, pengunjung *P)
//Menghapus elemen dengan indeks i dan bagian infotypenya disimpan di p
{
    //KAMUS LOKAL

    //ALGORITMA
    *P = T->Tab[i].pengunjung;
    if (T->NbElmt > 1){
        for(int j=i;j<T->NbElmt-1;j++){
            T->Tab[j] = T->Tab[j+1];
        }
    }
    T->NbElmt = T->NbElmt -1;
}

void Sort (TabProses *T)
{
    //KAMUS LOKAl
    int id, i, j;
    proses temp;
    //ALGORITMA
    for(i=0;i<T->NbElmt;i++){
		
        id = i;
		for(j=i+1;j<T->NbElmt;j++){
			if(T->Tab[j].durasi < T->Tab[id].durasi){
				id = j;
			}
		}

		temp = T->Tab[i];
		T->Tab[i] = T->Tab[id];
		T->Tab[id] = temp;
    }
}
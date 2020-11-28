/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* File: bintree.c */


#include "boolean.h"
#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Konstruktor *** */
BinTree Tree(infowahana* Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NilTree) jika alokasi gagal */
{
    /* Kamus Lokal */
    BinTree P;
    
    /* Algoritma */
    P = AlokNode(Akar);
    if(P!=NilTree)
    {
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}

void MakeTree(infowahana* Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = NilTree jika alokasi gagal. */
{
    *P = Tree(Akar,L,R);
}
    
/* Manajemen Memory */
addrNodeTree AlokNode(infowahana* X)
/* Mengirimkan addrNodeTree hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNodeTree tidak NilTree, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = NilTree, Right(P)=NilTree */
/* Jika alokasi gagal, mengirimkan NilTree */
{
    /* Kamus Lokal */
    addrNodeTree P;
    
    /* Algoritma */
    P = (addrNodeTree) malloc(sizeof(addrNodeTree));
    if(P!=NilTree)
    {
        Akar(P) = X;
        Left(P) = NilTree;
        Right(P) = NilTree;
    }
    return P;
}

void DealokNode(addrNodeTree P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNodeTree P */
{    
    /* Algoritma */
    free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    /* Algoritma */
    return P==NilTree;
}
boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    /* Algoritma */
    if(!IsTreeEmpty(P))
    {
        return Left(P)==NilTree && Right(P)==NilTree;
    }
    else
    {
        return false;
    }
}

boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    /* Algoritma */
    if(!IsTreeEmpty(P))
    {
        return Left(P)!=NilTree && Right(P)==NilTree;
    }
    else
    {
        return false;
    }
}

boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    /* Algoritma */
    if(!IsTreeEmpty(P))
    {
        return Left(P)==NilTree && Right(P)!=NilTree;
    }
    else
    {
        return false;
    }
}

boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    /* Algoritma */
    if(!IsTreeEmpty(P))
    {
        return Left(P)!=NilTree && Right(P)!=NilTree;
    }
    else
    {
        return false;
    }
}

/* *** Traversal *** */
void PrintPreorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    /* Kamus Lokal */
    
    /* Algoritma */
    if(IsTreeEmpty(P))
    {
        printf("()");
    }
    else
    {
        // Print
        printf("(%d",Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
        printf(")");
    }
}

void PrintInorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    /* Kamus Lokal */
    
    /* Algoritma */
    if(IsTreeEmpty(P))
    {
        printf("()");
    }
    else
    {
        // Print
        printf("(");
        PrintInorder(Left(P));
        printf("%d",Akar(P));
        PrintInorder(Right(P));
        printf(")");
    }
}

void PrintPostorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    /* Kamus Lokal */
    
    /* Algoritma */
    if(IsTreeEmpty(P))
    {
        printf("()");
    }
    else
    {
        // Print
        printf("(");
        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        printf("%d)",Akar(P));
    }
}

void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
    /* Kamus Lokal */
    int i=1;
    void PrintTree2(BinTree P, int h, int i)
    {
        if(IsTreeEmpty(P))
        {
            // Nothing
        }
        else
        {
            // Print
            printf("%d\n",Akar(P));
            
            if(Left(P)!=NilTree)
            {
                printf("%*c",h*i,' ');
            }
                PrintTree2(Left(P),h,i+1);
            if(Right(P)!=NilTree)
            {
                printf("%*c",h*i,' ');
           }
            PrintTree2(Right(P),h,i+1);
        }
    }
    
    /* Algoritma */
    PrintTree2(P,h,i);
}

/* *** Searching *** */
boolean SearchTree(BinTree P, infowahana* X)
/* Mengirimkan true jika ada node dari P yang berNilTreeai X */
{
    /* Kamus Lokal */
    
    /* Algoritma */
    if(IsTreeEmpty(P))
    {
        return false;
    }
    else
    {
        if(Akar(P)==X)
        {
            return true;
        }
        else
        {
            return SearchTree(Left(P),X) || SearchTree(Right(P),X);
        }
    }
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmtTree(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
    /* Kamus Lokal */
    
    /* Algoritma */
    if(IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        return 1+NbElmtTree(Right(P))+NbElmtTree(Left(P));
    }
}

int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
    /* Kamus Lokal */
    
    /* Algoritma */
    if(IsTreeOneElmt(P))
    {
        return 1;
    }
    else
    {
        if(IsUnerLeft(P))
        {
            return NbDaun(Left(P));
        }
        else if(IsUnerRight(P))
        {
            return NbDaun(Right(P));
        }
        else
        {
            return NbDaun(Left(P))+NbDaun(Right(P));
        }
    }
}

int Level(BinTree P, infowahana* X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
    /* Kamus Lokal */
    
    /* Algoritma */
    if(X==Akar(P))
    {
        return 1;
    }
    else
    {
        if(SearchTree(Left(P),X))
        {
            return 1+Level(Left(P),X);
        }
        else
        {
            return 1+Level(Right(P),X);
        }
    }
}

int Tinggi(BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
    /* Kamus Lokal */
    
    /* Algoritma */
    if(IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        if(Tinggi(Left(P))>Tinggi(Right(P)))
        {
            return 1+Tinggi(Left(P));
        }
        else
        {
            return 1+Tinggi(Right(P));
        }
    }
}

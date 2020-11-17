//Nama      : Ahmad Saladin
//NIM       : 13519187
//Tanggal   : 30 September 2020

#include<stdio.h>
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
   {
       /*KAMUS LOKAL*/

       /*ALGORITMA*/
       while (CC == BLANK && CC != MARK ){
           ADV();
       }


   }

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
   {
       /*KAMUS LOKAL*/

       /*ALGORITMA*/
       START();
       IgnoreBlank();
       if(CC == MARK){
           EndKata = true;
       }
       else{
           SalinKata();
           EndKata = false;
       }

   }

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
   {
       /*KAMUS LOKAL*/

       /*ALGORITMA*/
       IgnoreBlank();
       if (CC == MARK){
           EndKata = true;
       }
       else{
           SalinKata();
       }

       
   }

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
   {
       /*KAMUS LOKAL*/
        int i;
       /*ALGORITMA*/
        i = 0;
       while ((CC != BLANK) && (CC != MARK) && (i<NMax)){
            CKata.TabKata[i] = CC;
            i++;
           ADV();
       }
       CKata.Length = i;
       IgnoreBlank();
       
   }


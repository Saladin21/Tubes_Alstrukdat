#include <stdio.h>
#include "parser.h"
#include <string.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

boolean EndKata;
Kata CKata;


void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	pita = stdin;
	ADV();
}

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = 
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
       while ((getchar()) != '\n');
 	}
}

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
            if(CC != ' '){
	            CKata.TabKata[i] = CC;
	            i++;
	        }
           ADV();
       }
       CKata.Length = i;
       IgnoreBlank();
   }


boolean IsSama(Kata K, char str[]){
	int size = strlen(str);
	if(K.Length != size){
		return false;
	} else{
		int i = 0;
		boolean sama = true;
		while(sama && i<K.Length){
			if(K.TabKata[i] != str[i]){
				sama = false;
			} else{
				i++;
			}
		}
		return sama;
	}
}

void InputKata(Kata *K){
	STARTKATA();
	*K = CKata;
}



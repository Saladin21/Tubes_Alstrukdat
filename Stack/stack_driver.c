#include "stackt.h"

int main(){
	Stack S; //initialize stack
	CreateEmpty(&S); // Buat stack kosong

	if(IsEmptyStack(S)){ //Mengecek apakah stack kosong
		printf("Stack is Empty\n");
	}
	
	infotype X;
	X.kodeaksi = 1;
	X.kodebarang = 2;
	X.jumlah = 10;
	X.reqtime = 2;
	strcopy(X.ID, "ABC");

	infotype X1;
	Push(&S, X); //Push X pada stack
	Pop(&S, &X1); // Push X1 pada stack

	return 0;
}
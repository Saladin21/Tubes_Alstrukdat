#include <stdio.h>
#include <string.h>
#include "saver.h"
#include "map.h"


void SaveGame(Stack aksi, PLAYER P, JAM J, MAP M1, MAP M2, MAP M3, MAP M4, AllWahana L, material M, int day){
/* Prosedur untuk melakukan penyimpanan state variables ke file eksternal */
	SaveStack(aksi,"save/aksi.txt");
	SaveMAP(M1,"save/M1.txt");
	SaveMAP(M2,"save/M2.txt");
	SaveMAP(M3,"save/M3.txt");
	SaveMAP(M4,"save/M4.txt");
	fclose(fopen("save/listupgrade.txt","w"));
	SaveWahana(L,"save/Wahana.txt","save/listupgrade.txt");
	SaveTime(J,day,"save/Time.txt");
	SavePlayer(P,"save/Player.txt","CMap.txt","RMap.txt");
	SaveMaterial(M,"save/materialsave.txt");
}

void SaveStack(Stack aksi, char NamaFile[]){
/* Prosedur untuk Menyimpan stack aksi ke file eksternal */
/* I.S Stack Aksi terdefinisi dan boleh kosong */
/* F.S Stack Aksi pada game tersimpan pada suatu file eksternal */
	FILE *fp;
	fp = fopen(NamaFile, "w");
	Stack temp = Reverse(aksi);
	infotype X;
	
	while(!(IsEmptyStack(temp))){
		Pop(&temp, &X);
		fprintf(fp, "%d;%d;%d;%d;%s\n", X.kodeaksi, X.kodebarang, X.jumlah, X.reqtime, X.ID);
	}
	fclose(fp);
}

void SaveMAP(MAP M, char NamaFile[]){
/* Prosedur untuk Menyimpan map ke file eksternal */
/* I.S MAP M terdefinisi dan tidak kosong */
/* F.S MAP M pada game tersimpan pada suatu file eksternal */
	FILE *fp;
	fp = fopen(NamaFile, "w");
	int i = 0; int j = 0;

	for (i=0; i<NBrsEff(M)+1; i++){
		for(j=0; j<NKolEff(M)+1; j++){
			fprintf(fp, "%c", Elmt(M,i,j));
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
}

void SaveWahana(AllWahana L, char NamaFile[], char ListFile[]){
/* Prosedur untuk Menyimpan wahana yang telah dibuat ke map ke file eksternal */
/* I.S AllWahana L terdefinisi dan boleh kosong */
/* F.S AllWahana L pada game tersimpan pada suatu file eksternal */
	FILE *fp;
	fp  = fopen(NamaFile, "w");

	address P = FirstWahana(L);

	while(P != Nil){
		fprintf(fp, "%s;%d;%d:%d;%d;%d;%d;%d\n", InfoWahana(P).IDawal, InfoWahana(P).ID, InfoWahana(P).NbPengunjung, InfoWahana(P).status, InfoWahana(P).dayride, InfoWahana(P).liferide, InfoWahana(P).lokasi.X, InfoWahana(P).lokasi.Y);
		SaveListUpdgrade(InfoWahana(P).upgrade, ListFile);
		P = NextWahana(P);
	}
	fclose(fp);
}

void SavePlayer(PLAYER P, char NamaFile[], char FileCMap[], char FileRMap[]){
/* Prosedur untuk Menyimpan PLAYER P ke file eksternal */
/* I.S PLAYER P terdefinisi dan tidak kosong */
/* F.S PLAYER P pada game tersimpan pada suatu file eksternal */
	FILE *fp;
	fp = fopen(NamaFile, "w");
	fprintf(fp, "%s;%d;%d;%c;%d;%d\n", Name(P), PosisiX(P), PosisiY(P), CGedung(P), Money(P),Kode(CMap(P)));
	fclose(fp);

	SaveMAP(CMap(P), FileCMap);
	SaveMAP(RealMap(P), FileRMap);
}

void SaveTime(JAM J, int day, char NamaFile[]){
/* Prosedur untuk Menyimpan JAM currentTime (jam saat game di save) ke file eksternal */
/* I.S JAM currentTime terdefinisi dan tidak kosong */
/* F.S JAM currentTime pada game tersimpan pada suatu file eksternal */
	FILE *fp;
	fp = fopen(NamaFile, "w");
	fprintf(fp, "%d;%d;%d\n", Hour(J), Minute(J), day);
	fclose(fp);
}

void SaveMaterial(material M, char NamaFile[]){
	FILE *fp;
	fp = fopen(NamaFile, "w");
	int i;
	for(i=0; i<NMaterial; i++){
		fprintf(fp, "%s;%d;%d\n", JenisM(M,i), HargaM(M,i), JumlahM(M,i));
	}
	fclose(fp);
}

void SaveListUpdgrade(ListUpgrade upgrade, char NamaFile[]){
/* Prosedur untuk Menyimpan ListUpgrade upgrade (daftar upgrade yang telah dilakukan ke wahana) ke file eksternal */
/* I.S ListUpgrade upgrade terdefinisi dan tidak kosong */
/* F.S ListUpgrade upgrade pada game tersimpan pada suatu file eksternal */
	FILE *fp;
	fp = fopen(NamaFile, "a");
	if(IsEmptyUpgrade(upgrade)){

	} else {
		addrupgrade P = upgrade.First;
		while(P->next!=NULL){
			fprintf(fp, "%s;", P->IDawal);
			P = P->next;
		}
		fprintf(fp, "%s", P->IDawal);
	}
	fprintf(fp,"\n");
	fclose(fp);
}


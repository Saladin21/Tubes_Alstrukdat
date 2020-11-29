#include <stdio.h>
#include "boolean.h"
#include "../ADTLain/build.h"
#include "../Stack/stackt.h"
#include "../Jam/jam.h"
#include "map.h"
#include "mapplayer.h"

void SaveGame(Stack aksi, PLAYER P, JAM J, MAP M1, MAP M2, MAP M3, MAP M4, AllWahana L, material m, int day);
/* Prosedur untuk melakukan penyimpanan state variables ke file eksternal */

void SaveStack(Stack aksi, char NamaFile[]);
/* Prosedur untuk Menyimpan stack aksi ke file eksternal */
/* I.S Stack Aksi terdefinisi dan boleh kosong */
/* F.S Stack Aksi pada game tersimpan pada suatu file eksternal */

void SaveMAP(MAP M, char NamaFile[]);
/* Prosedur untuk Menyimpan map ke file eksternal */
/* I.S MAP M terdefinisi dan tidak kosong */
/* F.S MAP M pada game tersimpan pada suatu file eksternal */

void SaveWahana(AllWahana L, char NamaFile[], char ListFile[]);
/* Prosedur untuk Menyimpan wahana yang telah dibuat ke map ke file eksternal */
/* I.S AllWahana L terdefinisi dan boleh kosong */
/* F.S AllWahana L pada game tersimpan pada suatu file eksternal */

void SavePlayer(PLAYER P, char NamaFile[], char FileCMap[], char FileRMap[]);
/* Prosedur untuk Menyimpan PLAYER P ke file eksternal */
/* I.S PLAYER P terdefinisi dan tidak kosong */
/* F.S PLAYER P pada game tersimpan pada suatu file eksternal */

void SaveTime(JAM J, int day, char NamaFile[]);
/* Prosedur untuk Menyimpan JAM currentTime (jam saat game di save) ke file eksternal */
/* I.S JAM currentTime terdefinisi dan tidak kosong */
/* F.S JAM currentTime pada game tersimpan pada suatu file eksternal */

void SaveMaterial(material M, char NamaFile[]);
/* Prosedur untuk Menyimpan material M (daftar material) ke file eksternal */
/* I.S material M terdefinisi dan tidak kosong */
/* F.S material M pada game tersimpan pada suatu file eksternal */

void SaveListUpdgrade(ListUpgrade upgrade,char NamaFile[]);
/* Prosedur untuk Menyimpan ListUpgrade upgrade (daftar upgrade yang telah dilakukan ke wahana) ke file eksternal */
/* I.S ListUpgrade upgrade terdefinisi dan tidak kosong */
/* F.S ListUpgrade upgrade pada game tersimpan pada suatu file eksternal */
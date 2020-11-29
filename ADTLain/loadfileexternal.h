
#ifndef LOADFILEEXTERNAL_H
#define LOADFILEEXTERNAL_H

#include "../Matriks/mapmatriks.h"
#include "build.h"

MAP LoadMap(char NamaFile[]);
/* Membentuk data tipe MAP dari file dengan nama NamaFile */

material LoadMaterial(char NamaFile[]);

daftarwahana LoadWahana(char NamaFile[]);
#endif
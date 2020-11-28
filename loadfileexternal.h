
#ifndef LOADFILEEXTERNAL_H
#define LOADFILEEXTERNAL_H

#include "ADT/mapmatriks.h"
#include "ADT/build.h"

MAP LoadMap(char NamaFile[]);
/* Membentuk data tipe MAP dari file dengan nama NamaFile */

material LoadMaterial(char NamaFile[]);
#endif
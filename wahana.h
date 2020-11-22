#ifndef wahana_H
#define wahana_H

#include "mesinkata.h"
#include "mesinkata.c"
#include "mesinkar.h"
#include "jam.h"
#include "point.h"


typedef struct twahana * address_w;
typedef struct twahana {
    Kata namaWahana;
    Kata bentuk;
    int BiayaBuild;
    int BiayaUpgrade;
    int waktuBuild;
    int waktuUpgrade;
    int pasir; //Pasir
    int besi; //Besi
    int kaca; //Kaca
    int pintu; //Pintu
    int kayu; //Kayu

} Wahana;

void LoadWahana(Wahana *W);

#endif

#ifndef build_H
#define build_H

#include "matriks.h"
#include "boolean.h"
#include "point.h"


int inventorytemp[5]= {
    20, //Pasir
    20, //Besi
    20, //Kaca
    20, //Pintu
    20  // Kayu

};

int uangtemp = 10000;

void build(boolean prepPhase, MATRIKS M);
#endif
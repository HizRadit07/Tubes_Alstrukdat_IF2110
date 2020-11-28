#include <stdlib.h>
#include <stdio.h>
#include "matriks.h"
#include "matriks.c"
#include "point.c"
#include "point.h"
#include "jam.h"


void isRusak(Jam *JGlobal, MATRIKS *M ) {
    int r = rand() % 20; // faktor randomizer  
}

void repair (MATRIKS *M, boolean rusak, POINT Player){
    if (checkSekitar(&M, Player)){
        rusak = false;
    }
    
} 

int main(){
    MATRIKS Wahana;
    MATRIKS M2;

    //Map
    int NB = 7;
    int NK = 7;
    char filename2[30] = "map2.txt";
    MakeMATRIKS(NB, NK, &M2);
    BacaMATRIKS(&M2, NB, NK, filename2);

    MakeMATRIKS(3, 3, &Wahana);

    //Data Wahana
     Elmt(Wahana, 0, 0) = *"KomediPutar";
    Elmt(Wahana, 0, 1) = "5";
    Elmt(Wahana, 0, 2) =  "tidak rusak";

    Elmt(Wahana, 1, 0) = "Arungjeram";
    Elmt(Wahana, 1, 1) = "5";
    Elmt(Wahana, 1, 2) =  "tidak rusak";

    Elmt(Wahana, 2, 0) = "AnjimBanget";
    Elmt(Wahana, 2, 1) = "5";
    Elmt(Wahana, 2, 2) =  "tidak rusak"; 

    //Program
    TulisMATRIKS(M2);
    POINT Player = cariPoint(M2, 'P');
    
    

    return 0;
}
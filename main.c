#include "boolean.h"
#include "matriks.h"
#include <stdio.h>
#include "matriks.c"

int main(){
    MATRIKS M;
    int NB = 7;
    int NK = 7;
    char filename[30] = "map2.txt";
    MakeMATRIKS(NB, NK, &M);
    BacaMATRIKS(&M, NB, NK, filename);
    TulisMATRIKS(M);
    return 0;
}
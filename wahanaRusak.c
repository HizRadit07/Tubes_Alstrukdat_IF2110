#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
void wahanaRusak(boolean *wahanarusak1, boolean *wahanarusak2, boolean *wahanarusak3, boolean *wahanarusak4){
    int c = rand() % 100;
    if (c >= 0 && c < 25){
        *wahanarusak1 = true;
    }
    else if (c >= 25 && c < 50){
        *wahanarusak2 = true;
    }
    else if (c >= 50 && c < 75){
        *wahanarusak3 = true;
    }
    else if (c >= 75 && c <= 100){
        *wahanarusak4 = true;
        printf("***Wahana di Map 4 rusak***");
    }
}

void repairwahana(int mapstatus, boolean *wahanarusak1, boolean *wahanarusak2, boolean *wahanarusak3, boolean *wahanarusak4){
    if(mapstatus == 1){
        if (*wahanarusak1 == true){
            *wahanarusak1 = false;
            printf("wahana berhasil diperbaiki\n");
        }
        else{
            printf("Tidak ada wahana yang rusak\n");
        }
    }
    if(mapstatus == 2){
        if (*wahanarusak2 == true){
            *wahanarusak2 = false;
            printf("Wahana berhasil diperbaiki\n");
        }
        else{
            printf("Tidak ada wahana yang rusak\n");
        }
        
    }
    if(mapstatus == 3){
        if (*wahanarusak3 == true){
            *wahanarusak3 = false;
            printf("wWahana berhasil diperbaiki\n");
        }
        else{
            printf("Tidak ada wahana yang rusak\n");
        }
    }
    if(mapstatus == 4){
       if (*wahanarusak4 == true){
            *wahanarusak4 = false;
            printf("Wahana berhasil diperbaiki\n");
        }
        else{
            printf("Tidak ada wahana yang rusak\n");
        }
    }
}
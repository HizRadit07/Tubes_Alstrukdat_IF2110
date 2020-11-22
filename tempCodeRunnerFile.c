#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "point.h"
#include "boolean.h"
#include "matriks.h"
#include "matriks.c"
#include "jam.h"
#include <string.h>



int inventorytemp[5]= {
    20, //Pasir
    20, //Besi
    20, //Kaca
    20, //Pintu
    20  // Kayu

};

int uangtemp = 10000;

struct wahana {

    char bentuk[256];
    int waktu;
    int biaya;
    int upgradewahana;
    int req[5];
};


void build(boolean prepPhase){
//1. Setelah meminta command ini, program akan menampilkan wahana dasar yang mungkin dibuat (hasil load file eksternal).
//2. Setelah pemain memilih wahana dasar yang ingin dibuat.
//3. Jika resource untuk membangun wahana tidak mencukupi, maka akan ditampilkan pesan error.
//4. Setelah itu, perintah eksekusi ini akan dimasukkan ke dalam stack.
if (prepPhase){


int i = 0;

int wahana1 [5] = {10,10,10,10,10};

struct wahana KomediPutar;
strcpy( KomediPutar.bentuk, "@");
KomediPutar.waktu, 3;
KomediPutar.biaya, 5000;

boolean check;

printf("%s\n", KomediPutar.bentuk);

for (i = 0; i < 5; i++){
    if (inventorytemp[i] >= wahana1[i] && (uangtemp >= KomediPutar.biaya)){
        check = true;
        inventorytemp[i] = inventorytemp[i] - wahana1[i];
        uangtemp = uangtemp - KomediPutar.biaya;
        
    }else{
        check = false;

    }
}

if (check){
    printf("building...\n");
    printf("%d\n", inventorytemp[1]);
    printf("%d\n", uangtemp);

}else{
    printf("error, material kurang\n");
}
}else{

    printf("Anda berada di main phase");

}

}



int main(){

boolean prep = true;
build(prep);


return 0;
}
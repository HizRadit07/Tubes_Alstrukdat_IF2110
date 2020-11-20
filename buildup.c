#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "point.h"
#include "boolean.h"
#include "matriks.h"
#include "jam.h"
#include <string.h>


int inventory[5]= {
    20, //Pasir
    20, //Besi
    20, //Kaca
    20, //Pintu
    20  // Kayu

};

int uang = 10000;

struct wahana {

    char bentuk[256];
    int waktu;
    int biaya;
    int upgradewahana;
    int req[5];
};





void LoadWahana() {

    char bentuk[256];
    char title[256];
    int waktu;
    int value1; //Pasir
    int value2; //Besi
    int value3; //Kaca
    int value4; //Pintu
    int value5; //Kayu



    printf("~ Load Wahana yang tersedia ~\ngcc -o buildupgrade buildupgrade.c");
    FILE *pf;
    pf = fopen ("wahana.txt", "r");
    if (pf == NULL)
        printf("maap gan");
    fscanf(pf, "%s, %d,%d, %d, %d, %d, %d",bentuk, &waktu, &value1, &value2, &value3, &value4, &value5);
    fclose (pf); 


}


void build(){
//1. Setelah meminta command ini, program akan menampilkan wahana dasar yang mungkin dibuat (hasil load file eksternal).
//2. Setelah pemain memilih wahana dasar yang ingin dibuat.
//3. Jika resource untuk membangun wahana tidak mencukupi, maka akan ditampilkan pesan error.
//4. Setelah itu, perintah eksekusi ini akan dimasukkan ke dalam stack.
int i = 0;

int wahana1 [5] = {10,10,10,10,10};

struct wahana KomediPutar;
strcpy( KomediPutar.bentuk, "@");
KomediPutar.waktu, 3;
KomediPutar.biaya, 5000;

boolean check;

printf("%s\n", KomediPutar.bentuk);

for (i = 0; i < 5; i++){
    if (inventory[i] >= wahana1[i] && (uang >= KomediPutar.biaya)){
        check = true;
        inventory[i] = inventory[i] - wahana1[i];
        uang = uang - KomediPutar.biaya;
    }else{
        check = false;

    }
}

if (check){
    printf("building...\n");
    printf("%d\n", inventory[1]);
    printf("%d\n", uang);

}else{
    printf("error, material kurang\n");
}

}


void upgrade(){
//1. Setelah meminta command ini, program akan menampilkan daftar upgrade yang mungkin untuk tipe wahana tersebut.
//2. Jika resource untuk mengupgrade wahana tidak mencukupi, maka akan ditampilkan pesan error.
//3. Setelah itu, perintah eksekusi ini akan dimasukkan ke dalam stack.


    int upgrade1 [5] = {
    10,
    10,
    10,
    10,
    10
};

struct wahana KomediPutar;
KomediPutar.upgradewahana, 2000;

int i = 0;
boolean check;

for (i = 0; i < 5; i++){
    if (inventory[i] >= upgrade1[i]){
        check = true;
        inventory[i] = inventory[i] - upgrade1[i];
        uang = uang - KomediPutar.upgradewahana;
         printf("%d\n", uang);

    }else{
        check = false;

    }
}

if (check){
    printf("building...\n");
    printf("%d\n", inventory[1]);

}else{
    printf("error, material kurang\n");
}


}

int main(){

build();
upgrade();


return 0;
}
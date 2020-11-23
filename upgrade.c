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



int i = 0;
int biaya = 6000;
boolean check;

for (i = 0; i < 5; i++){
    if (inventory[i] >= upgrade1[i]){
        check = true;
        inventory[i] = inventory[i] - upgrade1[i];
        uang = uang - biaya;
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

int main (){
    upgrade();




    return 0;
}
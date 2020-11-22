#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "wahana.h"
#include "wahana.c"
#include "matriks.h"
#include "matriks.c"
#include "point.c"
#include "point.h"


int inventorytemp[5]= {
    20, //Pasir
    20, //Besi
    20, //Kaca
    20, //Pintu
    20  // Kayu

};

int uangtemp = 10000;



void build(boolean prepPhase, MATRIKS M){
//1. Setelah meminta command ini, program akan menampilkan wahana dasar yang mungkin dibuat (hasil load file eksternal).
//2. Setelah pemain memilih wahana dasar yang ingin dibuat.
//3. Jika resource untuk membangun wahana tidak mencukupi, maka akan ditampilkan pesan error.
//4. Setelah itu, perintah eksekusi ini akan dimasukkan ke dalam stack.
if (prepPhase){

Wahana W;
STARTWahana("wahana.txt");
loadWahana(&W);

int inventory_material_wahana[5];

    
    Kata nama = W.namaWahana;
    Kata bentuk = W.bentuk;
    char charBentuk = scanf("%s", &bentuk);
    printf("%s", charBentuk);
    
    int biayaBuild = W.BiayaBuild;
    int biayaUpgrade = W.BiayaUpgrade;
    int waktuBuild = W.waktuBuild;
    int waktuUpgrade = W.waktuUpgrade;
    inventory_material_wahana[1] = W.pasir;
    inventory_material_wahana[2] = W.besi;
    inventory_material_wahana[3] = W.kaca;
    inventory_material_wahana[4] = W.pintu;
    inventory_material_wahana[5] = W.kayu;

int i = 0;




boolean check;
printf("~ Wahana yang akan dibangun ~\n");
printf("Nama Wahana : %s\n", nama);
printf("Bentuk Wahana : %s\n", bentuk);
printf("Biaya untuk membangun : %d\n",  biayaBuild);
printf("Lama waktu untuk membangun : %d\n", waktuBuild);
printf("\n");


for (i = 0; i < 5; i++){
    if (inventorytemp[i] >= inventory_material_wahana[i] ){
        check = true;
        inventorytemp[i] = inventorytemp[i] - inventory_material_wahana[i];
        
        
    }else{
        check = false;

    }
}

if (check){
    
    uangtemp = uangtemp - biayaBuild;
    if (uangtemp > 0){
    printf("building...\n");
    POINT Player = cariPoint(M, 'P');
    TulisMATRIKS(M);
    TulisPOINT(Player);

    printf("\n");
    Elmt(M, Absis(Player), Ordinat(Player)) = charBentuk;
   
    if (Elmt(M,Absis(Player)-1, Ordinat(Player) ) == '-'){
        Elmt(M,Absis(Player)-1, Ordinat(Player) ) = 'P';
        Ordinat(Player)++;
    }else if (Elmt(M,Absis(Player), Ordinat(Player)-1 ) == '-'){
        Elmt(M,Absis(Player), Ordinat(Player)-1 ) = 'P';
        Absis(Player)--;
    }else if (Elmt(M,Absis(Player)+1, Ordinat(Player) ) == '-'){
        Elmt(M,Absis(Player)+1, Ordinat(Player) ) = 'P';
        Ordinat(Player)--;
    }else if (Elmt(M,Absis(Player), Ordinat(Player) +1 ) == '-'){
        Elmt(M,Absis(Player), Ordinat(Player) +1 ) = 'P';
        Absis(Player)++;

    }
    TulisMATRIKS(M);

    printf("\n");
    printf("Sisa Inventory anda :\n");
    printf("Pasir : %d\n", inventorytemp[0]);
    printf("Besi : %d\n", inventorytemp[1]);
    printf("Kaca : %d\n", inventorytemp[2]);
    printf("Pintu : %d\n", inventorytemp[3]);
    printf("Kayu : %d\n", inventorytemp[4]);
    printf("\n");
    printf("Sisa Uang anda :\n");
    printf("%d\n", uangtemp);}
    else
    {
         printf("error, material kurang\n");
    }
    

}else{
    printf("error, material kurang\n");
}
}else{

    printf("Anda berada di main phase");

}

}

/*MATRIKS buildingWahana(MATRIKS M, char wahana){
    
    POINT Player = cariPoint(M, 'P');
    TulisMATRIKS(M);
    TulisPOINT(Player);

    printf("\n");
    Elmt(M, Absis(Player), Ordinat(Player)) = wahana;
   
    if (Elmt(M,Absis(Player)-1, Ordinat(Player) ) == '-'){
        Elmt(M,Absis(Player)-1, Ordinat(Player) ) = 'P';
        Ordinat(Player)++;
    }else if (Elmt(M,Absis(Player), Ordinat(Player)-1 ) == '-'){
        Elmt(M,Absis(Player), Ordinat(Player)-1 ) = 'P';
        Absis(Player)--;
    }else if (Elmt(M,Absis(Player)+1, Ordinat(Player) ) == '-'){
        Elmt(M,Absis(Player)+1, Ordinat(Player) ) = 'P';
        Ordinat(Player)--;
    }else if (Elmt(M,Absis(Player), Ordinat(Player) +1 ) == '-'){
        Elmt(M,Absis(Player), Ordinat(Player) +1 ) = 'P';
        Absis(Player)++;

    }
    TulisMATRIKS(M);
    
}
*/


int main(){
    int NB = 7;
    int NK = 7;
    MATRIKS M2;
    char filename2[30] = "map2.txt";
    MakeMATRIKS(NB, NK, &M2);
    BacaMATRIKS(&M2, NB, NK, filename2);

    boolean prep = true;
    build(prep, M2);
  
 



    return 0;
}

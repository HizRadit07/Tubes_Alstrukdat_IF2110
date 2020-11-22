#include <stdio.h>
#include "wahana.h"
#include "mesinkar.h"
#include "mesinkar.c"
#include "mesinkata.h"


void loadWahana(Wahana *W){

    char separator = ' ';

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).namaWahana);

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).bentuk);

    ADVKATAW(separator);
    (*W).BiayaBuild = ConvertKataW(CKata);
    
     ADVKATAW(separator);
    (*W).BiayaUpgrade = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).waktuBuild = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).waktuUpgrade = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).pasir = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).besi = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).kaca = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).pintu = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).kayu = ConvertKataW(CKata);


}


void mainWahana(Wahana W){
     
    

    int inventory_material_wahana[4];

    
    Kata nama = W.namaWahana;
    Kata bentuk = W.bentuk;
    int biayaBuild = W.BiayaBuild;
    int biayaUpgrade = W.BiayaUpgrade;
    inventory_material_wahana[0] = W.pasir;
    inventory_material_wahana[1] = W.besi;
    inventory_material_wahana[2] = W.kaca;
    inventory_material_wahana[3] = W.pintu;
    inventory_material_wahana[4] = W.kayu;

    PrintKata(nama);
    printf("\n");
    PrintKata(bentuk);
    printf("\n");
    printf("%d", biayaBuild);

    
}


int main(){
    Wahana W;
   
    STARTWahana("wahana.txt");
    loadWahana(&W);
    mainWahana(W);


    return 0;
}

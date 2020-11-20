#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "mesinkar.c"
#include "mesinkata.c"
#include "jam.c"
#include "jam.h"
#include "boolean.h"
#include "matriks.h"
#include "matriks.c"
#include "point.h"
#include "point.c"
#include "stackt.h"
#include "stackt.c"


// Harusnya dri eksternal file, tapi masih on progress

// char material[5][20] = {
//     "pasir",        //0
//     "besi",         //1
//     "kaca",         //2
//     "pintu",        //3
//     "kayu"          //4

// };

// int hargaMaterial[5] = {
//     500, //0
//     600, //1
//     1000,//2
//     700, //3
//     200, //4
// };



    
void eksekusiBuy(int *uanglobal, int *inventory[5], Jam *sisaWaktu, int tempmat[3]) {
    int indexMaterial = tempmat[0];
    int jmlhMaterial = tempmat[1];
    int totalHarga = tempmat[2];
    // Penghitungan waktu dibutuhkan adalah 5menit(300detik) * jmlh material;
    int detikDibutuhkan = 300*jmlhMaterial;
    
    if (JamToDetik(*sisaWaktu) > detikDibutuhkan)
    {
        int detikSisa = JamToDetik(*sisaWaktu) - detikDibutuhkan;
        *sisaWaktu = DetikToJam(detikSisa);
        *uanglobal -= totalHarga;
        *inventory[indexMaterial] += jmlhMaterial;

    }
    else 
        printf("Waktu untuk buy tidak mencukupi");

}

void buy(int *TempUang, char Material[5][20], int hargaMaterial[5], Stack *stek, int *tempmat[3]) {
    printf("Daftar Harga Material\n");
    for (int i = 0; i < 5; i++){
        printf("%d. %s: %d \n", i+1, Material[i], hargaMaterial[i]);
    }
    int nomor,jmlh;
    printf("Masukkan nomor material: ");
    scanf("%d", &nomor);
    printf("Masukkan jumlah material: ");
    scanf("%d", &jmlh);
    
    nomor--;
    int totalHarga = jmlh*hargaMaterial[nomor];
    *tempmat[0] = nomor;
    *tempmat[1] = jmlh;
    *tempmat[2] = totalHarga;

    printf("Apakah Anda yakin ingin membeli %d buah %s dengan total harga %d? (y/n)", jmlh, Material[nomor], totalHarga);
    Kata Y,y,Yes,yes,Input;
    Y.TabKata[0]='Y'; Y.Length = 1;
    y.TabKata[0]='y'; Y.Length = 1;
    Yes.TabKata[0]='Y'; Yes.TabKata[1]='e'; Yes.TabKata[2]='s'; Yes.Length = 3;
    yes.TabKata[0]='y'; yes.TabKata[1]='e'; yes.TabKata[2]='s'; yes.Length = 3;
    InputUser(&Input);

    if (IsKataSama(Input,Y) || IsKataSama(Input,y) || IsKataSama(Input,Yes) || IsKataSama(Input,yes)){
        if (jmlh*hargaMaterial[nomor]>(*TempUang)){
            printf("Uang anda kurang\n");
        }
        else{
            *TempUang -= totalHarga;

            Kata execBuy;
            execBuy.TabKata[0] = 'e'; execBuy.TabKata[1] = 'x'; execBuy.TabKata[2] = 'e'; execBuy.TabKata[3] = 'c'; execBuy.TabKata[4] = 'B'; execBuy.TabKata[5] = 'u'; execBuy.TabKata[6] = 'y'; execBuy.Length = 7;
            Push(&stek, execBuy);

        }
        
    }
}


// int main(){
//     buy(uang, material,hargaMaterial);
//     return 0;
// }



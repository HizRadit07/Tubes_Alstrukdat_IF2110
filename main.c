#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "mesinkar.c"
#include "mesinkata.c"
#include "jam.h"
#include "jam.c"
#include "boolean.h"
#include "matriks.h"
#include "matriks.c"
#include "point.h"
#include "point.c"
#include "stackt.h"
#include "stackt.c"
#include "undoexec.c"
#include "buy_material.c"
#include "build.h"
#include "queue.h"
#include "queue.c"
//#include "wahanaRusak.c"

typedef struct twahana * address_w;
typedef struct twahana {
    Kata namaWahana1;
    Kata TipeWahana1;
    int HargaWahana1;
    Kata DeskripsiWahana1;
    int KapasitasWahana1;
    int DurasiWahana1;
    int CostWah1;
    int BiayaUpgrade1;
    int waktuBuild1;
    int waktuUpgrade1;
    int pasir1; //Pasir
    int besi1; //Besi
    int kaca1; //Kaca
    int pintu1; //Pintu
    int kayu1; //Kayu
    int hargaTiket1; 

    Kata namaWahana2;
    Kata TipeWahana2;
    int HargaWahana2;
    Kata DeskripsiWahana2;
    int KapasitasWahana2;
    int DurasiWahana2;
    int CostWah2;
    int BiayaUpgrade2;
    int waktuBuild2;
    int waktuUpgrade2;
    int pasir2; //Pasir
    int besi2; //Besi
    int kaca2; //Kaca
    int pintu2; //Pintu
    int kayu2; //Kayu
    int hargaTiket2; 

    Kata namaWahana3;
    Kata TipeWahana3;
    int HargaWahana3;
    Kata DeskripsiWahana3;
    int KapasitasWahana3;
    int DurasiWahana3;
    int CostWah3;
    int BiayaUpgrade3;
    int waktuBuild3;
    int waktuUpgrade3;
    int pasir3; //Pasir
    int besi3; //Besi
    int kaca3; //Kaca
    int pintu3; //Pintu
    int kayu3; //Kayu
    int hargaTiket3; 

    Kata namaWahana4;
    Kata TipeWahana4;
    int HargaWahana4;
    Kata DeskripsiWahana4;
    int KapasitasWahana4;
    int DurasiWahana4;
    int CostWah4;
    int BiayaUpgrade4;
    int waktuBuild4;
    int waktuUpgrade4;
    int pasir4; //Pasir
    int besi4; //Besi
    int kaca4; //Kaca
    int pintu4; //Pintu
    int kayu4; //Kayu
    int hargaTiket4; 

    
} Wahana;



/*#include "office.c"*/
void loadWahana(Wahana *W){

    char separator = ' ';

    //Wahana 1
    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).namaWahana1);

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).TipeWahana1);

    ADVKATAW(separator);
    (*W).HargaWahana1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).DurasiWahana1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).DeskripsiWahana1);

    ADVKATAW(separator);
    (*W).CostWah1 = ConvertKataW(CKata);
    
     ADVKATAW(separator);
    (*W).BiayaUpgrade1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).waktuBuild1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).waktuUpgrade1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).pasir1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).besi1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).kaca1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).pintu1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).kayu1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).hargaTiket1 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).KapasitasWahana1 = ConvertKataW(CKata);

    //Wahana 2

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).namaWahana2);

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).TipeWahana2);

    ADVKATAW(separator);
    (*W).HargaWahana2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).DurasiWahana2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).DeskripsiWahana2);

    ADVKATAW(separator);
    (*W).CostWah2 = ConvertKataW(CKata);
    
     ADVKATAW(separator);
    (*W).BiayaUpgrade2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).waktuBuild2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).waktuUpgrade2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).pasir2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).besi2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).kaca2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).pintu2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).kayu2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).hargaTiket2 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).KapasitasWahana2 = ConvertKataW(CKata);

    //Wahana 3

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).namaWahana3);

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).TipeWahana3);

    ADVKATAW(separator);
    (*W).HargaWahana3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).DurasiWahana3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).DeskripsiWahana3);

    ADVKATAW(separator);
    (*W).CostWah3 = ConvertKataW(CKata);
    
     ADVKATAW(separator);
    (*W).BiayaUpgrade3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).waktuBuild3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).waktuUpgrade3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).pasir3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).besi3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).kaca3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).pintu3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).kayu3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).hargaTiket3 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).KapasitasWahana3 = ConvertKataW(CKata);

    //Wahana 4

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).namaWahana4);

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).TipeWahana4);

    ADVKATAW(separator);
    (*W).HargaWahana4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).DurasiWahana4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &(*W).DeskripsiWahana4);

    ADVKATAW(separator);
    (*W).CostWah4 = ConvertKataW(CKata);
    
     ADVKATAW(separator);
    (*W).BiayaUpgrade4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).waktuBuild4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).waktuUpgrade4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).pasir4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).besi4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).kaca4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).pintu4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).kayu4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).hargaTiket4 = ConvertKataW(CKata);

    ADVKATAW(separator);
    (*W).KapasitasWahana4 = ConvertKataW(CKata);

    


}

void office(int *mapstatus, Wahana W){
    if (*mapstatus==2){

        
        WahanaSTART("wahana.txt");
        loadWahana(&W);
        
        Kata nameOfRides[4];
        nameOfRides[0] = W.namaWahana1;
        nameOfRides[1] = W.namaWahana2;
        nameOfRides[2] = W.namaWahana3;
        nameOfRides[3] = W.namaWahana4;

        int hargaWahana[4];
        hargaWahana[0] = W.HargaWahana1;
        hargaWahana[1] = W.HargaWahana2;
        hargaWahana[2] = W.HargaWahana3;
        hargaWahana[3] = W.HargaWahana4;

        //Kapasitas Wahana
        int kapasitasWahana[4];
        kapasitasWahana[0] = W.KapasitasWahana1; // 20
        kapasitasWahana[1] = W.KapasitasWahana2; // 10
        kapasitasWahana[2] = W.KapasitasWahana3; // 8
        kapasitasWahana[3] = W.KapasitasWahana4; // 15

        Kata deskripsi[4];
        deskripsi[0] = W.DeskripsiWahana1;
        deskripsi[1] = W.DeskripsiWahana2;
        deskripsi[2] = W.DeskripsiWahana3;
        deskripsi[3] = W.DeskripsiWahana4;

        //Durasi Wahana
        int durasiWahana[4];
        durasiWahana[0] = W.DurasiWahana1;
        durasiWahana[1] = W.DurasiWahana2;
        durasiWahana[2] = W.DurasiWahana3;
        durasiWahana[3] = W.DurasiWahana4;

        //Tipe Wahana
        Kata TypeWahana[4];
        TypeWahana[0] = W.TipeWahana1;
        TypeWahana[1] = W.TipeWahana2;
        TypeWahana[2] = W.TipeWahana3;
        TypeWahana[3] = W.TipeWahana4;

        //Harga Tiket
        int ticketPrice[4];
        ticketPrice[0] = W.hargaTiket1;
        ticketPrice[1] = W.hargaTiket2;
        ticketPrice[2] = W.hargaTiket3;
        ticketPrice[3] = W.hargaTiket4;



        int counterHari[4]; //diisi dari data hasilserve 
        counterHari[0] = 1;
        counterHari[1] = 1;
        counterHari[2] = 1;
        counterHari[3] = 1;

        int counterTotal[4]; //diisi dari data hasilserve 
        counterTotal[0] += counterHari[0];
        counterTotal[1] += counterHari[1];
        counterTotal[2] += counterHari[2];
        counterTotal[3] += counterHari[3];
        

        int penghasilanTotal[4];
        penghasilanTotal[0] = ticketPrice[0]*counterTotal[0];
        penghasilanTotal[1] = ticketPrice[1]*counterTotal[1];
        penghasilanTotal[2] = ticketPrice[2]*counterTotal[2];
        penghasilanTotal[3] = ticketPrice[3]*counterTotal[3];
        
        int penghasilanHari[4];
        penghasilanHari[0] =  ticketPrice[0]*counterHari[0];
        penghasilanHari[1] =  ticketPrice[1]*counterHari[1];
        penghasilanHari[2] =  ticketPrice[2]*counterHari[2];
        penghasilanHari[3] =  ticketPrice[3]*counterHari[3];


        

        for (int i = 0; i < 4; i++){
            printf("Selamat datang di office\n ");
            printf("Detail wahana :");
            printf("  1. Nama Wahana : ");
            PrintKataW(nameOfRides[i]);
            printf("\n");
            printf("  2. Tipe wahana\n");
            PrintKataW(TypeWahana[i]);
            printf("\n");
            printf("  3. Harga wahana : ", hargaWahana[i]);
            printf("\n");
            printf("  4. Lokasi wahana : \n");
            printf("  5. Deskripsi wahana :\n");
            PrintKataW(deskripsi[i]);
            printf("\n");
            printf("  6. Kapasitas wahana : %d \n", kapasitasWahana[i]);
            printf("  7. History Upgrade wahana : \n");
            printf("  8. Durasi wahana : %d \n", durasiWahana[i]);
            printf("  9. Ukuran wahana : \n");
            printf("\n");
            printf("Laporan wahana : ");
            printf("  1. Berapakali wahana dinaiki : %d\n", counterTotal[i]);
            printf("  2. Total penghasilan dari wahana : %d\n", penghasilanTotal[i]);
            printf("  3. Berapa kali wahana dinaiki dalam hari ini : %d\n", counterHari[i]);
            printf("  4. Total penghasilan dari wahana dalam hari ini : %d\n", penghasilanHari[i]);
        }
    }
    else{
        printf("***Anda tidak berada di Map 1***\n");
    }
}

void build(boolean prepPhase, MATRIKS *M, Jam *JGlobal, int *tempMoney){
//1. Setelah meminta command ini, program akan menampilkan wahana dasar yang mungkin dibuat (hasil load file eksternal).
//2. Setelah pemain memilih wahana dasar yang ingin dibuat.
//3. Jika resource untuk membangun wahana tidak mencukupi, maka akan ditampilkan pesan error.
//4. Setelah itu, perintah eksekusi ini akan dimasukkan ke dalam stack.
    if (prepPhase == true){

    Wahana W;
    WahanaSTART("wahana.txt");
    loadWahana(&W);

    
    

    //Nama Wahana
    Kata nameOfRides[4];
    nameOfRides[0] = W.namaWahana1;
    nameOfRides[1] = W.namaWahana2;
    nameOfRides[2] = W.namaWahana3;
    nameOfRides[3] = W.namaWahana4;

    //Harga Wahana
    int hargaWahana[4];
    hargaWahana[0] = W.HargaWahana1;
    hargaWahana[1] = W.HargaWahana2;
    hargaWahana[2] = W.HargaWahana3;
    hargaWahana[3] = W.HargaWahana4;

    //Kapasitas Wahana
    int kapasitasWahana[4];
    kapasitasWahana[0] = W.KapasitasWahana1;
    kapasitasWahana[1] = W.KapasitasWahana2;
    kapasitasWahana[2] = W.KapasitasWahana3;
    kapasitasWahana[3] = W.KapasitasWahana4;

    //Durasi Wahana
    int durasiWahana[4];
    durasiWahana[0] = W.DurasiWahana1;
    durasiWahana[1] = W.DurasiWahana2;
    durasiWahana[2] = W.DurasiWahana3;
    durasiWahana[3] = W.DurasiWahana4;

    //Deskripsi Wahana
    Kata deskripsi[4];
    deskripsi[0] = W.DeskripsiWahana1;
    deskripsi[1] = W.DeskripsiWahana2;
    deskripsi[2] = W.DeskripsiWahana3;
    deskripsi[3] = W.DeskripsiWahana4;

    //biaya Build
    int CostWah[4];
    CostWah[0] = W.CostWah1;
    CostWah[1] = W.CostWah2;
    CostWah[2] = W.CostWah3;
    CostWah[3] = W.CostWah4;

    //Biaya Upgrade
    int biayaUpgrade[4];
    biayaUpgrade[0] = W.BiayaUpgrade1;
    biayaUpgrade[1] = W.BiayaUpgrade2;
    biayaUpgrade[2] = W.BiayaUpgrade3;
    biayaUpgrade[3] = W.BiayaUpgrade4;

    //Waktu Build
    int waktuBuild[4];
    waktuBuild[0] = W.waktuBuild1;
    waktuBuild[1] = W.waktuBuild2;
    waktuBuild[2] = W.waktuBuild3;
    waktuBuild[3] = W.waktuBuild4;

    //Waktu Upgrade  
    int waktuUpgrade[4];
    waktuUpgrade[0] = W.waktuUpgrade1;
    waktuUpgrade[1] = W.waktuUpgrade2;
    waktuUpgrade[2] = W.waktuUpgrade3;
    waktuUpgrade[3] = W.waktuUpgrade4;

    //material yang dibutuhkan untuk membangun
    int requiredMat[4][5];
    requiredMat[0][1] = W.pasir1;
    requiredMat[0][2] = W.besi1;
    requiredMat[0][3] = W.kaca1;
    requiredMat[0][4] = W.pintu1;
    requiredMat[0][5] = W.kayu1;

    requiredMat[1][1] = W.pasir2;
    requiredMat[1][2] = W.besi2;
    requiredMat[1][3] = W.kaca2;
    requiredMat[1][4] = W.pintu2;
    requiredMat[1][5] = W.kayu2;
    
    requiredMat[2][1] = W.pasir3;
    requiredMat[2][2] = W.besi3;
    requiredMat[2][3] = W.kaca3;
    requiredMat[2][4] = W.pintu3;
    requiredMat[2][5] = W.kayu3;
    
    requiredMat[3][1] = W.pasir4;
    requiredMat[3][2] = W.besi4;
    requiredMat[3][3] = W.kaca4;
    requiredMat[3][4] = W.pintu4;
    requiredMat[3][5] = W.kayu4;

    
                for (int i = 0; i <4; i++){
                    printf("%d.", i +1 );
                    PrintKataW(nameOfRides[i]);
                    printf("\n");
                }
                printf("\n");
                int X;
                scanf(" Pilih Wahana : %d\n", &X);

                
    
    

    


    int detikAwal = JamToDetik(*JGlobal);
    *JGlobal = DetikToJam(detikAwal + (3600*waktuBuild[X-1]));
    TulisJam(*JGlobal);
    
    
    int i = 0;

    boolean check;
    printf("~ Wahana yang akan dibangun ~\n");
    printf("Nama Wahana :");
    PrintKataW(nameOfRides[X-1]);
    printf("\n");
    // printf("Nama Wahana : %s\n", nameOfRides[X-1]);
    printf("Biaya untuk membangun : %d\n",  CostWah[X-1]);
    printf("Lama waktu untuk membangun : %d\n", waktuBuild[X-1]);
    char bentukWahana = 'W';
    printf("Masukan bentuk wahana (char) : \n");
    printf("\n");


    for (i = 0; i < 5; i++){
        if (inventorytemp[i] >= requiredMat[X-1][i]){
            check = true;
            inventorytemp[i] = inventorytemp[i] - requiredMat[X-1][i];
            
            
        }else{
            check = false;

        }
    }

    if (check){
        
        *tempMoney = *tempMoney - CostWah[X];
        if (*tempMoney > 0){
        printf("building...\n");
        POINT Player = cariPoint(*M, 'P');
        

        
        Elmt(*M, Absis(Player), Ordinat(Player)) = bentukWahana;
        printf("\n");
        
    
        if (Elmt(*M,Absis(Player)-1, Ordinat(Player) ) == '-'){
            Elmt(*M,Absis(Player)-1, Ordinat(Player) ) = 'P';
            Ordinat(Player)++;
            
        }else if (Elmt(*M,Absis(Player), Ordinat(Player)-1 ) == '-'){
            Elmt(*M,Absis(Player), Ordinat(Player)-1 ) = 'P';
            Absis(Player)--;
            
        }else if (Elmt(*M,Absis(Player)+1, Ordinat(Player) ) == '-'){
            Elmt(*M,Absis(Player)+1, Ordinat(Player) ) = 'P';
            Ordinat(Player)--;
        
        }else if (Elmt(*M,Absis(Player), Ordinat(Player) +1 ) == '-'){
            Elmt(*M,Absis(Player), Ordinat(Player) +1 ) = 'P';
            Absis(Player)++;

        }else
        {
            printf("error, posisi wahana tidak memungkinkan untuk dibangun\n");
        }
        

        printf("\n");
        printf("Sisa Inventory anda :\n");
        printf("Pasir : %d\n", inventorytemp[0]);
        printf("Besi : %d\n", inventorytemp[1]);
        printf("Kaca : %d\n", inventorytemp[2]);
        printf("Pintu : %d\n", inventorytemp[3]);
        printf("Kayu : %d\n", inventorytemp[4]);
        printf("\n");
        printf("Sisa Uang anda :\n");
        printf("%d\n", *tempMoney);}
        else
        {
            printf("error, material kurang\n");
        }
        

    }else{
        printf("error, material kurang\n");
    }
    }else{

        printf("Anda berada di main phase\n");
    }
    
    
}

void mainPhase(Stack *S, Jam *J, boolean prepPhase){
    infotype X;
    if (prepPhase == true){
        while (!IsEmpty(*S)){
            if(Top(*S) != Nil){
                Pop(S, &X);
            }
        }
        Hour(*J) = 7;
        Minute(*J) = 0;
        Second(*J) = 0;
        prepPhase = false;
        printf("Anda memasuki main phase\n");
        printf("Sekarang jam : ");
        TulisJam(*J);
        printf("\n");
    }
    else{
        printf("***Anda sudah berada di Main Phase.***\n");
    }
}
void GenerateQueue(Queue Q){
//generate a queue with random numbers for the amount of times a visitor wants to play//
    infotypeQ ElQ;
    int num;
    CreateEmptyQueue(&Q,5);
    for (int i = 0; i < 5; i++)
    {
        ElQ.Kesabaran=10;
        num=rand()%5;
        ElQ.PlayNum=num;
        AddQueue(&Q,ElQ);
    }
}
void reduceKesabaran(Queue Q){
//reduce kesabaran of all elmts of q//
if (!IsEmptyQueue(Q)){
        for (int i = 0; i < NBElmtQueue(Q); i++)
        {
            Q.T[i].Kesabaran=Q.T[i].Kesabaran-1;
        }
    }
}
void DelQueueAll(Queue *Q){
//empties all queue//
    infotypeQ X;
    if (!IsEmptyQueue(*Q)){
    for (int i=0;i<NBElmtQueue(*Q);i++){
        DelQueue(Q,&X);
    }
    }
}
void print_title(){
//prosedur menulis title card yaitu Willy Wangky's workd//
printf(" __      __.__.__  .__           __      __                        __           /\\       __      __            .__       .___\n");
printf("/  \\    /  \\__|  | |  | ___.__. /  \\    /  \\_____    ____    ____ |  | _____.__.)/_____ /  \\    /  \\___________|  |    __| _/\n");
printf("\\   \\/\\/   /  |  | |  |<   |  | \\   \\/\\/   /\\__  \\  /    \\  / ___\\|  |/ <   |  |/  ___/ \\   \\/\\/   /  _ \\_  __ \\  |   / __ |\n"); 
printf(" \\        /|  |  |_|  |_\\___  |  \\        /  / __ \\|   |  \\/ /_/  >    < \\___  |\\___ \\   \\        (  <_> )  | \\/  |__/ /_/ |\n"); 
printf("  \\__/\\  / |__|____/____/ ____|   \\__/\\  /  (____  /___|  /\\___  /|__|_ \\/ ____/____  >   \\__/\\  / \\____/|__|  |____/\\____ |\n"); 
printf("       \\/               \\/             \\/        \\/     \\//_____/      \\/\\/         \\/         \\/                         \\/\n");
}
void print_mainmenu(){
//prosedur menuliskan main menu//
    printf("1. NEW GAME (new)\n");
    printf("2. EXIT (exit)\n");
}

int main(){
//nanti list untuk katanya bisa diletakkan disini//
Kata KataEXIT;
KataEXIT.TabKata[0]='e';KataEXIT.TabKata[1]='x';KataEXIT.TabKata[2]='i';KataEXIT.TabKata[3]='t';KataEXIT.Length=4;
Kata KataNew;
KataNew.TabKata[0]='n';KataNew.TabKata[1]='e';KataNew.TabKata[2]='w';KataNew.Length=3;
Kata input;
Kata KataMAIN;
KataMAIN.TabKata[0] = 'm'; KataMAIN.TabKata[1] = 'a'; KataMAIN.TabKata[2] = 'i'; KataMAIN.TabKata[3] = 'n'; KataMAIN.Length = 4;
Kata KataPREP;
KataPREP.TabKata[0] = 'p'; KataPREP.TabKata[1] = 'r'; KataPREP.TabKata[2] = 'e'; KataPREP.TabKata[3] = 'p'; KataPREP.Length=4;
Kata KataOffice;
KataOffice.TabKata[0]='o';KataOffice.TabKata[1]='f';KataOffice.TabKata[2]='f';KataOffice.TabKata[3]='i';KataOffice.TabKata[4]='c';KataOffice.TabKata[5]='e';KataOffice.Length=6;
Kata KataRepair;
KataRepair.TabKata[0]='r';KataRepair.TabKata[1]='e';KataRepair.TabKata[2]='p';KataRepair.TabKata[3]='a';KataRepair.TabKata[4]='i';KataRepair.TabKata[5]='r';KataRepair.Length=6;
Kata KataBuy;
KataBuy.TabKata[0] = 'b'; KataBuy.TabKata[1] = 'u'; KataBuy.TabKata[2] = 'y'; KataBuy.Length=3;
Kata KataBuild;
KataBuild.TabKata[0] = 'b'; KataBuild.TabKata[1] = 'u'; KataBuild.TabKata[2] = 'i'; KataBuild.TabKata[3] = 'l'; KataBuild.TabKata[4] = 'd'; KataBuild.Length=5;
Kata KataUpgrade;
KataUpgrade.TabKata[0] = 'u'; KataUpgrade.TabKata[1] = 'p'; KataUpgrade.TabKata[2] = 'g'; KataUpgrade.TabKata[3] = 'r'; KataUpgrade.TabKata[4] = 'a'; KataUpgrade.TabKata[5] = 'd'; KataUpgrade.TabKata[6] = 'e'; KataUpgrade.Length = 6;
Kata KataUndo;
KataUndo.TabKata[0]='u';KataUndo.TabKata[1]='n';KataUndo.TabKata[2]='d';KataUndo.TabKata[3]='0';KataUndo.Length=4;
Kata KataExecute;
KataExecute.TabKata[0]='e';KataExecute.TabKata[1]='x';KataExecute.TabKata[2]='e';KataExecute.TabKata[3]='c';KataExecute.TabKata[4]='u';KataExecute.TabKata[5]='t';KataExecute.TabKata[6]='e';KataExecute.Length=7;
Kata a;
a.TabKata[0]='a';a.Length=1;
Kata A;
A.TabKata[0]='A';A.Length=1;
Kata w;
w.TabKata[0]='w';w.Length=1;
Kata W;
W.TabKata[0]='W';W.Length=1;
Kata S;
S.TabKata[0]='S';S.Length=1;
Kata s;
s.TabKata[0]='s';s.Length=1;
Kata D;
D.TabKata[0]='D';D.Length=1;
Kata d;
d.TabKata[0]='d';d.Length=1;

/*inisialisasi jam global*/
Jam JGlobal=MakeJam(14,50,0);
Jam JStart=MakeJam(7,0,0);
Jam JSisa=MakeJam(0,0,0); JSisa = DetikToJam(JamToDetik(JStart) - JamToDetik(JGlobal) + 24*3600);
/*Variable global buy dan material*/
int jmlhStack=0;
int tempMaterial[10][3];
for (int i = 0; i < 10; i++){
    for (int j = 0; j < 3; j++){
        tempMaterial[i][j] = 0;
    }
}
int inventory[5]; //Berisi Jumlah material
for (int i = 0; i < 5; i++){
    inventory[i] = 0;
}

// Harusnya dri eksternal file
char Maaterial[5][20] = {
    "pasir",        //0
    "besi",         //1
    "kaca",         //2
    "pintu",        //3
    "kayu"          //4
};
int HargaaMaterial[5] = {
    500, //0
    600, //1
    1000,//2
    700, //3
    200, //4
};
/*inisialisasi stack*/
Stack Prep;
CreateEmpty(&Prep);
//main program//
print_title();
printf("\n");
print_mainmenu();
printf("\n");
printf("Masukkan input: ");
InputUser(&input);
boolean prepPhase = true;
while (!IsKataSama(input,KataEXIT))
{   
    //opsi 1 untuk main menu//
    if (IsKataSama(input,KataNew)){
     
    MATRIKS M1,M2,M3,M4;
     /*Initialize the matrices*/
        int NB = 7;
        int NK = 7;
        char filename1[30] = "map1.txt";
        char filename2[30] = "map2.txt";
        char filename3[30] = "map3.txt";
        char filename4[30] = "map4.txt";
        /*make the matrices*/
        MakeMATRIKS(NB, NK, &M1);
        MakeMATRIKS(NB, NK, &M2);
        MakeMATRIKS(NB, NK, &M3);
        MakeMATRIKS(NB, NK, &M4);
        /*read the matrices*/
        BacaMATRIKS(&M1, NB, NK, filename1);
        BacaMATRIKS(&M2, NB, NK, filename2);
        BacaMATRIKS(&M3, NB, NK, filename3);
        BacaMATRIKS(&M4, NB, NK, filename4);

        /*inisialisasi nama player*/
        char nama[100];
        printf("Masukkan Username : ");
        fgets(nama, 100, stdin);
        printf(nama);
        int money = 20000;
        int tempMoney = money;
        /*we always start at map2 hence TulisMatriks(M2)*/
        /*declare queue*/
        Queue Q1,Q2,Q3,Q4;

        /*inisialisasi semua elemen map*/
        TulisMATRIKS(M2);
        boolean cekjalan = true;
        Kata command;
        int mapstatus=2;
        POINT posisi;
        posisi=cariPoint(M2,'P');
        /*loop untuk jalan*/
        while (cekjalan){
            printf("Halo ");
            printf(nama);
            printf("Uang anda : $ %d\n", money);
            printf("Saat ini jam -> ");
            TulisJam(JGlobal);
            printf("\n");
            printf("Masukkan command: ");
            InputUser(&command);
            if (Hour(JGlobal) >= 15 || Hour(JGlobal) < 7){
                    prepPhase = true;
                    printf("Ini prep phase\n");
            }
            if(Hour(JGlobal) < 15 && Hour(JGlobal) >= 7){
                prepPhase = false;
                printf("Ini main phase\n");
            }
            if (IsKataSama(command,KataEXIT)){
                cekjalan=false;
            }
            else if (IsKataSama(command, KataMAIN)){
                mainPhase(&Prep, &JGlobal, prepPhase);
                GenerateQueue(Q1);
                prepPhase = false;
            }
            else if (IsKataSama(command,KataPREP)){
                Hour(JGlobal)=15;
                Minute(JGlobal)=0;
                Second(JGlobal)=0;
                prepPhase=true;
                DelQueueAll(&Q1);
                printf("Anda memasuki PrepPhase\n");
            }
            /*
            else if (IsKataSama(command, KataOffice)){
                office(mapstatus);
                */
            else if(IsKataSama(command,KataBuild)){
                //command yg buat build ngapain gitu//
                //push ke stack gitu//
               if (mapstatus==1){
                    build(prepPhase, &M1, &JGlobal, &tempMoney);
                }else if (mapstatus==2){    
                    build(prepPhase, &M2, &JGlobal, &tempMoney);
                }else if (mapstatus==3){
                    build(prepPhase, &M3, &JGlobal, &tempMoney);
                }else if (mapstatus==4){
                    build(prepPhase, &M4, &JGlobal, &tempMoney);
                    
                }
               
            }
            else if(IsKataSama(command,KataUpgrade)){
                //command yg buat build ngapain gitu//
                //push ke stack gitu//
            }
            else if(IsKataSama(command, KataExecute)){
                // Mengerjakan semua perintah dalam stack prep
                // execute(Prep, KataBuild, KataUpgrade, KataBuy);
            }
            else if(IsKataSama(command, KataUndo)){ 
                // Membuang command di dalam stack prep
                undo(&Prep, prepPhase);
            }
            
            else if (IsKataSama(command, KataBuy)) {
                buyy(&tempMoney, Maaterial, HargaaMaterial, &Prep, tempMaterial, &jmlhStack);
            }
            else{/*code if moving through gate*/
                /*map 2 gate movements*/
                if (mapstatus==2 && Elmt(M2,2,5)=='P' && IsKataSama(command,d)){
                    Elmt(M2,2,5)='-';
                    Elmt(M1,2,1)='P';
                    posisi=cariPoint(M1,'P');
                    mapstatus=1;
                }
                if (mapstatus==2 && Elmt(M2,5,3)=='P' && IsKataSama(command,s)){
                    Elmt(M2,5,3)='-';
                    Elmt(M3,1,3)='P';
                    posisi=cariPoint(M3,'P');
                    mapstatus=3;
                }
                /*map 1 gate movements*/
                if (mapstatus==1 && Elmt(M1,2,1)=='P' && IsKataSama(command,a)){
                    Elmt(M1,2,1)='-';
                    Elmt(M2,2,5)='P';
                    posisi=cariPoint(M2,'P');
                    mapstatus=2;
                }
                if (mapstatus==1 && Elmt(M1,5,4)=='P' && IsKataSama(command,s)){
                    Elmt(M1,5,4)='-';
                    Elmt(M4,1,4)='P';
                    posisi=cariPoint(M4,'P');
                    mapstatus=4;
                }
                /*map 3 gate movements*/
                if (mapstatus==3 && Elmt(M3,1,3)=='P' && IsKataSama(command,w)){
                     Elmt(M3,1,3)='-';
                    Elmt(M2,5,3)='P';
                    posisi=cariPoint(M2,'P');
                    mapstatus=2;
                }
                if (mapstatus==3 && Elmt(M3,3,5)=='P' && IsKataSama(command,d)){
                    Elmt(M3,3,5)='-';
                    Elmt(M4,3,1)='P';
                    posisi=cariPoint(M4,'P');
                    mapstatus=4;
                }
                /*map 4 gate movements */
                if (mapstatus==4 && Elmt(M4,1,4)=='P' && IsKataSama(command,w)){
                    Elmt(M4,1,4)='-';
                    Elmt(M1,5,4)='P';
                    posisi=cariPoint(M1,'P');
                    mapstatus=1;
                }
                if (mapstatus==4 && Elmt(M4,3,1)=='P' && IsKataSama(command,a)){
                    Elmt(M4,3,1)='-';
                    Elmt(M3,3,5)='P';
                    posisi=cariPoint(M3,'P');
                    mapstatus=3;
                }
                
                if (mapstatus==3 && Elmt(M3,3,5)=='P' && IsKataSama(command,d)){
                    Elmt(M3,3,5)='-';
                    Elmt(M4,3,1)='P';
                    posisi=cariPoint(M4,'P');
                    mapstatus=4;
                }
                /*map 4 gate movements */
                if (mapstatus==4 && Elmt(M4,1,4)=='P' && IsKataSama(command,w)){
                    Elmt(M4,1,4)='-';
                    Elmt(M1,5,4)='P';
                    posisi=cariPoint(M1,'P');
                    mapstatus=1;
                }
                if (mapstatus==4 && Elmt(M4,3,1)=='P' && IsKataSama(command,a)){
                    Elmt(M4,3,1)='-';
                    Elmt(M3,3,5)='P';
                    posisi=cariPoint(M3,'P');
                    mapstatus=3;
                }
                
                /*code for moving in the matrix*/
                if (mapstatus==1){
                M1=wasd(M1, posisi, command);
                TulisMATRIKS(M1);
                posisi=cariPoint(M1,'P');
                int plus = JamToDetik(JGlobal) + 60;
                JGlobal = DetikToJam(plus);
                }
                if (mapstatus==2){
                M2=wasd(M2, posisi, command);
                TulisMATRIKS(M2);
                posisi=cariPoint(M2,'P');
                int plus = JamToDetik(JGlobal) + 60;
                JGlobal = DetikToJam(plus);
                }
                if (mapstatus==3){
                M3=wasd(M3, posisi, command);
                TulisMATRIKS(M3);
                posisi=cariPoint(M3,'P');
                int plus = JamToDetik(JGlobal) + 60;
                JGlobal = DetikToJam(plus);
                }
                if (mapstatus==4){
                M4=wasd(M4, posisi, command);
                TulisMATRIKS(M4);
                posisi=cariPoint(M4,'P');
                int plus = JamToDetik(JGlobal) + 60;
                JGlobal = DetikToJam(plus);
                }
            }
        }
    }
    else
    {   
        printf("Mohon maaf, command tidak dikenali, coba perhatikan kembali input anda\n");   
    }
    print_mainmenu();
    printf("Masukkan input: ");
    InputUser(&input);
}

    return 0;
}
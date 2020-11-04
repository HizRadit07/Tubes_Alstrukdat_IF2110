#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "mesinkar.c"
#include "mesinkata.c"

#include "boolean.h"
#include "matriks.h"
#include "matriks.c"
#include "point.h"
#include "point.c"

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
//initialize kata exit//
Kata KataEXIT;
KataEXIT.TabKata[0]='e';KataEXIT.TabKata[1]='x';KataEXIT.TabKata[2]='i';KataEXIT.TabKata[3]='t';KataEXIT.Length=4;
Kata KataNew;
KataNew.TabKata[0]='n';KataNew.TabKata[1]='e';KataNew.TabKata[2]='w';KataNew.Length=3;
Kata input;

//main program//
print_title();
printf("\n");
print_mainmenu();
printf("\n");
printf("Masukkan input: ");
input=ScanKata();
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

        /*we always start at map2 hence TulisMatriks(M2)*/
        /*inisialisasi semua elemen map*/
        Elmt(M2,5,3)='P';//initialize player
        TulisMATRIKS(M2);
        boolean cekjalan = true;
        char jalan[1];
        int jalan2;
        int mapstatus=2;
        POINT posisi;
        posisi=cariPoint(M2,'P');
        /*loop untuk jalan*/
        while (cekjalan){
            scanf("%s", &jalan);
            jalan2=(int) jalan[0];
            if (jalan2 != 'w' && jalan2 != 'W' && jalan2 != 'a' && jalan2 != 'A' && jalan2 != 's' && jalan2 != 'S' && jalan2 != 'd'&& jalan2 != 'D'){
                cekjalan=false;
            }
            else{/*code if moving through gate*/
                /*map 2 gate movements*/
                if (mapstatus==2 && Elmt(M2,2,5)=='P' && jalan2=='d'){
                    Elmt(M1,2,1)='P';
                    posisi=cariPoint(M1,'P');
                    mapstatus=1;
                }
                if (mapstatus==2 && Elmt(M2,5,3)=='P' && jalan2=='s'){
                    Elmt(M3,1,3)='P';
                    posisi=cariPoint(M3,'P');
                    mapstatus=3;
                }
                /*map 1 gate movements*/
                if (mapstatus==1 && Elmt(M1,2,1)=='P' && jalan2=='a'){
                    Elmt(M2,2,5)='P';
                    posisi=cariPoint(M2,'P');
                    mapstatus=2;
                }
                if (mapstatus==1 && Elmt(M1,5,4)=='P' && jalan2=='s'){
                    Elmt(M4,1,4)='P';
                    posisi=cariPoint(M4,'P');
                    mapstatus=4;
                }
                /*map 3 gate movements*/
                if (mapstatus==3 && Elmt(M3,1,3)=='P' && jalan2=='w'){
                    Elmt(M2,5,3)='P';
                    posisi=cariPoint(M2,'P');
                    mapstatus=2;
                }
                if (mapstatus==3 && Elmt(M3,3,5)=='P' && jalan2=='d'){
                    Elmt(M4,3,1)='P';
                    posisi=cariPoint(M4,'P');
                    mapstatus=4;
                }
                /*map 4 gate movements */
                if (mapstatus==4 && Elmt(M4,1,4)=='P' && jalan2=='w'){
                    Elmt(M1,5,4)='P';
                    posisi=cariPoint(M1,'P');
                    mapstatus=1;
                }
                if (mapstatus==4 && Elmt(M4,3,1)=='P' && jalan2=='a'){
                    Elmt(M3,3,5)='P';
                    posisi=cariPoint(M3,'P');
                    mapstatus=3;
                }
                /*code for moving in the matrix*/
                if (mapstatus==1){
                M1=wasd(M1, posisi, jalan[0]);
                TulisMATRIKS(M1);
                posisi=cariPoint(M1,'P');
                }
                if (mapstatus==2){
                M2=wasd(M2, posisi, jalan[0]);
                TulisMATRIKS(M2);
                posisi=cariPoint(M2,'P');
                }
                if (mapstatus==3){
                M3=wasd(M3, posisi, jalan[0]);
                TulisMATRIKS(M3);
                posisi=cariPoint(M3,'P');
                }
                if (mapstatus==4){
                M4=wasd(M4, posisi, jalan[0]);
                TulisMATRIKS(M4);
                posisi=cariPoint(M4,'P');
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
    input=ScanKata();
}

    return 0;
}
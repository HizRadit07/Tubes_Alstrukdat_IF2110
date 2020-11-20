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
#include "office.c"

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
Kata KataOffice;
KataOffice.TabKata[0]='o';KataOffice.TabKata[1]='f';KataOffice.TabKata[2]='f';KataOffice.TabKata[3]='i';KataOffice.TabKata[4]='c';KataOffice.TabKata[5]='e';KataOffice.Length=6;
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
        int money=1000;
        /*we always start at map2 hence TulisMatriks(M2)*/
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
                
            }
            else if (IsKataSama(command, KataOffice)){
                office(mapstatus);
            }
            else if(IsKatasama(command,KataBuild)){
                //command yg buat build ngapain gitu//
                //push ke stack gitu//
            }
            else if(IsKatasama(command,KataUpgrade)){
                //command yg buat build ngapain gitu//
                //push ke stack gitu//
            }
            else if(IsKataSama(command, KataExecute)){
                // Mengerjakan semua perintah dalam stack prep
                // execute(Prep, KataBuild, KataUpgrade, KataBuy);
            }
            else if(IsKataSama(command, KataUndo)){
                // Membuang command di dalam stack prep
                // undo(&Prep);
            }
            
            else if (IsKataSama(command, KataBuy)) {
                // Buy
                // buy(int Money, char Material[12][20], int hargaMaterial[12], int TempMoney)
                // On progress
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
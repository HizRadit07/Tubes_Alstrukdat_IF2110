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
        printf("Masih dalam progres :)\n");
        
        MATRIKS M;
        int NB = 7;
        int NK = 7;
        char filename[30] = "map2.txt";
        MakeMATRIKS(NB, NK, &M);
        BacaMATRIKS(&M, NB, NK, filename);
        TulisMATRIKS(M);

        boolean cekjalan = true;
        char jalan;
        while (cekjalan){
            scanf("%c", &jalan);
            if (jalan != 'w' && jalan != 'W' && jalan != 'a' && jalan != 'A' && jalan != 's' && jalan != 'S' && jalan != 'd' && jalan != 'D'){
                cekjalan = false;
            }
            else{
                wasd(M, cariPoint(M, 'P'), jalan);
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
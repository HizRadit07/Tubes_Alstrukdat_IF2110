#include "stackt.h"
#include "stackt.c"
#include "mesinkar.h"
#include "mesinkata.h"
#include "mesinkar.c"
#include "mesinkata.c"

void execute(Stack S, Kata build, Kata up, Kata buy, boolean prepPhase)
{
    Stack S1;
    infotype X;
    CreateEmpty(&S1);
    if (prepPhase){
        while (!IsEmpty(S)){
            Pop(&S, &X);
            Push(&S1, X);
        }
        while (!IsEmpty(S1)){
            Pop(&S1, &X);
            // X itu command buy, build, undo or upgrade.
            if (IsKatasama(X, build))
            {
                //command yg buat ngerjain build ngapain gitu//
            }
            else if (IsKatasama(X, up))
            {
                //command yg buat ngerjain up ngapain gitu//
            }
            else if (IsKataSama(X, buy))
            {
                // Buy
                // buy(int Money, char Material[12][20], int hargaMaterial[12], int TempMoney)
                
            }
        }
    }
    else{
        printf("Anda berada di main phase");
    }
}

void undo(Stack *S, boolean prepPhase){
    if (prepPhase){
        infotype X;
        Pop(S, &X);
    }
    else{
        printf("Anda berada di main phase");
    }
}

#include "stackt.h"
#include "mesinkar.h"
#include "mesinkata.h"

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
            if (IsKataSama(X, build))
            {
                //command yg buat ngerjain build ngapain gitu//
            }
            else if (IsKataSama(X, up))
            {
                //command yg buat ngerjain up ngapain gitu//
            }
            else if (IsKataSama(X, buy))
            {   
                // Buy
                // eksekusiBuy(int *uanglobal, int *inventory[5], Jam *sisaWaktu, int tempmat[10][3], int *counter
                // --
                
            }
        }
        // moneyTemp = Uang;
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

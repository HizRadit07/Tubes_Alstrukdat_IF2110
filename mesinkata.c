#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include <string.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == BLANK) {
        ADV();
        }
}
void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlank();
    if (CC==MARK){
        EndKata=true;
    }
    else
    {
        EndKata=false;
        SalinKata();
    }
    
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
   {
       IgnoreBlank();
        if (CC == MARK) {
            EndKata = true;
            } 
        else {
            SalinKata();
            }
   }

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    {
        int i; /* definisi */
        i = 0;
        while ((CC != MARK) && (CC != BLANK) && i<NMax) {
            CKata.TabKata[i] = CC;
            ADV();
            i++;
            } /* CC = MARK or CC = BLANK or i>=nmax */
        IgnoreBlank();
        if (CC==MARK){
            EndKata=true;
        }
        CKata.Length = i;
    }

boolean IsKataSama(Kata K1,Kata K2)
/*Menghasilkan true jika K1 = K2*/
{   boolean same=true;
    if (K1.Length!=K2.Length){
        same=false;
    }
    else
    {
        int i=0;
        while (i<K1.Length)
        {
            if (K1.TabKata[i]!=K2.TabKata[i]){
                same=false;
            }
            else
            {
                i++;
            }
            
        }
        
    }
    return same;
}
Kata ScanKata()
/*fungsi untuk membaca input string dari pengguna dan mereturn kata*/
{
    Kata hasil;
    char a[50];
    int length;

    gets(a);
    hasil.Length=strlen(a);
    for (int i = 0; i < strlen(a); i++)
    {
        hasil.TabKata[i]=a[i];
    }
   return hasil; 
}
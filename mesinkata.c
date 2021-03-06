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
{  
    int i;
	boolean sama;
	sama = true;

	if (K1.Length != K2.Length){
		return false;
	} else {
		i = 0;
		while ((sama)&&(i < K1.Length)){
			sama = (K1.TabKata[i] == K2.TabKata[i]);
			i++;
		}
		return (sama);
	}
}

void PrintKata (Kata K)
/* I.S. Kata K terdefinisi */
/* F.S. K tercetak di layar tanpa karakter tambahan di awal maupun di akhir */
{
	int i = 0;
	while (i<K.Length)
	{
		printf("%c", K.TabKata[i]);
		i++;
	}
}

void InputUser(Kata *K)
/* I.S. Sembarang */
/* F.S. menginput masukan kata dari user dan menyimpannya di K */
{
	char c;
	int i = 0;
	scanf("%c",&c);
	while (c != '\n')
	{
		(*K).TabKata[i] = c;
		++i;
		scanf("%c",&c);
	}
	(*K).Length = i;
}

void IgnoreBlankW(char cc)
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == cc) {
        ADV();
        }
}
void STARTKATAWahana(char *file, char cc)
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    WahanaSTART(file);
    IgnoreBlankW(cc);
    if (CC==MARK){
        EndKata=true;
    }
    else
    {
        EndKata=false;
        ADVKATA(cc);
    }
    
}

void WahanaKataSTART(char * namafile){
	WahanaSTART(namafile);
	IgnoreBlank();
	if (CC == MARK)
		EndKata = true;
	else {
		EndKata = false;
		SalinKata();
		IgnoreBlank();
		if (CC == MARK)
			EndKata = true;
	}
}

void ADVKATAW(char cc)
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
   {
       IgnoreBlank(cc);
        if (CC == MARK) {
            EndKata = true;
            } 
        else {
            SalinKata(cc);
            IgnoreBlank(cc);
            }
   }

void CopyKataW(Kata in, Kata * out) {
    int i;

    for(i = 0; i < in.Length; i++) {
        (*out).TabKata[i] = in.TabKata[i];
    }

    (*out).Length = in.Length;
}

int ConvertKataW(Kata in) {
    int i;
    int val;

    val =0;
    for(i = 0; i < in.Length; i++) {
        val *= 10;
        val += (in.TabKata[i] - '0');
    } 

    return val;
}

int ConvertKataChar(Kata in) {
    int i;
    char val;

    val =0;
    for(i = 0; i < in.Length; i++) {
        val *= 10;
        val += (in.TabKata[i] - '0');
    } 

    return val;
}


void SalinKataW(char cc)
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    {
        int i; /* definisi */
        i = 0;
        while ((CC != MARK) && (CC != BLANK) && i<NMax && (CC != cc)) {
            CKata.TabKata[i] = CC;
            ADV();
            i++;
            } /* CC = MARK or CC = BLANK or i>=nmax */
        IgnoreBlank(cc);
        if (CC==MARK){
            EndKata=true;
        }
        CKata.Length = i;
    }

boolean IsKataSamaW(Kata K1,Kata K2)
/*Menghasilkan true jika K1 = K2*/
{  
    int i;
	boolean sama;
	sama = true;

	if (K1.Length != K2.Length){
		return false;
	} else {
		i = 0;
		while ((sama)&&(i < K1.Length)){
			sama = (K1.TabKata[i] == K2.TabKata[i]);
			i++;
		}
		return (sama);
	}
}

void PrintKataW (Kata K)
/* I.S. Kata K terdefinisi */
/* F.S. K tercetak di layar tanpa karakter tambahan di awal maupun di akhir */
{
	int i = 0;
	while (i<K.Length)
	{
		printf("%c", K.TabKata[i]);
		i++;
	}
}

void InputUserW(Kata *K)
/* I.S. Sembarang */
/* F.S. menginput masukan kata dari user dan menyimpannya di K */
{
	char c;
	int i = 0;
	scanf("%c",&c);
	while (c != '\n')
	{
		(*K).TabKata[i] = c;
		++i;
		scanf("%c",&c);
	}
	(*K).Length = i;
}
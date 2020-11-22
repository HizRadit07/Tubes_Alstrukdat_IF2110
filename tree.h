#ifndef BinTree_H
#define BinTree_H

#include <stdlib.h>
#include <stdio.h>

#define Nil NULL

#include "boolean.h"
#include "mesinkata.h"


typedef int Infotype;
typedef struct tNode *address;
typedef struct tNode {
Infotype info;
address left;
address right;
} Node;

typedef address BinTree;

#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

address Alokasi (Infotype X);
/* { Mengirimkan address hasil alokasi sebuah elemen X }
{ Jika alokasi berhasil, maka address tidak nil, dan misalnya
menghasilkan P, maka Info(P)=X, Left(P)=Nil, Right(P)=Nil 
{ Jika alokasi gagal, mengirimkan Nil } */

void Dealokasi (address P);
/*{ I.S. P terdefinisi }
{ F.S. P dikembalikan ke sistem }
{ Melakukan dealokasi/pengembalian address P } */

Infotype GetAkar(address P);

BinTree Pree (Infotype X , BinTree L ,BinTree R );

void MakeTree (Infotype X, BinTree L , BinTree R ,BinTree *P );


BinTree GetLeft (BinTree P);
// Mengirimkan Anak Kiri pohon biner P 

BinTree GetRight (BinTree P);
//Mengirimkan Anak Kanan pohon biner P 

boolean IsTreeEmpty (BinTree P);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil }
 Menghasilkan pohon kosong (Nil) jika alokasi gagal */


boolean IsOneElmt (BinTree P);
/*{ Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen }
*/

boolean IsUnerLeft (BinTree P);
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerleft:
hanya mempunyai subpohon kiri }*/

boolean IsUnerRight (BinTree P);
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerright:
hanya mempunyai subpohon kanan }*/

boolean IsBiner (BinTree P);
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon biner:
mempunyai subpohon kiri dan subpohon kanan }*/

boolean SearchXtree (BinTree P, Infotype X);
/*{ Mengirimkan true jika ada node dari P yang bernilai X }
*/

void AddDaunTerkiri (BinTree P ,Infotype X, Infotype Y,boolean Kiri);
/*{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya,
dengan X sebagai simpul daun terkiri }
*/


void DelDaunTerkiri (BinTree P ,Infotype X );
/*{ I.S. P tidak kosong }
{ F.S. Daun terkiri P dihapus, nilai daun ditampung di X }*/



#endif
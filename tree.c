#include "Tree.h"
#include "boolean.h"

address Alokasi (Infotype X){
    address temp;

    temp = (address) malloc (sizeof(Node));
    if (temp != Nil){
        Akar(temp) = X;
        Right(temp) = Nil;
        Left(temp) = Nil;
    }

    return temp;
}

void Dealokasi (address P){
    free(P);

}

Infotype GetAkar(BinTree P){
    return Akar(P);
}

BinTree Pree (Infotype X , BinTree L ,BinTree R ){
    

         address P;
    P = Alokasi(X);
    if (P != Nil){
        Left(P) = L;
        Right(P) = R;
        }

        return P;
}

void MakeTree (Infotype X, BinTree L , BinTree R ,BinTree *P ){
    *P = Alokasi(X);
    if (P != Nil){
        Left(*P) = L;
        Right(*P) = R;
        }
}

BinTree GetLeft (BinTree P)
// Mengirimkan Anak Kiri pohon biner P 
{
    return Left(P);
}

BinTree GetRight (BinTree P)
//Mengirimkan Anak Kanan pohon biner P 
{
    return Right(P);
}
boolean IsTreeEmpty (BinTree P)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil }
 Menghasilkan pohon kosong (Nil) jika alokasi gagal */
 {
     return P == Nil;
 }


boolean IsOneElmt (BinTree P)
/*{ Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen }
*/
{
    if(!IsTreeEmpty(P)){
        return ((Left(P) == Nil) && (Right(P) == Nil));

    }else
    {
        return false;
    }
    
}

boolean IsUnerLeft (BinTree P)
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerleft:
hanya mempunyai subpohon kiri }*/
{return (Left(P) == Nil) && (Right(P) != Nil) ;}

boolean IsUnerRight (BinTree P)
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerright:
hanya mempunyai subpohon kanan }*/
{return (Left(P) != Nil) && (Right(P) == Nil);}

boolean IsBiner (BinTree P)
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon biner:
mempunyai subpohon kiri dan subpohon kanan }*/
{
    {return (Left(P) != Nil) && (Right(P) != Nil);}
}

boolean SearchXTree (BinTree P, Infotype X)
/*{ Mengirimkan true jika ada node dari P yang bernilai X }*/
{   

    

    if (IsOneElmt(P)){
        if (Akar(P)==X){
            return true;

        }else
        {
            return false;
        }
        
    }else
    {
        if (IsBiner(P)){
            return  (SearchTree(Left(P),X) || SearchTree(Right(P),X));
        }else if (IsUnerLeft(P))
        {
            return SearchTree(Left(P),X);
        }else if(IsUnerRight(P)){
            SearchTree(Right(P),X);
        }
        
    }
    



}

void AddDaunTerkiri (BinTree P ,Infotype X)
/*{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya,
dengan X sebagai simpul daun terkiri }
*/
{
    if(IsTreeEmpty(P)){
        P = Alokasi(X);
    }else
    {
        if (IsUnerLeft(P)){

            return AddDaunTerkiri(Left(P),X);
         }
        else if(IsUnerRight(P)){
             return AddDaunTerkiri(Right(P),X);
        }else if (IsBiner(P)){

            if (SearchTree(Left(P),X)){
                AddDaun(Left(P),X);
            }
            else if (SearchTree(Right(P),X)) {
                AddDaun(Right(P),X);

         }
    }
    

}
}

void DelDaunTerkiri (BinTree P ,Infotype X )
/*{ I.S. P tidak kosong }
{ F.S. Daun terkiri P dihapus, nilai daun ditampung di X }*/
{

    address N;

    if(IsOneElmt(P)){
        X = Akar(P);
        N = P;
        P = Nil;
        Dealokasi(N);
    }else
    {if (IsUnerRight(P))
    {
        DelDaunTerkiri(Right(P),X );
    }else
    {
        DelDaunTerkiri(Left(P), X);
    }
    
    
        
    }
    

}
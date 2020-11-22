//Hizkia Raditya Pratama Roosadi//
//13519087//
//file arraypos.c realisasi fungsi arraypos//

#include <stdio.h>
#include <math.h>
#include "arraypos.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{   int i;
    for ( i = IdxMin; i <IdxMax+1; i++)
    {
        T->TI[i]=ValUndef;
    }
    
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{   int a,i;
    a=0;
    for (i = IdxMin; i < IdxMax+1; i++)
    {
        if (T.TI[i]!=ValUndef)
        {
            a=a+1;
        }  
    }
    return a;
}
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax-IdxMin+1;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return (IdxMin);
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (NbElmt(T)-1);
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{   boolean valid;
    valid=false;
    if ((i >= IdxMin) && (i <= IdxMax))
    {
        valid= true;
    }
    return valid;
}
boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{   boolean eff;
    eff=false;
    if ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)))
    {
        eff=true;
    }
    return eff;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{   boolean empty;
    empty=true;
    if ((T.TI[IdxMin])!=ValUndef)
    {
        empty=false;
    }
    return empty;
}
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
{   boolean full;
    int i;
    full=true;
    for (i = IdxMin; i < IdxMax+1; i++)
    {
        if (T.TI[i]==ValUndef){
            full=false;
        }
    }
    return full;
}
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int N,i,value;
    scanf ("%d",&N);
    while ((N<0) || (N>MaxNbEl(*T)))
    {
        scanf("%d",&N);
    }
    if (N==0)
    {
        MakeEmpty(T);
    }
    else
    {
        MakeEmpty(T);
        for ( i = IdxMin; i < N; i++)
            {
                scanf("%d",&value);
                T->TI[i]=value;
            }
    } 
}
void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{   int i;
    if (IsEmpty(T)){
        printf("[]");
    }
    else
    {   
        printf("[");
        for (i = IdxMin; i <GetLastIdx(T); i++)
        {
            printf("%d,",T.TI[i]);
        }
        printf("%d",T.TI[NbElmt(T)-1]);
        printf("]");
    }
    
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{   int i,j;
    TabInt T3;
    MakeEmpty(&T3);
    if (IsEmpty(T1))
    {
        return T2;
    }
    else if(IsEmpty(T2))
    {
        return T1;
    }
    else{
        if (plus==true){
            for ( i = IdxMin; i < NbElmt(T1); i++)
            {
                T3.TI[i]=T1.TI[i]+T2.TI[i];
            }  
        }
        else
        {
            for ( j = IdxMin; j < NbElmt(T1); j++)
            {
                T3.TI[j]=T1.TI[j]-T2.TI[j];
            }
        }
        return T3;
}
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{   
    boolean equal;
    int i;

    equal = true;
    i = GetFirstIdx(T1);
    while ((equal) && (i <= IdxMax)){
        if ((Elmt(T1,i)) != (Elmt(T2,i))){
            equal = false;
        }
        i++;
    }

    return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{   int i;
    boolean found;
    if (IsEmpty(T)){
        return (IdxUndef);
    }
    else
    {
        found=false;
        i=-1;
        while ((i<IdxMax+1) && (found==false))
        {   
            i=i+1;
            if ((T.TI[i])==X)
            {
                found=true;
            }
        }
        if (found==false)
        {
            return (IdxUndef);
        }
        else
        {
            return i;
        }
    }
    
}
boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{   int i;
    boolean found2;
    found2=false;
    for (i = IdxMin; i < NbElmt(T); i++)
    {
        if (T.TI[i]==X){
            found2=true;
        }
    }
    return (found2);
}
/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    int i;

    *Max = Elmt(T,GetFirstIdx(T));
    *Min = Elmt(T,GetFirstIdx(T));

    for (i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if ((Elmt(T,i)) > *Max){
            *Max = Elmt(T,i);
        }
        if ((Elmt(T,i)) < *Min){
            *Min = Elmt(T,i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{   int i;
    ElType sum;
    sum=0;
    if (IsEmpty(T)){
    return 0;}
    else{
    for ( i = IdxMin; i < NbElmt(T); i++)
    {
        sum=sum+T.TI[i];
    }
    return sum;
    }
}

int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{    int i,result;

    if(IsEmpty(T)){
        result = 0;
    }
    else{
        result = 0;
        for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++){
            if (T.TI[i] == X){
                result += 1;
            }
        }
    }

    return result;
}
boolean IsAllGenap (TabInt T)
/* Menghailkan true jika semua elemen T genap */
{   boolean genap;
    int i;
    genap=true;
    while((genap) && (i<=GetLastIdx(T))){
        if (((Elmt(T,i))%2) != 0){
            genap = false;
        }
        i++;
    }

    return genap;
}


/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{       int swap,i,j,position;
if (asc==true){
    for(i = IdxMin; i < NbElmt(*T) - 1; i++)
    {
    position=i;
    for(j = i + 1; j < NbElmt(*T); j++)
    {
    if(T->TI[position] >= T->TI[j])
    position=j;
    }
    if(position != i)
    {
    swap=T->TI[i];
    T->TI[i]=T->TI[position];
    T->TI[position]=swap;
    }
    }
    }
else
{
    for(i = IdxMin; i < NbElmt(*T) - 1; i++)
    {
    position=i;
    for(j = i + 1; j < NbElmt(*T); j++)
    {
    if(T->TI[position] <= T->TI[j])
    position=j;
    }
    if(position != i)
    {
    swap=T->TI[i];
    T->TI[i]=T->TI[position];
    T->TI[position]=swap;
    }
    } 
}
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    if (IsFull(*T)==false)
    {
       if (IsEmpty(*T))
       {
           T->TI[IdxMin]=X;
       }
       else
       {
         T->TI[GetLastIdx(*T)+1]=X;
        }
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{ 
    *X=T->TI[NbElmt(*T)-1];
    T->TI[NbElmt(*T)-1]=ValUndef;
}
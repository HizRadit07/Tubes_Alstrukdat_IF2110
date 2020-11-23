/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>
#include "point.h"
#include "mesinkata.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
} 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
    return ((i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
    return 0;
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
    return 0;
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
    return NBrsEff(M)-1;
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
    return NKolEff(M)-1;
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    return ((i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M)));
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK, char filename[30]){
    FILE *pf;
    pf = fopen (filename, "r");
    if (pf == NULL)
        printf("maap gan");

    for(size_t i = 1; i <= NB + 1; ++i)
    {
        for(size_t j = 1; j <= NK + 1 ; ++j){
            fscanf(pf, "%c", &Elmt(*M, i-1, j-1));
        }
    }
    fclose (pf); 
}
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M){
    for(indeks k = 0; k < NBrsEff(M); k++)
    {
        for(indeks l = 0; l < NKolEff(M); l++)
        {
            printf("%c",Elmt(M, k, l));
        }
        printf("\n");
    }
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
    return NBrsEff(M) * NKolEff(M);
}
/* Mengirimkan banyaknya elemen M */


boolean Jalan (MATRIKS M, indeks i, indeks j){
    return (Elmt(M, i, j) != 'W' && Elmt(M, i, j) != '*' && Elmt(M, i, j) != 'O' && Elmt(M, i, j) != 'A' && Elmt(M, i, j) != '>' && Elmt(M, i, j) != '<' && Elmt(M, i, j) != '^' && Elmt(M, i, j) != 'V');
}

MATRIKS wasd (MATRIKS M, POINT P, Kata jalan){
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
    if (IsKataSama(W, jalan) || IsKataSama(w, jalan)){
        if (Jalan(M, Absis(P)-1, Ordinat(P))){
            char temp = Elmt(M, Absis(P), Ordinat(P));
            Elmt(M, Absis(P), Ordinat(P)) = Elmt(M, Absis(P)-1, Ordinat(P));
            Elmt(M, Absis(P)-1, Ordinat(P)) = temp;
            Ordinat(P)++;
        }
    }

    if (IsKataSama(A, jalan) || IsKataSama(a, jalan)){
        if (Jalan(M, Absis(P), Ordinat(P)-1)){
            char temp = Elmt(M, Absis(P), Ordinat(P));
            Elmt(M, Absis(P), Ordinat(P)) = Elmt(M, Absis(P), Ordinat(P)-1);
            Elmt(M, Absis(P), Ordinat(P)-1) = temp;
            Absis(P)--;
        }
    }

    if (IsKataSama(S, jalan) || IsKataSama(s, jalan)){
        if (Jalan(M, Absis(P)+1, Ordinat(P))){
            char temp = Elmt(M, Absis(P), Ordinat(P));
            Elmt(M, Absis(P), Ordinat(P)) = Elmt(M, Absis(P)+1, Ordinat(P));
            Elmt(M, Absis(P)+1, Ordinat(P)) = temp;
            Ordinat(P)--;
        }
    }

    if (IsKataSama(D, jalan) || IsKataSama(d, jalan)){
        if (Jalan(M, Absis(P), Ordinat(P)+1)){
            char temp = Elmt(M, Absis(P), Ordinat(P));
            Elmt(M, Absis(P), Ordinat(P)) = Elmt(M, Absis(P), Ordinat(P)+1);
            Elmt(M, Absis(P), Ordinat(P)+1) = temp;
            Absis(P)++;
        }
    }
    return M;
}

POINT cariPoint (MATRIKS M, char Z){
    POINT P;
    for (int i = 0; i < NBrsEff(M); i++){
        for (int j = 0; j < NKolEff(M); j++){
            if (Elmt(M, i, j) == Z){
                P = MakePOINT(i, j);
            }
        }
    }
    return P;
}







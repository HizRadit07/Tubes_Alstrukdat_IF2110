#include <stdio.h>
#include <stdlib.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "mesinkar.c"
#include "mesinkata.c"

typedef struct twahana * address_w;
typedef struct twahana {
    Kata namaWahana;
    int HargaWahana;
    int KapasitasWahana;
    int DurasiWahana;
    Kata DeskripsiWahana;
    int BiayaBuild;
    int BiayaUpgrade;
    int waktuBuild;
    int waktuUpgrade;
    int pasir; //Pasir
    int besi; //Besi
    int kaca; //Kaca
    int pintu; //Pintu
    int kayu; //Kayu

} Wahana;

void KataWahanaSalin(){ //SALINKATA
	int i = 1;
	boolean STOP;
	do {
		CKata.TabKata[i] = CC;
		ADV();
		STOP = ((CC == MARK) || (CC == BLANK) || (i == NMax));
		if (!STOP)
			i++;
	} while (!STOP);
	CKata.Length = i;
}

void SalinKataFile() { //SALINKATA

    

   /* char EOL = '\n';
    
 
    int i;
    i = 0;

    while ( (i < NMax) && (CC != MARK)&& (CC != EOL)  && (CC != '-'))
    {
        CKata.TabKata[i] = CC;
        ADV();
        
        i++;        
    }
    if (CC == '-'){
        ADV();
    }if(CC = EOL){
        ADV();
    }
    


    CKata.Length = i; */

    int i = 1;
	boolean STOP;
	do {
		CKata.TabKata[i] = CC;
		ADV();
		STOP = ((CC == MARK) || (CC == BLANK) || (i == NMax));
		if (!STOP)
			i++;
	} while (!STOP);
	CKata.Length = i;

 

}


void WahanaADVKATA() //ADVKATA
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
   {
       IgnoreBlank();
	if (CC == MARK)
		EndKata = true;
	else {
		SalinKataFile();
		if (CC == MARK)
			EndKata = true;
	}
   }

int main()
{   
 /*
    WahanaSTART("test.txt");

    int i,j;
    Kata value[10000][13];
    FILE *archivo;
    archivo = fopen("wahana.txt","r");
    
    i=0;
    char separator = ' ';

    ADVKATAW(separator);

    CopyKataW(CKata, &value[i][0]);

    ADVKATAW(separator);
    CopyKataW(CKata, &value[i][1]);
  
    //CopyKataW(CKata, &value[i][1]);
    //(*W).HargaWahana = ConvertKataW(CKata);

    ADVKATAW(separator);
    //CopyKataW(CKata, &(*W).DurasiWahana);
    CopyKataW(CKata, &value[i][2]);
// (*W).DurasiWahana = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &value[i][3]);
    //CopyKataW(CKata, &(*W).DeskripsiWahana);

    ADVKATAW(separator);
    CopyKataW(CKata, &value[i][4]);
    //CopyKataW(CKata, &(*W).BiayaBuild);
    //(*W).BiayaBuild = ConvertKataW(CKata);

    ADVKATAW(separator);
    
    CopyKataW(CKata, &value[i][5]);
    //CopyKataW(CKata, &(*W).BiayaUpgrade);
    //(*W).BiayaUpgrade = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &value[i][6]);
    // CopyKataW(CKata, &(*W).waktuBuild);
    //(*W).waktuBuild = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &value[i][7]);
    // CopyKataW(CKata, &(*W).waktuUpgrade);
    //(*W).waktuUpgrade = ConvertKataW(CKata);

        ADVKATAW(separator);
        CopyKataW(CKata, &value[i][8]);
    // CopyKataW(CKata, &(*W).pasir);
    // (*W).pasir = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &value[i][9]);
    // CopyKataW(CKata, &(*W).besi);
        //(*W).besi = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &value[i][10]);
    //CopyKataW(CKata, &(*W).kaca);
    // (*W).kaca = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &value[i][11]);
    //CopyKataW(CKata, &(*W).pintu);
    // (*W).pintu = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &value[i][12]);
    //CopyKataW(CKata, &(*W).kayu);
    // (*W).kayu = ConvertKataW(CKata);

    ADVKATAW(separator);
    CopyKataW(CKata, &value[i][13]);
//fscanf( archivo, "%c %d %d %d %c %d %d %d %d %d %d %d %d %d", &value[i][0],&value[i][1],&value[i][2], );
//fscanf( archivo, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c", &value[i][0],&value[i][1],&value[i][2], &value[i][2], &value[i][3], &value[i][4], &value[i][5], &value[i][6], &value[i][7], &value[i][8], &value[i][9], &value[i][10], &value[i][11], &value[i][12], &value[i][13]);
//printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", value[i][0],value[i][1],value[i][2], value[i][2], value[i][3],value[i][4], value[i][5],value[i][6], value[i][7], value[i][8],value[i][9],value[i][10],value[i][11],value[i][12],value[i][13]);


    

    
     // int harga = W->HargaWahana;
  //  printf("%d", harga);

    /*printf("Your matrix:\n");
    for(j = 0; j < i; j++)
        fscanf( archivo, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c", &value[j][0],&value[j][1],&value[j][2], &value[j][2], &value[j][3], &value[j][4], &value[j][5], &value[j][6], &value[j][7], &value[j][8], &value[j][9], &value[j][10], &value[j][11], &value[j][12], &value[j][13]);


    fclose(archivo);
    return 0;
    

    */


   WahanaSTART("test.txt");
    while (!EndKata){
        for (int i = 1; i <= CKata.Length; i++)
			printf("%c", CKata.TabKata[i]);
		printf("\n");
        WahanaADVKATA();
    }
	for (int i = 1; i <= CKata.Length; i++)
		printf("%c", CKata.TabKata[i]);
	printf("\n");

//wahana.txt nama-apa-apa
//kata array_wahana[5]
//start
//i=0
/*while (not eop){
    advkata()//pembatas di '-',
    array_wahana[i]=ckata;
    advkata
    i++
}*/

   return 0;



}
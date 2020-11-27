#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
void readfile(){
    int i,j;
    char value[10000][3];
    FILE *archivo;
    archivo = fopen("test.txt","r");
    if (archivo == NULL)
        exit(1);
    i=0;
    while (feof(archivo) == 0)
    {
        sscanf( archivo, "%s %s %s", &value[i][0],&value[i][1],&value[i][2]);
        printf("%s %s %s\n", value[i][0], value[i][1], value[i][2]);
        i++;
    }

    printf("Your matrix:\n");
    for(j = 0; j < i; j++)
        printf("%s %s %s\n", value[j][0], value[j][1], value[j][2]);

    fclose(archivo);
  
}
*/


#define MAX_TEXT_LINE_LENGTH 128
int main(void)
{
    FILE    *my_file = fopen("test2.txt", "r");
    char    text_read[MAX_TEXT_LINE_LENGTH];
    char    nama_wahana[64];
    char    deskripsi_wahana[64];
    char    des_des[64];
    char    NamaWahana[64][64];
    char    DeskripsiWahana[64][64];
    char    desdes[64][64];
     int i = 0;
    if (!my_file)
    {
        fprintf(stderr, "Error opening data file:  data.txt");
        return EXIT_FAILURE;
    }
    while (fgets(text_read, MAX_TEXT_LINE_LENGTH, my_file))
    {
        char * p;
        //Separator ('/')
        p = strchr(text_read, '/');
        // Ngereset dri awal
        nama_wahana[0] = '\0';
        deskripsi_wahana[0] = '\0';
        des_des[0] = '\0';
       
        if (p != 0)
        {
            size_t  key_length = 0;
            key_length = p - text_read;

            //  Skip over the separator
            ++p;
            //strcpy(, p);
  
            
            
            strncpy(nama_wahana, text_read, key_length);
            nama_wahana[key_length] = '\0';
            strcpy(NamaWahana[i], nama_wahana);

            strncpy(deskripsi_wahana, text_read, key_length);
            deskripsi_wahana[key_length] = '\0';
            strcpy(DeskripsiWahana[i], deskripsi_wahana);
            
            
         


            strcpy(NamaWahana[i],nama_wahana);
            strcpy(DeskripsiWahana[i],deskripsi_wahana);
            strcpy(desdes[i],des_des);
            printf("%s %s %s\n", NamaWahana[i], DeskripsiWahana[i], desdes[i]);
            i++;
        }
        else
        {
            fprintf(stdout,
                    "Invalid formatted text: \"%s\"\n",
                    text_read);
        }
    } // End:  while fgets
    fclose(my_file);

    return EXIT_SUCCESS;
}


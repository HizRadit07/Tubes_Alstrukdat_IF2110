// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// void main()
// {
//     printf("Hello World");
//     FILE *fp = fopen("data.dat", "r");
//     char *Material[5][20];
//     int *HargaMaterial[5];
//     char texts[512];
//     int linecounter = 0;
//     if(fp != NULL)
//     {
//         printf("hello lagi\n");
//         while(fgets(texts, sizeof texts, fp) != NULL)
//         {
//             if (linecounter < 5) {
//                 *Material[linecounter] = texts;
//                 printf("%s \n", texts);
//             }
//             else if (linecounter >= 5 && linecounter <10)
//             {   
//                 // printf("&d test", atoi(texts));
//                 // *HargaMaterial[linecounter-5]=atoi(texts);
//                 // printf("&d", atoi(texts));
//             }
//             linecounter++;
//             printf("%d\n", linecounter);
//         }
//         fclose(fp);
//     } else {
//         perror("user.dat");
//     } 
//     for (int i = 0; i < 5; i++ ) {
//         printf("%s: %d \n", *Material[i], *HargaMaterial[i]);
//     }
// }   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LINE_LENGTH 128


int main(void)
{
    FILE    *my_file = fopen("material.txt", "r");
    char    text_read[MAX_TEXT_LINE_LENGTH];
    char    key_text[64];
    char    value_text[64];
    int     hargaMaterial[64];
    char    Material[64][64];
     int counter = 0;
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
        key_text[0] = '\0';
        value_text[0] = '\0';
       
        if (p != 0)
        {
            size_t  key_length = 0;
            key_length = p - text_read;

            //  Skip over the separator
            ++p;
            strcpy(value_text, p);

            strncpy(key_text, text_read, key_length);
            key_text[key_length] = '\0';
            strcpy(Material[counter],key_text);
            
            hargaMaterial[counter] = atoi(value_text);
            printf("Nama Material: %s -- Harga: %d\n", Material[counter], hargaMaterial[counter]);
            counter++;
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
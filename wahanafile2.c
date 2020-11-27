
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// #define MAX_TEXT_LINE_LENGTH 128

// int main(void)
// {
//     FILE    *my_file = fopen("wahanatemp.txt", "r");
//     char    text_read[MAX_TEXT_LINE_LENGTH];
//     char    namaWahana[64];
//     char    text2[64];
//     char    text3[64];
//     char    text4[64];
//     char    text5[64];

//     char    temp_text1[64];
//     char    temp_text2[64];
//     char    temp_text3[64];
//     char    temp_text4[64];

//     int     hargaMaterial[64];
//     char    Material[64][64];
//     int     linecounter = 0;
//     if (!my_file)
//     {
//         fprintf(stderr, "Error opening data file:  data.txt");
//         return EXIT_FAILURE;
//     }
//     while (fgets(text_read, MAX_TEXT_LINE_LENGTH, my_file))
//     {
//         char  *p;
//         char  *p1;
//         char  *p2;
//         char  *p3;

//         temp_text1[0] = '\0';
//         temp_text2[0] = '\0';
//         temp_text3[0] = '\0';
//         temp_text4[0] = '\0';
       
//         //Separator ('/')
//         p = strchr(text_read, '/'); // menghasilkan str kecuali paling kiri
//         strcpy(temp_text1, ++p);
//         p1 = strchr(temp_text1, '/'); // menghasilkan str keucali 2 paling kiri
//         strcpy(temp_text2, p);
//         p2 = strchr(p1, '/'); // menghasilkan str kecuali 3 paling kiri
//         strcpy(temp_text3, p2);
//         p3 = strchr(p2+2, '/'); // menghasilkan str kecuali  4 paling kiri
//         strcpy(temp_text4, ++p3);

//         // Ngereset dri awal
//         namaWahana[0] = '\0';
//         text2[0] = '\0';
//         text3[0] = '\0';
//         text4[0] = '\0';
//         text5[0] = '\0';
//         if (p != 0)
//         {
//             size_t  key_length = 0;
//             size_t  text2_length = 0;
//             size_t  text3_length = 0;
//             size_t  text4_length = 0;

//             key_length = (--p) - text_read;
//             text2_length = p1 - temp_text1;
//             text3_length = p2 - temp_text2;
//             text4_length = p3 - temp_text3;

//             printf("text1 length: %d -- text2 length: %d -- text3 length: %d -- text4 length: %d \n", key_length, text2_length, text3_length, text4_length);
//             //  Skip over the separator

//             strcpy(text5, p3);
//             strncpy(text4, temp_text3, text4_length);
//             strncpy(text3, temp_text2, text3_length);
//             strncpy(text2, temp_text1, text2_length);
//             strncpy(namaWahana, text_read, key_length);



//             namaWahana[key_length] = '\0';
//             text2[text2_length] = '\0';
//             text3[text2_length] = '\0';
//             text4[text2_length] = '\0';
//             // memmove(text2, text2+1, strlen(text2));
//             // memmove(text3, text3+1, strlen(text3));
//             // memmove(text4, text4+1, strlen(text4));


//             printf("text1: %s -- text2: %s -- text3: %s -- text4: %s -- text5: %s\n", namaWahana, text2, text3, text4, text5);

//             strcpy(Material[linecounter],namaWahana);
//             hargaMaterial[linecounter] = atoi(text2);
            


//             linecounter++;
//         }
//         else
//         {
//             fprintf(stdout,
//                     "Invalid formatted text: \"%s\"\n",
//                     text_read);
//         }
//     } // End:  while fgets
//     fclose(my_file);

//     return EXIT_SUCCESS;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LINE_LENGTH 512


int main(void)
{
    FILE    *my_file = fopen("wahanatemp.txt", "r");
    char    text_read[MAX_TEXT_LINE_LENGTH];
    char    namaWahana[512];
    
    char    text2[512];
    char    text3[512];
    char    text4[512];
    char    text5[512];
    char    text6[512];
    char    text7[512];

    char    temp_text1[128];
    char    temp_text2[128];
    char    temp_text3[128];
    char    temp_text4[128];
    char    temp_text5[128];
    char    temp_text6[128];
      
    int     hargaMaterial[64];
    char    Material[64][64];
    int     linecounter = 0;
    if (!my_file)
    {
        fprintf(stderr, "Error opening data file:  data.txt");
        return EXIT_FAILURE;
    }
    while (fgets(text_read, MAX_TEXT_LINE_LENGTH, my_file))
    {
        char  *p;
        char  *p1;
        char  *p2;
        char  *p3;
        char  *p4;
        char  *p5;

        size_t  key_length = 0;
        size_t  text2_length = 0;
        size_t  text3_length = 0;
        size_t  text4_length = 0;
        size_t  text5_length = 0;
        size_t  text6_length = 0;
        size_t  text7_length = 0;

        temp_text1[0] = '\0';
        temp_text2[0] = '\0';
        temp_text3[0] = '\0';
        temp_text4[0] = '\0';
        temp_text5[0] = '\0';
        temp_text6[0] = '\0';

        //Separator ('/')
        p = strchr(text_read, '/'); // menghasilkan str kecuali paling kiri
        strcpy(temp_text1, p);
        memmove(temp_text1, temp_text1+1, strlen(temp_text1));
        p1 = strchr(temp_text1, '.'); // menghasilkan str keucali 2 paling kiri
        strcpy(temp_text2, p1);
        memmove(temp_text2, temp_text2+1, strlen(temp_text2));
        p2 = strchr(p1, ','); // menghasilkan str kecuali 3 paling kiri
        strcpy(temp_text3, p2);
        memmove(temp_text3, temp_text3+1, strlen(temp_text3));
        p3 = strchr(p2, ';'); // menghasilkan str kecuali  4 paling kiri
        strcpy(temp_text4, p3);
        memmove(temp_text4, temp_text4+1, strlen(temp_text4));

        p4 = strchr(p3, '/');
        strcpy(temp_text5, p4);
        memmove(temp_text5, temp_text5+1, strlen(temp_text5));

        p5= strchr(p4, ',');
        strcpy(temp_text6, p5);
        memmove(temp_text6, temp_text6+1, strlen(temp_text6));
        

        // Ngereset dri awal
        namaWahana[0] = '\0';
        text2[0] = '\0';
        text3[0] = '\0';
        text4[0] = '\0';
        text5[0] = '\0';
        text6[0] = '\0';
        text7[0] = '\0';
        if (p != 0)
        {
            key_length = p - text_read;
            text7_length = strlen(temp_text6);
            text6_length = strlen(temp_text5) - text7_length;
            text5_length = strlen(temp_text4) -  text6_length - text7_length;
            text4_length = strlen(temp_text3) - text5_length -  text6_length - text7_length;
            text3_length = strlen(temp_text2) -text5_length - text4_length -  text6_length - text7_length;
            text2_length = strlen(temp_text1) - text5_length -text4_length -text3_length -  text6_length - text7_length;
            strncpy(namaWahana, text_read, key_length);
            namaWahana[key_length] = '\0';
            temp_text6[text7_length] = '\0';
            temp_text5[text6_length-1] = '\0';
            temp_text4[text5_length-1] = '\0';
            temp_text3[text4_length-1] = '\0';
            temp_text2[text3_length-1] = '\0';
            temp_text1[text2_length-1] = '\0';
            printf("text1: %s -- text2: %s -- text3: %s -- text4: %s -- text5: %s -- text6: %s -- text6: %s\n", namaWahana, temp_text1, temp_text2, temp_text3, temp_text4, temp_text5, temp_text6);
            linecounter++;
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define LOG_ENABLED

#ifdef LOG_ENABLED
#define LOG(str) printf("%c", str)
#endif

//static void replazar0A();
//static void pasarAHexa();
//static void remove6Mult();
static void removeMult16();
static void probarValorHex();
static void ValorHex(char *hex, int *ent);

/*
 * 
 */
int main(int argc, char** argv) {
    //replazar0A();
    //pasarAHexa();
    //remove6Mult();
    removeMult16();
    probarValorHex();
    return (EXIT_SUCCESS);
}

/*
 * Escribir un programa ANSI C que procese el archivo "b.bin" sobre sí mismo. El 
 * mismo posee enteros de 16 bits sin signo con valores entre 0 y 255. El 
 * proceso consiste en reemplazar cada entero por sus correspondientes símbolos
 * hexadecimales (2 caracteres ASCII). Ej: 00000000 00001010, se reemplazará por 
 * "0A".

void replazar0A() {
    FILE *fp = fopen("test.bin", "r+");

    if (fp != NULL) {
        fseek(fp, 0L, SEEK_END);
        int fileSize = ftell(fp);
        rewind(fp);
        char *reemplazo = malloc(2 * fileSize * sizeof (unsigned char));
        unsigned char c = '\0';
        char aux = '\0';
        int counter = 0;

        while (counter < 2 * fileSize) {
            c = fgetc(fp);
            aux = ((c & 0b11110000) >> 4);

            if (aux <= 9) {
                aux += 48;
            } else {
                aux += 55;
            }

            strcpy(reemplazo, &aux);
            ++reemplazo;
            ++counter;
            aux = (c & 0b00001111);

            if (aux <= 9) {
                aux += 48;
            } else {
                aux += 55;
            }

            strcpy(reemplazo, &aux);
            ++reemplazo;
            ++counter;
        }

        rewind(fp);
        reemplazo -= counter;
        printf("%s", reemplazo);
        fprintf(fp, "%s", reemplazo);
        fclose(fp);
        free(reemplazo);
    }
}
 */

/*
Escribir un programa ANSI C que procese el archivo datos.txt sobre sí mismo. El
procesamiento consiste en convertir los números encontrados (de 1 o más cifras 
decimales) a hexadecimal.
 */
/*
void pasarAHexa() {
    printf("pasarAHexa");
    FILE *fpInput;
    FILE *fpOutput;
    char *inputFilename = "datos.txt";
    char *outputFilename = "output.txt";
    char c;
    char numberChar[2048];
    char numberHexa[2048];
    int number = 0;
    int numberPos = 0;

    fpInput = fopen(inputFilename, "r");

    if (fpInput != NULL) {
        fpOutput = fopen(outputFilename, "w+");

        while ((c = fgetc(fpInput)) != EOF) {
            LOG(c);

            if (c <= '9' && c >= '0') {
                numberChar[numberPos] = c;
                ++numberPos;
            } else if (numberPos > 0) {
                numberChar[numberPos] = '\0';
                numberPos = 0;
                number = atoi(numberChar);

                int temp = 0;
                int i = 0;
                while (number != 0) {
                    temp = number % 16;

                    if (temp < 10) {
                        numberHexa[i] = temp + 48;
                    } else {
                        numberHexa[i] = temp + 55;
                    }

                    ++i;
                    number /= 16;
                }

                for (; i > 0; --i) {
                    fprintf(fpOutput, "%c", numberHexa[i - 1]);
                }
            } else {
                fprintf(fpOutput, "%c", c);
            }
        }

        fclose(fpInput);

        if (fpInput != NULL) {
            fclose(fpOutput);
        }
    }
}
 */

/*
 * Escribir un programa ISO C que procese el archivo "nros1byte.dat" sobre si 
 * mismo, eliminando los bytes multiplos de 6.
 */
void remove6Mult() {
    FILE *fpRead = fopen("nros1byte.dat", "r");
    FILE *fpWrite = fopen("nros1byte.dat", "r+");
    char c;
    int counter = 0;

    if (fpRead != NULL && fpWrite != NULL) {
        while ((c = fgetc(fpRead)) != EOF) {
            if ((c % 6) == 0) {
                ++counter;
            } else {
                fputc(c, fpWrite);
            }
        }

        ftruncate(fileno(fpWrite), ftell(fpWrite));
        fclose(fpWrite);
        fclose(fpRead);
    }
}

/*
 * Escribir un programa ISO C que procese el archivo "valuesword.dat" sobre sí 
 * mismo, eliminando los words (2 bytes) múltplos de 16.
 */
void removeMult16() {
    FILE *fpIn = fopen("valuesword.dat", "r");
    FILE *fpOut = fopen("valuesword.dat", "r+");
    char word[3] = {0}; // cantidad de bytes que quiero leer + caracter nulo
    int number;
    
    if (fpIn != NULL) {
        while (!feof(fpIn)) {
            // cantidad de bytes que quiero leer + caracter nulo
            if (fgets(word, 3, fpIn) != NULL){
                number = word[1] | word[0] << 8;

                puts(word);
                printf("%d\n", number);

                if ((number % 16) != 0) {
                    fputs(word, fpOut);                    
                }
            }
        }
        
        ftruncate(fileno(fpOut), ftell(fpOut));
        fclose(fpOut);
        fclose(fpIn);
    }
}

/*
 * Implemente la función 
 * 
 *      void ValorHex(char *hex, int *ent) 
 * 
 * que interprete la cadena hex (de símbolos hexadecimales) y guarde el valor 
 * correspondiente en el entero indicado por ent.
 */
void ValorHex(char *hex, int *ent) {
    int digit;
    int i = 0;
    int power = 0;
    
    while(hex[i] != '\0'){
        ++i;
    }
    --i;
    
    while (i >= 0){
        if (hex[i] >= 'A' && hex[i] <= 'Z'){
            digit = hex[i] - ('A' + 10);
        } else if (hex[i] >= '0' && hex[i] <= '9'){
            digit = hex[i] - '0';
        } else {
            ent = NULL;
            puts("invalid hexa param.");
            break;
        }
        
        *ent += digit * pow(16, power);
        
        --i;
        ++power;
    }
}

void probarValorHex(){
    char *hex = "10";
    int ent;
    ValorHex(hex, &ent);
    printf("%d", ent);
}
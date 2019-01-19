#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_ENABLED

#ifdef LOG_ENABLED
#define LOG(str) printf("%c", str)
#endif

static void replazar0A();
static void pasarAHexa();

/*
 * 
 */
int main(int argc, char** argv) {
    replazar0A();
    //pasarAHexa();
    return (EXIT_SUCCESS);
}

/*
 * Escribir un programa ANSI C que procese el archivo "b.bin" sobre sí mismo. El 
 * mismo posee enteros de 16 bits sin signo con valores entre 0 y 255. El 
 * proceso consiste en reemplazar cada entero por sus correspondientes símbolos
 * hexadecimales (2 caracteres ASCII). Ej: 00000000 00001010, se reemplazará por 
 * "0A".
 */
void replazar0A() {
    FILE *fp = fopen("test.bin", "r+");

    if (fp != NULL) {
        fseek(fp, 0L, SEEK_END);
        int fileSize = ftell(fp);
        rewind(fp);
        char *reemplazo = malloc(2*fileSize*sizeof(unsigned char));
        unsigned char c = '\0';
        char aux = '\0';
        int counter = 0;
                
        while (counter < 2*fileSize) {
            c = fgetc(fp);
            aux = ((c & 0b11110000) >> 4);
            
            if (aux <= 9) {
                aux += 48;
            } else {
                aux += 55;
            }
                        
            strcpy(reemplazo, &aux);
            ++reemplazo; ++counter;
            aux = (c & 0b00001111);
            
            if (aux <= 9) {
                aux += 48;
            } else {
                aux += 55;
            }
            
            strcpy(reemplazo, &aux);
            ++reemplazo; ++counter;
        }
        
        rewind(fp);
        reemplazo-=counter;
        printf("%s", reemplazo);
        fprintf(fp, "%s", reemplazo);
        fclose(fp);
        free(reemplazo);
    }
}

/*
Escribir un programa ANSI C que procese el archivo datos.txt sobre sí mismo. El
procesamiento consiste en convertir los números encontrados (de 1 o más cifras 
decimales) a hexadecimal.
 */
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
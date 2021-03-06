#include "files_operations.h"

/*
 * Escribir un programa ANSI C que procese el archivo "b.bin" sobre sí mismo. El 
 * mismo posee enteros de 16 bits sin signo con valores entre 0 y 255. El 
 * proceso consiste en reemplazar cada entero por sus correspondientes símbolos
 * hexadecimales (2 caracteres ASCII). Ej: 00000000 00001010, se reemplazará por 
 * "0A".
 */
void replazar0A() {
    FILE *fp = fopen("files/test.bin", "r+");

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
            aux = (c & 240) >> 4; // 240 == 0b11110000

            if (aux <= 9) {
                aux += 48;
            } else {
                aux += 55;
            }

            strcpy(reemplazo, &aux);
            ++reemplazo;
            ++counter;
            aux = c & 15; // 15 == 0b00001111

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

/*
 * Escribir un programa ISO C que procese el archivo "nros1byte.dat" sobre si 
 * mismo, eliminando los bytes multiplos de 6.
 */
void remove6Mult() {
    FILE *fpRead = fopen("files/nros1byte.dat", "r");
    FILE *fpWrite = fopen("files/nros1byte.dat", "r+");
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
    FILE *fpIn = fopen("files/valuesword.dat", "r");
    FILE *fpOut = fopen("files/valuesword.dat", "r+");
    char word[3] = {0}; // cantidad de bytes que quiero leer + caracter nulo
    int number;

    if (fpIn != NULL) {
        while (!feof(fpIn)) {
            // cantidad de bytes que quiero leer + caracter nulo
            if (fgets(word, 3, fpIn) != NULL) {
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
Escribir un programa ANSI C que procese el archivo datos.txt sobre sí mismo. El
procesamiento consiste en convertir los números encontrados (de 1 o más cifras 
decimales) a hexadecimal.
 */
void pasarAHexa() {
    printf("pasarAHexa");
    FILE *fpInput;
    FILE *fpOutput;
    char *inputFilename = "files/datos.txt";
    char *outputFilename = "files/output.txt";
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

/*
 * Escribir un programa que procese un archivo binario de enteros sin signo 
 * sobre si mismo. El procesamiento consiste en leer pares de enteros de 1 byte 
 * cada uno y reemplazarlos por 3 enteros (el archivo se agranda): su suma, su 
 * resta y el OR logico entre ambos.
 */
void operacionesAritmeticas() {
    FILE *fpIn = fopen("unsignedints.dat", "r");
    FILE *fpOut = fopen("unsignedints.dat", "r+");

    if (fpIn != NULL && fpOut != NULL) {
        fseek(fpIn, 0L, SEEK_END);
        int sizeofFileInitial = ftell(fpIn);
        int sizeofFileFinal;
        char c1, c2;
        char r1, r2, r3;

        if ((sizeofFileInitial % 2) == 0) {
            sizeofFileFinal = sizeofFileInitial * 1.5;
        } else {
            sizeofFileFinal = (sizeofFileInitial - 1)*1.5 + 1;
        }

        ftruncate(fileno(fpOut), sizeofFileFinal);
        fseek(fpOut, 0L, SEEK_END);

        int pos = sizeofFileInitial;

        if ((sizeofFileInitial % 2) != 0) {
            fseek(fpIn, -1, SEEK_CUR);
            fseek(fpOut, -1, SEEK_CUR);
            c1 = fgetc(fpIn);
            fputc(c1, fpOut);
            fseek(fpIn, -1, SEEK_CUR);
            fseek(fpOut, -1, SEEK_CUR);
            --pos;
        }

        while (pos > 0) {
            fseek(fpIn, -2, SEEK_CUR);
            fseek(fpOut, -3, SEEK_CUR);
            c1 = fgetc(fpIn);
            c2 = fgetc(fpIn);
            r1 = c1 + c2;
            r2 = c1 - c2;
            r3 = c1 | c2;
            fputc(r1, fpOut);
            fputc(r2, fpOut);
            fputc(r3, fpOut);
            fseek(fpIn, -2, SEEK_CUR);
            fseek(fpOut, -3, SEEK_CUR);

            pos -= 2;
        }

        fclose(fpIn);
        fclose(fpOut);
    }
}

/*
 * Escriba una rutina que procese un archivo binario indicado por parametro 
 * sobre si mismo sumarizando los listados de numeros que posee almacenado. 
 * La sumarizacion consiste en recorrer los valores enteros de 32 bits con signo
 * grabados en formato big-endian y acumular sus valores hasta encontrar el 
 * valor 0xffffffff que se considera un separador entre listados.
 * Todos los valores enteros detectados son reemplazados por su sumatoria (en el
 * mismo formati) manteniendo luego el elemento separador. Considere archivos 
 * bien formados.
 */
void sumarizarListados(const char *fileName) {
    FILE* fpIn = fopen(fileName, "r");
    FILE* fpOut = fopen(fileName, "r+");
    int32_t number;
    int32_t sum = 0;

    if (fpIn != NULL) {
        if (fpOut != NULL) {
            while (fread((void*) &number, sizeof (int32_t), 1, fpIn) > 0) {
                number = ntohl(number);
                if (number == -1 /* == 0xffffffff */) {
                    sum = htonl(sum);
                    number = htonl(number);
                    fwrite((void*) &sum, sizeof (int32_t), 1, fpOut);
                    fwrite((void*) &number, sizeof (int32_t), 1, fpOut);
                    sum = 0;
                } else {
                    sum += number;
                }
            }

            fclose(fpIn);
            ftruncate(fileno(fpOut), ftell(fpOut));
            fclose(fpOut);
        }

        fclose(fpIn);
    }
}

void pruebasSumarizado() {
    sumarizarListados("files/listadoNumeros.dat");
}

/*
 * Escriba un programa C que reciba por argumento el nombre de un archivo de 
 * numeros binarios de 16 bits y lo procese sobre si mismo.
 * El procesamiento consiste en repetir los numeros que sean 
 * "multiplos de 5 + 1" (6, 11, 16...) (El archivo se agranda)
 */
void multiplosDe5mas1() {
    FILE *fpIn = fopen("files/multiplos5mas1.bin", "r");
    FILE *fpOut = fopen("files/multiplos5mas1.bin", "r+");
    uint16_t value;
    int cont = 0;

    if (fpIn != NULL) {

        while (fread((void*) &value, sizeof (uint16_t), 1, fpIn) > 0) {
            if ((value - 1) % 5 == 0) {
                ++cont;
            }
        }

        if (fpOut != NULL) {
            fseek(fpIn, 0L, SEEK_END);
            int initSize = ftell(fpIn);

            ftruncate(fileno(fpOut), initSize + (cont * sizeof (uint16_t)));
            fseek(fpOut, 0L, SEEK_END);
            ftell(fpOut);

            int auxCont = initSize / sizeof (uint16_t);

            do {
                fseek(fpIn, -sizeof (uint16_t), SEEK_CUR);
                fread((void*) &value, sizeof (uint16_t), 1, fpIn);
                fseek(fpIn, -sizeof (uint16_t), SEEK_CUR);

                fseek(fpOut, -sizeof (uint16_t), SEEK_CUR);
                if ((value - 1) % 5 == 0) {
                    fseek(fpOut, -sizeof (uint16_t), SEEK_CUR);
                    fwrite((void*) &value, sizeof (uint16_t), 1, fpOut);
                }
                fwrite((void*) &value, sizeof (uint16_t), 1, fpOut);
                --auxCont;
            } while (auxCont > 0);

            fclose(fpOut);
        }

        fclose(fpIn);
    }
}

/*
 * Escribir un programa ISO C que, sin crear archivos intermedios, altere el 
 * archivo "data.bin" reemplazando todas las secuencias de 3 bytes 
 * 0x34 0x43 0x44 por la secuencia de 2 bytes 0x34 0x43. Cabe destacar que el 
 * programa debe reprocesar el reemplazo efectuado. 
 * (Ejemplo: 0x34 0x43 0x44 0x44 ---> 0x34 0x43 0x44 ---> 0x34 0x43).
 */
void procesarReprocesar() {
    FILE* fpI = fopen("files/data.bin", "r");
    FILE* fpO = fopen("files/data.bin", "r+");

    char c1, c2;

    while ((c1 = fgetc(fpI)) != EOF) {
        fputc(c1, fpO);
        printf("%d\n", c1);

        if (c1 == 52) {//0x34
            c2 = fgetc(fpI);
            fputc(c2, fpO);
            
            if (c2 == 67) {//0x43
                while (fgetc(fpI) == 68);
            }
        }
    }

    fclose(fpI);

    ftruncate(fileno(fpO), ftell(fpO));
    fclose(fpO);
}

/*
 * Escribir un programa ISO C que procese el archivo palabras.txt sobre sí 
 * mismo. El proceso consiste en duplicar las palabras que tengan más de 2 
 * consonantes.
 */

char consonantes[] = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";

int contarConsonantes(char *p) {
    int i = 0;
    int c = 0;
    while (p[i] != 0 && c < 3){
        if (strchr(consonantes,p[i]) != NULL){
            ++c;
        }
        ++i;
    }
    return c;
}

void procesar2Consonantes() {
    FILE *fpI = fopen("files/palabras.txt", "r");
    FILE *fpO = fopen("files/palabras.txt", "r+");
    fseek(fpO, 0L, SEEK_END);
    
    char l;
    char p[1024] = {0};
    int i = 0;
    
    while ((l = fgetc(fpI)) != EOF){
        if (l != ' ') {
            p[i] = l;
            ++i;
        } else {
            if (contarConsonantes(p)>2){
                fputc(' ', fpO);
                fputs(&p[0], fpO);                                
            }
            memset((void*)&p[0], 0, sizeof(char)*1024);
            i = 0;
        }
    }
    
    fclose(fpI);
    fclose(fpO);
}
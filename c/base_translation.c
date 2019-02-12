#include "base_translation.h"

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

    while (hex[i] != '\0') {
        ++i;
    }
    --i;

    while (i >= 0) {
        if (hex[i] >= 'A' && hex[i] <= 'Z') {
            digit = hex[i] - ('A' + 10);
        } else if (hex[i] >= '0' && hex[i] <= '9') {
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

void probarValorHex() {
    char *hex = "10";
    int ent;
    ValorHex(hex, &ent);
    printf("%d", ent);
}

void probarStringAInt() {
    char bin[32] = "00000000000000000000000011111111";
    int ent;
    String_a_Int(bin, &ent);
    printf("%d", ent);
}

/* 
 * Implemente la funcion void String_a_Int(char *bin, int *ent) que interprete 
 * la cadena bin (de 32 1s/0s) y guarde el valor correspondiente en el entero 
 * indicado por ent.
 */
void String_a_Int(char *bin, int *ent) {
    int numero = 0;
    for (int i = 31, j = 0; i >= 0; --i, ++j) {
        if (bin[i] == '1') {
            numero |= 1 << j;
        } else if (bin[i] != '0') {
            puts("invalid number.");
            numero = 0;
            break;
        }
    }
    *ent = numero;
}

void decimalAOctal(){
    char decStr[] = "1234";
    char octStr[255] = {0};
    
    int d = atoi(decStr);
    int r = 0;
    int i = 0;
    
    while (d!=0){
        r = d % 8;
        d = d / 8;
        octStr[i] = r + 48;
        ++i;
    }
    
    puts("decimal");
    printf("%s", decStr);
    puts("\noctal");
    while (i>=0) {
        --i;
        printf("%c", octStr[i]);
    }
}



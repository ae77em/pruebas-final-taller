#include "string_manipulation.h"

/*
 * Escriba una funcion de C llamada strncat_new que reciba tres parametros: dos 
 * punteros a caracter constante (S1 y S2) y un entero sin signo (L).
 * La funcion debe concatenar S1 con S2 y retornar una nueva cadena de 
 * caracteres considerando L como tamaño maximo para cualquiera de los elementos 
 * (S1, S2 y la nueva cadena). 
 * La funcion debe detectar condiciones de erro respecto de la longitud y 
 * retornar NULL en cualquier caso.
 * */
char* strncat_new(const char* s1, const char* s2, unsigned long l) {
    int l1 = 0, l2 = 0;
    int i = 0;

    while (s1[i] != '\0') {
        ++l1;
        ++i;
    }

    if (l1 > l) {
        return NULL;
    }

    i = 0;
    while (s2[i] != '\0') {
        ++l2;
        ++i;
    }

    if (l2 > l) {
        return NULL;
    }

    if (l1 + l2 > l) {
        return NULL;
    } else {
        char *to_return = malloc(sizeof (char)*(l1 + l2));
        strncat(to_return, s1, l1);
        strncat(to_return, s2, l2);
        return to_return;
    }
}

void pruebas_cat() {
    const char* s1 = "juan \0";
    const char* s2 = "perez\0";
    char *res = strncat_new(s1, s2, 15);
    
    if (res != NULL){
        printf("%s", res);
        free(res);
    } else {
        puts("invalid length");
    }
}


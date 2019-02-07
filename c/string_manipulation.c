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

    if (res != NULL) {
        printf("%s", res);
        free(res);
    } else {
        puts("invalid length");
    }
}

/*
 * Escriba una funcion C llamada Agrandar que reciba por parametro 1 cadena (S),
 * dos indices (I1, I2) y una cantidad (Q). La funcion debe retornar una copia 
 * de S salvo los caracteres entre los indices I1 y I2 que seran duplicados Q 
 * veces en la misma posicion.
 * Ej: Agrandar("Chau", 1, 2, 3) retorna "Chahahau".
 *                                        Chahahahau
 */
char* agrandar(const char *s, int i1, int i2, int q) {
    if (i1 > i2) {
        return NULL;
    }
    int s_size = strlen(s);
    int r_size = (s_size + (i2 - i1 + 1)*(q));
    char *toReturn = malloc(sizeof (char)*r_size);

    int i = 0;
    while (i <= i2) {
        toReturn[i] = s[i];
        ++i;
    }
    int j, k = i;
    while (q - 1 > 0) {
        j = i1;
        while (j <= i2) {
            toReturn[k] = s[j];
            ++j;
            ++k;
        }
        --q;
    }

    while (i < r_size) {
        toReturn[k] = s[i];
        ++i;
        ++k;
    }
    return toReturn;
}

char* agrandar2(const char *s, int i1, int i2, int q) {
    if (i1 > i2) {
        return NULL;
    }
    int s_size = strlen(s);

    int r_size = (s_size + (i2 - i1 + 1)*(q));
    int shift1 = sizeof (char)*i1;
    int shift2 = sizeof (char)*(i2 + 1);

    char *toReturn = malloc(sizeof (char)*r_size);

    strncpy(toReturn, s, i1);
    while (q > 0) {
        strncat(toReturn, s + shift1, i2 - i1 + 1);
        --q;
    }
    strncat(toReturn, s + shift2, r_size - i2 + 1);

    return toReturn;
}

void pruebaAgrandar() {
    char* agrandado = agrandar2("Chau", 1, 2, 3);
    if (agrandado != NULL) {
        printf("%s", agrandado);
        free(agrandado);
    }
}



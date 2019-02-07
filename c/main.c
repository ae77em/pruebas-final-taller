#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <wchar.h>

#include "base_translation.h"
#include "files_operations.h"
#include "string_manipulation.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char* agrandado = agrandar2("Chau", 1, 2, 3);
    if (agrandado != NULL){
        printf("%s", agrandado);
        free(agrandado);
    }
    return (EXIT_SUCCESS);
}

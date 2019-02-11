#ifndef FILE_OPERATIONS_H
#define	FILE_OPERATIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define LOG_ENABLED
#ifdef LOG_ENABLED
#define LOG(str) printf("%c", str)
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
    
    void replazar0A();
    void remove6Mult();
    void removeMult16();
    void pasarAHexa();
    void operacionesAritmeticas();
    void sumarizarListados(const char *fileName);
    void pruebasSumarizado();
    void multiplosDe5mas1();
    void procesarReprocesar();
    void procesar2Consonantes();
 


#ifdef	__cplusplus
}
#endif

#endif	/* FILE_OPERATIONS_H */


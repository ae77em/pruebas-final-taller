/* 
 * File:   file_operations.h
 * Author: esteban
 *
 * Created on February 2, 2019, 2:09 PM
 */

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

    
    void replazar0A();
    void remove6Mult();
    void removeMult16();
    void pasarAHexa();
    void operacionesAritmeticas();


#ifdef	__cplusplus
}
#endif

#endif	/* FILE_OPERATIONS_H */


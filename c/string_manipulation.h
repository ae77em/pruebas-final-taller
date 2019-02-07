/* 
 * File:   string_manipulation.h
 * Author: esteban
 *
 * Created on February 3, 2019, 5:10 PM
 */

#ifndef STRING_MANIPULATION_H
#define	STRING_MANIPULATION_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strncat_new(const char* s1, const char* s2, unsigned long l);
void pruebas_cat();
char* agrandar(const char *s, int i1, int i2, int q);  
char* agrandar2(const char *s, int i1, int i2, int q);  

#ifdef	__cplusplus
}
#endif

#endif	/* STRING_MANIPULATION_H */


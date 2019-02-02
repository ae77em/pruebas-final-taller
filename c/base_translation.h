/* 
 * File:   base_translation.h
 * Author: esteban
 *
 * Created on February 2, 2019, 2:14 PM
 */

#ifndef BASE_TRANSLATION_H
#define	BASE_TRANSLATION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <wchar.h>

    void ValorHex(char *hex, int *ent);
    void probarValorHex();
    void probarStringAInt();
    void String_a_Int(char *bin, int *ent);


#ifdef	__cplusplus
}
#endif

#endif	/* BASE_TRANSLATION_H */


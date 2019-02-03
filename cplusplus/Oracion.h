#ifndef ORACION_H
#define	ORACION_H

/*
 * La clase Oracion utiliza un ``char *a`` para almacenar un string terminado en 
 * ``\0``. Escriba la declaracion de esta clase no olvidando: constructor por 
 * default, constructor por copia, operadores ``+``, ``-``, ``=``, ``>>`` 
 * y "<<``.
 * Implemente el operador ``=`` y el operador ``-``. Este ultimo debe eliminar 
 * de la primer cadena todas las ocurrencias de la segunda.
 */

#include <iostream>
#include <string>
#include <stdbool.h>

class Oracion {
public:
    Oracion();
    Oracion(char *a);
    Oracion(const Oracion& orig);
    virtual ~Oracion();
    
    Oracion operator +(const Oracion& otra);
    Oracion operator -(const Oracion& otra);
    Oracion operator =(const Oracion& otra);
    //std::ostream& operator <<(std::ostream& os, const Oracion& otra);
    //std::istream& operator >>(std::istream& os, const Oracion& otra);
    
    char* getA();    
        
private:
    char *a;
};

#endif	/* ORACION_H */


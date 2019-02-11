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
#include <cstring>

class Oracion {
public:
    Oracion();
    Oracion(const char* o);
    Oracion(const Oracion& orig);
    virtual ~Oracion();
    
    Oracion operator +(const Oracion& otra);
    
    Oracion operator =(const Oracion& otra){
        this->a = otra.getA();
        return *this;
    };
    
    Oracion operator-(const Oracion& otra){
        std::string auxOther(otra.getA());
        std::string auxMine(a);
        
        int otherSize = auxOther.length();
        
        for (std::string::size_type i = auxMine.find(auxOther); 
                i != std::string::npos; 
                i = auxMine.find(auxOther)){
            auxMine.erase(i, otherSize);
        }
        
        Oracion oracionNueva(auxMine.c_str());
        
        return oracionNueva;
    };
    

    
    friend std::ostream& operator <<(std::ostream& os, const Oracion& otra);
    friend std::istream& operator >>(std::istream& os, const Oracion& otra);
    
    const char* getA() const { return a; };    
        
private:
    const char *a;
};

#endif	/* ORACION_H */


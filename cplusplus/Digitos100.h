/* 
 * Constructor default
 * Constructor con valor
 * Constructor copia
 * Operador ==
 * Operador =
 * Operador int (devuelve el nro en mod 100)
 * Operador  << (implementar)
 * Operador  < 
 */

#ifndef DIGITOS100_H
#define	DIGITOS100_H

#include <iostream>
#include <array>

class Digitos100 {
public:
    Digitos100();
    //Digitos100(const std::array<int>& otro);
   // Digitos100::Digitos100(const Digitos100& orig);
    virtual ~Digitos100();
/*
    operator ==(const std::array<int>& otro);
    Digitos100& operator =(const Digitos100& otro);
    //Digitos100& int(const Digitos100& otro);
    std::ostream& operator <<(std::ostream& os, const Digitos100& digitos);
    bool operator <(const Digitos100& otro);
    
    std::array<int, 100> getDigitos();
  */  
private:    
    std::array<int, 100> digitos;
};

#endif	/* DIGITOS100_H */


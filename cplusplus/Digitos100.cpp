/* 
 * Constructor default
 * Constructor con valor
 * Constructor copia
 * Operador ==
 * Operador =
 * Operador int (devuelve el nro en mod 100)
 * Operador  <<
 * Operador  <
 */

#include "Digitos100.h"
#include <iosfwd>

Digitos100::Digitos100() {
}

//Digitos100::Digitos100(const std::array<int>& otro) : digitos(otro) {
//}

//Digitos100::Digitos100(const Digitos100& orig) {
//}

Digitos100::~Digitos100() {
}
/*
std::array<int, 100>& Digitos100::getDigitos() {
    return digitos;
}

std::ostream& operator <<(std::ostream& os, const Digitos100& digitos){
    std::array<int, 100> aux = digitos.getDigitos();
    
    for (int& digito : aux){
        os << digito;
    }
    
    return os;
}
*/
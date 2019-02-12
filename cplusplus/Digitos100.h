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
    Digitos100(const std::array<int, 100>& otro);
    Digitos100(const Digitos100& orig);
    virtual ~Digitos100();

    bool operator ==(const Digitos100& otro);
    Digitos100& operator =(const Digitos100& otro);
    operator int();
    std::ostream& operator <<(std::ostream& os) const {
        for (auto it = digitos.begin(); it != digitos.end(); ++it){
            os << *it;
        }
        
        return os;
    };
    bool operator <(const Digitos100& otro);
    
    std::array<int, 100> getDigitos() const;
  
private:    
    std::array<int, 100> digitos;
};

#endif	/* DIGITOS100_H */


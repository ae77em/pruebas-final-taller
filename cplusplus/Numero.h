/* 
 * File:   Numero.h
 * Author: esteban
 *
 * Created on February 10, 2019, 5:36 PM
 */

#ifndef NUMERO_H
#define	NUMERO_H

#include <list>
#include <iostream>

class Numero {
    /*
     * Declare la clase Número para almacenar un número de 100 cifras decimales.
     * Incluya: constructor default, constructor de copia, los operadores ``+``,
     * ``++`` (posfijo), ``++`` (prefijo), ``>``, ``=``, ``<<`` (corrimiento de 
     * bits) y ``<<``(impresión). Implemente el operador ``<<``(impresión).
     */
public:
    Numero();
    Numero(const Numero& orig);
    virtual ~Numero();

    Numero& operator+(const Numero& o);
    Numero& operator++(int);
    Numero operator++();
    bool operator>(const Numero &o);
    Numero& operator=(const Numero &o);
    Numero& operator<<(int n);

    std::ostream& operator<<(std::ostream& os) const {
        for (auto it = nro.begin(); it != nro.end(); ++it) {
            os << *it;
        }
        return os;
    }

private:
    std::list<int> nro;
};

#endif	/* NUMERO_H */


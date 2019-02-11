
#ifndef COMPLEJO_H
#define	COMPLEJO_H

/*
 * Constructor default, 
 * Constructor con valores de inicialización y 
 * Constructor de Copia; 
 * Operador ``<``, 
 *      ``==``, 
 *      ``=``, 
 *      ``int`` (que devuelva la parte real del nro. encapsulado) 
 *    y ``<<`` (impresión). Implemente el operator``<<``
 */

#include <ostream>

class Complejo {
public:
    Complejo();
    Complejo(const Complejo& orig);
    virtual ~Complejo();
    
    bool operator<(const Complejo& o) const;
    bool operator==(const Complejo& o) const;
    Complejo operator=(const Complejo& o);
    operator int() const;
    std::ostream& operator<<(std::ostream& os) const {
        return os << r << " + " << i << "i";
    };
    
private:
    int r;
    int i;

};

#endif	/* COMPLEJO_H */


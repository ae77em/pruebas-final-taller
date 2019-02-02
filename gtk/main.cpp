/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on January 25, 2019, 8:00 PM
 */

#include <cstdlib>
#include <list>
#include <iostream>

using namespace std;

template <class T>
std::list<T> SinSegunda(std::list<T> a, std::list<T> b) {
    std::list<T> result(a);

    for (auto itb = b.begin(); itb != b.end(); ++itb) {
        result.remove(*itb);
    }

    return result;
}

/*
 * Escriba una aplicación básica con interfaz gráfica. El programa debe 
 * desplegar una ventana con un botón "Cerrar" (que terminar ordenadamente la
 * aplicación). Comente/explique el programa.
 */
int main(int argc, char** argv) {
    
    return 0;
}


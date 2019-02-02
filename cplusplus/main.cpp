/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on January 25, 2019, 7:59 PM
 */

#include <iostream>
#include <cstdlib>
#include <array>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

class Box {
public:
    static int objectCount;

    Box() {
        cout << "Box created." << endl;
        objectCount++;
    }

    int getObjectsCount() {
        return objectCount;
    }
};

template <class T>
std::list<T> SinSegunda(std::list<T> a, std::list<T> b) {
    std::list<T> result(a);

    for (auto itb = b.begin(); itb != b.end(); ++itb) {
        result.remove(*itb);
    }

    return result;
}

/*
 * Implemente una función C++ denominada Interseccion que reciba dos listas de elementos y
 * devuelva una nueva lista con los elementos que se encuentran en ambas listas:
 * std::list<T> Interseccion(std::list<T> a,std::list<T> b)
 */
template <class T>
std::list<T> Interseccion(std::list<T> a,std::list<T> b){
    std::list<T> res;
    a.sort();
    b.sort();

    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(res, res.begin()));

    return res;
}

class Base {
public:

    static void f1() {
        cout << "Base.f1" << endl;
    }

    virtual void f2() {
        cout << "Base.f2" << endl;
        f1();
    }

    virtual void f3() {
        cout << "Base.f3" << endl;
        f2();
        f1();
    }
};

class Derivada : public Base {
public:

    static void f1() {
        cout << "Derivada.f1" << endl;
    }

    void f2() {
        cout << "Derivada.f2" << endl;
        f1();
    }

    void f3() {
        cout << "Derivada.f3" << endl;
        f2();
        f1();
    }
};

class A {
public:

    A() {
        cout << "A()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }
};

class B : public A {
public:

    B() {
        cout << "B()" << endl;
    }

    ~B() {
        cout << "~B()" << endl;
    }
};

void pruebaBaseDerivada() {
    Derivada D;
    Base* pB = &D;
    Derivada* pD = &D;

    pD->f1();
    pD->f2();

    pB->f1();
    pB->f2();
}

void pruebaAB() {
    B b;
}

void pruebaSinSegunda() {
    int aints[] = {1, 2, 3, 4, 5, 5, 5, 6, 8, 7, 8, 9, 41};
    int bints[] = {5, 8, 41};
    std::list<int> a(aints, aints + sizeof (aints) / sizeof (int));
    std::list<int> b(bints, bints + sizeof (bints) / sizeof (int));

    std::list<int> c = SinSegunda<int>(a, b);

    printf("lista a: ");
    for (std::list<int>::iterator ita = a.begin(); ita != a.end(); ++ita) {
        printf("%d", *ita);
    }
    printf("\nlista b: ");
    for (std::list<int>::iterator itb = b.begin(); itb != b.end(); ++itb) {
        printf("%d", *itb);
    }
    printf("\na sin b: ");
    for (std::list<int>::iterator itc = c.begin(); itc != c.end(); ++itc) {
        printf("%d", *itc);
    }
}

// Initialize static member of class Box
int Box::objectCount = 0;

void pruebaStatic() {
    cout << endl << "box1 objects count: " << Box::objectCount << endl;
    Box box1;
    cout << "box1 objects count: " << box1.getObjectsCount() << endl;
    Box box2;
    cout << "box1 objects count after box2 creation: " << box1.getObjectsCount() << endl;
}

void pruebaUnion(){
    int auxa[] = {1,2,3};
    int auxb[] = {2,3,4};
    std::list<int> a(auxa, auxa + sizeof(auxa)/sizeof(int));
    std::list<int> b(auxb, auxb + sizeof(auxb)/sizeof(int));
    std::list<int> res = Interseccion<int>(a, b);
    
    for (auto const &r : res){
        std::cout << r << std::endl;
    }
}


/*
 * 
 */
int main(int argc, char** argv) {
    pruebaBaseDerivada();
    pruebaAB();
    pruebaSinSegunda();
    pruebaStatic();
    pruebaUnion();
        
    return 0;
}

#include "Oracion.h"

Oracion::Oracion() {
}

Oracion::Oracion(char *a): a(a) {
}

Oracion::Oracion(const Oracion& orig) {
}

Oracion::~Oracion() {
}

Oracion Oracion::operator -(const Oracion& otra){
    std::string str = std::string(this->a);
    std::string otraStr = std::string(otra.a);
    bool ended = false;
    size_t pos;
    
    while(!ended){        
        pos = str.find(otraStr);
        if(pos==std::string::npos){
            ended = true;
        } else {
            str.erase(pos, otraStr.length());
        }
    }
    
    strncpy(this->a, str.c_str(), str.length());
        
    return *this;
}

Oracion Oracion::operator =(const Oracion& otra){
    std::string otraStr = std::string(otra.a);
    
    delete this->a;
    
    this->a = (char*)otraStr.c_str();
    
    return *this;
}

char* Oracion::getA(){
    return a;
}

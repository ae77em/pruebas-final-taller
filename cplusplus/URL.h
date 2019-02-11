#ifndef URL_H
#define	URL_H

#include <string>
#include <iostream>

class URL {
public:
    URL();

    URL(std::string protocol,
            std::string host,
            unsigned short port,
            std::string file) : protocol(protocol),
    host(host),
    port(port),
    file(file) {
    };
    URL(const URL& orig);
    virtual ~URL();

    /*
     * Defina la clase URL para permitir almacenar las siguientes propiedades: 
     * protocolo (http), host (fi.uba.ar), port (80), y file (index.php o 
     * resources/img/logo.png).
     * A su vez se pide que implemente los siguientes operadores: operator 
     * ``<<``, operator``==`` y operator``=``.
     * */

    std::ostream& operator<<(std::ostream &os) const {
        return os << protocol << "://" << host << ":" << port;
    };

    bool operator==(const URL& other) const {
        return this->file == other.getFile(); // && host == other.getHost() && protocol = other.getProtocol() && port = other.getPort();
    };

    URL& operator=(const URL& other) {
        if (this != &other) {
            file = other.getFile();
            host = other.getHost();
            protocol = other.getProtocol();
            port = other.getPort();
        }
        return *this;
    };

    std::string getProtocol() const {
        return this->protocol;
    };

    std::string getHost() const {
        return this->host;
    };

    unsigned short getPort() const {
        return this->port;
    };

    std::string getFile() const {
        return this->file;
    };

private:
    std::string protocol;
    std::string host;
    unsigned short port;
    std::string file;
};

#endif	/* URL_H */


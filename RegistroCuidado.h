#ifndef REGISTRO_CUIDADO_H
#define REGISTRO_CUIDADO_H

#include <iostream>
#include <string>

class RegistroCuidado {
private:
    std::string fecha;
    std::string descripcion;

public:
    RegistroCuidado(std::string fecha, std::string descripcion) : fecha(fecha), descripcion(descripcion) {}
    void mostrarRegistro() const;
};

#endif
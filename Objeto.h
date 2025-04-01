#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
#include <string>

class Objeto {
private:
    std::string nombre;
    std::string tipo;
    std::string efecto;

public:
    Objeto(std::string nombre, std::string tipo);
    void mostrarInfo() const;
    void aplicarEfecto(Mascota& mascota);
    std::string getNombre() const;
    std::string getTipo() const;
    std::string getEfecto() const;
};

#endif
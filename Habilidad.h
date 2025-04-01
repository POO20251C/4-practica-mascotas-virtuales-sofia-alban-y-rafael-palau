#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <iostream>
#include <string>
#include "Mascota.h"

class Habilidad {
private:
    std::string nombre;
    int xpRequerida;
    std::string tipo;
    std::string descripcion;

public:
    Habilidad(std::string nombre, int xpRequerida, std::string tipo, std::string descripcion);
    void mostrarHabilidad() const;
    void desbloquearHabilidad(Mascota& mascota);

    std::string getNombre() const;
    std::string getTipo() const;
    int getXpRequerida() const;
    std::string getDescripcion() const;
};

#endif
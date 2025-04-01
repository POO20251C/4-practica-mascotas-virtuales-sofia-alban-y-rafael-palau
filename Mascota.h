#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string>
#include <vector>
#include "Habilidad.h"
#include "Objeto.h"
#include "RegistroCuidado.h"

class Mascota {
private:
    std::string nombre;
    int energia;
    int experiencia;
    std::string estadoSalud;
    int edad;
    std::string estadoEmocional;
    std::vector<Habilidad> habilidades;
    std::vector<RegistroCuidado> registrosCuidado;

public:
    Mascota(std::string nombre, int energia = 100, int experiencia = 0, std::string estadoSalud = "Sano", int edad = 0, std::string estadoEmocional = "Feliz");

    void mostrarInfo() const;
    void aprenderHabilidad(const Habilidad& habilidad);
    void listarHabilidades() const;
    void usarObjeto(Objeto& objeto);
    void aumentarEnergia(int cantidad);
    void aumentarExperiencia(int cantidad);
    void cambiarEstadoSalud(std::string nuevoEstado);
    void cambiarEstadoEmocional(std::string nuevoEstado);
    void aumentarEdad();
    void registrarCuidado(const RegistroCuidado& registro);
    void mostrarHistorial() const;

    // Getters y setters
    std::string getNombre() const;
    int getEnergia() const;
    int getExperiencia() const;
    std::string getEstadoSalud() const;
    int getEdad() const;
    std::string getEstadoEmocional() const;

    void setEnergia(int nuevaEnergia);
    void setExperiencia(int nuevaExperiencia);
    void setEstadoSalud(std::string nuevoEstado);
    void setEdad(int nuevaEdad);
    void setEstadoEmocional(std::string nuevoEstado);
};

#endif
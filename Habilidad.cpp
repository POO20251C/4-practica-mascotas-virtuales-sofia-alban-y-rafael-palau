#include "Habilidad.h"

Habilidad::Habilidad(std::string nombre, int xpRequerida, std::string tipo, std::string descripcion)
    : nombre(nombre), xpRequerida(xpRequerida), tipo(tipo), descripcion(descripcion) {}

void Habilidad::mostrarHabilidad() const {
    std::cout << "Habilidad: " << nombre << " | Tipo: " << tipo
              << " | Experiencia requerida: " << xpRequerida
              << " | Descripción: " << descripcion << "\n";
}

std::string Habilidad::getNombre() const { return nombre; }
std::string Habilidad::getTipo() const { return tipo; }
int Habilidad::getXpRequerida() const { return xpRequerida; }
std::string Habilidad::getDescripcion() const { return descripcion; }

void Habilidad::desbloquearHabilidad(Mascota& mascota) {
    if (mascota.getEnergia() >= 10 && mascota.getExperiencia() >= xpRequerida &&
        mascota.getEstadoSalud() == "Sano" && mascota.getEstadoEmocional() == "Feliz") {

        std::cout << "Tu mascota " << mascota.getNombre() << " está lista para aprender " << nombre << "!\n";
        std::cout << "Estas son las opciones disponibles:\n";
        mostrarHabilidad();

        if (tipo == "Fuego" || tipo == "Tierra") {
            mascota.setEnergia(mascota.getEnergia() - 10);
        } else if (tipo == "Agua" || tipo == "Aire") {
            mascota.setEnergia(mascota.getEnergia() - 20);
        }

        mascota.setExperiencia(mascota.getExperiencia() - xpRequerida);
        mascota.setEstadoSalud("Regular");
        mascota.aprenderHabilidad(*this);
    } else {
        std::cout << "A tu mascota " << mascota.getNombre() << " todavía le falta experiencia para aprender esta habilidad.\n";
        std::cout << "Stats actuales:\n";
        std::cout << "Energía: " << mascota.getEnergia() << ", Experiencia actual: " << mascota.getExperiencia()
                  << ", Experiencia requerida: " << xpRequerida << ", Estado de salud: " << mascota.getEstadoSalud()
                  << ", Estado emocional: " << mascota.getEstadoEmocional() << "\n";
    }
}
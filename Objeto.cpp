#include "Objeto.h"
#include "Mascota.h"

Objeto::Objeto(std::string nombre, std::string tipo) : nombre(nombre), tipo(tipo) {
    if (tipo == "Juguete") {
        efecto = "Al coste de 10 de energía, arreglas por completo el estado emocional de tu mascota.";
    } else if (tipo == "Comida") {
        efecto = "Al coste de 20 de energía, arreglas por completo el estado de salud de tu mascota.";
    } else if (tipo == "Pocion de xp") {
        efecto = "Si tu mascota cumple con tener energía y estar bien de salud y emocionalmente, puedes hacer que suba 20 de xp.";
    } else {
        efecto = "Efecto desconocido";
    }
}

void Objeto::mostrarInfo() const {
    std::cout << "Objeto: " << nombre << " | Tipo: " << tipo << " | Efecto: " << efecto << "\n";
}

void Objeto::aplicarEfecto(Mascota& mascota) {
    if (tipo == "Juguete") {
        if (mascota.getEnergia() >= 10) {
            std::cout << "Usando juguete...\n";
            mascota.setEnergia(mascota.getEnergia() - 10);
            mascota.setEstadoEmocional("Feliz");
        } else {
            std::cout << "Tu mascota no tiene suficiente energía para jugar.\n";
        }
    } else if (tipo == "Comida") {
        if (mascota.getEnergia() < 100) {
            std::cout << "Usando comida...\n";
            mascota.setEnergia(mascota.getEnergia() + 20);
            mascota.setEstadoSalud("Sano");
        } else {
            std::cout << "Tu mascota ya tiene toda la energía (100).\n";
        }
    } else if (tipo == "Pocion de xp") {
        if (mascota.getEnergia() >= 20 && mascota.getEstadoSalud() == "Sano" && mascota.getEstadoEmocional() == "Feliz") {
            std::cout << "Usando poción de experiencia...\n";
            mascota.setEnergia(mascota.getEnergia() - 20);
            mascota.setExperiencia(mascota.getExperiencia() + 20);
            std::cout << "¡Tu mascota ha ganado experiencia!\n";
        } else {
            std::cout << "Tu mascota necesita estar sana, feliz y con suficiente energía para ganar experiencia.\n";
        }
    }
}

std::string Objeto::getNombre() const {
    return nombre;
}

std::string Objeto::getTipo() const {
    return tipo;
}

std::string Objeto::getEfecto() const {
    return efecto;
}
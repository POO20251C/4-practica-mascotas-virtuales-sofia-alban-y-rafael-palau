#include "Usuario.h"

Usuario::Usuario(std::string nombre) : nombre(nombre) {}

void Usuario::adoptarMascota(std::string nombreMascota) {
    mascotas[nombreMascota] = std::make_shared<Mascota>(nombreMascota);
    std::cout << nombre << " ha adoptado a " << nombreMascota << "!\n";
}

void Usuario::mostrarMascotas() const {
    std::cout << "Mascotas de " << nombre << ":\n";
    for (const auto& par : mascotas) {
        par.second->mostrarInfo();
    }
}

void Usuario::historialMascotas() {
    std::cout << "Historial de mascotas de " << nombre << ":\n";
    for (const auto& par : mascotas) {
        par.second->mostrarHistorial();
    }
}

void Usuario::usarObjeto(std::string nombreMascota, Objeto& objeto) {
    auto it = mascotas.find(nombreMascota);
    if (it != mascotas.end()) {
        it->second->usarObjeto(objeto);
    } else {
        std::cout << "Mascota no encontrada.\n";
    }
}

bool Usuario::tieneMascota(const std::string& nombreMascota) const {
    return mascotas.find(nombreMascota) != mascotas.end();
}

void Usuario::brindarObjeto(const std::string& nombreMascota, Objeto& objeto) {
    auto it = mascotas.find(nombreMascota);
    if (it != mascotas.end()) {
        objeto.aplicarEfecto(*(it->second));
    } else {
        std::cout << "Mascota no encontrada.\n";
    }
}

void Usuario::enseñarHabilidad(const std::string& nombreMascota, Habilidad& habilidad) {
    auto it = mascotas.find(nombreMascota);
    if (it != mascotas.end()) {
        habilidad.desbloquearHabilidad(*(it->second));
    } else {
        std::cout << "Mascota no encontrada.\n";
    }
}

void Usuario::aumentarExperiencia(const std::string& nombreMascota) {
    auto it = mascotas.find(nombreMascota);
    if (it != mascotas.end()) {
        it->second->setExperiencia(it->second->getExperiencia() + 20);
    } else {
        std::cout << "Mascota no encontrada.\n";
    }
}

void Usuario::consultarHistorial(const std::string& nombreMascota) {
    auto it = mascotas.find(nombreMascota);
    if (it != mascotas.end()) {
        it->second->mostrarHistorial();
    } else {
        std::cout << "Mascota no encontrada.\n";
    }
}
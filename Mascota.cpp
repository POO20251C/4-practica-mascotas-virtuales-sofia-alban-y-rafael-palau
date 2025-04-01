#include "Mascota.h"

Mascota::Mascota(std::string nombre, int energia, int experiencia, std::string estadoSalud, int edad, std::string estadoEmocional)
    : nombre(nombre), energia(energia), experiencia(experiencia), estadoSalud(estadoSalud), edad(edad), estadoEmocional(estadoEmocional) {}

void Mascota::mostrarInfo() const {
    std::cout << "Mascota: " << nombre << "\n"
              << "Energía: " << energia << "\n"
              << "Experiencia: " << experiencia << "\n"
              << "Estado de salud: " << estadoSalud << "\n"
              << "Edad: " << edad << "\n"
              << "Estado emocional: " << estadoEmocional << "\n";
}

void Mascota::aprenderHabilidad(const Habilidad& habilidad) {
    habilidades.push_back(habilidad);
    std::cout << nombre << " ha aprendido la habilidad: " << habilidad.getNombre() << "!\n";
}

void Mascota::listarHabilidades() const {
    if (habilidades.empty()) {
        std::cout << nombre << " aún no ha aprendido ninguna habilidad.\n";
    } else {
        std::cout << "Habilidades de " << nombre << ":\n";
        for (const auto& habilidad : habilidades) {
            habilidad.mostrarHabilidad();
        }
    }
}

void Mascota::usarObjeto(Objeto& objeto) {
    objeto.aplicarEfecto(*this);
}

void Mascota::aumentarEnergia(int cantidad) {
    energia += cantidad;
    if (energia > 100) energia = 100;
}

void Mascota::aumentarExperiencia(int cantidad) {
    experiencia += cantidad;
}

void Mascota::cambiarEstadoSalud(std::string nuevoEstado) {
    estadoSalud = nuevoEstado;
}

void Mascota::cambiarEstadoEmocional(std::string nuevoEstado) {
    estadoEmocional = nuevoEstado;
}

void Mascota::aumentarEdad() {
    edad++;
}

void Mascota::registrarCuidado(const RegistroCuidado& registro) {
    registrosCuidado.push_back(registro);
}

void Mascota::mostrarHistorial() const {
    std::cout << "Historial de cuidados de " << nombre << ":\n";
    for (const auto& registro : registrosCuidado) {
        registro.mostrarRegistro();
    }
}

std::string Mascota::getNombre() const { return nombre; }
int Mascota::getEnergia() const { return energia; }
int Mascota::getExperiencia() const { return experiencia; }
std::string Mascota::getEstadoSalud() const { return estadoSalud; }
int Mascota::getEdad() const { return edad; }
std::string Mascota::getEstadoEmocional() const { return estadoEmocional; }

void Mascota::setEnergia(int nuevaEnergia) { energia = nuevaEnergia; }
void Mascota::setExperiencia(int nuevaExperiencia) { experiencia = nuevaExperiencia; }
void Mascota::setEstadoSalud(std::string nuevoEstado) { estadoSalud = nuevoEstado; }
void Mascota::setEdad(int nuevaEdad) { edad = nuevaEdad; }
void Mascota::setEstadoEmocional(std::string nuevoEstado) { estadoEmocional = nuevoEstado; }
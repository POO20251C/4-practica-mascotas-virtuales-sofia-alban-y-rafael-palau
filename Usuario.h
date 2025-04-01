#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <map>
#include <memory>
#include "Mascota.h"

class Usuario {
private:
    std::string nombre;
    std::map<std::string, std::shared_ptr<Mascota>> mascotas;

public:
    Usuario(std::string nombre);

    void adoptarMascota(std::string nombreMascota);
    void mostrarMascotas() const;
    void historialMascotas();
    void usarObjeto(std::string nombreMascota, Objeto& objeto);
    bool tieneMascota(const std::string& nombreMascota) const;
    void brindarObjeto(const std::string& nombreMascota, Objeto& objeto);
    void enseñarHabilidad(const std::string& nombreMascota, Habilidad& habilidad);
    void aumentarExperiencia(const std::string& nombreMascota);
    void consultarHistorial(const std::string& nombreMascota);
};

#endif
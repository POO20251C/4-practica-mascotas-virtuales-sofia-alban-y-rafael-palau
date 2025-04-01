#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <iostream>
#include <map>
#include "Usuario.h"
#include "Mascota.h"
#include "Objeto.h"
#include "Habilidad.h"

class Plataforma {
private:
    std::map<std::string, Usuario> usuarios;
    std::map<std::string, Objeto> objetos; // Mapa para los objetos

public:
    void mostrarMenu();
    void ejecutar();
    void registrarUsuario();
    void adoptarMascota();
    void brindarObjeto();
    void enseñarHabilidad();
    void aumentarExperiencia();
    void consultarHistorial();
    void inicializarDatos(); // Función para inicializar datos
};

#endif
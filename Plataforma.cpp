#include "Plataforma.h"

void Plataforma::mostrarMenu() {
    std::cout << "\n--- Bienvenido a PixelPets ---\n";
    std::cout << "1. Registrar un nuevo usuario\n";
    std::cout << "2. Adoptar una nueva mascota\n";
    std::cout << "3. Brindar un objeto a una mascota\n";
    std::cout << "4. Enseñar una habilidad a una mascota\n";
    std::cout << "5. Aumentar experiencia de una mascota\n";
    std::cout << "6. Consultar historial de una mascota\n";
    std::cout << "7. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void Plataforma::ejecutar() {
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1: registrarUsuario(); break;
            case 2: adoptarMascota(); break;
            case 3: brindarObjeto(); break;
            case 4: enseñarHabilidad(); break;
            case 5: aumentarExperiencia(); break;
            case 6: consultarHistorial(); break;
            case 7: std::cout << "Saliendo del programa...\n"; break;
            default: std::cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (opcion != 7);
}

void Plataforma::registrarUsuario() {
    std::string nombreUsuario;
    std::cout << "Ingrese el nombre de usuario: ";
    std::getline(std::cin, nombreUsuario);
    usuarios[nombreUsuario] = Usuario(nombreUsuario);
    std::cout << "Usuario registrado con éxito!\n";
}

void Plataforma::adoptarMascota() {
    std::string nombreUsuario, nombreMascota;
    std::cout << "Ingrese el nombre de usuario: ";
    std::getline(std::cin, nombreUsuario);
    if (usuarios.find(nombreUsuario) != usuarios.end()) {
        std::cout << "Ingrese el nombre de la mascota: ";
        std::getline(std::cin, nombreMascota);
        usuarios[nombreUsuario].adoptarMascota(nombreMascota);
        std::cout << "Mascota adoptada con éxito!\n";
    } else {
        std::cout << "Usuario no encontrado!\n";
    }
}

void Plataforma::brindarObjeto() {
    std::string nombreUsuario, nombreMascota, nombreObjeto, tipo;
    std::cout << "Ingrese el nombre de usuario: ";
    std::getline(std::cin, nombreUsuario);
    if (usuarios.find(nombreUsuario) != usuarios.end()) {
        std::cout << "Ingrese el nombre de la mascota: ";
        std::getline(std::cin, nombreMascota);
        if (usuarios[nombreUsuario].tieneMascota(nombreMascota)) {
            std::cout << "Ingrese el nombre del objeto: ";
            std::getline(std::cin, nombreObjeto);
            std::cout << "Ingrese el tipo del objeto (Juguete, Comida, Pocion de xp): ";
            std::getline(std::cin, tipo);
            Objeto obj(nombreObjeto, tipo);
            usuarios[nombreUsuario].brindarObjeto(nombreMascota, obj);
            std::cout << "Objeto brindado con éxito!\n";
        } else {
            std::cout << "La mascota no existe!\n";
        }
    } else {
        std::cout << "Usuario no encontrado!\n";
    }
}

void Plataforma::enseñarHabilidad() {
    std::string nombreUsuario, nombreMascota, nombreHabilidad, tipo, descripcion;
    int xpRequerida;
    std::cout << "Ingrese el nombre de usuario: ";
    std::getline(std::cin, nombreUsuario);
    if (usuarios.find(nombreUsuario) != usuarios.end()) {
        std::cout << "Ingrese el nombre de la mascota: ";
        std::getline(std::cin, nombreMascota);
        if (usuarios[nombreUsuario].tieneMascota(nombreMascota)) {
            std::cout << "Ingrese el nombre de la habilidad: ";
            std::getline(std::cin, nombreHabilidad);
            std::cout << "Ingrese el tipo de la habilidad: ";
            std::getline(std::cin, tipo);
            std::cout << "Ingrese la experiencia requerida: ";
            std::cin >> xpRequerida;
            std::cin.ignore();
            std::cout << "Ingrese la descripción: ";
            std::getline(std::cin, descripcion);
            Habilidad hab(nombreHabilidad, xpRequerida, tipo, descripcion);
            usuarios[nombreUsuario].enseñarHabilidad(nombreMascota, hab);
            std::cout << "Habilidad enseñada con éxito!\n";
        } else {
            std::cout << "La mascota no existe!\n";
        }
    } else {
        std::cout << "Usuario no encontrado!\n";
    }
}

void Plataforma::aumentarExperiencia() {
    std::string nombreUsuario, nombreMascota;
    std::cout << "Ingrese el nombre de usuario: ";
    std::getline(std::cin, nombreUsuario);
    if (usuarios.find(nombreUsuario) != usuarios.end()) {
        std::cout << "Ingrese el nombre de la mascota: ";
        std::getline(std::cin, nombreMascota);
        if (usuarios[nombreUsuario].tieneMascota(nombreMascota)) {
            usuarios[nombreUsuario].aumentarExperiencia(nombreMascota);
            std::cout << "Experiencia aumentada!\n";
        } else {
            std::cout << "La mascota no existe!\n";
        }
    } else {
        std::cout << "Usuario no encontrado!\n";
    }
}

void Plataforma::consultarHistorial() {
    std::string nombreUsuario, nombreMascota;
    std::cout << "Ingrese el nombre de usuario: ";
    std::getline(std::cin, nombreUsuario);
    if (usuarios.find(nombreUsuario) != usuarios.end()) {
        std::cout << "Ingrese el nombre de la mascota: ";
        std::getline(std::cin, nombreMascota);
        if (usuarios[nombreUsuario].tieneMascota(nombreMascota)) {
            usuarios[nombreUsuario].consultarHistorial(nombreMascota);
        } else {
            std::cout << "La mascota no existe!\n";
        }
    } else {
        std::cout << "Usuario no encontrado!\n";
    }
}

void Plataforma::inicializarDatos() {
    // Crear usuarios
    usuarios["Usuario1"] = Usuario("Rafael");
    usuarios["Usuario2"] = Usuario("Sofia");
    usuarios["Usuario3"] = Usuario("Sabrina");

    // Crear mascotas
    usuarios["Usuario1"].adoptarMascota("Tomy");
    usuarios["Usuario1"].adoptarMascota("Bruno");
    usuarios["Usuario2"].adoptarMascota("Apolo");
    usuarios["Usuario2"].adoptarMascota("Mandarina");
    usuarios["Usuario3"].adoptarMascota("Trompitas");

    // Crear objetos
    objetos["Snack1"] = Objeto("Pedigree", "Comida");
    objetos["Juguete1"] = Objeto("Huesito", "Juguete");
    objetos["PocionXP1"] = Objeto("PocionXP1", "Pocion de xp");
    objetos["Snack2"] = Objeto("Pollito", "Comida");
    objetos["Juguete2"] = Objeto("Cuerda", "Juguete");
    objetos["PocionXP2"] = Objeto("PocionXP2", "Pocion de xp");
    objetos["Objeto7"] = Objeto("Báculo mágico", "Otro");
    objetos["Objeto8"] = Objeto("Guanteletes", "Otro");
}

int main() {
    Plataforma plataforma;
    plataforma.inicializarDatos(); // Inicializar usuarios, mascotas y objetos
    plataforma.ejecutar(); // Iniciar el programa
    return 0;
}
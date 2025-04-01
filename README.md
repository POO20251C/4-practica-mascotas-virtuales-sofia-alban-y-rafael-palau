[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/_T9NCoa5)
# 4.-Pr-ctica-Mascotas-Virtuales

# PixelPets

Este proyecto simula la lógica principal de una tienda virtual de mascotas digitales, "PixelPets", siguiendo principios de la Programación Orientada a Objetos en C++.

## Instrucciones de Compilación

Para compilar el proyecto, necesitas tener un compilador de C++ instalado (como g++). Sigue estos pasos:

1.  **Guarda los archivos**: Asegúrate de que todos los archivos `.h` y `.cpp` estén en el mismo directorio.
2.  **Compila el código**: Abre una terminal y navega al directorio donde guardaste los archivos. Luego, ejecuta el siguiente comando:

    ```bash
    g++ Plataforma.cpp Usuario.cpp Mascota.cpp Objeto.cpp Habilidad.cpp RegistroCuidado.cpp -o PixelPets
    ```

    Esto compilará todos los archivos fuente y creará un archivo ejecutable llamado `PixelPets`.
3.  **Ejecuta el programa**: Una vez que la compilación sea exitosa, ejecuta el programa con el siguiente comando:

    ```bash
    ./PixelPets
    ```

    Esto iniciará el programa y mostrará el menú principal en la terminal.

## Breve Explicación del Diseño

El sistema está diseñado utilizando los siguientes principios de la Programación Orientada a Objetos:

* **Encapsulamiento**: Cada clase es responsable de su propia información y proporciona métodos para interactuar con sus datos.
* **Abstracción**: Las clases representan conceptos del mundo real (Usuarios, Mascotas, Objetos, Habilidades, Registros de Cuidado) y ocultan los detalles de implementación.
* **Agregación y Asociación**: Se utilizan relaciones de agregación y asociación para modelar las interacciones entre las clases. Por ejemplo, un `Usuario` tiene una agregación de `Mascota` (un usuario tiene muchas mascotas).
* **Contenedores**: Se utilizan contenedores `std::map` y `std::vector` para almacenar y gestionar colecciones de objetos. Por ejemplo, un `Usuario` utiliza un `std::map` para relacionar nombres de mascotas con objetos `Mascota`.
* **Punteros**: Se utilizan punteros para relacionar objetos entre clases y para pasar objetos a funciones que modifican sus atributos.

### Clases Principales

* `Usuario`: Representa a los usuarios de la plataforma y gestiona sus mascotas.
* `Mascota`: Representa las mascotas virtuales con atributos como nombre, energía, experiencia, etc.
* `Objeto`: Representa los objetos que se pueden usar en las mascotas.
* `Habilidad`: Representa las habilidades que las mascotas pueden aprender.
* `RegistroCuidado`: Representa los registros de cuidado de una mascota.
* `Plataforma`: La clase principal que maneja la lógica del sistema y la interacción con el usuario.

### Flujo del Programa

1.  Se inicializan los datos (usuarios, mascotas, objetos) al inicio del programa.
2.  Se muestra un menú interactivo en la terminal.
3.  El usuario selecciona una opción del menú.
4.  Se ejecuta la función correspondiente a la opción seleccionada.
5.  El programa continúa hasta que el usuario elige salir.

### Mejoras Futuras

* Manejo de errores más robusto.
* Persistencia de datos utilizando archivos o una base de datos.
* Interfaz gráfica de usuario utilizando una biblioteca como Qt o wxWidgets.
* Funcionalidades adicionales para la evolución de las mascotas y la interacción entre ellas.
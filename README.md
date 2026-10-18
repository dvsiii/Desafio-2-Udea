# Ude@Book - Core Lógico de Red Social en C++

## Descripción
Este proyecto implementa la capa lógica y de almacenamiento de una red social estructurada llamada Ude@Book. Desarrollado en **C++17** bajo el paradigma de Programación Orientada a Objetos (POO), el sistema gestiona dinámicamente perfiles, amistades, álbumes fotográficos y mensajes privados, garantizando un manejo eficiente de la memoria y persistencia de datos en archivos de texto plano.

## Funcionalidades Principales
* **Autenticación y Ponderación Visual:** Inicio de sesión con validación y visualización aleatoria de fotos de mejores amigos, utilizando un sistema de "tickets" basado en la cantidad de amigos en común.
* **Gestión de Amistades:** Algoritmos para enviar, validar y aceptar solicitudes de amistad.
* **Sugerencias Inteligentes (Top K):** Sistema de recomendación de amigos utilizando una **Matriz de Adyacencia** y filtrado por coincidencias exactas para sugerir conexiones óptimas.
* **Mensajería Estructurada:** Envío de mensajes de texto (límite de 512 caracteres) con registro de fecha de envío nativa (`<chrono>`). Permite búsqueda y lectura por rangos de fecha.
* **Carrusel Fotográfico Interactvo:** Navegación por los álbumes de los perfiles mediante un sistema circular y gestión de "Likes" a través de la **sobrecarga de operadores** (`++` y `--`).
* **Medición de Rendimiento:** Auditoría en tiempo real de las iteraciones algorítmicas y el consumo estricto de memoria RAM de las estructuras dinámicas utilizando `sizeof()`.

## Arquitectura de Clases
El proyecto se basa estrictamente en la gestión de memoria dinámica propia (`new` y `delete[]`), omitiendo contenedores de la STL para el manejo de colecciones.
1. `Interfaz`: El motor del sistema. Administra el arreglo dinámico global de usuarios, el analizador secuencial (*parser*) para la lectura de datos, la sobreescritura estructural y el flujo del menú principal interactivo.
2. `Usuarios`: Gestiona el perfil del individuo mediante arreglos dinámicos independientes para sus álbumes, mensajes, lista de amigos y solicitudes pendientes.
3. `Album`: Modela agrupaciones de fotografías, administrando su nivel de privacidad y capacidad dinámica.
4. `Fotos`: Contiene la metadata esencial (ruta del archivo, fecha de subida, contador de interacciones).
5. `Mensajes`: Estructura los textos intercambiados, registrando emisor, fecha generada y estado de lectura.

## Compilación y Ejecución
El proyecto está configurado para ser construido mediante **CMake**.
1. Abre la terminal en el directorio raíz del repositorio.
2. Genera los archivos de construcción:
   ```bash
   cmake .

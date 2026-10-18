#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <string>
#include "usuarios.h"
using namespace std;
class Interfaz
{
    Usuarios* usuarios;
    int numusuarios;
    int usuario;
    int iteraciones;
public:
    Interfaz();
    Usuarios& getusuario();
    bool iniciarsesion(string nombre, string clave);
    int getnumusuarios();
    void setnumusuarios(int Nnumusuarios);
    void enviarsolicitud(string destino);
    void aceptarsolicitud();
    void visualizarmejoresamigos();
    void enviarmensaje();
    void cargardatos();
    void actualizardatos();
    void verperfil(string perfil);
    void sugerencias(int k, string usuario);
    void medicionconsumo(int iteracionesmain);
    ~Interfaz();
};
#endif // INTERFAZ_H

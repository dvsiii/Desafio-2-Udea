#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <string>
#include "usuarios.h"
using namespace std;
class Interfaz
{
    Usuarios* usuarios;
    int numusuarios;
public:
    Interfaz();
    void iniciarsesion(string nombre, string clave);
    int getnumusuarios();
    void setnumusuarios(int Nnumusuarios);
    void enviarsolicitud(string destino, string mandante);
    void enviarmensaje(string destino, Mensajes mensaje);
    void cargardatos();
    void actualizardatos();
    void verperfil(string perfil);
    string sugerencias();
    void medicionconsumo();
    ~Interfaz();
};
#endif // INTERFAZ_H

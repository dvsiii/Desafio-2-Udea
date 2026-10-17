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
    bool iniciarsesion(string nombre, string clave);
    int getnumusuarios();
    void setnumusuarios(int Nnumusuarios);
    void enviarsolicitud(string destino, string mandante);
    void visualizarmejoresamigos();
    void enviarmensaje(string destino, string mensaje, string emisor);
    void cargardatos();
    void actualizardatos();
    void verperfil(string perfil);
    string sugerencias(int k, string usuario);
    void medicionconsumo(string usuario);
    ~Interfaz();
};
#endif // INTERFAZ_H

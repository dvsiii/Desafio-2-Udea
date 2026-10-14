#ifndef USUARIOS_H
#define USUARIOS_H
#include "album.h"
#include "mensajes.h"
#include <string>
using namespace std;
class Usuarios
{
    string nombre;
    string contrasena;
    Album* album;
    string ciudad;
    string nacimiento;
    string correo;
    string pais;
    string inscripcion;
    Mensajes* mensajes;
    string amigos;
    string solicitudamigos;
    string fotousuario;
    string sugerencias;
    int numalbum;
    int nummensajes;
public:
    Usuarios();
    string BuscarRangoFecha();
    string getnombre();
    void setnombre(string Nnombre);
    string getcontrasena();
    void setcontrasena(string Ncontrasena);
    string getciudad();
    void setciudad(string Nciudad);
    string getnacimiento();
    void setnacimiento(string Nnacimiento);
    string getcorreo();
    void setcorreo(string Ncorreo);
    string getpais();
    void setpais(string Npais);
    string getinscripcion();
    void setinscripcion(string Ninscripcion);
    string getamigos();
    void setamigos(string Namigos);
    string getsolicitud();
    void setsolicitud(string Nsolicitud);
    string getfotousuario();
    void setfotousario(string Nfotousuario);
    string getsugerencias();
    void setsugerencias(string Nsugerencia);
    int getnumalbum();
    void setnumalbum(int Nnumalbum);
    int getnummensajes();
    void setnumnensajes(int Nnummensajes);
    bool aceptarsolicitud();
    void vermensajes();
    ~Usuarios();
};

#endif // USUARIOS_H

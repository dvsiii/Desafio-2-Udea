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
    string* amigos;
    string* solicitudamigos;
    string fotousuario;
    int numalbum;
    int nummensajes;
    int numsolicitud;
    int numamigos;
    int iteraciones;
public:
    Usuarios();
    int getiteraciones();
    void setiteraciones(int Niteracion);
    void BuscarRangoFecha();
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
    int getnumamigos();
    void setnumamigos(int Nnumamigos);
    string getamigos(int numaigo);
    void estableceramigos(string Namigo);
    string getsolicitud(int solicitud);
    void establecersolicitud(string solicitud);
    int getnumsolicitud();
    void setnumsolicitud(int Nnumsolicitud);
    string getfotousuario();
    void setfotousario(string Nfotousuario);
    int getnumalbum();
    void setnumalbum(int Nnumalbum);
    int getnummensajes();
    void setnumnensajes(int Nnummensajes);
    void setsolicitud(int posicion, string solicitud);
    void vermensajes();
    Album& getalbum(int album);
    void estableceralbum(Album Nalbum);
    Mensajes getmensajes(int mensaje);
    void establevermensajes(Mensajes Nmensaje);
    void actualizaralbum(int posicion, Album album);
    ~Usuarios();
};

#endif // USUARIOS_H

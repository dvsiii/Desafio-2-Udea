#ifndef MENSAJES_H
#define MENSAJES_H
#include <string>
using namespace std;
class Mensajes
{
    string fecha;
    string contenido;
    bool leido;
    string emisor;
public:
    Mensajes();
    string getfecha();
    void setfecha(string Nfecha);
    string getcontenido();
    void setcontenido(string Ncontenido);
    bool getleido();
    void setleido(bool Nleido);
    string getemisor();
    void setemisor(string Nemisor);
    string BuscarRangoFecha();
    bool leermensaje();
};

#endif // MENSAJES_H

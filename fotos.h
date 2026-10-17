#ifndef FOTOS_H
#define FOTOS_H
#include <string>
using namespace std;
class Fotos
{
    string ruta;
    string fecha;
    int likes;
public:
    Fotos();
    string getruta();
    void setruta(string Nruta);
    string getfecha();
    void setfecha(string Nfecha);
    int getlikes();
    void setlikes(int Nlikes);
    void operator++();
    void operator--();
};

#endif // FOTOS_H

#ifndef ALBUM_H
#define ALBUM_H
#include "fotos.h"
#include <string>
using namespace std;
class Album
{
    string usuario;
    string nombre;
    int privacidad;
    Fotos;
public:
    Album();
    string getnombre();
    void setnombre(string Nnombre);
    string getusuario();
    void setusuario(string Nusuario);
    int getprivacidad();
    void setprivacidad(int Nprivacidad);
    int establecerp();
};

#endif // ALBUM_H

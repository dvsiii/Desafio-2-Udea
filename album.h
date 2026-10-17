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
    Fotos* foto;
    int numfoto;
    int iteraciones;
public:
    Album();
    int getiteraciones();
    string getnombre();
    void setnombre(string Nnombre);
    string getusuario();
    void setusuario(string Nusuario);
    int getprivacidad();
    void setprivacidad(int Nprivacidad);
    int getnumfoto();
    void setnumfoto(int Nnumfoto);
    Fotos getfotos(int nfoto);
    void establecerfotos(Fotos Nfoto);
    void actualizarfoto(int posicion, Fotos foto);
    ~Album();
};
#endif // ALBUM_H
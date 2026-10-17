#include "fotos.h"
using namespace std;
Fotos::Fotos() {
    ruta="";
    fecha="";
    likes=0;
}
string Fotos::getruta()
{
    return ruta;
}
void Fotos::setruta(string Nruta)
{
    ruta=Nruta;
}
string Fotos::getfecha()
{
    return fecha;
}
void Fotos::setfecha(string Nfecha)
{
    fecha=Nfecha;
}
int Fotos::getlikes()
{
    return likes;
}
void Fotos::setlikes(int Nlikes)
{
    likes=Nlikes;
}
void Fotos::operator++()
{
    likes++;
}
void Fotos::operator--()
{
    likes--;
}
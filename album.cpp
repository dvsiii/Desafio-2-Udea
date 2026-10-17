#include "album.h"
using namespace std;
Album::Album() {
    usuario="";
    nombre="";
    privacidad=0;
    numfoto=0;
    foto=new Fotos[100];
}
string Album::getusuario(){
    return usuario;
}
void Album::setusuario(string Nusuario){
    usuario=Nusuario;
}
string Album::getnombre(){
    return nombre;
}
void Album::setnombre(string Nnombre){
    nombre=Nnombre;
}
int Album::getprivacidad(){
    return privacidad;
}
void Album::setprivacidad(int Nprivacidad){
    privacidad=Nprivacidad;
}
int Album::getnumfoto(){
    return numfoto;
}
void Album::setnumfoto(int Nnumfoto){
    numfoto=Nnumfoto;
}
Fotos Album::getfotos(int nfoto){
    return foto[nfoto];
}
void Album::establecerfotos(Fotos Nfoto){
    foto[numfoto]=Nfoto;
    numfoto++;
}
void Album::actualizarfoto(int posicion, Fotos fotoz){
    foto[posicion]=fotoz;
}
Album::~Album(){
    delete[] foto;
    foto=NULL;
}
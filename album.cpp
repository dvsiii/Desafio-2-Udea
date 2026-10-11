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
void Album::establecerfotos(){
}
Album::~Album(){
    delete[] foto;
    foto=NULL;
}
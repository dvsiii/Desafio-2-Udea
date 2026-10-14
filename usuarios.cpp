#include "usuarios.h"
using namespace std;

Usuarios::Usuarios() {
    nombre="";
    contrasena="";
    album=new Album[100];
    ciudad="";
    nacimiento="";
    correo="";
    pais="";
    inscripcion="";
    mensajes=new Mensajes[100];
    amigos="";
    solicitudamigos="";
    fotousuario="";
    sugerencias="";
    numalbum=0;
    nummensajes=0;
}
string Usuarios::getnombre(){
    return nombre;
}
void Usuarios::setnombre(string Nnombre){
    nombre=Nnombre;
}
string Usuarios::getcontrasena(){
    return contrasena;
}
void Usuarios::setcontrasena(string Ncontrasena){
    contrasena=Ncontrasena;
}
string Usuarios::getciudad(){
    return ciudad;
}
void Usuarios::setciudad(string Nciudad){
    ciudad=Nciudad;
}
string Usuarios::getnacimiento(){
    return nacimiento;
}
void Usuarios::setnacimiento(string Nnacimiento){
    nacimiento=Nnacimiento;
}
string Usuarios::getcorreo(){
    return correo;
}
void Usuarios::setcorreo(string Ncorreo){
    correo=Ncorreo;
}
string Usuarios::getpais(){
    return pais;
}
void Usuarios::setpais(string Npais){
    pais=Npais;
}
string Usuarios::getinscripcion(){
    return inscripcion;
}
void Usuarios::setinscripcion(string Ninscripcion){
    inscripcion=Ninscripcion;
}
string Usuarios::getamigos(){
    return amigos;
}
void Usuarios::setamigos(string Namigos){
    amigos=Namigos;
}
string Usuarios::getsolicitud(){
    return solicitudamigos;
}
void Usuarios::setsolicitud(string Nsolicitud){
    solicitudamigos=Nsolicitud;
}
string Usuarios::getfotousuario(){
    return fotousuario;
}
void Usuarios::setfotousario(string Nfotousuario){
    fotousuario=Nfotousuario;
}
string Usuarios::getsugerencias(){
    return sugerencias;
}
void Usuarios::setsugerencias(string Nsugerencias){
    sugerencias=Nsugerencias;
}
int Usuarios::getnumalbum(){
    return numalbum;
}
void Usuarios::setnumalbum(int Nnumalbum){
    numalbum=Nnumalbum;
}
int Usuarios::getnummensajes(){
    return nummensajes;
}
void Usuarios::setnumnensajes(int Nnummensajes){
    nummensajes=Nnummensajes;
}
Usuarios::~Usuarios(){
    delete[]album;
    delete[]mensajes;
    album=NULL;
    mensajes=NULL;
}
string Usuarios::BuscarRangoFecha(){
}
bool Usuarios::aceptarsolicitud(){
}
void Usuarios::vermensajes(){
}
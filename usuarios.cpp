#include "usuarios.h"
#include <iostream>
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
    amigos=new string[100];
    solicitudamigos=new string[100];
    fotousuario="";
    numalbum=0;
    nummensajes=0;
    numsolicitud=0;
    numamigos=0;
    iteraciones=0;
}
int Usuarios::getiteraciones(){
    return iteraciones;
}
void Usuarios::setiteraciones(int Niteracion){
    iteraciones=Niteracion;
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
int Usuarios::getnumamigos(){
    return numamigos;
}
void Usuarios::setnumamigos(int Nnumamigos){
    numamigos=Nnumamigos;
}
string Usuarios::getamigos(int amigo){
    return amigos[amigo];
}
void Usuarios::estableceramigos(string Namigo){
    amigos[numamigos]=Namigo;
    numamigos++;
}
string Usuarios::getsolicitud(int solicitud){
    return solicitudamigos[solicitud];
}
void Usuarios::establecersolicitud(string solicitud){
    solicitudamigos[numsolicitud]=solicitud;
    numsolicitud++;
}
int Usuarios::getnumsolicitud(){
    return numsolicitud;
}
void Usuarios::setnumsolicitud(int Nnumsolicitud){
    numsolicitud=Nnumsolicitud;
}
string Usuarios::getfotousuario(){
    return fotousuario;
}
void Usuarios::setfotousario(string Nfotousuario){
    fotousuario=Nfotousuario;
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
Album Usuarios::getalbum(int nalbum){
    return album[nalbum];
}
void Usuarios::estableceralbum(Album Nalbum){
    album[numalbum]=Nalbum;
    numalbum++;
}
Mensajes Usuarios::getmensajes(int Nmensaje){
    return mensajes[Nmensaje];
}
void Usuarios::establevermensajes(Mensajes Nmensaje){
    mensajes[nummensajes]=Nmensaje;
    nummensajes++;
}
void Usuarios::BuscarRangoFecha(){
    string Finicial="";
    string Ffinal="";
    cout<<"Ingrese la fecha inicial de forma añomesdia: ";
    cin>>Finicial;
    cout<<"Ingrese la fecha final de forma añomesdia: ";
    cin>>Ffinal;
    for(int i=0;i<nummensajes;i++){
        if(mensajes[i].getfecha()>=Finicial){
            if(mensajes[i].getfecha()<=Ffinal){
                mensajes[i].leermensaje();
            }
        }
        iteraciones++;
    }
}
void Usuarios::vermensajes(){
    for(int i=0;i<nummensajes;i++){
        if(mensajes[i].getleido()==false){
            mensajes[i].leermensaje();
        }
        iteraciones++;
    }
}
void Usuarios::actualizaralbum(int posicion, Album albumns){
    album[posicion]=albumns;
}
Usuarios::~Usuarios(){
    delete[]album;
    delete[]mensajes;
    delete[]solicitudamigos;
    delete[]amigos;
    album=NULL;
    mensajes=NULL;
    solicitudamigos=NULL;
    amigos=NULL;
}
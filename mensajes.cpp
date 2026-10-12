#include "mensajes.h"
#include <iostream>
using namespace std;
Mensajes::Mensajes() {
    fecha="";
    contenido="";
    emisor="";
    leido=false;
}
string Mensajes::getfecha() {
    return fecha;
}
void Mensajes::setfecha(string Nfecha){
    fecha=Nfecha;
}
string Mensajes::getcontenido(){
    return contenido;
}
void Mensajes::setcontenido(string Ncontenido){
    contenido=Ncontenido;
}
string Mensajes::getemisor(){
    return emisor;
}
void Mensajes::setemisor(string Nemisor){
    emisor=Nemisor;
}
bool Mensajes::getleido(){
    return leido;
}
void Mensajes::setleido(bool Nleido){
    leido=Nleido;
}
void Mensajes::leermensaje(){
    cout<<"fecha: "<<fecha<<endl;
    cout<<"emisor: "<<emisor<<endl;
    cout<<contenido<<endl;
    leido=true;
}
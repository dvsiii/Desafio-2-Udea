#include "interfaz.h"
using namespace std;
#include <fstream>
#include <iostream>
Interfaz::Interfaz() {
    numusuarios=0;
    usuarios=NULL;
}
int Interfaz::getnumusuarios(){
    return numusuarios;
}
void Interfaz::setnumusuarios(int Nnumusuarios){
    numusuarios=Nnumusuarios;
}
void Interfaz::iniciarsesion(string nombre, string clave){
    for(int i=0;i<numusuarios;i++){
        if(nombre==usuarios[i].getnombre()){
            if(clave==usuarios[i].getcontrasena()){
        }
        }
    }
}
void Interfaz::enviarsolicitud(string destino, string mandante){
    for(int i=0;i<numusuarios;i++){
        if(destino==usuarios[i].getnombre()){
            usuarios[i].establecersolicitud(mandante);
        }
    }
}
void Interfaz::enviarmensaje(string destino, Mensajes mensaje){
    for(int i=0;i<numusuarios;i++){
        if(destino==usuarios[i].getnombre()){
            usuarios[i].establevermensajes(mensaje);
        }
    }
}
void Interfaz::cargardatos(){
    ifstream lectura("usuarios.txt");
    string linea;
    while(getline(lectura,linea)){

    }
}
void Interfaz::actualizardatos(){
}
void Interfaz::verperfil(string perfil){
    for(int i=0;i<numusuarios;i++){
        if(perfil==usuarios[i].getnombre()){
        }
    }
}
string Interfaz::sugerencias(){
}
void Interfaz::medicionconsumo(){
}
Interfaz::~Interfaz(){
    delete[] usuarios;
    usuarios=NULL;
}
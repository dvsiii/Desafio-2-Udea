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
    string linea="";
    int conteo=0;
    int lineapresente=0;
    while(getline(lectura,linea)){
        if(linea[0]=='*'){
            conteo++;
        }
    }
    usuarios=new Usuarios[conteo];
    lectura.close();
    lectura.open("usuarios.txt");
    while(getline(lectura,linea)){
        if(linea[0]=='*'){
            lineapresente=0;
            string guardar="";
            for(int i=1;linea[i]!=':';i++){
                guardar+=linea[i];
                conteo=i;
            }
            usuarios[numusuarios].setnombre(guardar);
            if(linea[conteo]==':'){
                string guardar="";
                for(int i=conteo+1;linea[i]!='<';i++){
                    if(linea[i]!=','){
                        guardar+=linea[i];
                    }
                    else{
                        usuarios[numusuarios].estableceramigos(guardar);
                        guardar="";
                    }
                    conteo=i;
                }
                if(linea[conteo]=='<'){
                    guardar="";
                    for(int i=conteo+1;linea[i]!='\n';i++){
                        if(linea[i]!=','){
                            guardar+=linea[i];
                        }
                        else{
                            usuarios[numusuarios].establecersolicitud(guardar);
                            guardar="";
                        }
                    }
                }
            }
            numusuarios++;
        }
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
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
        string guarda="";
        int posi=1;
        if(linea[0]=='*'){
            lineapresente=numusuarios;
            guarda="";
            posi=1;
            while(linea[posi]!=':') {
                guarda+=linea[posi];
                posi++;
            }
            usuarios[numusuarios].setnombre(guarda);
            posi++;
            guarda="";
            while(linea[posi]!='<') {
                if(linea[posi]!=','){
                    guarda+=linea[posi];
                    posi++;
                }
                else{
                    usuarios[numusuarios].estableceramigos(guarda);
                    guarda="";
                    posi++;
                }
            }
            usuarios[numusuarios].estableceramigos(guarda);
            guarda="";
            posi++;
            while(linea[posi]!='>'){
                if(linea[posi]!=','){
                    guarda+=linea[posi];
                    posi++;
                }
                else{
                    usuarios[numusuarios].establecersolicitud(guarda);
                    guarda="";
                    posi++;
                }
            }
            usuarios[numusuarios].establecersolicitud(guarda);
            guarda="";
            numusuarios++;
        }
        if(linea[0]=='{'){
            guarda="";
            posi=1;
            short unsigned int conteo=0;
            while(linea[posi]!='}'){
                if(linea[posi]!=','){
                    guarda+=linea[posi];
                    posi++;
                }
                else{
                    if(conteo==0){
                        usuarios[lineapresente].setcontrasena(guarda);
                        guarda="";
                        posi++;
                    }
                    if(conteo==1){
                        usuarios[lineapresente].setnacimiento(guarda);
                        guarda="";
                        posi++;
                    }
                    if(conteo==2){
                        usuarios[lineapresente].setcorreo(guarda);
                        guarda="";
                        posi++;
                    }
                    if(conteo==3){
                        usuarios[lineapresente].setciudad(guarda);
                        guarda="";
                        posi++;
                    }
                    if(conteo==4){
                        usuarios[lineapresente].setpais(guarda);
                        guarda="";
                        posi++;
                    }
                    conteo++;
                }
            }
            usuarios[lineapresente].setfotousario(guarda);
            guarda="";
            posi=0;
        }
        if(linea[0]=='#'){
            posi=1;
            Album albumpunte;
            Fotos fotopuente;
            do{
                while(linea[posi]!=','){
                    guarda+=linea[posi];
                    posi++;
                }
                albumpunte.setnombre(guarda);
                posi+=2;
                guarda="";
                while(linea[posi]!=']'){
                    guarda=linea[posi];
                    posi++;
                }
                albumpunte.setprivacidad(stoi(guarda));
                posi+=2;
                do{
                    while(linea[posi]!=','){
                        while(linea[posi]!='/'){
                            guarda+=linea[posi];
                            posi++;
                        }
                        fotopuente.setruta(guarda);
                        posi++;
                        guarda="";
                        while(linea[posi]!='<'){
                            guarda+=linea[posi];
                            posi++;
                        }
                        fotopuente.setfecha(guarda);
                        guarda="";
                        posi++;
                        while(linea[posi]!='>'){
                            guarda=linea[posi];
                            posi++;
                        }
                        fotopuente.setlikes(stoi(guarda));
                        guarda="";
                        posi++;
                        albumpunte.establecerfotos(fotopuente);
                    }
                }
                while(linea[posi]!='.');
                usuarios[lineapresente].estableceralbum(albumpunte);
            }
            while(linea[posi]!='#');
        }
        if(linea[0]=='E'){
            posi=3;
            guarda="";
            Mensajes puente;
            while(linea[posi]!=' '){
                guarda+=linea[posi];
                posi++;
            }
            puente.setfecha(guarda);
            posi++;
            guarda="";
            while(linea[posi]!=' '){
                guarda+=linea[posi];
                posi++;
            }
            puente.setemisor(guarda);
            guarda="";
            posi+=2;
            guarda+=linea[posi];
            if(stoi(guarda)==1){
                puente.setleido(true);
            }
            else{
                puente.setleido(false);
            }
            posi+=11;
            guarda="";
            while(linea[posi]!='.'){
                guarda+=linea[posi];
                posi++;
            }
            puente.setcontenido(guarda);
            usuarios[lineapresente].establevermensajes(puente);
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
#include "interfaz.h"
using namespace std;
#include <fstream>
#include <iostream>
#include <chrono>
#include <random>
Interfaz::Interfaz() {
    numusuarios=0;
    usuarios=NULL;
    usuario=0;
    iteraciones=0;
}
Usuarios Interfaz::getusuario(){
    return usuarios[usuario];
}
int Interfaz::getnumusuarios(){
    return numusuarios;
}
void Interfaz::setnumusuarios(int Nnumusuarios){
    numusuarios=Nnumusuarios;
}
bool Interfaz::iniciarsesion(string nombre, string clave){
    for(int i=0;i<numusuarios;i++){
        if(nombre==usuarios[i].getnombre()){
            if(clave==usuarios[i].getcontrasena()){
                usuario=i;
                return true;
            }
        }
        iteraciones++;
    }
    return false;
}
void Interfaz::enviarsolicitud(string destino){
    if(destino==usuarios[usuario].getnombre()){
        cout<<"No puede ser usted mismo"<<endl;
        return;
    }
    for(int i=0;i<numusuarios;i++){
        if(destino==usuarios[i].getnombre()){
            for(int j=0;j<usuarios[usuario].getnumamigos();j++){
                if(destino==usuarios[usuario].getamigos(j)){
                    cout<<"el usuario es su amigo"<<endl;
                    return;
                }
                iteraciones++;
            }
            for(int j=0;j<usuarios[usuario].getnumsolicitud();j++){
                if(destino==usuarios[usuario].getsolicitud(j)){
                    cout<<"Usated ya tiene una solicitud pendiente de esa persona"<<endl;
                    return;
                }
                iteraciones++;
            }
            for(int j=0;j<usuarios[i].getnumsolicitud();j++){
                if(usuarios[usuario].getnombre()==usuarios[i].getsolicitud(j)){
                    cout<<"Usted ya le mando una solicitud a esa persona"<<endl;
                    return;
                }
                iteraciones++;
            }
            usuarios[i].establecersolicitud(usuarios[usuario].getnombre());
        }
        iteraciones++;
    }
}
void Interfaz::aceptarsolicitud(){
    string solicitud="";
    for(int i=0;i<usuarios[usuario].getnumsolicitud();i++){
        cout<<usuarios[usuario].getsolicitud(i)<<endl;
        iteraciones++;
    }
    cout<<"Si quiere aceptar a alguien ingrese el nombre de quien quiere aceptar"<<endl;
    cout<<"Caso contrario ingrese salir en minuscula y sin espacios";
    cin>>solicitud;
    if(solicitud=="salir"){
        return;
    }
    for(int i=0;i<usuarios[usuario].getnumsolicitud();i++){
        if(usuarios[usuario].getsolicitud(i)==solicitud){
            usuarios[usuario].setsolicitud(i,"");
            usuarios[usuario].estableceramigos(solicitud);
            usuarios[usuario].setnumsolicitud(usuarios[usuario].getnumsolicitud()-1);
            for(int j=0;j<numusuarios;j++){
                if(usuarios[j].getnombre()==solicitud){
                    usuarios[j].estableceramigos(usuarios[usuario].getnombre());
                }
                iteraciones++;
            }
        }
        iteraciones++;
    }
}
void Interfaz::visualizarmejoresamigos(){
    string ganadores[6];
    int puntajes[6]={0,0,0,0,0,0};
    double multiplicador=0;
    random_device rd;
    mt19937 generador(rd());
    uniform_int_distribution<int> distribucion(1, 100);
    int cambio=0;
    for(int i=0;i<usuarios[usuario].getnumamigos();i++){
        for(int j=0;j<numusuarios;j++){
            int amigoscomun=0;
            if(usuarios[j].getnombre()==usuarios[usuario].getamigos(i)){
                for(int k=0;k<usuarios[j].getnumamigos();k++){
                    for(int m=0;m<usuarios[usuario].getnumamigos();m++){
                        if(usuarios[j].getamigos(k)==usuarios[usuario].getamigos(m)){
                            amigoscomun++;
                        }
                        iteraciones++;
                    }
                    iteraciones++;
                }
                if(amigoscomun<=10){
                    multiplicador=1;
                }
                else if(amigoscomun>=11&&amigoscomun<=20){
                    multiplicador=2.5;
                }
                else{
                    multiplicador=3.5;
                }
                int puntajesuerte=distribucion(generador)*multiplicador;
                for(int k=0;k<6;k++){
                    if(puntajesuerte>puntajes[k]){
                        for(int desplazar=5;desplazar>k;desplazar--){
                            puntajes[desplazar]=puntajes[desplazar-1];
                            ganadores[desplazar]=ganadores[desplazar-1];
                            iteraciones++;
                        }
                        puntajes[k]=puntajesuerte;
                        ganadores[k]=usuarios[j].getfotousuario();
                        break;
                    }
                    iteraciones++;
                }
            }
            iteraciones++;
        }
        iteraciones++;
    }
    cout<<ganadores[0]<<endl;
    cout<<ganadores[1]<<endl;
    cout<<ganadores[2]<<endl;
    cout<<"Si desea actualizar la distribucion ingrese 1, si no ingrese cualquier otro numero: ";
    cin>>cambio;
    if(cambio==1){
        cout<<ganadores[3]<<endl;
        cout<<ganadores[4]<<endl;
        cout<<ganadores[5]<<endl;
    }
}
void Interfaz::enviarmensaje(){
    string destino="";
    char mensaje[512]="";
    cout<<"Ingrese el usuario a quien el quiere mandar el mensaje: ";
    cin>>destino;
    cin.ignore();
    cout<<"Ingrese el mensaje: ";
    cin.getline(mensaje, 512);
    auto ahora=chrono::system_clock::now();
    time_t tiempo=chrono::system_clock::to_time_t(ahora);
    tm* fecha=localtime(&tiempo);
    string fechaActual=to_string(1900+fecha->tm_year)+(fecha->tm_mon+1<10?"0":"")+to_string(fecha->tm_mon+1)+(fecha->tm_mday<10?"0":"")+to_string(fecha->tm_mday);
    Mensajes mensaj;
    mensaj.setfecha(fechaActual);
    mensaj.setemisor(usuarios[usuario].getnombre());
    mensaj.setcontenido(mensaje);
    for(int i=0;i<numusuarios;i++){
        for(int j=0;j<usuarios[usuario].getnumamigos();j++){
            if(destino==usuarios[i].getnombre()&&destino==usuarios[usuario].getamigos(j)){
                usuarios[i].establevermensajes(mensaj);
                return;
            }
        }
        iteraciones++;
    }
    cout<<"No se pudo enviar el mensaje, pues no se pudo encontrar al usuario"<<endl;
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
        iteraciones++;
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
                iteraciones++;
            }
            usuarios[numusuarios].setnombre(guarda);
            posi++;
            guarda="";
            while(linea[posi]!='<') {
                if(linea[posi]!=','){
                    guarda+=linea[posi];
                }
                else{
                    usuarios[numusuarios].estableceramigos(guarda);
                    guarda="";
                }
                posi++;
                iteraciones++;
            }
            usuarios[numusuarios].estableceramigos(guarda);
            guarda="";
            posi++;
            while(linea[posi]!='>'){
                if(linea[posi]!=','){
                    guarda+=linea[posi];
                }
                else{
                    usuarios[numusuarios].establecersolicitud(guarda);
                    guarda="";
                }
                posi++;
                iteraciones++;
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
                }
                else{
                    if(conteo==0){
                        usuarios[lineapresente].setcontrasena(guarda);
                        guarda="";
                    }
                    if(conteo==1){
                        usuarios[lineapresente].setnacimiento(guarda);
                        guarda="";
                    }
                    if(conteo==2){
                        usuarios[lineapresente].setcorreo(guarda);
                        guarda="";
                    }
                    if(conteo==3){
                        usuarios[lineapresente].setciudad(guarda);
                        guarda="";
                    }
                    if(conteo==4){
                        usuarios[lineapresente].setpais(guarda);
                        guarda="";
                    }
                    conteo++;
                }
                posi++;
                iteraciones++;
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
                    iteraciones++;
                }
                albumpunte.setnombre(guarda);
                posi+=2;
                guarda="";
                while(linea[posi]!=']'){
                    guarda=linea[posi];
                    posi++;
                    iteraciones++;
                }
                albumpunte.setprivacidad(stoi(guarda));
                posi+=2;
                do{
                    while(linea[posi]!=','){
                        while(linea[posi]!=';'){
                            guarda+=linea[posi];
                            posi++;
                            iteraciones++;
                        }
                        fotopuente.setruta(guarda);
                        posi++;
                        guarda="";
                        while(linea[posi]!='<'){
                            guarda+=linea[posi];
                            posi++;
                            iteraciones++;
                        }
                        fotopuente.setfecha(guarda);
                        guarda="";
                        posi++;
                        while(linea[posi]!='>'){
                            guarda+=linea[posi];
                            posi++;
                            iteraciones++;
                        }
                        fotopuente.setlikes(stoi(guarda));
                        guarda="";
                        posi++;
                        albumpunte.establecerfotos(fotopuente);
                        iteraciones++;
                    }
                    iteraciones++;
                }
                while(linea[posi]!='.');
                usuarios[lineapresente].estableceralbum(albumpunte);
                iteraciones++;
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
                iteraciones++;
            }
            puente.setfecha(guarda);
            posi++;
            guarda="";
            while(linea[posi]!=' '){
                guarda+=linea[posi];
                posi++;
                iteraciones++;
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
                iteraciones++;
            }
            puente.setcontenido(guarda);
            usuarios[lineapresente].establevermensajes(puente);
        }
        iteraciones++;
    }
    lectura.close();
}
void Interfaz::actualizardatos(){
    ofstream escribir("usuarios.txt");
    Mensajes puente;
    Album puentealbum;
    Fotos puentefoto;
    for(int i=0;i<numusuarios;i++){
        escribir<<"*"<<usuarios[i].getnombre()<<":";
        if(usuarios[i].getnumamigos()!=0){
            for(int j=0;j<usuarios[i].getnumamigos()-1;j++){
                escribir<<usuarios[i].getamigos(j)<<",";
                iteraciones++;
            }
            escribir<<usuarios[i].getamigos(usuarios[i].getnumamigos()-1)<<"<";
        }
        else{
            escribir<<"<";
        }
        if(usuarios[i].getnumsolicitud()!=0){
            for(int j=0;j<usuarios[i].getnumsolicitud()-1;j++){
                escribir<<usuarios[i].getsolicitud(j)<<",";
                iteraciones++;
            }
            escribir<<usuarios[i].getsolicitud(usuarios[i].getnumsolicitud()-1)<<">"<<endl;
        }
        else{
            escribir<<">"<<endl;
        }
        escribir<<"{"<<usuarios[i].getcontrasena()<<","<<usuarios[i].getnacimiento()<<","<<usuarios[i].getcorreo();
        escribir<<","<<usuarios[i].getciudad()<<","<<usuarios[i].getpais()<<","<<usuarios[i].getfotousuario()<<"}"<<endl;
        if(usuarios[i].getnumalbum()!=0){
            escribir<<"#";
            for(int j=0;j<usuarios[i].getnumalbum();j++){
                puentealbum=usuarios[i].getalbum(j);
                escribir<<puentealbum.getnombre()<<","<<"["<<puentealbum.getprivacidad()<<"]:";
                for(int k=0;k<puentealbum.getnumfoto()-1;k++){
                    puentefoto=puentealbum.getfotos(k);
                    escribir<<puentefoto.getruta()<<";"<<puentefoto.getfecha()<<"<"<<puentefoto.getlikes()<<">,";
                    iteraciones++;
                }
                puentefoto=puentealbum.getfotos(puentealbum.getnumfoto()-1);
                escribir<<puentefoto.getruta()<<";"<<puentefoto.getfecha()<<"<"<<puentefoto.getlikes()<<">.#"<<endl;
                iteraciones++;
            }
        }
        if(usuarios[i].getnummensajes()!=0){
            for(int j=0;j<usuarios[i].getnummensajes();j++){
                puente=usuarios[i].getmensajes(j);
                if(puente.getleido()==true){
                    escribir<<"El "<<puente.getfecha()<<" "<<puente.getemisor()<<" 1 escribio: "<<puente.getcontenido()<<endl;
                }
                else{
                    escribir<<"El "<<puente.getfecha()<<" "<<puente.getemisor()<<" 0 escribio: "<<puente.getcontenido()<<endl;
                }
                iteraciones++;
            }
        }
        iteraciones++;
    }
}
void Interfaz::verperfil(string perfil){
    Album puente;
    Fotos fotopuente;
    string decision="";
    int posicion=0;
    bool verificacion=true;
    for(int i=0;i<numusuarios;i++){
        if(perfil==usuarios[i].getnombre()){
            cout<<usuarios[i].getnombre()<<endl;
            cout<<usuarios[i].getfotousuario()<<endl;
            for(int j=0;j<usuarios[i].getnumalbum();j++){
                puente=usuarios[i].getalbum(j);
                cout<<j<<". "<<puente.getnombre()<<endl;
                iteraciones++;
            }
            cout<<"Ingrese el numero del album que desea ver: ";
            cin>>decision;
            while(verificacion==true){
                unsigned short int album=stoi(decision);
                puente=usuarios[i].getalbum(stoi(decision));
                fotopuente=puente.getfotos(posicion);
                cout<<fotopuente.getruta()<<endl;
                cout<<fotopuente.getfecha()<<endl;
                cout<<fotopuente.getlikes()<<endl;
                cout<<"Desea"<<endl;
                cout<<"1. Salir del album"<<endl;
                cout<<"2. ir a la siguiente foto"<<endl;
                cout<<"3. Ir a la foto anterior"<<endl;
                cout<<"4. dar or quitar like?"<<endl;
                cout<<"ingrese el numero de la opcion: ";
                cin>>decision;
                switch(stoi(decision)){
                case 1: verificacion=false;
                    break;
                case 2: if(posicion!=puente.getnumfoto()-1){
                        posicion++;
                    }
                    else{
                        posicion=0;
                    }
                    break;
                case 3: if(posicion!=0){
                        posicion--;
                    }
                    else{
                        posicion=puente.getnumfoto()-1;
                    }
                    break;
                case 4: cout<<"si desea dar like ingrese el uno, de lo contrario ingrese el 0: ";
                    cin>>decision;
                    if(stoi(decision)==1){
                        ++fotopuente;
                    }
                    else{
                        --fotopuente;
                    }
                    puente.actualizarfoto(posicion, fotopuente);
                    usuarios[i].actualizaralbum(album, puente);
                default: cout<<"Ingrese un valor valido, que sea 1, 2, 3 o 4";
                }
                iteraciones++;
            }
        }
    }
}
void Interfaz::sugerencias(int k, string usuario){
    int** matriz=new int*[numusuarios];
    int posicion=0;
    string sugerencias[k];
    int puntajes[k];
    string resultado="";
    for(int i=0;i<k;i++){
        puntajes[i]=0;
        iteraciones++;
    }
    for(int i=0;i<numusuarios;i++){
        matriz[i]=new int[numusuarios];
        for(int j=0;j<numusuarios;j++){
            matriz[i][j]=0;
            iteraciones++;
        }
        iteraciones++;
    }
        for(int i=0;i<numusuarios;i++){
            if(usuarios[i].getnombre()==usuario){
                    posicion=i;
            }
            for(int j=0;j<usuarios[i].getnumamigos();j++){
                for(int m=0;m<numusuarios;m++){
                    if(usuarios[m].getnombre()==usuarios[i].getamigos(j)){
                        matriz[i][m]=1;
                    }
                    iteraciones++;
                }
                iteraciones++;
            }
            iteraciones++;
        }
        for(int c=0;c<numusuarios;c++){
            if(c!=posicion&&matriz[posicion][c]==0){
                int posible=0;
                for(int i=0;i<numusuarios;i++){
                    if(matriz[posicion][i]==1&&matriz[c][i]==1){
                        posible++;
                    }
                    iteraciones++;
                }
                for(int i=0;i<k;i++){
                    if(posible>puntajes[i]){
                        for(int desplazar=k-1;desplazar>i;desplazar--){
                            puntajes[desplazar]=puntajes[desplazar-1];
                            sugerencias[desplazar]=sugerencias[desplazar-1];
                            iteraciones++;
                        }
                        puntajes[i]=posible;
                        sugerencias[i]=usuarios[c].getnombre();
                        break;
                    }
                    iteraciones++;
                }
            }
            iteraciones++;
        }
        for(int i=0;i<numusuarios;i++){
            delete[]matriz[i];
            iteraciones++;
        }
        delete[]matriz;
        for(int i=0;i<k;i++){
            cout<<sugerencias[i]<<endl;
            iteraciones++;
        }
}
void Interfaz::medicionconsumo(int iteracionesmain){
    int iteraciontotal=0;
    iteraciontotal=iteraciones+usuarios[usuario].getiteraciones()+iteracionesmain;
    cout<<"iteraciones hechas: "<<iteraciontotal<<endl;
    iteraciones=0;
    usuarios[usuario].setiteraciones(0);
    int pesoporusuario=sizeof(Usuarios)+(100*sizeof(Album))+(10000*sizeof(Fotos))+(100*sizeof(Mensajes))+(200*sizeof(string));
    int memoriatotal=sizeof(Interfaz)+(numusuarios*pesoporusuario);
    cout<<"Memoria total consumida en el sistema: "<<memoriatotal<<" bytes."<<endl;
}
Interfaz::~Interfaz(){
    delete[] usuarios;
    usuarios=NULL;
}
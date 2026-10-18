#include <iostream>
#include "interfaz.h"
using namespace std;
int main()
{
    Interfaz local;
    string nombre="";
    Usuarios* usuario = nullptr;
    string clave="";
    string decision="";
    bool salir=false;
    int iteraciones=0;
    local.cargardatos();
    cout<<"Bienvenido a Udeabook"<<endl;
    while(salir==false){
        cout<<"Desea iniciar sesion?"<<endl;
        cout<<"y: si"<<endl;
        cout<<"n: salir"<<endl;
        cout<<"ingrese el numero de la accion: ";
        cin>>decision;
        if(decision=="y"){
            if(local.iniciarsesion(nombre,clave)==true){
                cout<<"si desea cambiar de sesion ingrese y en misnuscula sin espacios"<<endl;
                cout<<"Ingrese su decision: ";
                cin>>decision;
                if(decision=="y"){
                    nombre="";
                    clave="";
                }
            }
            while(local.iniciarsesion(nombre,clave)==false){
                cout<<"Por favor ingrese su nombre de usuario: ";
                cin>>nombre;
                cout<<"por favor ingrese su contraseña: ";
                cin>>clave;
                if(local.iniciarsesion(nombre,clave)==false){
                    cout<<"Datos invalidos, por favor intente denuevo"<<endl;
                }
            }
        }
        else if(decision=="n"){
            salir=true;
            break;
        }
        else{
            cout<<"usted ingreso un valor invalido, intente denuevo"<<endl;
        }
        local.visualizarmejoresamigos();
        while(true){
            if(iteraciones>=2){
                local.actualizardatos();
            }
            usuario=&local.getusuario();
            local.medicionconsumo(iteraciones);
            iteraciones=0;
            cout<<"Bienvenido "<<usuario->getnombre()<<endl;
            cout<<"Que desea hacer hoy?"<<endl;
            cout<<"1.-Administrar Amistades"<<endl;
            cout<<"2.-Visitar perfil de un amigo"<<endl;
            cout<<"3.-Ver sugerencias de amistad"<<endl;
            cout<<"4.-Administrar mensajes"<<endl;
            cout<<"s.-Cerrar Sesion"<<endl;
            cout<<"Su decision: ";
            cin>>decision;
            if(decision=="1"){
                while(true){
                    cout<<"desea"<<endl;
                    cout<<"a. Enviar solicitud de amistad"<<endl;
                    cout<<"b. Aceptar las solicitudes de amistad recibidas"<<endl;
                    cout<<"Su decision: ";
                    cin>>decision;
                    if(decision=="a"){
                        cout<<"Ingrese el usuario a quien desea mandar solicitud: ";
                        cin>>decision;
                        local.enviarsolicitud(decision);
                        break;
                    }
                    else if(decision=="b"){
                        local.aceptarsolicitud();
                        break;
                    }
                    else{
                        cout<<"Ingrese un caracter valido"<<endl;
                    }
                }
            }
            else if(decision=="2"){
                cout<<"ingrese el nombre de usuario del amigo: ";
                cin>>decision;
                local.verperfil(decision);
            }
            else if(decision=="3"){
                while(true){
                    cout<<"Ingrese cuantas sugerencias desea ver, maximo 20: ";
                    cin>>decision;
                    if(stoi(decision)>20){
                        cout<<"No puede ser mas de 20"<<endl;
                    }
                    else{
                        break;
                    }
                    iteraciones++;
                }
                local.sugerencias(stoi(decision),usuario->getnombre());
                while(true){
                    cout<<"desea enviarle solicitud de amistad a alguno?"<<endl;
                    cout<<"s: si"<<endl;
                    cout<<"n: no"<<endl;
                    cout<<"Su decision: ";
                    cin>>decision;
                    if(decision=="s"){
                        cout<<"Ingrese el usuario a quien desea mandarle solicitud: ";
                        cin>>decision;
                        local.enviarsolicitud(decision);
                        break;
                    }
                    else if(decision=="n"){
                        break;
                    }
                    else{
                        cout<<"Ingrese un caracter valido"<<endl;
                    }
                }
            }
            else if(decision=="4"){
                while(true){
                    cout<<"desea"<<endl;
                    cout<<"a. Enviar mensaje"<<endl;
                    cout<<"b. Leer nuevos mensajes"<<endl;
                    cout<<"c. Buscar mensajes por rango de fecha"<<endl;
                    cout<<"su decision: ";
                    cin>>decision;
                    if(decision=="a"){
                        local.enviarmensaje( );
                        break;
                    }
                    else if(decision=="b"){
                        usuario->vermensajes();
                        break;
                    }
                    else if(decision=="c"){
                        usuario->BuscarRangoFecha();
                        break;
                    }
                    else{
                        cout<<"Ingrese un caracter valido, por favor intente denuevo"<<endl;
                    }
                }
            }
            else if(decision=="s"){
                break;
            }
            else{
                cout<<"Ingrese un caracter valido, por favor intente denuevo"<<endl;
            }
            iteraciones++;
        }
        iteraciones++;
    }
    local.actualizardatos();
    return 0;
}
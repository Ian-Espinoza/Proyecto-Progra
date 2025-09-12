
#include "instructores.h"
#include <sstream>
instructor::instructor(string cedula, string nombre, string telefono, string correo, string fechaNaci) {
    this->cedula = cedula;
    this->nombre = nombre;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNaci = fechaNaci;
    max = 10;
    can = 0;
    esp = new especialidades*[max];
}
void instructor::agregarEspecialidad(especialidades* e) {
    if (can < max) { 
        esp[can++] = e;
    }
}
bool instructor::tieneEspecialidad(especialidades* e) {
    for (int i = 0; i < can; ++i) {
        if (esp[i] == e) {
            return true;
        }
    }
    return false;
}
string instructor::getCedula() {return cedula;}
string instructor::getNombre() {return nombre;}
string instructor::getTelefono() {return telefono;}
string instructor::getCorreo() { return correo;}
string instructor::getFechaNaci() { return fechaNaci;}
especialidades** instructor::getEspecialidades() {return esp;}

string instructor::tostring() {
    stringstream s;
    s << "**********************************************"<<endl;
    s << "Nombre: "<<nombre<<endl;
    s << "Cedula: "<<cedula<<endl;
    s << "Telefono: "<<telefono<<endl;
    s << "Correo: "<<correo<<endl;
    s << "Fecha de nacimiento: "<<fechaNaci<<endl;
    for(int i=0; i < can;++i){
        if(tieneEspecialidad(esp[i])==true){
         s << "Especialidad: "<< esp[i]->getespe()<<endl;
        }
        else{
         s << "Especialidad: no cuenta con una especialidad"<<endl;
        }
    }
    return s.str();
}
instructor::~instructor() {
    for(int i=0; i < can;++i){
        delete esp[i];
    }
    delete[] esp;
}


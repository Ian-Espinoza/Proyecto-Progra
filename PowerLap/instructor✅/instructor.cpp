#include "instructor.h"

instructor::instructor(string cedula, string nombre, string telefono, string correo, string fechaNaci) {
    this->cedula = cedula;
    this->nombre = nombre;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNaci = fechaNaci;
    can = 0;
    especialidades = new string *[2];
    for (int i = 0; i < 2; ++i) {
        especialidades[i] = nullptr;
    }
}

string instructor::getCedula(){return cedula;}
string instructor::getNombre(){return nombre;}
string instructor::getTelefono(){return telefono;}
string instructor::getCorreo(){return correo;}
string instructor::getFechaNaci(){return fechaNaci;}

void instructor::agregarEspecialidad(string* e) {
    if (can < 2) {
        especialidades[can] = e;
        can++;
    } else {
        cout << "No se pueden agregar más especialidades. Límite alcanzado." << endl;
    }
}
bool instructor::tieneEspecialidad(string* e) {
    for (int i = 0; i < can; ++i) {
        if (*especialidades[i] == *e) {
            return true;
        }
    }
    return false;
}
string instructor::mostrarInstructor() {
    stringstream s;
    s << "--------------------------------------------------------------------"<<endl;
    s << "Nombre: "<<nombre<<endl;
    s << "Cedula: "<<cedula<<endl;
    s << "Telefono: "<<telefono<<endl;
    s << "Correo: "<<correo<<endl;
    s << "Fecha de nacimiento: "<<fechaNaci<<endl;
    s << "Especialidades: "<<endl;
    if(can == 0){
        s << "No tiene especialidades asignadas"<<endl;
    } else {
        for(int i = 0; i < can; ++i){
            s << " #" <<i+1<<". " <<*especialidades[i] << endl;
        }
    }
    return s.str();
}
instructor::~instructor() {
    delete[] especialidades;
}


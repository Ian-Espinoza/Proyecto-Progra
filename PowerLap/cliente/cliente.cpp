#include "cliente.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#include "../sucursales/sucursales.h"
#include "../instructor/instructor.h"
#include "../rutinas/rutinas.h"
#include "../reporteMedicion/reporteMedicion.h"
#include "../claseGrupal/claseGrupal.h"

cliente::cliente(){
    cedula = "";
    nombre = "";
    telefono = "";
    correo = "";
    fechaNaci = "";
    sexo = ' ';
    fechaInscripcion = "";
    sucursalCliente = nullptr;
    instructorCliente = nullptr;
    rutinaActual = nullptr;
    // Ajustes de capacidad según rúbrica
    mediciones = new reporteMedicion*[10];   // máximo 10 mediciones
    clasesMatriculadas = new claseGrupal*[3]; // máximo 3 clases por cliente
    canMediciones = 0;
    canClases = 0;
}

cliente::~cliente(){
    for (int i = 0; i < canMediciones; i++){
        delete mediciones[i];
    }
    delete[] mediciones;
    delete[] clasesMatriculadas;
}

string cliente::getCedula(){ return cedula; }
string cliente::getNombre(){ return nombre; }
string cliente::getTelefono(){ return telefono; }
string cliente::getCorreo(){ return correo; }
string cliente::getFechaNaci(){ return fechaNaci; }
char cliente::getSexo(){ return sexo; }
string cliente::getFechaInscripcion(){ return fechaInscripcion; }
sucursales* cliente::getSucursalCliente(){ return sucursalCliente; }
instructor* cliente::getInstructorCliente(){ return instructorCliente; }
rutinas* cliente::getRutinaActual(){ return rutinaActual; }
reporteMedicion** cliente::getMediciones(){ return mediciones; }
claseGrupal** cliente::getClasesMatriculadas(){ return clasesMatriculadas; }
int cliente::getCanMediciones(){ return canMediciones; }
int cliente::getCantidadClases(){ return canClases; }

void cliente::setCedula(string cedula){ this->cedula = cedula; }
void cliente::setNombre(string nombre){ this->nombre = nombre; }
void cliente::setTelefono(string telefono){ this->telefono = telefono; }
void cliente::setCorreo(string correo){ this->correo = correo; }
void cliente::setFechaNaci(string fechaNaci){ this->fechaNaci = fechaNaci; }
void cliente::setSexo(char sexo){ this->sexo = sexo; }
void cliente::setFechaInscripcion(string fechaInscripcion){ this->fechaInscripcion = fechaInscripcion; }
void cliente::setSucursalCliente(sucursales* suc){ this->sucursalCliente = suc; }
void cliente::setInstructorCliente(instructor* inst){ this->instructorCliente = inst; }

void cliente::agregarMedicion(reporteMedicion* rep){
    for(int i=0;i<canMediciones;i++){
        if(mediciones[i] == rep){
            cout << "La medicion ya esta registrada." << endl;
            return;
        }
    }
    if(canMediciones < 10){
        mediciones[canMediciones++] = rep;
    } else {
        cout << "No se pueden agregar mas mediciones (max 10)." << endl;
    }
}

void cliente::asignarRutina(rutinas* rut){
    rutinaActual = rut;
}

bool cliente::matricularClase(claseGrupal* clase){
    for(int i=0;i<canClases;i++){
        if(clasesMatriculadas[i] == clase){
            cout << "Ya matriculado en esta clase." << endl;
            return false;
        }
    }
    if(canClases < 3){
        clasesMatriculadas[canClases++] = clase;
        return true;
    }
    cout << "No se pueden matricular mas clases (max 3 por cliente)." << endl;
    return false;
}

bool cliente::desmatricularClase(claseGrupal* clase){
    int pos = -1;
    for(int i=0;i<canClases;i++){
        if(clasesMatriculadas[i] == clase){
            pos = i;
            break;
        }
    }
    if(pos != -1){
        for(int i=pos;i<canClases-1;i++){
            clasesMatriculadas[i] = clasesMatriculadas[i+1];
        }
        canClases--;
        clasesMatriculadas[canClases] = nullptr;
        return true;
    }
    return false;
}

void cliente::mostrarhistorialMediciones(){
    cout << "Historial de Mediciones:" << endl;
    if(canMediciones == 0){
        cout << "No hay mediciones registradas" << endl;
    } else {
        for(int i=0;i<canMediciones;i++){
            cout << mediciones[i]->tostring() << endl;
        }
    }
}

void cliente::mostrarClasesMatriculadas(){
    cout << "Clases Matriculadas:" << endl;
    if(canClases == 0){
        cout << "No hay clases matriculadas" << endl;
    } else {
        for(int i=0;i<canClases;i++){
            cout << clasesMatriculadas[i]->mostrarClase() << endl;
        }
    }
}

reporteMedicion* cliente::ultimaMedicion(){
    if(canMediciones > 0) return mediciones[canMediciones-1];
    return nullptr;
}

string cliente::mostrarCliente(){
    stringstream s;
    s << "------------------------- Datos del Cliente -------------------------" << endl;
    s << "Cedula: " << cedula << endl;
    s << "Nombre: " << nombre << endl;
    s << "Telefono: " << telefono << endl;
    s << "Correo: " << correo << endl;
    s << "Fecha de Nacimiento: " << fechaNaci << endl;
    s << "Sexo: " << sexo << endl;
    s << "Fecha de Inscripcion: " << fechaInscripcion << endl;
    if(instructorCliente != nullptr){
        s << "Instructor Asignado: " << instructorCliente->getNombre() << endl;
    } else {
        s << "Instructor Asignado: No tiene instructor asignado" << endl;
    }
    if(sucursalCliente != nullptr){
        s << "Sucursal Asignada: " << sucursalCliente->getNombre() << endl;
    } else {
        s << "Sucursal Asignada: No tiene sucursal asignada" << endl;
    }
    s << "----------------------------------------------------------------------" << endl;
    return s.str();
}
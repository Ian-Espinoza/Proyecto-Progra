#include "especialidades.h"
especialidad::especialidad(){nombre = new string[tam];} 

void especialidad::agregar(string nom) {
    if (can < 2) {nombre[can++] = nom;}
    else {cout << "No se pueden agregar mas especialidades" << endl;}}

string especialidad::getEspecialidad(int i) {
        if(i<can&&i>=0){return nombre[i];}
        else{return"No tiene esa especialidad";} }
    
int especialidad::getCan(){return can;}
int especialidad::getTam(){return tam;}

void especialidad::mostrar() { cout << "Especialidades: " << endl;
    for(int i=0; i<can; i++){cout<<nombre[i]<<endl;}}
especialidad::~especialidad() { delete[] nombre; }
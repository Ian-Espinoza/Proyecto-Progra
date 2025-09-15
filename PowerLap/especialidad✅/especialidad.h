#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
#include <iostream>
#include <string>
using namespace std;
class especialidad
{
private:  
    string nombre;
public:
    especialidad(string);
    string getNombre();
    string nombreEspecialidad[8];
    void mostrarEspecialidades();
};
#endif
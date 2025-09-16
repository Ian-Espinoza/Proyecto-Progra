#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include <string>
#include <sstream>
#include "especialidad.h"
using namespace std;
class especialidad;
class instructor{
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fechaNaci;
    string** especialidades;
    int can;
public:
    instructor(string, string, string, string, string);
    void agregarEspecialidad(string *);
    bool tieneEspecialidad(string *);
    string getCedula();
    string getNombre();
    string getTelefono();
    string getCorreo();
    string getFechaNaci();
    string tostring();
    ~instructor();
};
#endif
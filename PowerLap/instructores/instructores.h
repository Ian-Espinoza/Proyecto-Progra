#ifndef INSTRUCTORES_H
#define INSTRUCTORES_H
#include <iostream>
#include <string>
using namespace std;

class especialidades;
class instructor{
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fechaNaci;
    especialidades** esp;
    int can;
    int tam;
    int max;
public:
    instructor(string, string, string, string, string);
    void agregarEspecialidad(especialidades *);
    bool tieneEspecialidad(especialidades *);
    string getCedula();
    string getNombre();
    string getTelefono();
    string getCorreo();
    string getFechaNaci();
    especialidades** getEspecialidades();
    string tostring();
};
#endif
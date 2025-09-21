#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
#include <iostream>
#include <string>
using namespace std;
class especialidad{
private:
    string* especialidades;
    int tam;
public:
    especialidad(); 

    string* getEspecialidadNombre(int);

    int getCantidadEspecialidades();
    void mostrarEspecialidades();
    string getEspecialidadPorNumero(int);
    ~especialidad();
};
#endif
#include <iostream>
using namespace std;
#ifndef ESPECIALIDADES_H
#define ESPECIALIDADES_H
class especialidad
{
private:  
    string *nombre;
    int can=0;
    int tam=2;
public:
    especialidad();
    void agregar(string);
    string getEspecialidad(int );
    int getCan();
    int getTam();
    void mostrar();
    ~especialidad();
};
#endif
#ifndef CLASEGRUPAL_H
#define CLASEGRUPAL_H

#include <iostream>
#include <string>
using namespace std;

// Forward declarations
class especialidades;
class matricula;
class cliente;

class claseGrupal {
private:
    string codigo;
    especialidades* esp;
    string salon;
    string horario;
    int cupoMax;
    int cupoDisponible;
    matricula** matriculas; 
    int can;     
    int tam;      

public:
    claseGrupal(string , especialidades* , string , string , int );
    bool matricular(cliente* );
    void listadoMatriculados();
    ~claseGrupal();
};
#endif
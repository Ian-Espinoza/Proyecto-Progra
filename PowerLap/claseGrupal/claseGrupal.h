#ifndef CLASEGRUPAL_H
#define CLASEGRUPAL_H
#include <iostream>
#include <string>
using namespace std;

class especialidades;
class matricula;
class cliente;

class claseGrupal {
private:
    string codigo;
    int cupoMax;
    string salon;
    especialidades* esp;
    string horario;
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
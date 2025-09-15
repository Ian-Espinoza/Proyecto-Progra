#ifndef CLASEGRUPAL_H
#define CLASEGRUPAL_H
#include <iostream>
#include <string>
#include "especialidades.h"
#include "cliente.h"
#include "instructor.h"
using namespace std;

class especialidades;
class cliente;
class instructor;

class claseGrupal {
private:
    string codigo;
    int cupoMax;
    string salon;
    especialidades* especialidad;
    string horario;
    instructor* instructores;
    cliente** matriculados;
    int cantidadMatriculados=0;
    public:
    claseGrupal(string , especialidades* , string , string , int , instructor* );
    ~claseGrupal();
    
    string getCodigo() { return codigo; }
    string getSalon() { return salon; }
    especialidades* getEspecialidad() { return especialidad; }
    string getHorario() { return horario; }
    int getCupoMax() { return cupoMax; }
    int getCantidadMatriculados() { return cantidadMatriculados; }
    instructor* getInstructor();
    
    void setCodigo(string codigo) { this->codigo = codigo; }
    void setSalon(string salon) { this->salon = salon; }
    void setEspecialidad(especialidades* especialidad) { this->especialidad = especialidad; }
    void setHorario(string horario) { this->horario = horario; }
    void setCupoMax(int cupoMax) { this->cupoMax = cupoMax; }
    void setCantidadMatriculados(int cantidadMatriculados) { this->cantidadMatriculados = cantidadMatriculados; }
    void setInstructor(instructor* instructor) { this->instructores = instructor; }

    bool matricular(cliente* );
    bool desmatricular(string );
    void verificarMatricula(string );
    void listadoMatriculados();
    int getCuposLibres();
    string tostring();
};
#endif
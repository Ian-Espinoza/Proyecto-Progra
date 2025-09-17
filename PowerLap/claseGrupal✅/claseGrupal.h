#ifndef CLASEGRUPAL_H
#define CLASEGRUPAL_H
#include <iostream>
#include <string>
#include <sstream>
#include "especialidad.h"
#include "cliente.h"
#include "instructor.h"
using namespace std;
class claseGrupal{
private:
    string codigo;
    string EspecialidadDeLaClase;
    int cupoMax;
    string salon;
    string horario;
    instructor* instructores;
    cliente** matriculados;
    int cantidadMatriculados=0;
public:
    claseGrupal(string, string, string, string, int, instructor*);
    ~claseGrupal();
    
    string getCodigo() { return codigo; }
    string getSalon() { return salon; }
    string getHorario() { return horario; }
    int getCupoMax() { return cupoMax; }
    int getCantidadMatriculados() { return cantidadMatriculados; }
    instructor* getInstructor();
    
    void setCodigo(string codigo) { this->codigo = codigo; }
    void setSalon(string salon) { this->salon = salon; }
    void setHorario(string horario) { this->horario = horario; }
    void setCupoMax(int cupoMax) { this->cupoMax = cupoMax; }
    void setCantidadMatriculados(int cantidadMatriculados) { this->cantidadMatriculados = cantidadMatriculados; }
    void setInstructor(instructor* instructor) { this->instructores = instructor; }

    bool matricular(cliente* );
    bool desmatricular(string );
    void verificarMatricula(string );
    void listadoMatriculados();
    int getCuposLibres();
    string mostrarClase();
};
#endif
#ifndef CLASEGRUPAL_H
#define CLASEGRUPAL_H

#include <string>
#include <sstream>
using namespace std;

class instructor;
class cliente;

class claseGrupal{
private:
    string codigo;
    string EspecialidadDeLaClase;
    int cupoMax;
    string salon;
    string horario;
    instructor* instructores;
    cliente** matriculados;
    int cantidadMatriculados;
public:
    claseGrupal(string, string, string, string, int, instructor*);
    ~claseGrupal();

    string getCodigo();
    string getSalon();
    string getHorario();
    int getCupoMax();
    int getCantidadMatriculados();
    instructor* getInstructor();

    void setCodigo(string);
    void setSalon(string);
    void setHorario(string);
    void setCupoMax(int);
    void setInstructor(instructor*);

    bool matricular(cliente*);
    bool desmatricular(string);
    void verificarMatricula(string);
    void listadoMatriculados();
    int getCuposLibres();
    string mostrarClase();
};
#endif
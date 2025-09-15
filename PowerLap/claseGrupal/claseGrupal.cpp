#include"claseGrupal.h"
// Ensure this matches the declaration in claseGrupal.h
claseGrupal::claseGrupal(string codigo, especialidades* especialidad, string salon, string horario, int cupoMax, instructor* instructor) {
    this->codigo = codigo;
    this->especialidad = especialidad;
    this->salon = salon;
    this->horario = horario;
    this->cupoMax = cupoMax;
    this->instructores = instructor;
    cantidadMatriculados = 0;
    matriculados = new cliente * [cupoMax];
}
bool claseGrupal::matricular(cliente* c) {
    if (cantidadMatriculados < cupoMax) {
        matriculados[cantidadMatriculados++] = c;
        return true;
    }
    else {
        cout << "No hay cupos disponibles en la clase grupal " << codigo << endl;
        return false;
    }
}
void claseGrupal::listadoMatriculados() {
    cout << "Listado de matriculados en la clase grupal " << codigo << ":" << endl;
    for (int i = 0; i < cantidadMatriculados; i++) {
        cout << "- " << matriculados[i]->getNombre() << " (Cédula: " << matriculados[i]->getCedula() << ")" << endl;
    }
}
int claseGrupal::getCuposLibres() {
    return cupoMax - cantidadMatriculados;
}
instructor* claseGrupal::getInstructor() {
    return instructores;
}
claseGrupal::~claseGrupal() {
    delete[] matriculados;
}


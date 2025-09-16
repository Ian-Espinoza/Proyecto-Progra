#include"claseGrupal.h"
#include"especialidad.h"
claseGrupal::claseGrupal(string codigo, string EspecialidadDeLaClase, string salon, string horario, int cupoMax, instructor* instructores) {
    this->codigo = codigo;
    this->EspecialidadDeLaClase = EspecialidadDeLaClase;
    this->salon = salon;
    this->horario = horario;
    this->cupoMax = cupoMax;
    this->instructores = instructores;
    this->matriculados = new cliente * [cupoMax];
    this->cantidadMatriculados = 0;
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
claseGrupal::~claseGrupal() {
    delete[] matriculados;
}

void claseGrupal::verificarMatricula(string cedula) {
    for (int i = 0; i < cantidadMatriculados; i++) {
        if (matriculados[i]->getCedula() == cedula) {
            cout << "El cliente con cédula " << cedula << " está matriculado en la clase grupal " << codigo << "." << endl;
            return;
        }
    }
    cout << "El cliente con cédula " << cedula << " no está matriculado en la clase grupal " << codigo << "." << endl;
}
bool claseGrupal::desmatricular(string cedula) {
    for (int i = 0; i < cantidadMatriculados; i++) {
        if (matriculados[i]->getCedula() == cedula) {
            for (int j = i; j < cantidadMatriculados - 1; j++) {
                matriculados[j] = matriculados[j + 1];
            }
            cantidadMatriculados--;
            cout << "El cliente con cédula " << cedula << " ha sido desmatriculado de la clase grupal " << codigo << "." << endl;
            return true;
        }
    }
    cout << "El cliente con cédula " << cedula << " no está matriculado en la clase grupal " << codigo << "." << endl;
    return false;
}

string claseGrupal::getCodigo() {return codigo;}
string claseGrupal::getSalon() {return salon;}
string claseGrupal::getHorario() {return horario;}
int claseGrupal::getCupoMax() {return cupoMax;}
int claseGrupal::getCantidadMatriculados() {return cantidadMatriculados;}
instructor* claseGrupal::getInstructor() {return instructores;}

void claseGrupal::setInstructor(instructor* instructor) {this->instructores = instructor;}
void claseGrupal::setCantidadMatriculados(int cantidadMatriculados) {this->cantidadMatriculados = cantidadMatriculados;}
void claseGrupal::setCupoMax(int cupoMax) {this->cupoMax = cupoMax;}
void claseGrupal::setHorario(string horario) {this->horario = horario;}
void claseGrupal::setSalon(string salon) {this->salon = salon;}
void claseGrupal::setCodigo(string codigo) {this->codigo = codigo;}

string claseGrupal::tostring() {
    stringstream s;
    s << "===== Detalles de la Clase Grupal =====" << endl;
    s << "Código: " << codigo << endl;
    s << "Especialidad: " << EspecialidadDeLaClase << endl;
    s << "Salón: " << salon << endl;
    s << "Horario: " << horario << endl;
    s << "Cupo máximo: " << cupoMax << endl;
    s << "Cantidad de matriculados: " << cantidadMatriculados << endl;
    s << "--- Informacion del intstructor ---" << endl;
    if(instructores != nullptr) {
        s << instructores->tostring() << endl;
    } else {
        s << "No hay instructor asignado" << endl;
    }
    return s.str();
}
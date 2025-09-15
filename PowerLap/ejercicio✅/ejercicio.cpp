#include "ejercicio.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

ejercicio::ejercicio() {codigo = 0;nombre = "";descripcion = "";areaCuerpo = "";}

ejercicio::ejercicio(int codigo, string nombre, string descripcion, string areaCuerpo) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->areaCuerpo = areaCuerpo;
}
ejercicio::~ejercicio() {}

int ejercicio::getCodigo() { return codigo; }
string ejercicio::getNombre() { return nombre; }
string ejercicio::getDescripcion() { return descripcion; }
string ejercicio::getAreaCuerpo() { return areaCuerpo; }

void ejercicio::setCodigo(int codigo) {this->codigo = codigo; }
void ejercicio::setNombre(string nombre) {this->nombre = nombre; }
void ejercicio::setDescripcion(string descripcion) {this->descripcion = descripcion; }
void ejercicio::setAreaCuerpo(string areaCuerpo) {this->areaCuerpo = areaCuerpo; }

string ejercicio::tostring() {
    stringstream s;
    s << "Codigo: " << codigo << endl;
    s << "Nombre: " << nombre << endl;
    s << "Descripcion: " << descripcion << endl;
    s << "Area del cuerpo: " << areaCuerpo << endl;
    return s.str();
}
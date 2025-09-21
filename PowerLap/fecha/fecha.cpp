#include "fecha.h"

fecha::fecha() { dia = 1; mes = 1; anio = 2000; }

fecha::fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int fecha::getDia() { return dia; }
int fecha::getMes() { return mes; }
int fecha::getAnio() { return anio; }
void fecha::setDia(int dia) { this->dia = dia; }
void fecha::setMes(int mes) { this->mes = mes; }
void fecha::setAnio(int anio) { this->anio = anio; }

bool fecha::esValida(){
    if(anio < 1900 || anio > 2100) return false;
    if(mes < 1 || mes > 12) return false;
    if(dia < 1) return false;
    int diasMes[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(mes == 2 && (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0))){
        diasMes[1] = 29;
    }
    return dia <= diasMes[mes - 1];
}

string fecha::tostring() {
    stringstream s;
    s << dia << "/" << mes << "/" << anio;
    return s.str();
}

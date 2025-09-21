#include "reporteMedicion.h"
#include <sstream>
using namespace std;
reporteMedicion::reporteMedicion() {
    peso = 0;
    estatura = 0;
    porcentajeGrasa = 0;
    porcentajeMusculo = 0;
    grasaViseral = 0;
    cintura = 0;
    cadera = 0;
    pecho = 0;
    muslo = 0;
    imc = 0;
}
reporteMedicion::reporteMedicion(fecha fechas, float peso, float estatura, float porcentajeGrasa, float porcentajeMusculo, float grasaViseral, int edadMetabolica, float cintura, float cadera, float pecho, float muslo, float imc) {
    this->fechas = fechas;
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = porcentajeGrasa;
    this->porcentajeMusculo = porcentajeMusculo;
    this->grasaViseral = grasaViseral;
    this->edadMetabolica = edadMetabolica;
    this->cintura = cintura;
    this->cadera = cadera;
    this->pecho = pecho;
    this->muslo = muslo;
    this->imc = imc;
}
fecha reporteMedicion::getfecha() { return fechas; }
float reporteMedicion::getPeso() { return peso; }
float reporteMedicion::getEstatura() { return estatura; }
float reporteMedicion::getPorcentajeGrasa() { return porcentajeGrasa; }
float reporteMedicion::getPorcentajeMusculo() { return porcentajeMusculo; }
float reporteMedicion::getGrasaViseral() { return grasaViseral; }
int reporteMedicion::getEdadMetabolica() { return edadMetabolica; }
float reporteMedicion::getCintura() { return cintura; }
float reporteMedicion::getCadera() { return cadera; }
float reporteMedicion::getPecho() { return pecho; }
float reporteMedicion::getMuslo() { return muslo; }
float reporteMedicion::getIMC() { return imc; }

void reporteMedicion::setFecha(fecha fechas) { this->fechas = fechas; }
void reporteMedicion::setPeso(float peso) { this->peso = peso; }
void reporteMedicion::setEstatura(float estatura) { this->estatura = estatura; }
void reporteMedicion::setPorcentajeGrasa(float porcentajeGrasa) { this->porcentajeGrasa = porcentajeGrasa; }
void reporteMedicion::setPorcentajeMusculo(float porcentajeMusculo) { this->porcentajeMusculo = porcentajeMusculo; }
void reporteMedicion::setGrasaViseral(float grasaViseral) { this->grasaViseral = grasaViseral; }
void reporteMedicion::setEdadMetabolica(int edadMetabolica) { this->edadMetabolica = edadMetabolica; }
void reporteMedicion::setCintura(float cintura) { this->cintura = cintura; }
void reporteMedicion::setCadera(float cadera) { this->cadera = cadera; }
void reporteMedicion::setPecho(float pecho) { this->pecho = pecho; }
void reporteMedicion::setMuslo(float muslo) { this->muslo = muslo; }
void reporteMedicion::setIMC(float imc) { this->imc = imc; }

float reporteMedicion::calcularIMC() {
    imc = estatura != 0 ? peso / (estatura * estatura) : 0;
    return imc;
}
int reporteMedicion::calcularVasosAgua() { return (int)(peso * 35 / 250); }
string reporteMedicion::obtenerClasificacionIMC() {
    if (imc < 16.00) return "Delgadez severa";
    else if (imc >= 16.01 && imc < 16.99) return "delgadez moderada";
    else if (imc >= 17 && imc < 18.49) return "delgadez leve";
    else if (imc >= 18.5 && imc < 24.99) return "normal";
    else if (imc >= 25 && imc < 29.99) return "pre-sobrepeso";
    else if (imc >= 30 && imc < 34.99) return "obesidad leve";
    else if (imc >= 35 && imc < 39.99) return "obesidad media";
    else if (imc >= 40) return "obesidad morbida";
    return "";
}
float reporteMedicion::calcularProteinaRequerida(char sexo, bool haceEjercicio) {
    if (!haceEjercicio) return peso * 0.8f;
    if (sexo == 'M' || sexo == 'm') return peso * 2.0f;
    if (sexo == 'F' || sexo == 'f') return peso * 1.7f;
    return peso * 0.8f;
}
string reporteMedicion::tostring() {
    stringstream s;
    s << "----------------------REPORTE DE MEDICION------------------------" << endl;
    s << "Fecha: " << fechas.tostring() << endl;
    s << "Peso: " << peso << " kg" << endl;
    s << "Estatura: " << estatura << " m" << endl;
    s << "Porcentaje de grasa: " << porcentajeGrasa << " %" << endl;
    s << "Porcentaje de musculo: " << porcentajeMusculo << " %" << endl;
    s << "Edad Metabolica: " << edadMetabolica << "Anios" << endl;
    s << "Grasa visceral: " << grasaViseral << " %" << endl;
    s << "Cintura: " << cintura << " cm" << endl;
    s << "Cadera: " << cadera << " cm" << endl;
    s << "Pecho: " << pecho << " cm" << endl;
    s << "Muslo: " << muslo << " cm" << endl;
    s << "IMC: " << imc << endl;
    s << "Clasificacion IMC: " << obtenerClasificacionIMC() << endl;
    s << "Vasos de agua recomendados al dia: " << calcularVasosAgua() << " vasos" << endl;
    s << "----------------------FIN DEL REPORTE DE MEDICION--------------------" << endl;
    return s.str();
}
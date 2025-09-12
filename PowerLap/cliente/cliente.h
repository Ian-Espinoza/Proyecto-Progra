#include <iostream>
#include <string>
using namespace std;
#ifndef CLIENTE_H
#define CLIENTE_H
class reporteMedicion;
class rutinas;
class cliente
{
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fechaNaci;
    char sexo;
    string fechaInscripción;
    reporteMedicion **medicion;
    int can;
    int max;
    rutinas *rutinaActual;

public:
    cliente(string, string, string, string, string, char, string);

    void agregarMedicion(reporteMedicion *);
    void historialPorFecha();
    double calcularIMC(double, double);
    string clasificarIMC(double);
    int recomendacionAgua(double peso);
    double recomendacionProteina(double, char, bool);
    ~cliente();
};
#endif
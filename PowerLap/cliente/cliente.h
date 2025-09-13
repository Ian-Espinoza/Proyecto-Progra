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
    double IMC;
    string cedula;
    string nombre;
    double peso;
    double altura;
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
    cliente(double, string, string, double, double, string, string, string, char, string);
    double getIMC();
    string getCedula();
    string getNombre();
    double getPeso();
    double getAltura();
    string getTelefono();
    string getCorreo();
    string getFechaNaci();
    char getSexo();
    string getFechaInscripción();
    void agregarMedicion(reporteMedicion *);
    void historialPorFecha();
    double calcularIMC(double, double);
    string clasificarIMC(double);
    int recomendacionAgua(double);
    double recomendacionProteina(double, char, bool);
    ~cliente();
};
#endif
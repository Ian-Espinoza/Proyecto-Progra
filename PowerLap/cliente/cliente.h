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
    bool esAtleta;
    rutinas *rutinaActual;

public:
    cliente(double, string, string, double, double, string, string, string, char, string, bool);

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
    bool getEsAtleta();

    void setIMC();
    void setCedula();
    void setNombre();
    void setPeso();
    void setAltura();
    void setTelefono();
    void setCorreo();
    void setFechaNaci();
    void setSexo();
    void setFechaInscripción();
    void setEsAtleta();

    void agregarMedicion(reporteMedicion *);

    void historialPorFecha();

    double calcularIMC(double, double);

    string clasificarIMC(double);

    int recomendacionAgua(double);

    double recomendacionProteina(double, char, bool);
    
    ~cliente();
};
#endif
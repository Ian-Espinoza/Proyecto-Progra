#ifndef REPORTEMEDICION_H
#define REPORTEMEDICION_H
#include "../fecha/fecha.h"
using namespace std;
#include <string>

class fecha;

class reporteMedicion {
private:
    fecha fechas;
    float peso;
    float estatura;
    float porcentajeGrasa;
    float porcentajeMusculo;
    float grasaViseral;
    int edadMetabolica;
    float cintura;
    float cadera;
    float pecho;
    float muslo;
    float imc;
public:
    reporteMedicion();
    reporteMedicion(fecha, float, float, float, float, float, int, float, float, float, float, float);
    fecha getfecha();
    float getPeso();
    float getEstatura();
    float getPorcentajeGrasa();
    float getPorcentajeMusculo();
    float getGrasaViseral();
    int getEdadMetabolica();
    float getCintura();
    float getCadera();
    float getPecho();
    float getMuslo();
    float getIMC();

    void setFecha(fecha);
    void setPeso(float);
    void setEstatura(float);
    void setPorcentajeGrasa(float);
    void setPorcentajeMusculo(float);
    void setGrasaViseral(float);
    void setEdadMetabolica(int);
    void setCintura(float);
    void setCadera(float);
    void setPecho(float);
    void setMuslo(float);
    void setIMC(float);

    float calcularIMC();
    float calcularProteinaRequerida(char, bool);
    string tostring();
    string obtenerClasificacionIMC();
    int calcularVasosAgua();
};
#endif
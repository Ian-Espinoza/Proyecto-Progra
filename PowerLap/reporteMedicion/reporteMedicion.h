#ifndef REPORTEMEDICION_H
#define REPORTEMEDICION_H
#include "fecha.h"
using namespace std;
#include <string>
class fecha;
class medicion{
private:
    fecha fechas;
    float peso;
    float estatura;
    float porcentajeGrasa;
    float porcentajeMusculo;
    float grasaViseral;
    float cintura;
    float cadera;
    float pecho;
    float muslo;
    float imc;
    public:
        medicion();
        medicion(fecha, float, float, float, float, float, float, float, float, float);
        fecha getfecha();
        float getPeso();
        float getEstatura();
        float getPorcentajeGrasa();
        float getPorcentajeMusculo();
        float getGrasaViseral();
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
        void setCintura(float);
        void setCadera(float);
        void setPecho(float);
        void setMuslo(float);
        void setIMC(float);

        float calcularIMC();
        float calcularProteinaRequerida (char , bool);
        string tostring(); //NO BORRE ESTO QUE YA LO VEO VENIR, mostrar medicion
        char* obtenerClasificacionIMC();
        
};
#endif
#ifndef HISTORIAL_H
#define HISTORIAL_H
#include <iostream>
using namespace std;
class reporteMedicion;
class historial{
private:
    reporteMedicion** mediciones;
    int can;
    int tam;
public:
    historial();
    ~historial();
    bool agregarMedicion(reporteMedicion*);
    void mostrarHistorial();
    reporteMedicion* getUltimaMedicion();
    int getCanMediciones();
};
#endif
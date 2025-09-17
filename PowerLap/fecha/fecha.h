#ifndef FECHA_H
#define FECHA_H
using namespace std;
#include <string>
#include <sstream>
class fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    fecha();
    fecha(int, int, int);
    int getDia();
    int getMes();
    int getAnio();

    void setDia(int);
    void setMes(int);
    void setAnio(int);

    bool esValida();
    string tostring();
};
#endif
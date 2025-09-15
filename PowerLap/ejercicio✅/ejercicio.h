#ifndef EJERCICIO_H
#define EJERCICIO_H
#include <sstream>
#include <string>
using namespace std;

class ejercicio{
private:
    int codigo;
    string nombre;
    string descripcion;
    string areaCuerpo;
public:
    ejercicio();
    ejercicio(int, string, string, string);
    ~ejercicio();
    int getCodigo();
    string getNombre();
    string getDescripcion();
    string getAreaCuerpo();
    void setCodigo(int);
    void setNombre(string);
    void setDescripcion(string);
    void setAreaCuerpo(string);
    string tostring();
};
#endif
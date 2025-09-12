#include <iostream>
#include <string>
#ifndef SUCURSALES_H
#define SUCURSALES_H
using namespace std;
class cliente;
class instructores;
class claseGrupal;
class sucursales{
private:
    string provincia;
    string telefono;
    string canton;
    string correo;
    string codigo;
    cliente *client;
    instructores *instructor;
    claseGrupal *clase;
public:
sucursales(string, string, string, string, string);
void agregarCliente(cliente*);
void agregarInstructor(instructores*);
void agregarClase(claseGrupal*);
void listarcliente();
void reporteIMC();
};
#endif 
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
    string telefono;
    string canton;
    string correo;
    string codigo;
    cliente **client;
    int canClientes;
    instructores **instructor;
    int canInstructor;
    claseGrupal **clase;
    int canClases;
public:
    sucursales(string, string, string, string, string);
    void agregarCliente(cliente*);
    void agregarInstructor(instructores*);
    void agregarClase(claseGrupal*);
    void listarcliente();
    void reporteIMC();
    ~sucursales();
};
#endif  
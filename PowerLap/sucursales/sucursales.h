#ifndef SUCURSALES_H
#define SUCURSALES_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class cliente;
class instructor;
class claseGrupal;

class sucursales{
private:
    int codigo;
    string nombre;
    string canton;
    string correo;
    string provincia;
    string telefono;
    cliente** clientes;
    int canClientes;
    int tamClientes;
    instructor** instructores;
    int canInstructores;
    int tamInstructores;
    claseGrupal** clases;
    int canClases;
    int tamClases;
public:
    sucursales();
    sucursales(int, string, string, string, string, string);
    ~sucursales();

    int getCodigo();
    string getNombre();
    string getCanton();
    string getCorreo();
    string getTelefono();
    string getProvincia();
    cliente** getClientes();
    int getCanClientes();
    instructor** getInstructores();
    int getCanInstructores();
    claseGrupal** getClases();
    int getCanClases();

    void setCodigo(int);
    void setCanton(string);
    void setProvincia(string);
    void setCorreo(string);
    void setTelefono(string);

    void agregarCliente(cliente*);
    void agregarInstructor(instructor*);
    void agregarClase(claseGrupal*);
    cliente* buscarCliente(string);
    instructor* buscarInstructor(string);
    claseGrupal* buscarClase(string);
    void listarClientes();
    void listarInstructores();
    void listarClases();
    void generarReporteIMC();
    string mostrarSucursal();
};
#endif
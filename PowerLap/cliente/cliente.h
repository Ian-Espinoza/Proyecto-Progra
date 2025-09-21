#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class sucursales;
class claseGrupal;
class rutinas;
class reporteMedicion;
class instructor;

class cliente {
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fechaNaci;
    char sexo;
    string fechaInscripcion;
    sucursales* sucursalCliente;
    instructor* instructorCliente;
    rutinas* rutinaActual;
    reporteMedicion** mediciones;
    int canMediciones;
    claseGrupal** clasesMatriculadas;
    int canClases;
public:
    cliente();
    ~cliente();

    string getCedula();
    string getNombre();
    string getTelefono();
    string getCorreo();
    string getFechaNaci();
    char getSexo();
    string getFechaInscripcion();
    sucursales* getSucursalCliente();
    instructor* getInstructorCliente();
    rutinas* getRutinaActual();
    reporteMedicion** getMediciones();
    claseGrupal** getClasesMatriculadas();
    int getCanMediciones();
    int getCantidadClases();
    reporteMedicion* ultimaMedicion();

    void setCedula(string);
    void setNombre(string);
    void setTelefono(string);
    void setCorreo(string);
    void setFechaNaci(string);
    void setSexo(char);
    void setFechaInscripcion(string);
    void setSucursalCliente(sucursales*);
    void setInstructorCliente(instructor*);

    void agregarMedicion(reporteMedicion*);
    void asignarRutina(rutinas*);
    bool matricularClase(claseGrupal*);
    bool desmatricularClase(claseGrupal*);
    void mostrarhistorialMediciones();
    void mostrarClasesMatriculadas();
    string mostrarCliente();
};
#endif
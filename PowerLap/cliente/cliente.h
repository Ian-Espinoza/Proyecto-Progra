#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class sucursal;
class claseGrupal;
class rutinas;
class reporteMedicion;
class instructor;
class cliente
{
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fechaNaci;
    char sexo;
    string fechaInscripcion;

    sucursal* sucursalCliente;
    instructor* instructorCliente;
    rutinas *rutinaActual;
    reporteMedicion** mediciones;
    claseGrupal** clasesMatriculadas;
    
    int canMediciones;
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
    string getFechaInscripción();
    sucursal* getSucursalCliente();
    instructor* getInstructorCliente();
    rutinas* getRutinaActual();
    reporteMedicion** getMediciones();
    int getCanMediciones();
    claseGrupal** getClasesMatriculadas();
    int getCantidadClases();
    
    void setCedula(string);
    void setNombre(string);
    void setTelefono(string);
    void setCorreo(string);
    void setFechaNaci(string);
    void setSexo(char);
    void setFechaInscripción(string);
    void setSucursalCliente(sucursal*);
    void setInstructorCliente(instructor*);
    
    void agregarMedicion(reporteMedicion *);
    void asignarRutina(rutinas *);
    bool matricularClase(claseGrupal*);
    bool desmatricularClase(claseGrupal*);
    void mostrarhistorialMediciones();
    void mostrarClasesMatriculadas();
    reporteMedicion* ultimaMedicion();
    
    string mostrarCliente();

};
#endif
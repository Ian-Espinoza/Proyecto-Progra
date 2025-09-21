#ifndef POWERLAB_H
#define POWERLAB_H

#include <string>
#include <iostream>
using namespace std;

class sucursales;
class instructor;
class cliente;
class claseGrupal;
class ejercicio;
class rutinas;
class reporteMedicion;
class fecha;
class especialidad;

class PowerLab {
private:
    // Limites
    static const int MAX_SUCURSALES = 30;
    static const int MAX_EJERCICIOS = 200;

    // Estado
    sucursales** _sucursales;
    int _canSuc;

    // Batería de ejercicios central
    ejercicio** _bateria;
    int _canEj;

    // Catálogo de especialidades (vida del programa)
    especialidad* _catalogo;

    // Utilidades de búsqueda
    sucursales* buscarSucursalPorCodigo(int codigo);
    instructor* buscarInstructorGlobalPorCedula(const string& ced);
    cliente* buscarClienteGlobalPorCedula(const string& ced);
    claseGrupal* buscarClaseGlobalPorCodigo(const string& cod, sucursales*& sucSalida);

    // Helpers de entrada
    int leerInt(const string& prompt);
    float leerFloat(const string& prompt);
    string leerStr(const string& prompt);

    // Clonado de ejercicios para rutinas (evita doble delete con batería)
    ejercicio* clonarEjercicio(const ejercicio* e);

    // Funcionalidades
    void uiIngresarSucursal();
    void uiIngresarInstructor();
    void uiIngresarCliente();
    void uiRegistrarMedicion();
    void uiVerHistorialMediciones();
    void uiAgregarEjercicioBateria();
    void uiGenerarRutinaCliente();
    void uiCrearClaseGrupal();
    void uiMatricularClienteEnClase();
    void uiReporteIMCPorSucursal();
    void uiListados();

    // Sub-listados
    void listadoClientesPorSucursal();
    void detalleClienteEspecifico();
    void listadoClientesPorInstructor();
    void listadoInstructoresPorSucursal();
    void listadoInstructoresPorEspecialidad();
    void listarClasesPorSucursal();
    void listarClasesPorCliente();

public:
    PowerLab();
    ~PowerLab();

    // Bucle principal
    void run();
};

#endif
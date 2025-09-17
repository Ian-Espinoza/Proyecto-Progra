#include "powerlab.h"
#include "../sucursales/sucursales.h"
#include <iostream>

using namespace std;

powerlab::powerlab()
{
    maxSucursales = 30;
    canSucursales = 0;
    // CORRECCIÓN: Creas el arreglo dinámico aquí
    listaSucursales = new sucursales *[maxSucursales];
}

powerlab::~powerlab()
{
    // CORRECCIÓN: Liberas la memoria correctamente
    for (int i = 0; i < canSucursales; ++i)
    {
        delete listaSucursales[i];
    }
    delete[] listaSucursales;
}

void powerlab::agregarSucursal(sucursales *nuevaSucursal)
{
    if (canSucursales < maxSucursales)
    {
        listaSucursales[canSucursales++] = nuevaSucursal;
    }
    else
    {
        cout << "No se pueden agregar mas sucursales" << endl;
    }
}

void powerlab::mostrarSucursales()
{
    cout << "--- Sucursales de PowerLab ---" << endl;
    for (int i = 0; i < canSucursales; i++)
    {
        // Asumo que tu clase sucursales tiene un método tostring()
        cout << listaSucursales[i]->tostring() << endl;
    }
}

sucursales *powerlab::buscarSucursalPorCodigo(string codigo)
{
    for (int i = 0; i < canSucursales; i++)
    {
        // CORRECCIÓN: Compara con el parámetro 'codigo' y usa getCodigo()
        if (listaSucursales[i]->getCodigo() == codigo)
        {
            // CORRECCIÓN: Devuelve el puntero directamente
            return listaSucursales[i];
        }
    }
    return nullptr; // No se encontró
}

int powerlab::getCanSucursales()
{
    return canSucursales;
}

// --- Aquí empieza la Interfaz de Usuario ---

void powerlab::menuPrincipal()
{
    int opcion = 0;
    do
    {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Gestion de Sucursales" << endl;
        cout << "2. Gestion de Clientes" << endl;
        cout << "3. Gestion de Instructores" << endl;
        cout << "4. Reportes" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------" << endl;
        cout << "Digite una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // ¡AHORA SÍ LLAMAMOS AL SUBMENÚ!
            menuGestionSucursales();
            break;
        case 2:
            // menuGestionClientes();
            cout << "Entrando a gestion de clientes..." << endl;
            break;
        case 3:
            // menuGestionInstructores();
            cout << "Entrando a gestion de instructores..." << endl;
            break;
        case 4:
            // menuReportes();
            cout << "Entrando a reportes..." << endl;
            break;
        case 0:
            cout << "Saliendo del sistema. ¡Hasta pronto!" << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 0);
}

void powerlab::menuGestionSucursales()
{
    int opcion = 0;
    do
    {
        cout << "\n--- GESTION DE SUCURSALES ---" << endl;
        cout << "1. Agregar Nueva Sucursal" << endl;
        cout << "2. Mostrar Todas las Sucursales" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "-----------------------------" << endl;
        cout << "Digite una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            // --- LÓGICA PARA AGREGAR SUCURSAL ---
            string codigo, provincia, canton, correo, telefono;

            cout << "--- Nueva Sucursal ---" << endl;
            cout << "Digite el codigo: ";
            cin >> codigo;
            cin.ignore(); // Limpia el buffer después de leer un número o string simple

            cout << "Digite la provincia: ";
            getline(cin, provincia);

            cout << "Digite el canton: ";
            getline(cin, canton);

            cout << "Digite el correo: ";
            cin >> correo;

            cout << "Digite el telefono: ";
            cin >> telefono;

            // 1. Crea el objeto en memoria dinámica
            sucursales *nuevaSucursal = new sucursales(codigo, provincia, canton, correo, telefono);

            // 2. Usa el método que ya tenías para agregarlo a la lista
            agregarSucursal(nuevaSucursal);

            cout << "\n¡Sucursal agregada con exito!" << endl;
            break;
        }
        case 2:
            // Llama al método que ya tenías para mostrar las sucursales
            mostrarSucursales();
            break;
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    } while (opcion != 0);
}

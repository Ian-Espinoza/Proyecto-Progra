#include "powerlab/powerlab.h"
#include <iostream>
using namespace std;

int main()
{
    // 1. Crea el objeto principal del sistema en memoria dinámica
    powerlab *miGimnasio = new powerlab();

    // Opcional: Aquí podrías llamar a una función para cargar datos de prueba
    // miGimnasio->cargarDatosDePrueba();

    // 2. Inicia la interfaz de usuario llamando al menú principal
    miGimnasio->menuPrincipal();

    // 3. Libera la memoria del objeto principal al salir del programa
    delete miGimnasio;

    return 0;
}
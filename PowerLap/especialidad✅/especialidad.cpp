#include "especialidad.h"

string especialidades::especialidad[8] = {"CrossFit", "HIIT", "TRX", "Pesas", "Spinning", "Cardio", "Yoga", "Zumba"};

especialidad::especialidad(string nom) {
    this->nombre = nom;
}
string especialidad::getNombre() {
    return nombre;
}
void especialidad::mostrarEspecialidades() {
    cout << "Especialidades disponibles:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i + 1 << ". " << listaEspecialidades[i] << endl;
    }
}


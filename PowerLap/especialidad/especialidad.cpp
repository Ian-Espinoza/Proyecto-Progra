#include "especialidad.h"

especialidad::especialidad() {
    tam = 8;
    especialidades = new string[tam];
    especialidades[0] = "CrossFit";
    especialidades[1] = "HIIT";
    especialidades[2] = "TRX";
    especialidades[3] = "pesas";
    especialidades[4] = "spinning";
    especialidades[5] = "cardio";
    especialidades[6] = "yoga";
    especialidades[7] = "zumba";
}   
string* especialidad::getEspecialidadNombre(int num) {
    if (num > 0 && num <= tam) {
        return &especialidades[num - 1];
    }
    return nullptr;
}
void especialidad::mostrarEspecialidades() {
    cout << "especialidades disponibles: " << endl;
    for (int i = 0; i < tam; i++) {
        cout << i + 1 << ". " << especialidades[i] << endl;
    }
}
string especialidad::getEspecialidadPorNumero(int num) {
    if (num > 0 && num <= tam) {
        return especialidades[num - 1];
    }
    return "invalido";
}
int especialidad::getCantidadEspecialidades() { return tam; }
especialidad::~especialidad() {
    delete[] especialidades;
}

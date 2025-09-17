#include "especialidad.h"
especialidad::especialidad(){
    tam = 8;
    Especialidades = [tam];
    Especialidades[0] = "CrossFit";
    Especialidades[1] = "HIIT";
    Especialidades[2] = "TRX";
    Especialidades[3] = "pesas";
    Especialidades[4] = "spinning";
    Especialidades[5] = "cardio";
    Especialidades[6] = "yoga";
    Especialidades[7] = "zumba";
}
string* especialidad::getEspecialidadNombre(int num){
    if (num > 0 && num <= tam) {
        return Especialidades[num - 1];
    }
    return nullptr;
}

void especialidad::mostrarEspecialidades(){
    cout << "Especialidades disponibles: " << endl;
    for (int i = 0; i < tam; i++){
        cout << i + 1 << ". " << *Especialidades[i] << endl;}
}

string especialidad::getEspecialidadPorNumero(int num){
    if (num > 0 && num <= tam) {
        return *Especialidades[num - 1];
    }
    return "invalido";
}

int especialidad::getCantidadEspecialidades(){return tam;}

especialidad::~especialidad(){
    for (int i = 0; i < tam; i++){
    delete Especialidades[i];
    }
    delete[] Especialidades;
}

#include "especialidad.h"
especialidad::especialidad(){
    tam = 8;
    Especialidades = new string *[tam];
    Especialidades[0] = new string("CrossFit");
    Especialidades[1] = new string("HIIT");
    Especialidades[2] = new string("TRX");
    Especialidades[3] = new string("pesas");
    Especialidades[4] = new string("spinning");
    Especialidades[5] = new string("cardio");
    Especialidades[6] = new string("yoga");
    Especialidades[7] = new string("zumba");
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

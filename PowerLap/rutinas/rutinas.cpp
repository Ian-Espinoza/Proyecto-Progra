#include "rutinas.h"
#include "ejercicio.h"
rutinas::rutinas() {
    canPe = 0;
    canBi = 0;
    canPi = 0;
    canEs = 0;
    pechoTriceps = new ejercicio * [20];
    biceps = new ejercicio * [20];
    piernas = new ejercicio * [20];
    espalda = new ejercicio * [20];
}
rutinas::~rutinas() {
    for (int i = 0; i < canPe; ++i) { delete pechoTriceps[i]; }
    for (int i = 0; i < canBi; ++i) { delete biceps[i]; }
    for (int i = 0; i < canPi; ++i) { delete piernas[i]; }
    for (int i = 0; i < canEs; ++i) { delete espalda[i]; }
    delete[] pechoTriceps;
    delete[] biceps;
    delete[] piernas;
    delete[] espalda;
}
void rutinas::agregarEjercicio(ejercicio* e, string* area) {
    if (*area == "pecho" || *area == "triceps") {
        if (canPe < 20) {
            pechoTriceps[canPe++] = e;
        }
        else {
            cout << "No se pueden agregar mas ejercicios de pecho y triceps" << endl;
        }
    }
    else if (*area == "biceps") {
        if (canBi < 20) {
            biceps[canBi++] = e;
        }
        else {
            cout << "No se pueden agregar mas ejercicios de biceps" << endl;
        }
    }
    else if (*area == "piernas") {
        if (canPi < 20) {
            piernas[canPi++] = e;
        }
        else {
            cout << "No se pueden agregar mas ejercicios de piernas" << endl;
        }
    }
    else if (*area == "espalda") {
        if (canEs < 20) {
            espalda[canEs++] = e;
        }
        else {
            cout << "No se pueden agregar mas ejercicios de espalda" << endl;
        }
    }
    else {
        cout << "Area del cuerpo no valida" << endl;
    }
}
void rutinas::eliminarEjercicio(int codigo, string* area) {
    if (*area == "pecho" || *area == "triceps") {
        for (int i = 0; i < canPe; ++i) {
            if (pechoTriceps[i]->getCodigo() == codigo) {
                delete pechoTriceps[i];
                for (int j = i; j < canPe - 1; ++j) {
                    pechoTriceps[j] = pechoTriceps[j + 1];
                }
                canPe--;
                cout << "Ejercicio eliminado de pecho y triceps" << endl;
                return;
            }
        }
        cout << "Ejercicio no encontrado en pecho y triceps" << endl;
    }
    else if (*area == "biceps") {
        for (int i = 0; i < canBi; ++i) {
            if (biceps[i]->getCodigo() == codigo) {
                delete biceps[i];
                for (int j = i; j < canBi - 1; ++j) {
                    biceps[j] = biceps[j + 1];
                }
                canBi--;
                cout << "Ejercicio eliminado de biceps" << endl;
                return;
            }
        }
        cout << "Ejercicio no encontrado en biceps" << endl;
    }
    else if (*area == "piernas") {
        for (int i = 0; i < canPi; ++i) {
            if (piernas[i]->getCodigo() == codigo) {
                delete piernas[i];
                for (int j = i; j < canPi - 1; ++j) {
                    piernas[j] = piernas[j + 1];
                }
                canPi--;
                cout << "Ejercicio eliminado de piernas" << endl;
                return;
            }
        }
        cout << "Ejercicio no encontrado en piernas" << endl;
    } else if (*area == "espalda") {
        for (int i = 0; i < canEs; ++i) {
            if (espalda[i]->getCodigo() == codigo) {
                delete espalda[i];
                for (int j = i; j < canEs - 1; ++j) {
                    espalda[j] = espalda[j + 1];
                }
                canEs--;
                cout << "Ejercicio eliminado de espalda" << endl;
                return;
            }
        }
        cout << "Ejercicio no encontrado en espalda" << endl;
    }
    else {
        cout << "Area del cuerpo no valida" << endl;
    }
}
void rutinas::mostrarRutina() {
    cout << "Ejercicios de Pecho y Triceps:" << endl;
    for (int i = 0; i < canPe; ++i) {
        cout << pechoTriceps[i]->tostring() << endl;
    }
    cout << "Ejercicios de Biceps:" << endl;
    for (int i = 0; i < canBi; ++i) {
        cout << biceps[i]->tostring() << endl;
    }
    cout << "Ejercicios de Piernas:" << endl;
    for (int i = 0; i < canPi; ++i) {
        cout << piernas[i]->tostring() << endl;
    }
    cout << "Ejercicios de Espalda:" << endl;
    for (int i = 0; i < canEs; ++i) {
        cout << espalda[i]->tostring() << endl;
    }
}
ejercicio** rutinas::getPechoTriceps() { return pechoTriceps; }
ejercicio** rutinas::getBiceps() { return biceps; }
ejercicio** rutinas::getPiernas() { return piernas; }
ejercicio** rutinas::getEspalda() { return espalda; }
int rutinas::getCanPechoTriceps() { return canPe; }
int rutinas::getCanBiceps() { return canBi; }
int rutinas::getCanPiernas() { return canPi; }
int rutinas::getCanEspalda() { return canEs; }


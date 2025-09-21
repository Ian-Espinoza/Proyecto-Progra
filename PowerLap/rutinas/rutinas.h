#ifndef RUTINAS_H
#define RUTINAS_H
#include <iostream>
using namespace std;

class ejercicio;

class rutinas
{   
private:
    ejercicio** pechoTriceps;
    ejercicio** biceps;
    ejercicio** piernas;
    ejercicio** espalda;
    int canPe;
    int canBi;
    int canPi;
    int canEs;
    int tam;
public:
    rutinas();
    ~rutinas();
    void agregarEjercicio(ejercicio*, string*);
    void eliminarEjercicio(int, string*);
    void mostrarRutina();

    ejercicio** getPechoTriceps();
    ejercicio** getBiceps();
    ejercicio** getPiernas();
    ejercicio** getEspalda();

    int getCanPechoTriceps();
    int getCanBiceps();
    int getCanPiernas();
    int getCanEspalda();
};
#endif
#include <iostream>
using namespace std;
#ifndef POWERLAB_H
#define POWERLAB_H
class sucursales;
class powerlab
{
private:
    sucursales *sucursal[30];
    int canSucursales=10;
public:
    powerlab();
    void agregarSucursal(sucursales*);
    void mostrarSucursales();
    sucursales* getSucursal(string);
    int getCanSucursales();
    ~powerlab();
};
#endif
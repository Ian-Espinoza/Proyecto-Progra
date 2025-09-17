#include <iostream>
#include <string>
using namespace std;
#ifndef POWERLAB_H
#define POWERLAB_H

class sucursales;

class powerlab
{
private:
    sucursales **listaSucursales;
    int canSucursales;
    int maxSucursales;
    // --- MÉTODOS DE SUBMENÚ ---
    void menuGestionSucursales(); // ¡NUEVO!

public:
    powerlab();
    ~powerlab();

    void agregarSucursal(sucursales *nuevaSucursal);
    void mostrarSucursales();
    sucursales *buscarSucursalPorCodigo(std::string codigo);
    int getCanSucursales();

    // --- Interfaz de Usuario ---
    void menuPrincipal();
};

#endif
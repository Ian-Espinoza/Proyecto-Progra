#include"powerlab.h"
powerlab::powerlab() {for (int i = 0; i < 30; i++) {sucursal[i] = nullptr;}}

void powerlab::agregarSucursal(sucursales* nuevaSucursal) {
    if (canSucursales < 30) {sucursal[canSucursales++] = nuevaSucursal;}
    else {cout << "No se pueden agregar otra sucursal" << endl;}
}

void powerlab::mostrarSucursales() {
    cout << "Sucursales de PowerLab:" << endl;
    for (int i = 0; i < canSucursales; i++) {
        if (sucursal[i] != nullptr) {sucursal[i]->mostrar();}
    }
}
sucursales* powerlab::getSucursal(string codigo) {
    for (int i = 0; i < canSucursales; i++) {
        if (sucursal[i] != nullptr && sucursal[i]->getNombre() == nombre) {
            return &sucursal[i];
        }
    }
    return nullptr;
}
int powerlab::getCanSucursales() { return canSucursales; }

powerlab::~powerlab() { for(int i=0; i < canSucursales;++i){delete sucursal[i];} delete[] sucursal; }

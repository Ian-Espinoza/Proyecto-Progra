#include "historial.h"
#include "reporteMedicion.h"
historial::historial(){
    can = 0;
    tam = 10;
    mediciones = new reporteMedicion*[tam];
}
historial::~historial(){
    delete[] mediciones;
}
void historial::agregarMedicion(reporteMedicion* rep){
    if(can < tam){
        mediciones[can++] = rep;
    }
    else{
        cout << "No se pueden agregar mas mediciones" << endl;
    }
}
void historial::mostrarHistorial(){
    cout << "Historial de Mediciones: " << endl;
    if(can == 0){
        cout << "No hay mediciones registradas" << endl;}
    else{
        for(int i = 0; i < can; i++){
            cout << mediciones[i]->mostrarMedicion() << endl;
        }
    }
}
reporteMedicion* historial::getUltimaMedicion(){
    if(can > 0){
        return mediciones[can - 1];
    }
    return nullptr;
}
int historial::getCanMediciones(){
    return can;
}
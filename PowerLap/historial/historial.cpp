#include "historial.h"
using namespace std;
#include "../reporteMedicion✅/reporteMedicion.h"
historial::historial(){
    can = 0;
    tam = 10;
    mediciones = new reporteMedicion*[tam];
}
historial::~historial(){
    for (int i = 0; i < can; i++) {
        delete mediciones[i];
    }
    delete[] mediciones;
}
bool historial::agregarMedicion(reporteMedicion* rep){
    if(can < tam){
        mediciones[can++] = rep;
        return true;
    }
    else{
        cout << "No se pueden agregar mas de 10 mediciones" << endl;
        return false;
    }
}
void historial::mostrarHistorial(){
    cout << "Historial de Mediciones: " << endl;
    if(can == 0){
        cout << "No hay mediciones registradas" << endl;}
    else{
        for(int i = 0; i < can; i++){
            cout << mediciones[i]->tostring() << endl;
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
#include"sucursales.h"

sucursales::sucursales(){
    codigo = "";
    nombre = "";
    direccion = "";
    telefono = "";
    correo = "";
    canClientes = 0;
    tamClientes = 100;
    clientes = new cliente*[tamClientes];
    canInstructores = 0;
    tamInstructores = 8;
    instructores = new instructor*[tamInstructores];
    canClases = 0;
    tamClases = 8;
    clases = new claseGrupal*[tamClases];
}
sucursales::sucursales(int codigo, string nombre,string provincia, string canton, string telefono, string correo){
    this->codigo = codigo;
    this->nombre = nombre;
    this->provincia = provincia;
    this->canton = canton;
    this->telefono = telefono;
    this->correo = correo;

    canClientes = 0;
    tamClientes = 100;
    clientes = new cliente*[tamClientes];

    canInstructores = 0;
    tamInstructores = 8;
    instructores = new instructor*[tamInstructores];

    canClases = 0;
    tamClases = 8;
    clases = new claseGrupal*[tamClases];
}
sucursales::~sucursales(){
    delete[] clientes;
    delete[] instructores;
    delete[] clases;
}

int sucursales::getCodigo(){return codigo;}
string sucursales::getNombre(){return nombre;}
string sucursales::getCanton(){return canton;}
string sucursales::getTelefono(){return telefono;}
string sucursales::getCorreo(){return correo;}
int sucursales::getCanClientes(){return canClientes;}
cliente** sucursales::getClientes(){return clientes;}
int sucursales::getCanInstructores(){return canInstructores;}
instructor** sucursales::getInstructores(){return instructores;}
int sucursales::getCanClases(){return canClases;}
claseGrupal** sucursales::getClases(){return clases;}
string sucursales::getProvincia(){return provincia;}

void sucursales::setCodigo(int codigo){this->codigo = codigo;}
void sucursales::setCanton(string canton){this->canton = canton;}
void sucursales::setTelefono(string telefono){this->telefono = telefono;}
void sucursales::setCorreo(string correo){ this->correo = correo;}
void sucursales::setProvincia(string provincia){this->provincia = provincia;}

void sucursales::agregarCliente(cliente* clienteNuevo){
    if(canClientes < 100){
        clientes[canClientes] = clienteNuevo;
        canClientes++;
    }
    else{
        cout << "No se pueden agregar mas clientes a esta sucursal" << endl;
    }
}

void sucursales::agregarInstructor(instructor* i){
    if(canInstructores < 8){
        instructores[canInstructores] = i;
        canInstructores++;
    }
    else{
        cout << "No se pueden agregar mas instructores a esta sucursal" << endl;
    }
}

void sucursales::agregarClase(claseGrupal* clienteNuevo){
    if(canClases < 8){
        clases[canClases] = clienteNuevo;
        canClases++;
    }
    else{
        cout << "No se pueden agregar mas clases a esta sucursal" << endl;
    }
}

cliente* sucursales::buscarCliente(string cedula){
    for(int i = 0; i < canClientes; i++){
        if(clientes[i]->getCedula() == cedula){
            return clientes[i];
        }
    }
    return nullptr;
}

instructor* sucursales::buscarInstructor(string cedula){
    for(int i = 0; i < canInstructores; i++){
        if(instructores[i]->getCedula() == cedula){
            return instructores[i];
        }
    }
    return nullptr;
}

claseGrupal* sucursales::buscarClase(int id){
    for(int i = 0; i < canClases; i++){
        if(clases[i]->getCodigo() == id){
            return clases[i];
        }
    }
    return nullptr;
}

void sucursales::listarClientes(){
    cout << "---Clientes de la sucursal " << nombre << "---" << endl;
    if(canClientes == 0){
        cout << "No hay clientes en esta sucursal" << endl;
    }
    else{
        for(int i = 0; i < canClientes; i++){
           cout << clientes[i]->mostrarCliente() << endl;
        }
    }
}

void sucursales::listarInstructores(){
    cout << "---Instructores de la sucursal " << nombre << "---" << endl;
    if(canInstructores == 0){
        cout << "No hay instructores en esta sucursal" << endl;
    }
    else{
        for(int i = 0; i < canInstructores; i++){
           cout << instructores[i]->mostrarInstructor() << endl;
        }
    }
}

void sucursales::listarClases(){
    cout << "---Clases grupales de la sucursal " << nombre << "---" << endl;
    if(canClases == 0){
        cout << "No hay clases grupales en esta sucursal" << endl;
    }
    else{
        for(int i = 0; i < canClases; i++){
            cout << clases[i]->mostrarClase() << endl;
        }
    }
}

void sucursales::generarReporteIMC(){
    cout << "--- Reporte de IMC para los clientes ----" << endl;
    if(canClientes == 0){
        cout << "No hay clientes en esta sucursal" << endl;
        return;
    }
    else{
        for(int i = 0; i < canClientes; i++){
            cliente* cli = clientes[i];
            reporteMedicion* rep = cli->ultimaMedicion();
            cout << "Cliente: " << cli->getNombre() << endl;
            if(rep != nullptr){
                cout << "Fecha de la ultima medicion: " << rep->getFecha() << endl;
                cout << "IMC: " << rep->getIMC() << endl;
                cout << "Clasificacion: " << rep->obtenerClasificacionIMC() << endl;
            } else {
                cout << "No hay mediciones registradas para este cliente." << endl; 
            }
        }
    }
}

string sucursales::mostrarSucursal(){
    stringstream s;
    s << "***** Detalles de la Sucursal *****" << endl;
    s << "Código: " << codigo << endl;
    s << "Nombre: " << nombre << endl;
    s << "Provincia: " << provincia << endl;
    s << "Cantón: " << canton << endl;
    s << "Teléfono: " << telefono << endl;
    s << "Correo: " << correo << endl;
    s << "Cantidad de Clientes: " << canClientes << endl;
    s << "Cantidad de Instructores: " << canInstructores << endl;
    s << "Cantidad de Clases Grupales: " << canClases << endl;
    s << "************************************" << endl;
    return s.str();
}



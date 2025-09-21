#include "PowerLab.h"

#include "../sucursales/sucursales.h"
#include "../instructor/instructor.h"
#include "../cliente/cliente.h"
#include "../claseGrupal/claseGrupal.h"
#include "../ejercicio/ejercicio.h"
#include "../rutinas/rutinas.h"
#include "../reporteMedicion/reporteMedicion.h"
#include "../fecha/fecha.h"
#include "../especialidad/especialidad.h"

#include <limits>
#include <sstream>

// ========== Constructores / Destructores ==========

PowerLab::PowerLab() {
    _sucursales = new sucursales*[MAX_SUCURSALES];
    _canSuc = 0;

    _bateria = new ejercicio*[MAX_EJERCICIOS];
    _canEj = 0;

    _catalogo = new especialidad();
}

PowerLab::~PowerLab() {
    // Liberar rutinas de clientes y reportes de medición ya los borra cliente
    for (int i = 0; i < _canSuc; ++i) {
        sucursales* s = _sucursales[i];
        // Borrar clases grupales creadas en la sucursal
        for (int c = 0; c < s->getCanClases(); ++c) {
            delete s->getClases()[c];
        }
        // Borrar instructores
        for (int k = 0; k < s->getCanInstructores(); ++k) {
            delete s->getInstructores()[k];
        }
        // Borrar clientes (y sus rutinas si existen)
        for (int j = 0; j < s->getCanClientes(); ++j) {
            cliente* cli = s->getClientes()[j];
            if (cli->getRutinaActual() != nullptr) {
                delete cli->getRutinaActual();
            }
            delete cli;
        }
        delete s;
    }
    delete[] _sucursales;

    // Batería de ejercicios central
    for (int i = 0; i < _canEj; ++i) delete _bateria[i];
    delete[] _bateria;

    delete _catalogo;
}

// ========== Helpers de entrada ==========

int PowerLab::leerInt(const string& prompt) {
    cout << prompt;
    int v;
    while (!(cin >> v)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente nuevamente: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return v;
}
float PowerLab::leerFloat(const string& prompt) {
    cout << prompt;
    float v;
    while (!(cin >> v)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente nuevamente: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return v;
}
string PowerLab::leerStr(const string& prompt) {
    cout << prompt;
    string s;
    getline(cin, s);
    return s;
}

// ========== Búsquedas ==========

sucursales* PowerLab::buscarSucursalPorCodigo(int codigo) {
    for (int i = 0; i < _canSuc; ++i) {
        if (_sucursales[i]->getCodigo() == codigo) return _sucursales[i];
    }
    return nullptr;
}
instructor* PowerLab::buscarInstructorGlobalPorCedula(const string& ced) {
    for (int i = 0; i < _canSuc; ++i) {
        sucursales* s = _sucursales[i];
        for (int j = 0; j < s->getCanInstructores(); ++j) {
            if (s->getInstructores()[j]->getCedula() == ced) return s->getInstructores()[j];
        }
    }
    return nullptr;
}
cliente* PowerLab::buscarClienteGlobalPorCedula(const string& ced) {
    for (int i = 0; i < _canSuc; ++i) {
        sucursales* s = _sucursales[i];
        for (int j = 0; j < s->getCanClientes(); ++j) {
            if (s->getClientes()[j]->getCedula() == ced) return s->getClientes()[j];
        }
    }
    return nullptr;
}
claseGrupal* PowerLab::buscarClaseGlobalPorCodigo(const string& cod, sucursales*& sucSalida) {
    sucSalida = nullptr;
    for (int i = 0; i < _canSuc; ++i) {
        sucursales* s = _sucursales[i];
        for (int j = 0; j < s->getCanClases(); ++j) {
            if (s->getClases()[j]->getCodigo() == cod) {
                sucSalida = s;
                return s->getClases()[j];
            }
        }
    }
    return nullptr;
}

// ========== Clonado de ejercicios ==========

ejercicio* PowerLab::clonarEjercicio(const ejercicio* e) {
    return new ejercicio(e->getCodigo(), e->getNombre(), e->getDescripcion(), e->getAreaCuerpo());
}

// ========== UI: Altas y operaciones ==========

void PowerLab::uiIngresarSucursal() {
    if (_canSuc >= MAX_SUCURSALES) {
        cout << "No se pueden agregar mas sucursales (limite alcanzado)." << endl;
        return;
    }
    int cod = leerInt("Codigo: ");
    if (buscarSucursalPorCodigo(cod)) {
        cout << "Ya existe una sucursal con ese codigo." << endl;
        return;
    }
    string nombre = leerStr("Nombre: ");
    string provincia = leerStr("Provincia: ");
    string canton = leerStr("Canton: ");
    string tel = leerStr("Telefono: ");
    string correo = leerStr("Correo: ");

    sucursales* s = new sucursales(cod, nombre, provincia, canton, tel, correo);
    _sucursales[_canSuc++] = s;
    cout << "Sucursal creada." << endl;
}

void PowerLab::uiIngresarInstructor() {
    if (_canSuc == 0) { cout << "Primero cree sucursales." << endl; return; }
    int cod = leerInt("Codigo sucursal: ");
    sucursales* s = buscarSucursalPorCodigo(cod);
    if (!s) { cout << "Sucursal no encontrada." << endl; return; }

    string ced = leerStr("Cedula: ");
    if (buscarInstructorGlobalPorCedula(ced)) {
        cout << "Ya existe un instructor con esa cedula." << endl; return;
    }
    string nom = leerStr("Nombre: ");
    string tel = leerStr("Telefono: ");
    string corr = leerStr("Correo: ");
    string fnac = leerStr("Fecha nacimiento (dd/mm/aaaa): ");

    instructor* ins = new instructor(ced, nom, tel, corr, fnac);

    cout << "Especialidades disponibles:" << endl;
    _catalogo->mostrarEspecialidades();
    int cuantas = leerInt("Cantidad de especialidades a asignar (max 2): ");
    if (cuantas > 2) cuantas = 2;
    for (int i = 0; i < cuantas; ++i) {
        int idx = leerInt("Numero de especialidad: ");
        string* espPtr = _catalogo->getEspecialidadNombre(idx);
        if (espPtr) ins->agregarEspecialidad(espPtr);
    }

    s->agregarInstructor(ins);
    cout << "Instructor agregado a la sucursal." << endl;
}

void PowerLab::uiIngresarCliente() {
    if (_canSuc == 0) { cout << "Primero cree sucursales." << endl; return; }
    int cod = leerInt("Codigo sucursal: ");
    sucursales* s = buscarSucursalPorCodigo(cod);
    if (!s) { cout << "Sucursal no encontrada." << endl; return; }

    string ced = leerStr("Cedula: ");
    if (buscarClienteGlobalPorCedula(ced)) {
        cout << "Ya existe un cliente con esa cedula." << endl; return;
    }
    string nom = leerStr("Nombre completo: ");
    string tel = leerStr("Telefono: ");
    string corr = leerStr("Correo: ");
    string fnac = leerStr("Fecha nacimiento (dd/mm/aaaa): ");
    char sexo = ' ';
    {
        string sx = leerStr("Sexo (M/F): ");
        if (!sx.empty()) sexo = sx[0];
    }
    string fins = leerStr("Fecha inscripcion (dd/mm/aaaa): ");

    cliente* c = new cliente();
    c->setCedula(ced);
    c->setNombre(nom);
    c->setTelefono(tel);
    c->setCorreo(corr);
    c->setFechaNaci(fnac);
    c->setSexo(sexo);
    c->setFechaInscripcion(fins);
    c->setSucursalCliente(s);

    // Asignar instructor (opcional)
    if (s->getCanInstructores() > 0) {
        string cedIns = leerStr("Cedula instructor asignado (enter para omitir): ");
        if (!cedIns.empty()) {
            instructor* ins = s->buscarInstructor(cedIns);
            if (ins) c->setInstructorCliente(ins);
            else cout << "Instructor no encontrado en esta sucursal (cliente queda sin instructor)." << endl;
        }
    } else {
        cout << "La sucursal no tiene instructores aun. Podras asignarlo luego." << endl;
    }

    s->agregarCliente(c);
    cout << "Cliente agregado a la sucursal." << endl;
}

void PowerLab::uiRegistrarMedicion() {
    string ced = leerStr("Cedula cliente: ");
    cliente* c = buscarClienteGlobalPorCedula(ced);
    if (!c) { cout << "Cliente no encontrado." << endl; return; }
    if (!c->getInstructorCliente()) {
        cout << "El cliente no tiene instructor asignado (requerido)." << endl; return;
    }
    int d = leerInt("Dia: ");
    int m = leerInt("Mes: ");
    int a = leerInt("Anio: ");
    float peso = leerFloat("Peso (kg): ");
    float est = leerFloat("Estatura (m): ");
    float pGrasa = leerFloat("% Grasa: ");
    float pMus = leerFloat("% Musculo: ");
    float gVis = leerFloat("Grasa visceral: ");
    int edadMet = leerInt("Edad metabolica: ");
    float cint = leerFloat("Cintura (cm): ");
    float cad = leerFloat("Cadera (cm): ");
    float pech = leerFloat("Pecho (cm): ");
    float muslo = leerFloat("Muslo (cm): ");

    fecha f(d, m, a);
    reporteMedicion* rep = new reporteMedicion(f, peso, est, pGrasa, pMus, gVis, edadMet, cint, cad, pech, muslo, 0);
    rep->calcularIMC();
    c->agregarMedicion(rep);

    cout << "Medicion registrada. IMC: " << rep->getIMC() << " - " << rep->obtenerClasificacionIMC() << endl;
}

void PowerLab::uiVerHistorialMediciones() {
    string ced = leerStr("Cedula cliente: ");
    cliente* c = buscarClienteGlobalPorCedula(ced);
    if (!c) { cout << "Cliente no encontrado." << endl; return; }
    c->mostrarhistorialMediciones();
}

void PowerLab::uiAgregarEjercicioBateria() {
    if (_canEj >= MAX_EJERCICIOS) { cout << "Bateria llena." << endl; return; }
    int cod = leerInt("Codigo ejercicio: ");
    // evitar duplicados por codigo
    for (int i = 0; i < _canEj; ++i) if (_bateria[i]->getCodigo() == cod) {
        cout << "Ya existe un ejercicio con ese codigo." << endl; return;
    }
    string nom = leerStr("Nombre: ");
    string desc = leerStr("Descripcion: ");
    string area = leerStr("Area (pecho|triceps|biceps|piernas|espalda): ");
    _bateria[_canEj++] = new ejercicio(cod, nom, desc, area);
    cout << "Ejercicio agregado a la bateria." << endl;
}

void PowerLab::uiGenerarRutinaCliente() {
    string ced = leerStr("Cedula cliente: ");
    cliente* c = buscarClienteGlobalPorCedula(ced);
    if (!c) { cout << "Cliente no encontrado." << endl; return; }
    if (_canEj == 0) { cout << "Bateria de ejercicios vacia." << endl; return; }

    // Si tiene rutina actual, liberarla
    if (c->getRutinaActual() != nullptr) {
        delete c->getRutinaActual();
    }
    rutinas* r = new rutinas();

    // Estrategia simple: agregar todos los ejercicios de la batería por su area a la rutina
    for (int i = 0; i < _canEj; ++i) {
        ejercicio* eClone = clonarEjercicio(_bateria[i]);
        string area = _bateria[i]->getAreaCuerpo();
        r->agregarEjercicio(eClone, &area);
    }
    c->asignarRutina(r);
    cout << "Rutina generada para el cliente." << endl;
}

void PowerLab::uiCrearClaseGrupal() {
    if (_canSuc == 0) { cout << "Primero cree sucursales." << endl; return; }
    int cod = leerInt("Codigo sucursal: ");
    sucursales* s = buscarSucursalPorCodigo(cod);
    if (!s) { cout << "Sucursal no encontrada." << endl; return; }

    string id = leerStr("Codigo clase: ");
    string tipo = leerStr("Tipo (CrossFit|HIIT|TRX|pesas|spinning|cardio|yoga|zumba): ");
    string salon = leerStr("Salon: ");
    string horario = leerStr("Horario (hh:mm): ");
    int cupo = leerInt("Cupo maximo: ");
    string cedIns = leerStr("Cedula instructor: ");
    instructor* ins = s->buscarInstructor(cedIns);
    if (!ins) { cout << "Instructor no encontrado en la sucursal." << endl; return; }

    // Validar especialidad del instructor vs tipo de clase
    string tmp = tipo;
    if (!ins->tieneEspecialidad(&tmp)) {
        cout << "El instructor no posee la especialidad requerida para la clase." << endl; return;
    }

    claseGrupal* cg = new claseGrupal(id, tipo, salon, horario, cupo, ins);
    s->agregarClase(cg);
    cout << "Clase grupal creada." << endl;
}

void PowerLab::uiMatricularClienteEnClase() {
    string idClase = leerStr("Codigo de clase: ");
    sucursales* sucDeClase = nullptr;
    claseGrupal* cg = buscarClaseGlobalPorCodigo(idClase, sucDeClase);
    if (!cg) { cout << "Clase no encontrada." << endl; return; }

    string ced = leerStr("Cedula cliente: ");
    cliente* c = buscarClienteGlobalPorCedula(ced);
    if (!c) { cout << "Cliente no encontrado." << endl; return; }

    // Regla: max 3 clases por cliente
    if (c->getCantidadClases() >= 3) {
        cout << "El cliente ya tiene el maximo de 3 clases." << endl; return;
    }
    // Verificar cupo por clase
    if (cg->getCuposLibres() <= 0) {
        cout << "La clase ya esta llena." << endl; return;
    }

    if (cg->matricular(c)) {
        c->matricularClase(cg);
        cout << "Cliente matriculado en la clase." << endl;
    } else {
        cout << "No se pudo matricular al cliente." << endl;
    }
}

void PowerLab::uiReporteIMCPorSucursal() {
    if (_canSuc == 0) { cout << "No hay sucursales." << endl; return; }
    int cod = leerInt("Codigo sucursal: ");
    sucursales* s = buscarSucursalPorCodigo(cod);
    if (!s) { cout << "Sucursal no encontrada." << endl; return; }

    // Contadores por clasificacion
    int cSev=0,cMod=0,cLev=0,cNorm=0,cPre=0,cOb1=0,cOb2=0,cOb3=0;

    cout << "--- Reporte IMC por sucursal: " << s->getNombre() << " ---" << endl;
    for (int i = 0; i < s->getCanClientes(); ++i) {
        cliente* cli = s->getClientes()[i];
        reporteMedicion* rep = cli->ultimaMedicion();
        if (!rep) continue;
        string cls = rep->obtenerClasificacionIMC();
        if (cls == "Delgadez severa") cSev++;
        else if (cls == "delgadez moderada") cMod++;
        else if (cls == "delgadez leve") cLev++;
        else if (cls == "normal") cNorm++;
        else if (cls == "pre-sobrepeso") cPre++;
        else if (cls == "obesidad leve") cOb1++;
        else if (cls == "obesidad media") cOb2++;
        else if (cls == "obesidad morbida") cOb3++;
    }
    cout << "Delgadez severa: " << cSev << endl;
    cout << "Delgadez moderada: " << cMod << endl;
    cout << "Delgadez leve: " << cLev << endl;
    cout << "Normal: " << cNorm << endl;
    cout << "Pre-obesidad: " << cPre << endl;
    cout << "Obesidad leve: " << cOb1 << endl;
    cout << "Obesidad media: " << cOb2 << endl;
    cout << "Obesidad morbida: " << cOb3 << endl;
}

void PowerLab::listadoClientesPorSucursal() {
    int cod = leerInt("Codigo sucursal: ");
    sucursales* s = buscarSucursalPorCodigo(cod);
    if (!s) { cout << "Sucursal no encontrada." << endl; return; }
    s->listarClientes();
}
void PowerLab::detalleClienteEspecifico() {
    string ced = leerStr("Cedula cliente: ");
    cliente* c = buscarClienteGlobalPorCedula(ced);
    if (!c) { cout << "Cliente no encontrado." << endl; return; }
    cout << c->mostrarCliente() << endl;
}
void PowerLab::listadoClientesPorInstructor() {
    string ced = leerStr("Cedula instructor: ");
    instructor* ins = buscarInstructorGlobalPorCedula(ced);
    if (!ins) { cout << "Instructor no encontrado." << endl; return; }
    cout << "--- Clientes del instructor " << ins->getNombre() << " ---" << endl;
    for (int i = 0; i < _canSuc; ++i) {
        sucursales* s = _sucursales[i];
        for (int j = 0; j < s->getCanClientes(); ++j) {
            cliente* c = s->getClientes()[j];
            if (c->getInstructorCliente() == ins) {
                cout << c->mostrarCliente() << endl;
            }
        }
    }
}
void PowerLab::listadoInstructoresPorSucursal() {
    int cod = leerInt("Codigo sucursal: ");
    sucursales* s = buscarSucursalPorCodigo(cod);
    if (!s) { cout << "Sucursal no encontrada." << endl; return; }
    s->listarInstructores();
}
void PowerLab::listadoInstructoresPorEspecialidad() {
    _catalogo->mostrarEspecialidades();
    int idx = leerInt("Numero de especialidad: ");
    string* espPtr = _catalogo->getEspecialidadNombre(idx);
    if (!espPtr) { cout << "Especialidad invalida." << endl; return; }
    cout << "--- Instructores con especialidad: " << *espPtr << " ---" << endl;
    for (int i = 0; i < _canSuc; ++i) {
        sucursales* s = _sucursales[i];
        for (int j = 0; j < s->getCanInstructores(); ++j) {
            instructor* ins = s->getInstructores()[j];
            if (ins->tieneEspecialidad(espPtr)) {
                cout << ins->mostrarInstructor() << endl;
            }
        }
    }
}
void PowerLab::listarClasesPorSucursal() {
    int cod = leerInt("Codigo sucursal: ");
    sucursales* s = buscarSucursalPorCodigo(cod);
    if (!s) { cout << "Sucursal no encontrada." << endl; return; }
    s->listarClases();
}
void PowerLab::listarClasesPorCliente() {
    string ced = leerStr("Cedula cliente: ");
    cliente* c = buscarClienteGlobalPorCedula(ced);
    if (!c) { cout << "Cliente no encontrado." << endl; return; }
    c->mostrarClasesMatriculadas();
}

void PowerLab::uiListados() {
    cout << "1) Lista de clientes por sucursal" << endl;
    cout << "2) Detalle de cliente especifico" << endl;
    cout << "3) Lista de clientes por instructor" << endl;
    cout << "4) Lista de instructores por sucursal" << endl;
    cout << "5) Lista de instructores por especialidad" << endl;
    cout << "6) Clases por sucursal" << endl;
    cout << "7) Clases matriculadas por cliente" << endl;
    int op = leerInt("Opcion: ");
    switch (op) {
        case 1: listadoClientesPorSucursal(); break;
        case 2: detalleClienteEspecifico(); break;
        case 3: listadoClientesPorInstructor(); break;
        case 4: listadoInstructoresPorSucursal(); break;
        case 5: listadoInstructoresPorEspecialidad(); break;
        case 6: listarClasesPorSucursal(); break;
        case 7: listarClasesPorCliente(); break;
        default: cout << "Opcion invalida." << endl; break;
    }
}

// ========== Bucle principal ==========

void PowerLab::run() {
    int op = -1;
    do {
        cout << "\n=== PowerLab ===" << endl;
        cout << "1) Ingresar sucursal" << endl;
        cout << "2) Ingresar instructor (por sucursal)" << endl;
        cout << "3) Ingresar cliente (por sucursal)" << endl;
        cout << "4) Registrar medicion a cliente" << endl;
        cout << "5) Ver historial de mediciones de cliente" << endl;
        cout << "6) Agregar ejercicio a bateria" << endl;
        cout << "7) Generar rutina a cliente (desde bateria)" << endl;
        cout << "8) Crear clase grupal (por sucursal)" << endl;
        cout << "9) Matricular cliente en clase grupal" << endl;
        cout << "10) Reporte IMC por sucursal" << endl;
        cout << "11) Listados e informes" << endl;
        cout << "0) Salir" << endl;
        op = leerInt("Opcion: ");

        switch (op) {
            case 1: uiIngresarSucursal(); break;
            case 2: uiIngresarInstructor(); break;
            case 3: uiIngresarCliente(); break;
            case 4: uiRegistrarMedicion(); break;
            case 5: uiVerHistorialMediciones(); break;
            case 6: uiAgregarEjercicioBateria(); break;
            case 7: uiGenerarRutinaCliente(); break;
            case 8: uiCrearClaseGrupal(); break;
            case 9: uiMatricularClienteEnClase(); break;
            case 10: uiReporteIMCPorSucursal(); break;
            case 11: uiListados(); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl; break;
        }
    } while (op != 0);
}

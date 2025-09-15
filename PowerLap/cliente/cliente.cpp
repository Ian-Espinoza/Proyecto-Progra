#include "cliente.h"
cliente::cliente(double IMC,string cedula, string nombre, double peso, double altura, string telefono, string correo, string fechaNaci, char sexo, string fechaInscripció, bool esAtleta{this->cedula = cedula;this->nombre = nombre; this->telefono = telefono;this->correo = correo;this->fechaNaci = fechaNaci;this->sexo = sexo;this->fechaInscripción = fechaInscripción; this->esAtleta=esAtleta;}

double cliente::getIMC(){return IMC;}
string cliente::getCedula(){return cedula;}
string cliente::getNombre(){return nombre;}
double cliente::getPeso(){return peso;}
double cliente::getAltura(){return altura;} 
string cliente::getTelefono(){return telefono;} 
string cliente::getCorreo(){return correo;} 
string cliente::getFechaNaci() { return fechaNaci;}
char cliente::getSexo(){return sexo;} 
string cliente::getFechaInscripción(){return fechaInscripción;}
bool cliente::getEsAtleta(){return esAtleta;}

void cliente::setIMC(){this->IMC=IMC;}
void cliente::setCedula(){this->cedula=cedula;}
void cliente::setNombre(){this->nombre=nombre;}
void cliente::setPeso(){this->peso=peso;}
void cliente::setAltura(){this->altura=altura;}
void cliente::setTelefono(){this->telefono=telefono;}
void cliente::setCorreo(){this->correo=correo;}
void cliente::setFechaNaci(){this->fechaNaci=fechaNaci;}
void cliente::setSexo(){this->sexo=sexo;}
void cliente::setFechaInscripción(){this->fechaInscripción=fechaInscripción;}
void cliente::setEsAtleta(){this->esAtleta=esAtleta;}

void cliente::agregarMedicion(reporteMedicion *)
{
}

void cliente::historialPorFecha()
{
}

double cliente::calcularIMC(double peso, double altura){IMC= peso/(altura*altura);return IMC;}

string cliente::clasificarIMC(double IMC){
if (IMC<16.00){return "Delgadez severa";}
else if(IMC>=16.01 && IMC<16.99){return "delgadez moderada";}
else if(IMC>=17 && IMC<18.49){return "delgadez leve";}
else if(IMC>=18.5 && IMC<24.99){return "normal";}
else if(IMC>=25 && IMC<29.99){return "pre-sobrepeso";}
else if(IMC>=30 && IMC<34.99){return "obesidad leve";}
else if(IMC>=35 && IMC<39.99){return "obesidad media";}
else if(IMC>=40){return "obesidad morbida";}}

int cliente::recomendacionAgua(double peso){return peso*35/250;}

double cliente::recomendacionProteina(double peso, char sexo, bool esAtleta){
    if(sexo=='M' && esAtleta==true){return peso*2.0;}
    else if(sexo=='M' && esAtleta==false){return peso*0.8;}
    else if(sexo=='F' && esAtleta==true){return peso*1.6;}
    else if(sexo=='F' && esAtleta==false){return peso*0.7;}

cliente::~cliente(){
    for(int i=0; i < can;++i){
        delete medicion[i];
    }
    delete[] medicion;}
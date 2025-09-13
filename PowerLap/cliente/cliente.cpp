#include "cliente.h"
cliente::cliente(double IMC,string cedula, string nombre, double peso, double altura, string telefono, string correo, string fechaNaci, char sexo, string fechaInscripció{this->cedula = cedula;this->nombre = nombre; this->telefono = telefono;this->correo = correo;this->fechaNaci = fechaNaci;this->sexo = sexo;this->fechaInscripción = fechaInscripción;}

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

void cliente::agregarMedicion(reporteMedicion *)
{
}
void cliente::historialPorFecha()
{
}
double cliente::calcularIMC(double peso, double altura){IMC= peso/(altura*altura);return IMC;}
string cliente::clasificarIMC(double IMC)
{if (IMC<16.00){return "Delgadez severa";}else if(IMC>=16.01 && IMC<16.99){return "delgadez moderada";}
else if(IMC>=17 && IMC<18.49){return "delgadez leve";}
else if(IMC>=18.5 && IMC<24.99){return "normal";}
else if(IMC>=25 && IMC<29.99){return "pre-sobrepeso";}
else if(IMC>=30 && IMC<34.99){return "obesidad leve";}
else if(IMC>=35 && IMC<39.99){return "obesidad media";}
else if(IMC>=40){return "obesidad morbida";}
}
int cliente::recomendacionAgua(double peso)
{
}
double cliente::recomendacionProteina(double, char, bool)
{
}
cliente::~cliente()
{
}
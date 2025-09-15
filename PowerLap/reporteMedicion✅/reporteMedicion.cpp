#include"reporteMedicion.h" 

medicion::medicion(){peso=0;estatura=0;porcentajeGrasa=0;porcentajeMusculo=0;grasaViseral=0;cintura=0;cadera=0;pecho=0;muslo=0;imc=0;}

medicion::medicion(fecha fechas, float peso, float estatura, float porcentajeGrasa, float porcentajeMusculo ,float grasaViseral ,int edadMetabolica , float cintura, float cadera, float pecho, float muslo, float imc){this->fechas=fechas;this->peso=peso;this->estatura=estatura;this->porcentajeGrasa=porcentajeGrasa;this->porcentajeMusculo=porcentajeMusculo;this->grasaViseral=grasaViseral;this->edadMetabolica=edadMetabolica;this->cintura=cintura;this->cadera=cadera;this->pecho=pecho;this->muslo=muslo;this->imc=imc;}

fecha medicion::getfecha(){return fechas;}
float medicion::getPeso(){return peso;}
float medicion::getEstatura(){return estatura;}
float medicion::getPorcentajeGrasa(){return porcentajeGrasa;}
float medicion::getPorcentajeMusculo(){return porcentajeMusculo;}
float medicion::getGrasaViseral(){return grasaViseral;}
int medicion::getEdadMetabolica(){return edadMetabolica; }
float medicion::getCintura(){return cintura;}
float medicion::getCadera(){return cadera;}
float medicion::getPecho(){return pecho;}
float medicion::getMuslo(){return muslo;}
float medicion::getIMC(){return imc;}

void medicion::setFecha(fecha fechas){this->fechas=fechas;}
void medicion::setPeso(float peso){this->peso=peso;}
void medicion::setEstatura(float estatura){this->estatura=estatura;}
void medicion::setPorcentajeGrasa(float porcentajeGrasa){this->porcentajeGrasa=porcentajeGrasa;}
void medicion::setPorcentajeMusculo(float porcentajeMusculo){this->porcentajeMusculo=porcentajeMusculo;}
void medicion::setGrasaViseral(float grasaViseral){this->grasaViseral=grasaViseral;}
void medicion::setEdadMetabolica(int edadMetabolica){this->edadMetabolica=edadMetabolica;}
void medicion::setCintura(float cintura){this->cintura=cintura;}
void medicion::setCadera(float cadera){this->cadera=cadera;}
void medicion::setPecho(float pecho){this->pecho=pecho;}
void medicion::setMuslo(float muslo){this->muslo=muslo;}
void medicion::setIMC(float imc){this->imc=imc;}

float medicion::calcularIMC(){imc=peso/(estatura*estatura);return imc;}

int medicion::calcularVasosAgua(){return peso*35/250;}

string medicion::obtenerClasificacionIMC(){
    if (imc<16.00){return "Delgadez severa";}
    else if(imc>=16.01 && imc<16.99){return "delgadez moderada";}
    else if(imc>=17 && imc<18.49){return "delgadez leve";}
    else if(imc>=18.5 && imc<24.99){return "normal";}
    else if(imc>=25 && imc<29.99){return "pre-sobrepeso";}
    else if(imc>=30 && imc<34.99){return "obesidad leve";}
    else if(imc>=35 && imc<39.99){return "obesidad media";}
    else if(imc>=40){return "obesidad morbida";}
    return "";}

float medicion::calcularProteinaRequerida(char sexo, bool haceEjercicio) {
    if (!haceEjercicio) return peso * 0.8f;
    if (sexo == 'M' || sexo == 'm') return peso * 2.0f;
    if (sexo == 'F' || sexo == 'f') return peso * 1.7f;
    return peso * 0.8f;}


string medicion::tostring(){
    stringstream s;
    s<<"----------------------REPORTE DE MEDICION------------------------"<<endl;
    s<<"Fecha: "<<fechas.tostring()<<endl;
    s<<"Peso: "<<peso<<" kg"<<endl;
    s<<"Estatura: "<<estatura<<" m"<<endl;
    s<<"Porcentaje de grasa: "<<porcentajeGrasa<<" %"<<endl;
    s<<"Porcentaje de musculo: "<<porcentajeMusculo<<" %"<<endl;
    s<<"Edad Metabolica: "<<edadMetabolica<<"Anios"<<endl;
    s<<"Grasa visceral: "<<grasaViseral<<" %"<<endl;
    s<<"Cintura: "<<cintura<<" cm"<<endl;
    s<<"Cadera: "<<cadera<<" cm"<<endl;
    s<<"Pecho: "<<pecho<<" cm"<<endl;
    s<<"Muslo: "<<muslo<<" cm"<<endl;
    s<<"IMC: "<<imc<<endl;
    s<<"Clasificacion IMC: "<<obtenerClasificacionIMC()<<endl;
    s<<"Vasos de agua recomendados al dia: "<<calcularVasosAgua()<<" vasos"<<endl;
    s<<"----------------------FIN DEL REPORTE DE MEDICION--------------------"<<endl;
    return s.str();}
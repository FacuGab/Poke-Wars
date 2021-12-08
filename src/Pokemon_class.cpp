//Nombre: CLASE POKEMON

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <iomanip>
using namespace std;
#include "Pokemon_class.h"
#include "Stats_Ataques_class.h"
#include "rlutil.h"


//{ CONSTRUCTOR Y METODOS:
Pokemon::Pokemon()
{
    strcpy(_nombre, "Nada");
    _ID = 0;
    _tipo = 6;
    _vida = 0;
    _resistencia = 0;
    _ataques = NULL;
}
Pokemon::Pokemon(const char * nom, int ID, int tipo, int vida, int res, Ataque * atq)
{
    strcpy(_nombre, nom);
    _ID = ID;
    _tipo = tipo;
    _vida = vida;
    _resistencia = res;
    _ataques = atq;
}

/// METODOS:
///Mostrar
void Pokemon::Mostrar(int ps)
{
    cout << "NOMBRE: " << _nombre << endl;
    if(ps > 0){

         cout << "VIDA: ";
         rlutil::setColor(12);
         cout<< ps << endl;
         rlutil::setColor(10);
    } else {
         cout << "VIDA: ";
         rlutil::setColor(12);
         cout << "0" << endl;
         rlutil::setColor(10);
    }
    cout << "ATAQUE 1:" << _ataques[0].getNombre() << endl;
    cout << "ATAQUE 2:" << _ataques[1].getNombre() << endl;
    cout << "ATAQUE 3:" << _ataques[2].getNombre() << endl;
    cout << "ATAQUE 4:" << _ataques[3].getNombre() << endl;
}
//}

//{ GETS:
///Nombre
char* Pokemon::getNombre(){
    return _nombre;
}
///Nombre Jugador
char* Pokemon::getNombreJugador(){
    return _nombreJugador;
}
///ID
int Pokemon::getID(){
    return _ID;
}
///Tipo
int Pokemon::getTipo(){
    return _tipo;
}
///Puntos Salud
int Pokemon::getVida(){
    return _vida;
}
///Resistencia
int Pokemon::getResistencia()
{
    return _resistencia;
}
///Ataques
Ataque * Pokemon::getAtaques(){
    return _ataques;
}
//}

//{ SETS:
///Nombre
void Pokemon::setNombre(const char* cad){
    strcpy(_nombre, cad);
}
///Nombre Jugador
void Pokemon::setNombreJugador(const char* cad){
    strcpy(_nombreJugador, cad);
}
///ID
void Pokemon::setID(int num){
    _ID = num;
}
///Tipo
void Pokemon::setTipo(int num){
    _tipo = num;
}
///Puntos Salud
void Pokemon::setVida (int num){
    _vida = num;
}
///Resistencia
void Pokemon::setResistencia(int num){
    _resistencia = num;
}

///Ataque
void Pokemon::setAtaque (Ataque * atq){
    _ataques = atq;
}
//}

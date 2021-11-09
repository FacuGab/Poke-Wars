//Nombre: CLASE POKEMON

#include <iostream>
#include <clocale>
#include <cstring>
#include <stdio.h>
using namespace std;
#include "Pokemon_class.h"
#include "Stats_Ataques_class.h"

// sin uso por ahora _Estado[]
const string _Estado[7] = {"Paralisis",///-	Parálisis (causado por un ataque de tipo Eléctrico)

                            "Quemado",   ///-	Quemado (causado por un ataque de tipo Fuego)
                            "Envenenado",///-	Envenenado (causado por un ataque de tipo Bicho)
                            "Confundido",///-	Confundido (causado por un ataque de tipo Tierra)
                            "Congelado", ///-	Congelado (causado por un ataque de tipo Agua)
                            "Dormido",   ///-	Dormido (causado por un ataque de tipo Planta)
                            "Normal"};   ///-   Sin Efectos

//{ CONSTRUCTOR Y METODOS:
Pokemon::Pokemon(const char * nom, int ID, int tipo, int vida, int res, Ataque * atq)
{
    strcpy(_nombre, nom);
    _ID = ID;
    _tipo = tipo;
    _vida = vida;
    _resistencia = res;
    _ataques = atq;
    _estado = "Normal"; // sin uso por ahora
}

/// METODOS:
void Pokemon::Mostrar(int ps)
{
    cout << "Nombre: " << _nombre << endl;
    if(ps > 0) cout << "VIDA: " << ps << endl;
    else cout << "VIDA: 0 "<< endl;
    cout << "Ataques: " << _ataques[0].getNombre() << endl;
    cout << "Ataques: " << _ataques[1].getNombre() << endl;
    cout << "Ataques: " << _ataques[2].getNombre() << endl;
    cout << "Ataques: " << _ataques[3].getNombre() << endl;
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
///Estados
string Pokemon::getEstado(){
    return _estado;
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
///Estado
void Pokemon::setEstado (string str){
    _estado = str;
}
//}

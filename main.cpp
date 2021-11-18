//Nombre: PROTOTIPO 1 Juego Labo2 "-- PokeMail --"
//Comentarios:
/*
PAUTAS DE AL DEFINIR VARIALBES, OBJETOS, FUNCIONES, ETC:

- Objetos y Funciones: camelcase , PERO! los atri tienen que tener "_".

- Parametros: camelcase.

- Variables locales: sin mayuculas, sin guiones, ej: int numeroCutro, uso de camelcase !!!

*/
#include <iostream>
#include <clocale>
#include <cstring>
#include <stdio.h>
using namespace std;
#include "Pokemon_class.h"
#include "Stats_Ataques_class.h"
#include "GameLoop.h"
#include "Funciones.h"
#include "Jugador.h"

///Main de Incio
int main()
{
    setlocale(LC_ALL, "Spanish");

    /// Creamos lista de Ataques para cada Pokemon:
    /// Obs: el fasle o true de los constructores no tiene uso por ahora.
    Ataque charizardAtaques[4] = { Ataque(false, "Tacle", 50, 25, NORMAL, 95),      //pos 0
                                    Ataque(false, "Rasguño", 90, 10, FUEGO, 80),    //pos 1
                                    Ataque(false, "Vuelo", 90, 10, NORMAL, 80),     //pos 2
                                    Ataque(true, "Lanzallamas", 90, 10, FUEGO, 80)};//pos 3

    Ataque blastoiseAtaques[4] = { Ataque(false, "Cabezaso", 75, 20, NORMAL, 90),
                                    Ataque(true, "Refugio", 60, 15, AGUA, 95),
                                    Ataque(true, "Pistola de Agua", 78, 20, AGUA, 85),
                                    Ataque(true, "Hidrobomba", 92, 10, AGUA, 75)};
    /// Pokemons:
    Pokemon Charizard("Charizard", 6, FUEGO, 78, 85, charizardAtaques);
    Pokemon Blastoise("Blastoise", 9, AGUA, 80, 100, blastoiseAtaques);
    /// GamePlay
    GameLoop Main;

    // INICIO //
    ///Intro:
    intro();
    int opc;
    do
    {
        cout << endl;
        ///Menu de inicio:
        system("cls");
        cout << endl;
        gotoxy(5, 2);
        cout << "*** JUEGO POKE-WARS ***\n";
        cout << "  Ingrese Opcion: \n";
        cout << "   1- Pelea\n";
        cout << "   2- Cargar\n";
        cout << "   3- Estadisticas\n";
        cout << "   0- Salir\n";
        cuadro(1, 30, 1, 8);
        cout << endl;
        cout << "   opcion>> ";
        cin >> opc;

        switch(opc)
        {
        case 1:

            Main.gamePlay(Charizard, Blastoise);
            if(Main.getGanador() == 1) {
                cout << "Ganador Jugador !!\n";
                cout << "Sumaste 1 Punto de Batalla!\n";
            }else if (Main.getGanador() == 2) {
                cout << "Ganador Rival. Perdiste\n";
                cout << "No sumaste Puntos de Batalla\n";
            }
            break;
        case 2:
            system("cls");
            cout << "En construccion (: \n";
            break;
        case 3:
            cout << "En construccion (: \n";
            break;
        case 0:
            cout << "Salir\n";
            break;
        default:
            cout << "Comando Incorrecto\n";
            break;
        }
        system("pause");

    }while(opc != 0);

    // ----- //
    return 0;
}



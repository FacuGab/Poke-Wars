//Nombre: PROTOTIPO 1 Juego Labo2 "-- PokeMail --"
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
#include "GameLoop.h"
#include "Funciones.h"
#include "Jugador.h"


/// MAIN:
int main()
{
    setlocale(LC_ALL, "Spanish");
    /// Variables
    int opc;
    int opc2;
    bool flag = true;

    /// Jugador
    Jugador player;

    /// GamePlay
    GameLoop Main;

    /// Intro:
    //intro();

    // INICIO //
    do {
        while(flag)
        {
            /// MENU INICIAL:
            system("cls");
            gotoxy(2, 2);
            cout << " ***JUEGO POKEMAIL***\n";
            cout << "  Ingrese Opcion: \n";
            cout << "   1- Nueva Partida\n";
            cout << "   2- Cargar\n";
            cout << "   3- Creditos\n";
            cout << "   0- Salir \n";
            cuadro(1, 30, 1, 8);
            cout << endl;
            cout << "   opcion>>";
            cin >> opc2;
            switch(opc2)
            {
            case 1:
                system("cls");
                cout << endl;
                cout << "    ***CREACION DE NUEVA PARTIDA***\n";
                cout << "----------------------------------------\n";
                player.cargar();
                player.eleccion();
                cout << "------------------------------------------------------------------------------\n";
                cout << "Ya elegiste tu party! ahora planifica tu estrategia y preparate para la Lucha!\n";
                flag = false;
                break;

            case 2:
                cout << "Puntajes:\n";
                mostrarPartidasGuardadas();
                break;

            case 3:
                cout << "Sin hacer\n";
                break;

            case 0:
                cout << "Salir.\n";
                return 0;
                break;

            default:
                cout << "Opcion incorrecta.\n";
            }
            system("pause");
            /// fin menu inicial.
        }

        /// MENU SECUNDARIO:
        system("cls");
        cout << endl;
        gotoxy(5, 2);
        cout << "*** JUEGO POKE-WARS ***\n";
        cout << "  Ingrese Opcion: \n";
        cout << "   1- Pelea\n";
        cout << "   2- Estadisticas\n";
        cout << "   0- Volver\n";
        cuadro(1, 30, 1, 8);
        cout << endl;
        cout << "   opcion>> ";
        cin >> opc;

        switch(opc)
        {
        case 1:

            Main.gamePlay(player);
            if(Main.getGanador() == 1) {
                cout << "Ganador Jugador !!\n";
                cout << "Sumaste Puntos de Batalla!\n";
            } else if (Main.getGanador() == 2) {
                cout << "Ganador Rival. Perdiste\n";
                cout << "No sumaste Puntos de Batalla\n";
            }
            break;
        case 2:
            cout << "En construccion (: \n";
            break;
        case 0:
            cout << "Volver\n";
            flag = true;
            break;
        default:
            cout << "Comando Incorrecto\n";
            break;
        }
        system("pause");
        /// fin menu secundario.

    } while(true);

    // ----- //
    return 0;
}



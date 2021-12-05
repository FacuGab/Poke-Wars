//Nombre: PROTOTIPO "-- PokeWars --"
/*

INSTITUCION:
-Universidad Tecnologica Nacional

MATERIA:
- Laboratorio 2 de Programacion 2do cuatrimestre

INTEGRANTES:
- Facundo Gabriel Amarilla
- Gaston
- Roberto

*/

#include <iostream>
#include <clocale>
#include <cstring>
#include <stdio.h>
using namespace std;
#include "GameLoop.h"
#include "Funciones.h"
#include "Jugador.h"
#include "Lideres.h"

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

    /// Lideres
    Lideres uno;

    /// Intro
    //intro();

    // INICIO //
    do {
        while(flag)
        {
            /// MENU INICIAL:
            system("cls");
            gotoxy(2, 2);
            cout << " ***JUEGO POKEMAIL***\n";
            cout << "  INGRESE OPCION: \n";
            cout << "   1- NUEVA PARTIDA\n";
            cout << "   2- VER PUNTAJES\n";
            cout << "   3- LIDERES DE GIMNASIO\n";
            cout << "   0- SALIR\n";
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
                system("cls");
                cout << "Puntajes:\n";
                mostrarPartidasGuardadas();
                break;

            case 3:
                system("cls");
                cout << "Comprueba si tus puntos se comparan a los grandes lideres de gimnacio!\n";
                system("pause");
                uno.listarLider(&uno);
                break;

            case 0:
                cout << "SALIR.\n";
                return 0;
                break;

            default:
                cout << "OPCION INCORRECTA.\n";
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
        cout << "   2- Tus Pokemon Elegidos\n";
        cout << "   3- Estadisticas Pokedex\n";
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
            }else{
                cout << "No hay ganador\n";
            }
            break;

        case 2:
            player.estadisticaParty();
            break;

        case 3:
            player.estadisticaPokedex();
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



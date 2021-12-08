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
#include "rlutil.h"
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
    Lideres reg;
    rlutil::setColor(15);

    /// Intro
    //intro();

    // INICIO //
    do {
        while(flag)
        {
            /// MENU INICIAL:
            system("cls");
            gotoxy(3, 3);
            rlutil::setColor(14);
            cout << "   ***JUEGO POKEMAIL***\n";
            rlutil::setColor(10);

            cout << "  INGRESE OPCION: \n";
            cout << "   1- NUEVA PARTIDA\n";
            cout << "   2- VER PUNTAJES\n";
            cout << "   3- LIDERES DE GIMNASIO\n";
            cout << "   0- SALIR\n";
            cuadro(1, 30, 1, 9);
            cout << endl;
            rlutil::setColor(10);
            cout << "   opcion>>";
            rlutil::setColor(15);
            cin >> opc2;
            rlutil::setColor(10);
            switch(opc2)
            {
            case 1:
                system("cls");
                cout << endl;
                rlutil::setColor(14);
                cout << "    ***CREACION DE NUEVA PARTIDA***\n";
                rlutil::setColor(10);
                cout << "----------------------------------------\n";
                player.cargar();
                player.eleccion();
                cout << "------------------------------------------------------------------------------\n";
                rlutil::setColor(15);
                cout << "Ya elegiste tu party! ahora planifica tu estrategia y preparate para la Lucha!\n";
                flag = false;
                break;

            case 2:
                system("cls");
                rlutil::setColor(14);
                cout << "Puntajes:\n";
                rlutil::setColor(10);
                mostrarPartidasGuardadas();
                break;

            case 3:
                system("cls");
                rlutil::setColor(14);
                cout << "COMPRUEBA SI TUS PUNTOS SE COMPARAN A LOS GRANDES LIDERES DE GIMNASIO!\n";
                rlutil::setColor(10);
                system("pause");
                reg.listarLider(&reg);
                break;

            case 0:

                cout << "SALIR.\n";
                rlutil::setColor(15);
                return 0;
                break;

            default:
                cout << "OPCION INCORRECTA.\n";
            }
            rlutil::anykey();
            /// fin menu inicial.
        }

        /// MENU SECUNDARIO:
        system("cls");
        cout << endl;
        gotoxy(5, 2);
        rlutil::setColor(14);
        cout << "*** JUEGO POKE-WARS ***\n";
        rlutil::setColor(10);
        cout << "  Ingrese Opcion: \n";
        cout << "   1- Pelea\n";
        cout << "   2- Tus Pokemon Elegidos\n";
        cout << "   3- Estadisticas Pokedex\n";
        cout << "   0- Volver\n";
        cuadro(1, 30, 1, 8);
        cout << endl;
        cout << "   opcion>> ";
        rlutil::setColor(15);
        cin >> opc;
        rlutil::setColor(10);
        switch(opc)
        {
        case 1:
            Main.gamePlay(player);
            cout << "Fin de Batallas!, ve a mirar la cantidad de puntos que acumulaste!\n";
            cout << "Puntos: " << player.getPuntaje() << endl;
            player.reseteo();
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



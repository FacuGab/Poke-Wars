//Nombre: GameLoop
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
#include "GameLoop.h"
#include "Funciones.h"
#include "Utiles.h"


//{ Constructor y Destructor (sin usos por ahora):
GameLoop::GameLoop()
{
    //ctor
}

GameLoop::~GameLoop()
{
    //dtor
}
//}

//{ Metodos:

/// LOOP DE BATALLA
void GameLoop::gamePlay(Pokemon &pok1, Pokemon &pok2) // GamePlay de batalla
{
    ///Variables Locales
    srand (time(NULL));
    _pkJugador = &pok1;
    _pkRival = &pok2;
    ///_vidaPkJugador = _pkJugador->getVida(); // reemplazar a vidaJugador ¿?
    ///_vidaPkRival = _pkRival->getVida(); // reemplazar a vidaRival ¿?
    bool golpeo = false;
    int vidaJugador = _pkJugador->getVida();
    int vidaRival = _pkRival->getVida();
    int quit = 1;

    // Loop:
    while(quit != 0) {

        /// MENU DE BATALLA CON LOS STATS
        system("cls");
        cout << "\t BATALLA: \n";
        cout << "============================\n";
        cout << "Jugador 1\n";
        _pkJugador->Mostrar(vidaJugador);
        cout << endl;
        cout << "----------------------------\n";
        cout << "Enemigo\n";
        _pkRival->Mostrar(vidaRival);
        cout << endl;
        cout << "----------------------------\n";
        cout << "OPCIONES: \n";
        cout << " 1- Atacar\n 2- Pasar Turno\n 0- Salir\n";

        /// ASIGNAMOS TURNO:
        switch( asignarTurno() ) {
        /// TURNO JUGADOR:
        case 1:
            cout << "····Turno Jugador····\n";
            setInput(); /// Input de Jugador
            if (_input == 0) {
                quit = 0;
            } else if (_input == 1) {
                ataquesJugador(vidaRival); /// Seleccion de Ataque y daño
            }
            break;
        /// TURNO RIVAL:
        case 0:
            cout << "····Turno Rival····\n";
            Sleep(500);
            ataquesRival(vidaJugador); /// Ataque de rival y daño
            break;
        }
        /// CONTROLAMOS VIDA Y SI DA TRUE, CONTROLAMOS QUIEN GANA Y SI CONTINUAN LOS COMBATES
        if ( controlVida( vidaJugador, vidaRival ) ) {
            if(vidaJugador <= 0) {
                cout << "Pokemon de Jugador debilitado!!\n";
                cout << "GANADOR: Rival!\n";

            }
            if(vidaRival <= 0) {
                cout << "Pokemon de Rival debilitado!!\n";
                cout << "GANADOR: Jugador!\n";
            }
            Sleep(500);
            /// PREGUNTAMOS SI QUEREMOS CONTINUAR LA BATALLA UNA VEZ QUE UN JUGADOR PIERDE
            siguienteBatalla(vidaJugador, vidaRival, quit);
            /// MEDIANTE EL METODO siguienteBatalla(), tambien nos permite elegir otro pokemon (solo como ejemplo x ahora)
        }
        system("pause");
        _loop ++;
    }
    // fin de loop

    system("cls");
    gotoxy(2, 2);
    cout << "########################\n\n";
    cout << "  RESULTADO: \n";
    cout << "  Jugador 1\n";
    cout << "  Nombre: " << _pkJugador->getNombre() << endl;
    cout << "  Vida Final: ";
    if(vidaJugador < 0) cout << "0\n";
    else cout << vidaJugador << endl;
    cout << endl;
    cout << "  Enemigo\n";
    cout << "  Nombre: " << _pkRival->getNombre() << endl;
    cout << "  Vida final: ";
    if(vidaRival < 0) cout << "0\n";
    else cout << vidaRival << endl;
    cout << endl;
    cuadro(1, 25, 1, 13);
    cout << endl;
    system("pause");
}

/// CONTROL DE VIDA
bool GameLoop::controlVida(int p_vidaJugador, int p_vidaRival)
{
    if (p_vidaJugador <= 0) {
        _ganador = 2;
        return true;
    } else if (p_vidaRival <= 0) {
        _ganador = 1;
        return true;
    } else {
        return false;
    }
}

/// CONTROL DE SIGUIR LA BATALLA
void GameLoop::siguienteBatalla(int &vidaJugador, int &vidaRival, int &quit)
{
    do {
        cout << endl;
        cout << "Batalla terminada.\n";
        cout << "Que desea hacer??\n";
        cout << "1- Continuar Batalla\n";
        cout << "2- Salir de Batalla\n";
        setInput();
        switch(getInput()) {
        case 1:
            /// ·····································
            /// Funcion o Metodo de eleccion de otro pokemon al que se puede acceder iria aca¿?
            /// Ej: redefinir con otro pokemon a eleccion los punteros _pkJugador y _pkRival
            /*
            Ejemplo de forma de eleccioon de otro pokemon tiene usando un vector para la elecion.
            */
            /// Ejemplo:
            system("cls");
            int opc;
            cout << "Siguente Batalla!\n";
            cout << "Elige un pokemon:\n";
            /// Aca puede ir una lista mostrada con una funcion o metodo
            cout << "1- Bulbasuar\n";
            cout << "2- Charmander\n";
            cout << "3- Squirtle\n";
            cout << "4- Pikachu\n";
            cout << ">>";
            cin >> opc;
            switch (opc)
            {
            case 1:
                cout << "Bulbasaur Elegido!\n";
                _pkJugador = &pokedex[0];
                break;
            case 2:
                cout << "Charmander Elegido!\n";
                _pkJugador = &pokedex[1];
                break;
            case 3:
                cout << "Squirtle Elegido!\n";
                _pkJugador = &pokedex[2];
                break;
            case 4:
                cout << "Pikachu Elegido!\n";
                _pkJugador = &pokedex[3];
                break;
            }
            /// ·····································
            vidaJugador = _pkJugador->getVida();
            vidaRival = _pkRival->getVida();
            _loop = -1;
            break;
        case 2:
            quit = 0;
            cout << "Fin de batalla\n";
            break;
        default:
            cout << "Opcion Incorrecta\n";
            system("pause");
            system("cls");
            break;
        }

    } while(getInput() != 1 && getInput() != 2);
}

/// CONTROL DE TURNO
int GameLoop::asignarTurno()
{
    if(_loop % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

/// CALCULAR DAÑO
int GameLoop::calcularDanio(int danio, int defensa)
{

    int calculo;
    float aleatorio = (rand() % 100 + 1);
    aleatorio = aleatorio/100;
    cout << "Coeficiente aleatorio: " << aleatorio << endl;
    ///cout << aleatorio << endl;
    calculo = (danio /*-(aleatorio*10))*/ - (defensa * aleatorio));
    cout << "calculo de defnesa: "<< (defensa*aleatorio) << endl;
    cout << "calculo de potencia: "<< (danio -(aleatorio*10)) << endl;
    cout << "pre-daño: " << calculo << endl;
    if( calculo > 10 ) {
        return calculo;
    } else {
        return 0;
    }
}

/// MOSTRAR Y ELEGIR ATAQUES JUGADOR
void GameLoop::ataquesJugador(int &vidaPokRival)
{
    cout << "Ataques de " << _pkJugador->getNombre() << endl;
    cout << "1- "<< _pkJugador->getAtaques()[0].getNombre() << endl;
    cout << "2- "<< _pkJugador->getAtaques()[1].getNombre() << endl;
    cout << "3- "<< _pkJugador->getAtaques()[2].getNombre() << endl;
    cout << "4- "<< _pkJugador->getAtaques()[3].getNombre() << endl;
    setInput();
    switch(_input) {
    case 1:
        cout <<_pkJugador->getAtaques()[0].getNombre() <<", Potencia: "<< _pkJugador->getAtaques()[0].getPotencia()<<endl;
        _damage = calcularDanio( _pkJugador->getAtaques()[0].getPotencia(), _pkRival->getResistencia());
        break;
    case 2:
        cout <<_pkJugador->getAtaques()[1].getNombre() <<", Potencia: "<< _pkJugador->getAtaques()[1].getPotencia()<<endl;
        _damage = calcularDanio( _pkJugador->getAtaques()[1].getPotencia(),  _pkRival->getResistencia());
        break;
    case 3:
        cout <<_pkJugador->getAtaques()[2].getNombre() <<", Potencia: "<< _pkJugador->getAtaques()[2].getPotencia()<<endl;
        _damage = calcularDanio( _pkJugador->getAtaques()[2].getPotencia(),  _pkRival->getResistencia());
        break;
    case 4:
        cout <<_pkJugador->getAtaques()[3].getNombre() <<", Potencia: "<< _pkJugador->getAtaques()[3].getPotencia()<<endl;
        _damage = calcularDanio( _pkJugador->getAtaques()[3].getPotencia(),  _pkRival->getResistencia());
        break;
    }

    Sleep(400);
    if( _damage > 0 ) {
        vidaPokRival -= _damage;
        cout << "Daño causado por Pokemon de Jugador: " << _damage << endl;
    } else {
        cout << "No causo Daño el ataque de Pokemon Jugador.\n";
    }
}

/// ELEGIR ATAQUES RIVAL
void GameLoop::ataquesRival(int &vidaPokJugador)
{
    int aleatorio = (rand() % 4 + 1);
    _input = aleatorio;
    switch(_input) {
    case 1:
        _damage = calcularDanio( _pkRival->getAtaques()[0].getPotencia(), _pkJugador->getResistencia());
        cout << "Ataque usado por Pokemon Rival: " << _pkRival->getAtaques()[0].getNombre() << endl;
        break;
    case 2:
        _damage = calcularDanio( _pkRival->getAtaques()[1].getPotencia(),  _pkJugador->getResistencia());
        cout << "Ataque usado por Pokemon Rival: " << _pkRival->getAtaques()[1].getNombre() << endl;
        break;
    case 3:
        _damage = calcularDanio( _pkRival->getAtaques()[2].getPotencia(),  _pkJugador->getResistencia());
        cout << "Ataque usado por Pokemon Rival: " << _pkRival->getAtaques()[2].getNombre() << endl;
        break;
    case 4:
        _damage = calcularDanio( _pkRival->getAtaques()[3].getPotencia(),  _pkJugador->getResistencia());
        cout << "Ataque usado por Pokemon Rival: " << _pkRival->getAtaques()[3].getNombre() << endl;
        break;
    }

    Sleep(400);
    if( _damage > 0 ) {
        vidaPokJugador -= _damage;
        cout << "Daño causado por Pokemon de Rival: " << _damage << endl;
    } else {
        cout << "No causo Daño el ataque de Pokemon Rival.\n";
    }
}

//}

//{ Gest y Sets
/// Set Input
void GameLoop::setInput()
{
    cout << ">>";
    cin >> _input;
}
/// Get Ganador
int GameLoop::getGanador()
{
    return _ganador;
}
int GameLoop::getInput()
{
    return _input;
}
//}


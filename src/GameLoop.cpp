//Nombre: GameLoop
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
#include "GameLoop.h"


//{ Constructor y Destructor:
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
    int vidaJugador = _pkJugador->getVida();
    int vidaRival = _pkRival->getVida();
    int quit = 1;

    //Loop:
    while(quit != 0)
    {
        system("cls");
        cout << "Batalla: \n";
        cout << "Jugador 1\n";
        _pkJugador->Mostrar(vidaJugador);
        cout << endl;
        cout << "Enemigo\n";
        _pkRival->Mostrar(vidaRival);
        cout << endl;
        cout << "OPCIONES: \n";
        cout << " 1- Atacar\n 2- Pasar Turno\n 0- Salir\n";

        /// ASIGNAMOS TURNO:
        switch( asignarTurno() )
        {
           /// TURNO JUGADOR:
        case 1:
            cout << "Turno Jugador\n";
            setInput(); /// Input de Jugador
            if (_input == 0) {
                quit = 0;
            } else if (_input == 1) {

                ataquesJugador(vidaRival); /// Seleccion de Ataque y daño
            }
            break;

           /// TURNO RIVAL:
        case 0:
            cout << "Turno Rival\n";
            Sleep(500);
            ataquesRival(vidaJugador); /// Ataque de rival y daño
            break;
        }
        /// CONTROLAMOS VIDA
        if ( controlVida( vidaJugador, vidaRival ) ) {
            if(vidaJugador <= 0) cout << "Pokemon de Jugador debilitado!!\n";
            if(vidaRival <= 0) cout << "Pokemon de Rival debilitado!!\n";
            Sleep(500);
            cout << "Batalla terminada.\n";
            quit = 0;
        }
        system("pause");
        _loop ++;

    }
    // fin de loop

    system("cls");
    cout << "########################\n";
    cout << "Resultado de la Batalla: \n";
    cout << "Jugador 1\n";
    pok1.Mostrar(vidaJugador);
    cout << endl;
    cout << "Enemigo\n";
    pok2.Mostrar(vidaRival);
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
    float aleatorio = (rand() % defensa + 1);
    aleatorio = aleatorio/100;
    cout << "Coeficiente aleatorio: " << aleatorio << endl;
    ///cout << aleatorio << endl;
    calculo = (danio -(aleatorio*10)) - (defensa * aleatorio);
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
//}


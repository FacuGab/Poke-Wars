//Nombre: GameLoop
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
#include "Jugador.h"
#include "GameLoop.h"
#include "Funciones.h"

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
void GameLoop::gamePlay(Jugador& jugador) // GamePlay de batalla
{
    ///Variables Locales
    srand (time(NULL));
    _pkJugador = &jugador.getPokemon(0);
    _pkRival = &jugador.getRival(5);
    jugador.setNombrePokemon(_pkJugador->getNombre());
    int vidaJugador = _pkJugador->getVida();
    int vidaRival = _pkRival->getVida();
    int vidaRivalInicial = vidaRival;
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
        if ( controlVida(vidaJugador, vidaRival) ) {
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
            siguienteBatalla(vidaJugador, vidaRival, quit, jugador, vidaRivalInicial);
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
void GameLoop::siguienteBatalla(int &vidaJugador, int &vidaRival, int &quit, Jugador &jugador, int vidaRivalInicio)
{
    do {
        cout << endl;
        cout << "Batalla terminada.\n";
        cout << "Que desea hacer??\n";
        cout << "1- Continuar Batalla\n";
        cout << "2- Salir de Batalla\n";
        setInput();
        switch(getInput())
        {
        case 1:
            /// ·····································
            /// Elegimos otro pokemon para continuar la batalla de los que tenemos
            system("cls");
            int opc;
            cout << "Siguente Batalla!\n";
            cout << "Elige un pokemon:\n";
            for(int i = 0; i < 4; i++) cout<< i+1 <<" - "<< jugador.getPokemon(i).getNombre()<<endl;
            cout << "Ingresa una opcion del 1 al 4 para elegir\n";
            cout << ">>";
            cin >> opc; // cuidado, no contempla que eligas un pokemon fuera del vector o vacio
            switch (opc)
            {
            case 1:
                _pkJugador = &jugador.getPokemon(opc-1);
                cout << _pkJugador->getNombre() << " elegido !!\n";
                break;
            case 2:
                _pkJugador = &jugador.getPokemon(opc-1);
                cout << _pkJugador->getNombre() << " elegido !!\n";
                break;
            case 3:
                _pkJugador = &jugador.getPokemon(opc-1);
                cout << _pkJugador->getNombre() << " elegido !!\n";
                break;
            case 4:
                _pkJugador = &jugador.getPokemon(opc-1);
                cout << _pkJugador->getNombre() << " elegido !!\n";
                break;
            }
            /// ·····································
            /// Cargamos la vida del pokemon jugador para la siguiente lucha
            vidaJugador = _pkJugador->getVida();
            /// Seleccionamos un nuevo rival para la lucha
            _pkRival = &jugador.getRival(rand() % 6 + 1);
            vidaRival = _pkRival->getVida();
            _loop = -1;
            break;

        case 2:{
            int puntajeFinal = calcularPuntaje(vidaRivalInicio, vidaRival, jugador.getPuntaje());
            if(guardarPartidaFinalizada(jugador.getNombreJugador(), jugador.getNombrePokemon(), puntajeFinal)){
                cout << "Partida Guardada Exitosamente\n";
            } else {
                cout << "Error al guardar la partida\n";
            }
            quit = 0;
            cout << "Fin de batalla\n";
            break;
            }
        default:{
            cout << "Opcion Incorrecta\n";
            system("pause");
            system("cls");
            break;
            }
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

/// CALCULAR PUNTAJE:
int GameLoop::calcularPuntaje(int vidaRivalSano, int vidaRival, int puntos)
{
    cout<< "***************"<<endl;
    cout<< "vida del Rival Inicial: "<< vidaRivalSano <<endl;
    cout<< "vida del Rival Restante: "<< vidaRival <<endl;
    cout<< "***************"<<endl;

    if(vidaRival <= 0)
    {
        puntos = vidaRivalSano;
    }
    else
    {
        puntos = vidaRivalSano - vidaRival;
    }   ///arreglar la vida extra <0
    cout<< "*************************************"<<endl;
    cout << "Puntaje obtenido en esta batalla: " << puntos <<endl;
    cout<< "*************************************"<<endl;
    return puntos;
}

/// GUARDAR PARTIDA:
bool GameLoop::guardarPartidaFinalizada(const char* nJug, const char *nPk, int puntos)
{
    Jugador aux(nJug, nPk, puntos);
    /*
    aux.setNombreJugador(nJug);
    aux.setNombrePokemon(nPk);
    aux.setPuntaje(puntos);
    */
    return aux.guardarPartida();
}

//}

//{ Gest y Sets
/// Set Input
void GameLoop::setInput()
{
    cout << ">>";
    cin >> _input;
}
/// Get Input:
int GameLoop::getInput()
{
    return _input;
}
/// Get Ganador:
int GameLoop::getGanador()
{
    return _ganador;
}

//}


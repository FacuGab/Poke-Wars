//Nombre: GameLoop
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
#include "Jugador.h"
#include "GameLoop.h"
#include "Funciones.h"
#include "rlutil.h"


//{ Metodos:

/// LOOP DE BATALLA
void GameLoop::gamePlay(Jugador& jugador) // GamePlay de batalla
{
    /// VARIABLES LOCALES:
    srand (time(NULL));
    for(int i = 0; i < 4; i++) {jugador.setEstado(i, true);} /// Ponemos todos los pokemons disponibles al inicio de un loop de batalla
    _pkJugador = &jugador.getPokemon(0);
    _pkRival = &jugador.getRival(rand() % 9);
    _ganador = -1;
    _loop = 0;
    jugador.setNombrePokemon(_pkJugador->getNombre());
    int vidaJugador = _pkJugador->getVida();
    int vidaRival = _pkRival->getVida();
    int vidaRivalInicial = vidaRival;
    int quit = 1;
    int posPoke = 0;
    int cantVictoria = 0;
    int puntaje = 0;
    bool flagIntro = true;

    /// INTRO BATALLA
    introBatalla(flagIntro);

    // Loop:
    while(quit != 0) {

        /// MENU DE BATALLA CON LOS STATS
        system("cls");
        rlutil::setColor(14);
        cout << "\t BATALLA: \n";
        rlutil::setColor(10);
        cout << "============================\n";
        rlutil::setColor(3);
        cout << jugador.getNombreJugador() << endl;
        rlutil::setColor(10);
        _pkJugador->Mostrar(vidaJugador);
        cout << endl;
        cout << "----------------------------\n";
        cout << "Enemigo\n";
        _pkRival->Mostrar(vidaRival);
        cout << endl;
        cout << "----------------------------\n";
        cout << "OPCIONES: \n";
        rlutil::setColor(15);
        cout << " 1- Atacar\n 2- Pasar Turno\n 0- Salir\n";
        rlutil::setColor(10);

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
            } else {
                cout << "Opcion Incorrecta, turno perdido!\n";
            }

            break;
          /// TURNO RIVAL:
        case 0:
            cout << endl;
            cout << "····Turno Rival····\n";
            Sleep(500);
            ataquesRival(vidaJugador); /// Ataque de rival y daño
            break;
        }
        /// CONTROLAMOS VIDA Y SI DA TRUE, CONTROLAMOS QUIEN GANA Y SI CONTINUAN LOS COMBATES
        if ( controlVida( vidaJugador, vidaRival ) ) {

            cout << "=========================\n";
            if(vidaJugador <= 0) {
                jugador.setEstado(posPoke, false);
                rlutil::setColor(15);
                cout << "Pokemon de Jugador debilitado!!\n";
                cout << "GANADOR: Rival!\n";
            }
            if(vidaRival <= 0) {
                rlutil::setColor(15);
                cout << "Pokemon de Rival debilitado!!\n";
                cout << "GANADOR: " << jugador.getNombreJugador() << endl;
                cantVictoria ++;
            }
            Sleep(500);
                /// PREGUNTAMOS SI QUEREMOS CONTINUAR LA BATALLA UNA VEZ QUE UN JUGADOR PIERDE
                /// MEDIANTE EL METODO siguienteBatalla(), podemos elegir otro pokemon si quremos continuar la batallas
            if(vidaRival < 0) vidaRival = 0;
            siguienteBatalla(vidaJugador, vidaRival, quit, jugador, vidaRivalInicial, posPoke, puntaje);
        }
        rlutil::anykey();
        _loop ++;
    }
    // fin de loop

    system("cls");
    gotoxy(2, 2);
    cout << "#########################\n\n";
    rlutil::setColor(15);
    cout << " RESULTADOS: \n";
    cout << " JUGADOR: " << jugador.getNombreJugador() << endl;
    cout << " Cantidad de Victorias: " << cantVictoria << endl;
    cout << endl;
    rlutil::setColor(10);
    cuadro(1, 27, 1, 8);
    cout << endl;
    rlutil::anykey();
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
void GameLoop::siguienteBatalla(int &vidaJugador, int &vidaRival, int &quit, Jugador &jugador, int vidaRivalInicio, int &pos, int &puntaje)
{
    bool flagPuntaje = true;
    bool flag = true;

    do {
        cout << endl;
        rlutil::setColor(14);
        cout << "Puntos al inicio de la batalla: " << puntaje << endl;
        cout << "Batalla terminada.\n";
        rlutil::anykey();
        if(flagPuntaje) {
            rlutil::setColor(15);
            puntaje = calcularPuntaje(vidaRivalInicio, vidaRival, puntaje);
            flagPuntaje = false;
        }
        rlutil::setColor(10);
        cout << "Que desea hacer??\n";
        cout << "1- Continuar Batalla\n";
        cout << "2- Salir de Batalla\n";
        setInput();

        switch(getInput())
        {
        case 1:{
            /// ·····································
            /// Elegimos otro pokemon para continuar la batalla de los que tenemos
            system("cls");
            int opc;
            cout << "Siguente Batalla!\n";
            cout << "Elige un pokemon:\n";
            rlutil::setColor(15);
            for(int i = 0; i < 4; i++) { cout<< i+1 <<" - "<< jugador.getPokemon(i).getNombre()<<endl; }
            rlutil::setColor(10);
            cout << "Ingresa una opcion del 1 al 4 para elegir\n";
            cout << ">>";
            rlutil::setColor(15);
            cin >> opc;
            rlutil::setColor(10);

            /// seleccionar otro pokemon que no este debil
            if(opc > 0 && opc < 5){
                if(jugador.getEstado(opc-1) == false){
                    cout << "Pokemon Debilitado, elige otro\n";
                    system("pause");
                } else {
                    if(jugador.getPokemon(opc-1).getID() > 0) {
                        _pkJugador = &jugador.getPokemon(opc-1);
                        pos = opc - 1;
                        cout << _pkJugador->getNombre() << " elegido !!\n";

                        /// Cargamos la vida del pokemon jugador para la siguiente lucha
                        vidaJugador = _pkJugador->getVida();

                        /// Seleccionamos un nuevo rival para la lucha
                        _pkRival = &jugador.getRival(rand() % 9);
                        vidaRival = _pkRival->getVida();
                        _loop = -1;
                        flag = false;
                    } else {
                        cout << "No hay Pokemons en la opcion elegida!\n";
                        system("pause");
                    }

                }
            } else {
                cout << "Opcion Incorrecta\n";
                system("pause");
                system("cls");
            }
            break;
        }
        case 2:{
            system("cls");
            cout << "Puntos antes de guardar: " << puntaje << endl;
            if(guardarPartidaFinalizada(jugador.getNombreJugador(), jugador.getNombrePokemon(), puntaje)){
                    cout << "Partida Guardada Exitosamente\n";
                    jugador.setPuntaje(puntaje);
                } else {
                    cout << "Error al guardar la partida\n";
                }
            quit = 0;
            cout << "Fin de batalla\n";
            flag = false;
            break;
            }
        default:{
            cout << "Opcion Incorrecta\n";
            system("pause");
            system("cls");
            break;
            }
        }

    } while(flag);
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
int GameLoop::calcularDanio(int danio, int defensa, int pres)
{
    int calculo;
    int calculoFinal;
    float aleatorio = (rand() % 100 + 1);
    cout << endl;
    rlutil::setColor(14);
    cout << " ######·CALCULANDO·######\n";
    rlutil::setColor(10);
    Sleep(1000);
    int defAleatorea = (rand() % 20 + 1);
    cout << "Aleatorio: " << aleatorio << endl;
    if( pres > aleatorio ) {
        aleatorio = aleatorio/100;
        calculo = (danio - ((defensa * aleatorio) + defAleatorea));
        cout << "Potencia: " << danio << endl;
        cout << "Defensa: " << defensa << endl;
        cout << "Coeficiente aleatorio: " << aleatorio << endl;
        cout << "calculo de defnesa final: " << (defensa * aleatorio) + defAleatorea << endl;
        cout << "pre-daño: " << calculo << endl;
        calculoFinal = tipoDanio(calculo); /// buscamos si hay mas daño por tipo
        cout << "daño final: " << calculoFinal << endl;
        if( calculoFinal > 0 ) {
            return calculoFinal;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

/// TIPO DAÑO
int GameLoop::tipoDanio(int preDanio)
{
    /*
    FUEGO     = 0, fuerte contra planta
    AGUA      = 1, fuerte contra fuego
    PLANTA    = 2, fuerte contra agua
    ELECTRICO = 3, fuerte contra agua
    BICHO     = 4, fuerte contra planta
    TIERRA    = 5, fuerte contra electrico
    NORMAL    = 6  fuerte contra tierra
    */
    int tipoRival;
    int tipoAtaque;

    if(asignarTurno() == 0){
        tipoRival = _pkRival->getTipo();
        tipoAtaque = _pkJugador->getAtaques()[getInput()-1].getTipo();
    }else if (asignarTurno() == 1){
        tipoRival = _pkJugador->getTipo();
        tipoAtaque = _pkRival->getAtaques()[getInput()-1].getTipo();
    }

    if(tipoRival == 0 && tipoAtaque == 1) {
        cout << "Es super efectivo!\n";
        return preDanio*2;
    }
    if(tipoRival == 1 && tipoAtaque == 2) {
        cout << "Es super efectivo!\n";
        return preDanio*2;
    }
    if(tipoRival == 2 && tipoAtaque == 0) {
        cout << "Es super efectivo!\n";
        return preDanio*2;
    }
    if(tipoRival == 3 && tipoAtaque == 5) {
        cout << "Es super efectivo!\n";
        return preDanio*2;
    }
    if(tipoRival == 4 && tipoAtaque == 2) {
        cout << "Es super efectivo!\n";
        return preDanio*2;
    }
    if(tipoRival == 5 && tipoAtaque == 6) {
        cout << "Es super efectivo!\n";
        return preDanio*2;
    }
    if(tipoRival == 6 && tipoAtaque == 6) {
        cout << "Es super efectivo!\n";
        return preDanio*2;
    }

    return preDanio;
}

/// MOSTRAR Y ELEGIR ATAQUES JUGADOR
void GameLoop::ataquesJugador(int &vidaPokRival)
{
    _damage = 0;
    int pp;
    rlutil::setColor(15);
    cout << "Ataques de " << _pkJugador->getNombre() << endl;
    cout << "1- "<< _pkJugador->getAtaques()[0].getNombre() << endl;
    cout << "2- "<< _pkJugador->getAtaques()[1].getNombre() << endl;
    cout << "3- "<< _pkJugador->getAtaques()[2].getNombre() << endl;
    cout << "4- "<< _pkJugador->getAtaques()[3].getNombre() << endl;
    rlutil::setColor(10);
    setInput();
    switch(_input)
    {
    case 1:
        if(_pkJugador->getAtaques()[0].getPP() > 0) {
            cout <<" ATAQUE: " << _pkJugador->getAtaques()[0].getNombre() << endl;
            cout <<" Potencia: " << _pkJugador->getAtaques()[0].getPotencia() <<endl;
            cout <<" Puntos de Ataque: " << _pkJugador->getAtaques()[0].getPP() <<endl;
            cout <<" Precision: " << _pkJugador->getAtaques()[0].getPrec() <<endl;
            cout <<" Descripcion: " << _pkJugador->getAtaques()[0].getDesc() <<endl;
            _damage = calcularDanio( _pkJugador->getAtaques()[0].getPotencia(), _pkRival->getResistencia(), _pkJugador->getAtaques()[0].getPrec() );
            pp = _pkJugador->getAtaques()[0].getPP();
            pp--;
            _pkJugador->getAtaques()[0].setPP(pp);
        } else {
            cout << "No quedan Puntos de Ataque para realizar el movimiento.\n";
        }
        break;

    case 2:
       if(_pkJugador->getAtaques()[1].getPP() > 0) {
            cout <<" ATAQUE: " << _pkJugador->getAtaques()[1].getNombre() << endl;
            cout <<" Potencia: "<< _pkJugador->getAtaques()[1].getPotencia() <<endl;
            cout <<" Puntos de Ataque: "<< _pkJugador->getAtaques()[1].getPP() <<endl;
            cout <<" Precision: "<< _pkJugador->getAtaques()[1].getPrec() <<endl;
            cout <<" Descripcion: "<< _pkJugador->getAtaques()[1].getDesc() <<endl;
            _damage = calcularDanio( _pkJugador->getAtaques()[1].getPotencia(), _pkRival->getResistencia(), _pkJugador->getAtaques()[1].getPrec() );
            pp = _pkJugador->getAtaques()[1].getPP();
            pp--;
            _pkJugador->getAtaques()[1].setPP(pp);
        } else {
            cout << "No quedan Puntos de Ataque para realizar el movimiento.\n";
        }
        break;

    case 3:
        if(_pkJugador->getAtaques()[2].getPP() > 0) {
            cout <<" ATAQUE: " << _pkJugador->getAtaques()[2].getNombre() << endl;
            cout <<" Potencia: "<< _pkJugador->getAtaques()[2].getPotencia() <<endl;
            cout <<" Puntos de Ataque: "<< _pkJugador->getAtaques()[2].getPP() <<endl;
            cout <<" Precision: "<< _pkJugador->getAtaques()[2].getPrec() <<endl;
            cout <<" Descripcion: "<< _pkJugador->getAtaques()[2].getDesc() <<endl;
            _damage = calcularDanio( _pkJugador->getAtaques()[2].getPotencia(), _pkRival->getResistencia(), _pkJugador->getAtaques()[2].getPrec() );
            pp = _pkJugador->getAtaques()[2].getPP();
            pp--;
            _pkJugador->getAtaques()[2].setPP(pp);
        } else {
            cout << "No quedan Puntos de Ataque para realizar el movimiento.\n";
        }
        break;

    case 4:
        if(_pkJugador->getAtaques()[3].getPP() > 0) {
            cout <<" ATAQUE: " << _pkJugador->getAtaques()[3].getNombre() << endl;
            cout <<" Potencia: "<< _pkJugador->getAtaques()[3].getPotencia() <<endl;
            cout <<" Puntos de Ataque: "<< _pkJugador->getAtaques()[3].getPP() <<endl;
            cout <<" Precision: "<< _pkJugador->getAtaques()[3].getPrec() <<endl;
            cout <<" Descripcion: "<< _pkJugador->getAtaques()[3].getDesc() <<endl;
            _damage = calcularDanio( _pkJugador->getAtaques()[3].getPotencia(), _pkRival->getResistencia(), _pkJugador->getAtaques()[3].getPrec() );
            pp = _pkJugador->getAtaques()[3].getPP();
            pp--;
            _pkJugador->getAtaques()[3].setPP(pp);
        } else {
            cout << "No quedan Puntos de Ataque para realizar el movimiento.\n";
        }
        break;
    }

    Sleep(400);
    if( _damage > 0 ) {
        vidaPokRival -= _damage;
        rlutil::setColor(15);
        cout << "Daño causado por Pokemon de Jugador: " << _damage << endl;
    } else {
        cout << "El ataque fallo. No causo Daño el ataque de Pokemon Jugador.\n";
    }
    rlutil::setColor(10);
}

/// ELEGIR ATAQUES RIVAL
void GameLoop::ataquesRival(int &vidaPokJugador)
{
    int aleatorio = (rand() % 4 + 1);
    _input = aleatorio;
    switch(_input) {
    case 1:
         cout << "Ataque usado por Pokemon Rival: " << _pkRival->getAtaques()[0].getNombre() << endl;
        _damage = calcularDanio( _pkRival->getAtaques()[0].getPotencia(), _pkJugador->getResistencia(), _pkRival->getAtaques()[0].getPrec() );
        break;
    case 2:
        cout << "Ataque usado por Pokemon Rival: " << _pkRival->getAtaques()[1].getNombre() << endl;
        _damage = calcularDanio( _pkRival->getAtaques()[1].getPotencia(),  _pkJugador->getResistencia(), _pkRival->getAtaques()[1].getPrec() );

        break;
    case 3:
        cout << "Ataque usado por Pokemon Rival: " << _pkRival->getAtaques()[2].getNombre() << endl;
        _damage = calcularDanio( _pkRival->getAtaques()[2].getPotencia(),  _pkJugador->getResistencia(), _pkRival->getAtaques()[2].getPrec() );

        break;
    case 4:
        cout << "Ataque usado por Pokemon Rival: " << _pkRival->getAtaques()[3].getNombre() << endl;
        _damage = calcularDanio( _pkRival->getAtaques()[3].getPotencia(),  _pkJugador->getResistencia(), _pkRival->getAtaques()[3].getPrec() );
        break;
    }
    Sleep(400);
    if( _damage > 0 ) {
        vidaPokJugador -= _damage;
        rlutil::setColor(15);
        cout << "Daño causado por Pokemon de Rival: " << _damage << endl;
    } else {
        cout << "El ataque fallo. No causo Daño el ataque de Pokemon Rival.\n";
    }
    rlutil::setColor(10);
}

/// CALCULAR PUNTAJE:
int GameLoop::calcularPuntaje(int vidaRivalSano, int vidaRival, int acumulador)
{
    int puntosLocales = 0;
    int puntosBatalla = 0;
    int vidaRivalInicial = _pkRival->getVida();
    system("cls");
    cout << "acumulador: "<< acumulador << endl;
    cout<< "*************************************"<<endl;
    cout<< "vida del Rival Inicial: "<< vidaRivalInicial <<endl;
    if (vidaRival >= 0) cout<< "vida del Rival Restante: "<< vidaRival <<endl;
    else cout<< "vida del Rival Restante: 0"<<endl;
    cout<< "*************************************"<<endl;

    if( vidaRival <= 0 ) {
        puntosBatalla = vidaRivalInicial;
        puntosLocales = vidaRivalInicial + acumulador;
    } else {
        puntosBatalla = vidaRivalInicial - vidaRival;
        puntosLocales = (vidaRivalInicial - vidaRival) + acumulador;
    }

    cout<< "*************************************"<<endl;
    cout << "Puntaje obtenido en esta batalla: ";
    (puntosBatalla > 0) ? cout << puntosBatalla << endl : cout << "0\n";
    cout<< "*************************************"<<endl;
    cout << puntosLocales << endl;
    system("pause");
    return puntosLocales;
}

/// GUARDAR PARTIDA:
bool GameLoop::guardarPartidaFinalizada(const char* nJug, const char *nPk, int puntos)
{
    int d,m,a,h,mi=0;
    obtenerFechaHora(d,m,a,h,mi);
    Jugador aux(nJug, nPk, puntos);
    aux.setPartidaDia(d);
    aux.setPartidaMes(m);
    aux.setPartidaAnio(a);
    aux.setPartidaHora(h);
    aux.setPartidaMinuto(mi);
    return aux.guardarPartida();
}

/// INTRO BATALLA
void GameLoop::introBatalla(bool &flag)
{
    if(flag){
        system("cls");
        gotoxy(2,2);
        rlutil::setColor(15);
        cout << " Estas A punto de iniciar una Batalla Pokemon!!\n";
        cout << "  Estas consisten en batallas 1vs1 por turnos, en las cuales puedes elegir entre 4 ataques que \n";
        cout << "  tiene tu pokemon a efectuar, estos mismos tienen una posibilidad de golpear o no dependiendo de su Precisión.\n";
        cout << "  Los ataques causan daño dependiendo de su potencia, la defensa del rival y un coeficiente\n";
        cout << "  aleatorio que se determina durante cada turno.\n";
        cout << "  Estos pueden ser usados un numero limitado de veces, los mas potentes tienen menor precisión y\n";
        cout << "  los de menor potencia mayor, usalos con inteligencia.\n";
        cout << "  Ademas si el ataque que se realiza tiene ventaja sobre el tipo del pokemon rival, se causa doble daño.\n";
        cout << "  Por eso es importante conocer los tipos de ventaja que se tiene a la hora de pelear.\n";
        rlutil::setColor(10);
        cuadro(1, 113, 1, 11);
        cout << endl;
        system("pause");
        flag = false;
    }
}

//}

//{ Gest y Sets
/// Set Input
void GameLoop::setInput()
{
    cout << ">>";
    rlutil::setColor(15);
    cin >> _input;
    rlutil::setColor(10);
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


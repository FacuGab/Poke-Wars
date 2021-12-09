//Nombre: Clase Jugador
#include <iomanip>
#include <iostream>
using namespace std;
#include "Pokemon_class.h"
#include "Jugador.h"
#include "Utiles.h"
#include "Funciones.h"
#include "rlutil.h"

/// CONSTRUCTORES:
Jugador::Jugador()
{
    strcpy(_nombreJugador,"test1");
    strcpy(_nombrePokemon,"test1");
    _itr = 0;
    _puntaje = 0;
    _rivales = pokedex;
    for(int i = 0; i < 4; i++)
    {
        _party[i] = Pokemon();
    }
}

Jugador::Jugador(const char* nomJugador, const char* nomPokemon, int puntos)
{
    strcpy(_nombreJugador,nomJugador);
    strcpy(_nombrePokemon,nomPokemon);
    _puntaje = puntos;
}

/// Guardar Partida:
bool Jugador::guardarPartida()
{
    bool suceso = 0;
    FILE *p;
    p = fopen("partidas.dat","ab");
    if(p == NULL) return false;
    suceso = fwrite(this, sizeof(Jugador), 1, p);
    fclose(p);
    return suceso;
}

/// Cargar Partida:
bool Jugador::cargarPartida(int pos)
{
    bool suceso = 0;
    FILE *p;
    p = fopen("partidas.dat","rb");
    if(p == NULL) return false;
    fseek(p, pos*sizeof(Jugador), 0);
    suceso = fread(this, sizeof(Jugador), 1, p);
    fclose(p);
    return suceso;
}

/// Mostrar Registros de Puntaje:
void Jugador::mostrar()
{
    cout <<_nombreJugador<<"   ,  "<<_nombrePokemon<<"  ,    "<<_puntaje<< "    , "<<fechaPartida.getDia()<<"/"<<fechaPartida.getMes()<< "/"<<fechaPartida.getAnio()<<" ,  "<<horaPartida.getHora()<<":";

    if(horaPartida.getMinuto() < 10)
    {
        cout <<"0"<< horaPartida.getMinuto() <<endl;
    }
    else
    {
        cout << horaPartida.getMinuto() <<endl;
    }
    cout<<"***************************************************************"<<endl;
}

/// Cargar Nombre de Jugador:
void Jugador::cargar()
{
    cout << "    ### INGRESE NOMBRE JUGADOR ###" << endl;

    cout << "       NOMBRE: ";
    rlutil::setColor(15);
    cin.ignore();
    cin.getline(_nombreJugador, 30);
    rlutil::setColor(10);

}

/// Eleccion de Pokemons:
void Jugador::eleccion()
{
    bool flag = true;
    int opcion;

    system("cls");
    gotoxy(2,2);
    rlutil::setColor(15);
    cout << "HOLA " << _nombreJugador << "!, BIENVENIDO A ";
    rlutil::setColor(10);
    cout << "POKEWARS";
    rlutil::setColor(15);
    cout << ", POR FAVOR ELIGE TUS POKEMONS PARA PODER JUGAR.\n";
    rlutil::setColor(10);
    cuadro(1, 85, 1, 4);
    cout << endl;
    system("pause");

    do
    {
        system("cls");
        rlutil::setColor(10);
        cout << "-------------------------\n";
        rlutil::setColor(15);
        cout << "ELIJA UN POKEMON: \n";
        cout << "1- ELEGIR \n";
        cout << "2- VOLVER\n";
        rlutil::setColor(10);
        cout << "-------------------------\n";
        cout << "ESPACIO EN EL PARTY: " << 4 -_itr << endl;
        if(_itr == 3) cout << "PARTY LLENA, POR FAVOR ELIJA LA OPCION VOLVER.\n";
        cout << " >>";
        rlutil::setColor(15);
        cin >> opcion;
        rlutil::setColor(10);

        switch(opcion)
        {
        case 1:
            system("cls");
            cout << "-------------------------\n";
            rlutil::setColor(15);
            cout << "ELIGE ENTRE 6 POKEMONS\n";
            listaPokemon();
            rlutil::setColor(10);
            cout << "-------------------------\n";
            cout << ">>";
            rlutil::setColor(15);
            cin >> opcion;
            rlutil::setColor(10);

            if(_itr < 4)
            {
                bool f = false;
                for(int i = 0; i < 4; i++)
                {
                    if( _party[i].getID() == pokedex[opcion-1].getID() ) f = true;
                }
                if(!f)
                {
                    _party[_itr] = pokedex[opcion-1];
                    cout << "POKEMON ELEGIDO ";
                    rlutil::setColor(15);
                    cout << _party[_itr].getNombre();
                    rlutil::setColor(10);
                    cout << "!!" << endl;
                    _itr++;
                }
                else
                {
                    cout << "POKEMON YA ELEGIDO!\n";
                }
            }
            else
            {
                cout << "PARTY LLENA.\n";
            }
            system("pause");
            break;

        case 2:
            cout << "VOLVER.\n";
            if(_itr == 0) cout << "NO ELEGISTE NINGUN POKEMON, POR FAVOR ELIGE UNO.\n";
            else flag = false;
            system("pause");
            break;

        default:
            cout << "OPCION INCORRECTA.\n";
            system("pause");
        }

    }
    while(flag);
}

/// Eleccion de Rival:
void Jugador::cargarRival()
{
    _rivales = pokedex;
}

/// ESTADISTICAS DEL POKEDEX:
void Jugador::estadisticaPokedex()
{
    system("cls");
    rlutil::setColor(14);
    cout << "\t\t·························\n";
    cout << "\t\t······P-O-K-E-D-E-X······\n";
    cout << "\t\t·························\n";
    rlutil::setColor(10);
    cout << "-----------------------------------------------------------\n";
    for(int i = 0; i < 6; i++)
    {
        rlutil::setColor(13);
        cout << left;
        cout << setw(12) << "NOMBRE";
        cout << setw(12) << "ID";
        cout << setw(12) << "TIPO";
        cout << setw(12) << "VIDA";
        cout << setw(12) << "RESISTENCIA";
        cout << endl;
        rlutil::setColor(10);
        cout << left;
        cout << setw(12) << pokedex[i].getNombre();
        cout << setw(12) << pokedex[i].getID();
        cout << setw(12) << tipo( pokedex[i].getTipo() );
        cout << setw(12) << pokedex[i].getVida();
        cout << setw(12) << pokedex[i].getResistencia();
        cout << endl;
        cout << "-----------------------------------------------------------\n";
    }
}

/// ESTADISTICAS DE LOS POKEMON ELEGIDOS:
void Jugador::estadisticaParty()
{
    system("cls");
    rlutil::setColor(14);
    cout << "\t·····························\n";
    cout << "\t······T-U···E-Q-U-I-P-O······\n";
    cout << "\t·····························\n";
    rlutil::setColor(13);
    cout << "============================================================\n";
    rlutil::setColor(10);


    rlutil::setColor(11);
    cout << left;
    cout << setw(12) << "NOMBRE";
    cout << setw(12) << "ID";
    cout << setw(12) << "TIPO";
    cout << setw(12) << "VIDA";
    cout << setw(12) << "RESISTENCIA";
    cout << endl;
    rlutil::setColor(13);
    cout << "============================================================\n";
    rlutil::setColor(10);
    for(int i = 0; i < 4; i++)
    {
        cout << endl;
        cout << left;
        cout << setw(12) << _party[i].getNombre();
        cout << setw(12) << _party[i].getID();
        cout << setw(12) << tipo( _party[i].getTipo() );
        cout << setw(12) << _party[i].getVida();
        cout << setw(12) << _party[i].getResistencia();
        cout << endl;
        rlutil::setColor(13);
        cout << "------------------------------------------------------------\n";
        rlutil::setColor(10);
    }
    system("pause");
    cout << endl;
    rlutil::setColor(14);
    cout << "············································································································\n";
    cout << "\t\t\tA-T-A-Q-U-E-S:\n";
    cout << "············································································································\n";
    rlutil::setColor(10);
    for(int x = 0; x < 4; x++)
    {
        if(_party[x].getAtaques() != NULL)
        {
            cout <<"-"<< _party[x].getNombre() <<"-"<< endl;
            rlutil::setColor(13);
            cout << "------------------------------------------------------------------------------------------------------------\n";
            rlutil::setColor(11);
            cout << left;
            cout << setw(16) << "NOMBRE";
            cout << setw(16) << "POTENCIA";
            cout << setw(16) << "CANTIDAD";
            cout << setw(16) << "TIPO";
            cout << setw(16) << "PRESICION";
            cout << setw(24) << "DESCRIPCION";
            cout << endl;
            rlutil::setColor(10);
            for(int j = 0; j < 4; j++)
            {
                cout << left;
                cout << setw(16) << _party[x].getAtaques()[j].getNombre();
                cout << setw(16) << _party[x].getAtaques()[j].getPotencia();
                cout << setw(16) << _party[x].getAtaques()[j].getPP();
                cout << setw(16) << _party[x].getAtaques()[j].getTipo();
                cout << setw(16) << _party[x].getAtaques()[j].getPrec();
                cout << setw(24) << _party[x].getAtaques()[j].getDesc();
                cout << endl;
            }
        }
    }
}

/// RESET
void Jugador::reseteo()
{
    strcpy(_nombreJugador,"test1");
    strcpy(_nombrePokemon,"test1");
    _itr = 0;
    _puntaje = 0;
    _rivales = pokedex;
    for(int i = 0; i < 4; i++)
    {
        _party[i] = Pokemon();
    }
}


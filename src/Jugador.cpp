//Nombre: Clase Jugador
#include <iostream>
using namespace std;
#include "Pokemon_class.h"
#include "Jugador.h"
#include "Utiles.h"
#include "Funciones.h"

/// Constructores:
Jugador::Jugador()
{
    strcpy(_nombreJugador,"test1");
    strcpy(_nombrePokemon,"test1");
    _itr = 0;
    _puntaje = 0;
    _rivales = pokedex;
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
    cout<<" "<<_nombreJugador<<" , "<<_nombrePokemon<<" ,  "<<_puntaje<<endl;
    cout<<"*********************************"<<endl;
}

/// Cargar Nombre de Jugador:
void Jugador::cargar()
{
    cout<< "    ### INGRESE NOMBRE JUGADOR ###"<< endl;
    cout << "       Nombre: ";
    cin >> _nombreJugador;
    system("cls");
    gotoxy(2,2);
    cout << "HOLA " << _nombreJugador << "!, bienvenido a POKEWARS, por favor elige tus pokemons para poder jugar.\n";
    cuadro(1, 82, 1, 4);
    cout << endl;
    system("pause");
}

/// Eleccion de Pokemons:
void Jugador::eleccion()
{
    bool flag = true;
    int opcion;
    do
    {
        system("cls");
        cout << "-------------------------\n";
        cout << "ELIJA UN POKEMON: \n";
        cout << "1- Elegir\n";
        cout << "2- Volver\n";
        cout << "-------------------------\n";
        cout << "Espacio en el party: " << 4 -_itr << endl;
        if(_itr == 3) cout << "Party llena, por favor eliga opcion Voler.\n";
        cout << " >>";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            system("cls");
            cout << "-------------------------\n";
            cout << "Elige de entre 4 pokemons\n";
            listaPokemon();
            cout << "-------------------------\n";
            cout << ">>";
            cin >> opcion; // CUIDADO! no controla que opcion entra, se puede caer fuera del vector (-1 o 5 xejm)

            if(_itr < 4){
            _party[_itr] = pokedex[opcion-1];
            cout << "Pokemon elegido " << _party[_itr].getNombre() << "!!" << endl;
            _itr++;
            } else {cout << "Party llena.\n";}
            system("pause");
            break;

        case 2:
            cout << "Volver.\n";
            if(_itr == 0) cout << "No elegiste ningun Pokemon, por favor elige uno.\n";
            else flag = false;
            system("pause");
            break;

        default:
            cout << "Opcion incorrecta.\n";
            system("pause");
        }

    }while(flag);
}

/// Eleccion de Rival:
void Jugador::cargarRival()
{
    _rivales = pokedex;
}

#ifndef JUGADOR_H
#define JUGADOR_H
#include <cstring>
#include "Pokemon_class.h"

class Jugador
{
    public:
        /// CONSTRUCTORES:
        Jugador();
        Jugador(const char* nomJugador, const char* nomPokemon, int puntos);

        /// METODOS:
        void mostrar();
        void eleccion();
        void cargar();
        void cargarRival();
        bool guardarPartida();
        bool cargarPartida(int pos);

        /// SETS Y GETS:
        void setNombreJugador(const char *nombreJugador){ strcpy(_nombreJugador, nombreJugador);}
        void setNombrePokemon(const char *nombrePokemon){ strcpy(_nombrePokemon, nombrePokemon);}
        void setPuntaje(int p){_puntaje = p;}
        char *getNombreJugador(){ return _nombreJugador;}
        char *getNombrePokemon(){return _nombrePokemon;}
        int getPuntaje(){return _puntaje;}
        Pokemon &getPokemon(int pos){ return _party[pos];}
        Pokemon &getRival(int pos){ return _rivales[pos];}

    private:
        char _nombreJugador [30];
        char _nombrePokemon [30];
        int  _puntaje;
        int  _itr;
        Pokemon _party[4];
        Pokemon *_rivales;
};


#endif // JUGADOR_H

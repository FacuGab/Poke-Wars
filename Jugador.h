#ifndef JUGADOR_H
#define JUGADOR_H
#include <cstring>

class Jugador
{
    public:
        Jugador();

        void setNombreJugador(const char *nombreJugador){ strcpy(_nombreJugador, nombreJugador);}
        void setNombrePokemon(const char *nombrePokemon){ strcpy(_nombrePokemon, nombrePokemon);}


        char *getNombreJugador(){ return _nombreJugador;}
        char *getNombrePokemon(){return _nombreJugador;}



    private:

        char _nombreJugador [30];
        char _nombrePokemon[30];
				int _puntaje=0;






};

#endif // JUGADOR_H

#ifndef JUGADOR_H
#define JUGADOR_H
#include <cstring>
#include "Pokemon_class.h"
#include "Fecha.h"
#include "Hora.h"

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
        void estadisticaPokedex();
        void estadisticaParty();
        void reseteo();

        /// SETS Y GETS:
        void setNombreJugador(const char *nombreJugador){ strcpy(_nombreJugador, nombreJugador);}
        void setNombrePokemon(const char *nombrePokemon){ strcpy(_nombrePokemon, nombrePokemon);}
        void setPuntaje(int p){_puntaje = p;}
        void setEstado(int pos, bool est){_estado[pos] = est;}
        void setPartidaDia(int d){fechaPartida.setDia(d);}
        void setPartidaMes(int m){fechaPartida.setMes(m);}
        void setPartidaAnio(int a){fechaPartida.setAnio(a);}
        void setPartidaHora(int h){horaPartida.setHora(h);}
        void setPartidaMinuto(int mi){horaPartida.setMinuto(mi);}
        char *getNombreJugador(){ return _nombreJugador;}
        char *getNombrePokemon(){return _nombrePokemon;}
        int getPuntaje(){return _puntaje;}
        bool getEstado(int pos){return _estado[pos];}
        Pokemon &getPokemon(int pos){ return _party[pos];}
        Pokemon &getRival(int pos){ return _rivales[pos];}
        int  getPartidaHora(){return horaPartida.getHora();}
        int  getPartidaMinuto(){return horaPartida.getMinuto();}
        int  getPartidaDia(){return fechaPartida.getDia();}
        int  getPartidaMes(){return fechaPartida.getMes();}
        int  getPartidaAnio(){return fechaPartida.getAnio();}

    protected :
        char _nombreJugador [30];
        char _nombrePokemon [30];
        int  _puntaje;
        Fecha fechaPartida;
        Hora  horaPartida;

    private:
        bool _estado[4];
        int  _itr;
        Pokemon _party[4];
        Pokemon *_rivales;
};


#endif // JUGADOR_H

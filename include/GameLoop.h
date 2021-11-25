#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Pokemon_class.h"
#include "Jugador.h"

class GameLoop
{
    public:
        /// COSNTRUCTOR y DESTRUCTOR
        GameLoop(); /// Sin uso por ahora
        ~GameLoop(); /// Sin uso por ahora

        /// METODOS
        void gamePlay(Jugador&);
        void ataquesJugador(int &vidaPokRival);
        void ataquesRival(int &vidaPokJugador);
         int asignarTurno();
         int calcularDanio(int p_danio, int p_defensa, int pres);
        bool controlVida(int p_vidaJugador, int p_vidaRival);
        void siguienteBatalla(int &, int &, int &, Jugador &, int, int &);
         int calcularPuntaje(int vidaRivalSano, int vidaRival,int puntos);
        bool guardarPartidaFinalizada(const char* nJug,const char *nPk,int puntos);
         int tipoDanio(int);

        /// GETS y SETS
        void setInput(); /// pide por pantalla, no es un set normal
         int getInput();
         int getGanador();

    private:
    Pokemon* _pkJugador;
    Pokemon* _pkRival;
        int _vidaPkJugador; ///sin uso por ahora
        int _vidaPkRival; ///sin uso por ahora
        int _input;
        int _ganador;
        int _loop = 0;
        int _damage;
};

#endif // GAMELOOP_H

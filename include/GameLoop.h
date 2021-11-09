#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Pokemon_class.h"


class GameLoop
{
    public:
        /// COSNTRUCTOR y DESTRUCTOR
        GameLoop(); /// Sin uso por ahora
        ~GameLoop(); /// Sin uso por ahora

        /// METODOS
        void gamePlay(Pokemon &pok1, Pokemon &pok2);
        void ataquesJugador(int &vidaPokRival);
        void ataquesRival(int &vidaPokJugador);
         int asignarTurno();
         int calcularDanio(int p_danio, int p_defensa);
        bool controlVida(int p_vidaJugador, int p_vidaRival);

        /// GETS y SETS
        void setInput();
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

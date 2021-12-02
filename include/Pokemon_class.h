#ifndef POKEMON_CLASS_H
#define POKEMON_CLASS_H
#include "Stats_Ataques_class.h"
#include <iostream>

class Pokemon
{
    public:
        /// CONSTRUCTORES:
        Pokemon();
        Pokemon(const char* nom,
                int ID,
                int tipo,
                int vida,
                int res,
                Ataque* atq);

        /// METODOS:
         void Mostrar(int ps);

        /// GETS:
        char* getNombre();
        char* getNombreJugador();
          int getID();
          int getTipo();
          int getVida();
          int getResistencia();
      Ataque* getAtaques();
        /// SETS:
        void setNombre(const char* cad);
        void setNombreJugador(const char* cad);
        void setID (int num);
        void setTipo (int num);
        void setVida (int num);
        void setResistencia (int num);
        void setAtaque (Ataque * atq);

    private:
        char _nombre[30];
        char _nombreJugador[35];
         int _ID;
         int _tipo;
         int _vida;
         int _resistencia;
     Ataque* _ataques;
};

#endif // POKEMON_CLASS_H

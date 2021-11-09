#ifndef POKEMON_CLASS_H
#define POKEMON_CLASS_H
#include "Stats_Ataques_class.h"


class Pokemon
{
    public:
        /// CONSTRUCTOR:
        Pokemon(const char* nom,
                 int ID, // sin uso
                 int tipo, // sin uso
                 int vida,
                 int res,
                 Ataque* atq);
        /// METODOS:
        void Mostrar(int ps);

        /// GETS:
        char* getNombre();
        char* getNombreJugador();
        int getID(); // sin uso
        int getTipo(); // sin uso
        int getVida();
        int getResistencia();
        Ataque* getAtaques();
        string getEstado(); // sin uso

        /// SETS:
        void setNombre(const char* cad);
        void setNombreJugador(const char* cad);
        void setID (int num); // sin uso
        void setTipo (int num); // sin uso
        void setVida (int num);
        void setResistencia (int num);
        void setAtaque (Ataque * atq);
        void setEstado (string str); // sin uso

    private:
        char _nombre[30];
        char _nombreJugador[35];
        int _ID; // sin uso
        int _tipo; // sin uso
        int _vida;
        int _resistencia;
        Ataque* _ataques;
        string _estado; // sin uso
};

#endif // POKEMON_CLASS_H

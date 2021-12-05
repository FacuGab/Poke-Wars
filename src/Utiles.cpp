//Nombre:
//TP N: 2
//Ejercicio N:
//Comentarios:

#include <iostream>
using namespace std;
#include "Pokemon_class.h"

/// Lista de Ataques:
Ataque pikachudAtaques[4] = { Ataque(false, "Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),                                   //pos 0
                              Ataque(false, "Rasguño", 55, 10, NORMAL, 80, "Ataque con las garras"),                        //pos 1
                              Ataque(false, "Ataque Rapido", 45, 10, NORMAL, 99, "Ataque no puede fallar"),                 //pos 2
                              Ataque(true, "Impacto Trueno", 90, 10, ELECTRICO, 70, "Impacto Electrico, puede paralizar")}; //pos 3

Ataque bulbasaurAtaques[4] = {Ataque(false, "Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                              Ataque(false, "Hojas Navajas", 50, 25, PLANTA, 95, "Ataque con hojas afiladas"),
                              Ataque(false, "Polvo Veneno", 50, 25, NORMAL, 95, "Envenena al Enemigo"),
                              Ataque(false, "Drenadoras", 50, 25, NORMAL, 95, "Drena la vida del Enemigo")};

Ataque charmanderAtaques[4] = {Ataque(false, "Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                               Ataque(false, "Rasguño", 50, 25, NORMAL, 95, "Ataque con las garras"),
                               Ataque(false, "Golpe Fuego", 50, 25, FUEGO, 95, "Golpea envuelto en llamas"),
                               Ataque(false, "Dia Soleado", 50, 25, FUEGO, 95, "Potencia los ataques de tipo fuego")};

Ataque squirtleAtaques[4] = {Ataque(false, "Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                             Ataque(false, "Cabezazo", 50, 25, NORMAL, 95, "Golpe fisico, puede paralizar al rival"),
                             Ataque(false, "Refugio", 50, 25, NORMAL, 95, "Aumenta la defensa"),
                             Ataque(false, "Pistola de Agua", 50, 25, AGUA, 95, "Golpe con agua")};

/// Lista de Pokemons:
Pokemon pokedex[4] = {Pokemon("Bulbasaur", 1, PLANTA, 55, 60, bulbasaurAtaques),
                      Pokemon("Charmander", 2, FUEGO, 55, 62, charmanderAtaques),
                      Pokemon("Squirtle", 3, AGUA, 55, 64, squirtleAtaques),
                      Pokemon("Pikachu", 25, ELECTRICO, 50, 70, pikachudAtaques)};

void listPokemon()
{
    for(int i = 0; i < 4; i++)
    {
        cout << i+1 <<" "<< pokedex[i].getNombre() << endl;
    }
}

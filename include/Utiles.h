#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED
#include "Pokemon_class.h"

/// Lista de Ataques:

Ataque pikachudAtaques[4] = { Ataque("Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                              Ataque("Rasguño", 55, 10, NORMAL, 80, "Ataque con las garras"),
                              Ataque("Ataque Rapido", 45, 10, NORMAL, 99, "Ataque de alta velocidad"),
                              Ataque("Impacto Trueno", 90, 10, ELECTRICO, 80, "Impacto Electrico")};

Ataque bulbasaurAtaques[4] = {Ataque("Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                              Ataque("Hojas Navajas", 50, 25, PLANTA, 95, "Ataque con hojas afiladas"),
                              Ataque("Polvo Veneno", 50, 25, NORMAL, 95, "Envenena al Enemigo"),
                              Ataque("Drenadoras", 50, 25, NORMAL, 95, "Drena la vida del Enemigo")};

Ataque charmanderAtaques[4] = {Ataque("Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                               Ataque("Rasguño", 50, 25, NORMAL, 95, "Ataque con las garras"),
                               Ataque("Golpe Fuego", 50, 25, FUEGO, 95, "Golpea envuelto en llamas"),
                               Ataque("Dia Soleado", 50, 25, FUEGO, 95, "Potencia los ataques de tipo fuego")};

Ataque squirtleAtaques[4] = {Ataque("Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                             Ataque("Cabezazo", 50, 25, NORMAL, 95, "Golpe fisico"),
                             Ataque("Refugio", 50, 25, NORMAL, 95, "Aumenta la defensa"),
                             Ataque("Pistola de Agua", 50, 25, AGUA, 95, "Golpe con agua")};

Ataque charizardAtaques[4] = {Ataque("Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                              Ataque("Rasguño", 90, 10, FUEGO, 80, "Golpe fisico"),
                              Ataque("Vuelo", 90, 10, NORMAL, 80, "Ataque desde el cielo"),
                              Ataque("Lanzallamas", 90, 10, FUEGO, 70, "Llamarada poderosa")};

Ataque blastoiseAtaques[4] = {Ataque("Cabezaso", 75, 20, NORMAL, 90, "Golpe fisico"),
                              Ataque("Refugio", 60, 15, AGUA, 95, "Golpea con su caprazon"),
                              Ataque("Pistola de Agua", 78, 20, AGUA, 85, "Golpe con agua"),
                              Ataque("Hidrobomba", 92, 10, AGUA, 65, "Golpe masivo con agua")};
/// Lista de Pokemons:
Pokemon pokedex[6] = {Pokemon("Bulbasaur", 1, PLANTA, 55, 60, bulbasaurAtaques),
                      Pokemon("Charmander", 2, FUEGO, 55, 62, charmanderAtaques),
                      Pokemon("Squirtle", 3, AGUA, 55, 64, squirtleAtaques),
                      Pokemon("Pikachu", 25, ELECTRICO, 50, 60, pikachudAtaques),
                      Pokemon("Charizard", 6, FUEGO, 78, 85, charizardAtaques),
                      Pokemon("Blastoise", 9, AGUA, 80, 100, blastoiseAtaques)};

void listaPokemon()
{
    for(int i = 0; i < 4; i++)
    {
        cout << i+1 <<" "<< pokedex[i].getNombre() << endl;
    }
}


#endif // UTILES_H_INCLUDED

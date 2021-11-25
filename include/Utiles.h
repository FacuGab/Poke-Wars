#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED
#include "Pokemon_class.h"

/// Lista de Ataques:

Ataque pikachudAtaques[4] = { Ataque(false, "Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                              Ataque(false, "Rasguño", 55, 10, NORMAL, 80, "Ataque con las garras"),
                              Ataque(false, "Ataque Rapido", 45, 10, NORMAL, 99, "Ataque no puede fallar"),
                              Ataque(true, "Impacto Trueno", 90, 10, ELECTRICO, 80, "Impacto Electrico, puede paralizar")};

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

Ataque charizardAtaques[4] = {Ataque(false, "Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                              Ataque(false, "Rasguño", 90, 10, FUEGO, 80, "Golpe fisico, puede paralizar al rival"),
                              Ataque(false, "Vuelo", 90, 10, NORMAL, 80, "Ataque desde el cielo"),
                              Ataque(true, "Lanzallamas", 90, 10, FUEGO, 70, "Llamarada poderosa")};

Ataque blastoiseAtaques[4] = {Ataque(false, "Cabezaso", 75, 20, NORMAL, 90, "Golpe fisico"),
                              Ataque(true, "Refugio", 60, 15, AGUA, 95),
                              Ataque(true, "Pistola de Agua", 78, 20, AGUA, 85, "Golpe con agua"),
                              Ataque(true, "Hidrobomba", 92, 10, AGUA, 65, "Golpe masivo con agua")};
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

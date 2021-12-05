#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED
#include "Pokemon_class.h"

/// Lista de Ataques:

Ataque pikachudAtaques[4] = { Ataque("Tacle", 50, 15, NORMAL, 95, "Golpe fisico"),
                              Ataque("Rasguño", 55, 10, NORMAL, 85, "Ataque con las garras"),
                              Ataque("Ataque Rapido", 40, 15, NORMAL, 99, "Ataque de alta velocidad"),
                              Ataque("Impacto Trueno", 90, 5, ELECTRICO, 70, "Impacto Electrico")};

Ataque buterrfreeAtaques[4] = {Ataque("Tacle", 50, 15, NORMAL, 95, "Golpe fisico"),
                               Ataque("Polvo Veneno", 60, 10,  BICHO, 90, "Envenena al Enemigo"),
                               Ataque("Ataque Rapido", 40, 15, NORMAL, 99, "Ataque de alta velocidad"),
                               Ataque("Espina", 75, 10, BICHO, 80, "Espinas afiladas")};

Ataque      DittoAtaques[4] = {Ataque("Rasguño", 55, 10, NORMAL, 85, "Ataque con las garras"),
                               Ataque("Refugio", 60, 15, NORMAL, 95, "Golpea con su caprazon"),
                               Ataque("Lluvia de Rocas", 65, 10, TIERRA, 85, "Lanza rocas al enemigo"),
                               Ataque("Terremoto", 85, 8, TIERRA, 75, "Causa un potente terremoto")};

Ataque ratatadAtaques[4] = {  Ataque("Tacle", 50, 15, NORMAL, 95, "Golpe fisico"),
                              Ataque("Rasguño", 55, 10, NORMAL, 85, "Ataque con las garras"),
                              Ataque("Ataque Rapido", 45, 10, NORMAL, 99, "Ataque de alta velocidad"),
                              Ataque("Terremoto", 85, 10, TIERRA, 75, "Causa un potente terremoto")};

Ataque bulbasaurAtaques[4] = {Ataque("Tacle", 50, 15, NORMAL, 95, "Golpe fisico"),
                              Ataque("Hojas Navajas", 65, 8, PLANTA, 80, "Ataque con hojas afiladas"),
                              Ataque("Polvo Veneno", 60, 10, BICHO, 85, "Envenena al Enemigo"),
                              Ataque("Drenadoras", 45, 15, NORMAL, 95, "Drena la vida del Enemigo")};

Ataque charmanderAtaques[4] = {Ataque("Tacle", 50, 15, NORMAL, 95, "Golpe fisico"),
                               Ataque("Rasguño", 55, 10, NORMAL, 85, "Ataque con las garras"),
                               Ataque("Golpe Fuego", 70, 8, FUEGO, 80, "Golpea envuelto en llamas"),
                               Ataque("Dia Soleado", 60, 10, FUEGO, 85, "Potencia los ataques de tipo fuego")};

Ataque squirtleAtaques[4] = {Ataque("Tacle", 50, 25, NORMAL, 95, "Golpe fisico"),
                             Ataque("Cabezazo", 50, 25, NORMAL, 95, "Golpe fisico"),
                             Ataque("Refugio", 50, 25, NORMAL, 95, "Aumenta la defensa"),
                             Ataque("Pistola de Agua", 50, 25, AGUA, 95, "Golpe con agua")};

Ataque charizardAtaques[4] = {Ataque("Tacle", 50, 15, NORMAL, 95, "Golpe fisico"),
                              Ataque("Rasguño", 55, 10, NORMAL, 85, "Ataque con las garras"),
                              Ataque("Vuelo", 85, 10, NORMAL, 80, "Ataque desde el cielo"),
                              Ataque("Lanzallamas", 90, 5, FUEGO, 65, "Llamarada poderosa")};

Ataque blastoiseAtaques[4] = {Ataque("Cabezaso", 75, 10, NORMAL, 80, "Golpe de cabeza"),
                              Ataque("Refugio", 60, 15, NORMAL, 85, "Golpea con su caprazon"),
                              Ataque("Pistola de Agua", 78, 10, AGUA, 85, "Golpe con agua"),
                              Ataque("Hidrobomba", 92, 5, AGUA, 65, "Golpe masivo con agua")};
/// Lista de Pokemons:
Pokemon pokedex[9] = {Pokemon("Bulbasaur", 1, PLANTA, 65, 68, bulbasaurAtaques),
                      Pokemon("Charmander", 2, FUEGO, 62, 65, charmanderAtaques),
                      Pokemon("Squirtle", 3, AGUA, 62, 70, squirtleAtaques),
                      Pokemon("Pikachu", 25, ELECTRICO, 60, 62, pikachudAtaques),
                      Pokemon("Ratata", 10, NORMAL, 62, 65, ratatadAtaques),
                      Pokemon("Buterrfree", 11, BICHO, 60, 62, buterrfreeAtaques),
                      Pokemon("Ditto", 12, TIERRA, 60, 65, buterrfreeAtaques),
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

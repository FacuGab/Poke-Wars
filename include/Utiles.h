#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED
#include "Pokemon_class.h"

/// Lista de Ataques:

Ataque pikachudAtaques[4] = { Ataque("TACLE", 50, 15, NORMAL, 95, "GOLPE FISICO"),
                              Ataque("RASGUÑO", 55, 10, NORMAL, 85, "ATAQUE CON LAS GARRAS"),
                              Ataque("ATAQUE RAPIDO", 40, 15, NORMAL, 99, "ATAQUE DE ALTA VELOCIDAD"),
                              Ataque("IMPACTO TRUENO", 90, 5, ELECTRICO, 70, "IMPACTO ELECTRICO")};

Ataque buterrfreeAtaques[4] = {Ataque("TACLE", 50, 15, NORMAL, 95, "Golpe fisico"),
                               Ataque("POLVO VENENO", 60, 10,  BICHO, 90, "ENVENENA AL ENEMIGO"),
                               Ataque("ATAQUE RAPIDO", 40, 15, NORMAL, 99, "ATAQUE DE ALTA VELOCIDAD"),
                               Ataque("ESPINA", 75, 10, BICHO, 80, "ESPINAS AFILADAS")};

Ataque      DittoAtaques[4] = {Ataque("RASGUÑO", 55, 10, NORMAL, 85, "ATAQUE CON LAS GARRAS"),
                               Ataque("REFUGIO", 60, 15, NORMAL, 95, "GOLPEA CON SU CAPARAZON"),
                               Ataque("LLUVIA DE ROCAS", 65, 10, TIERRA, 85, "LANZA ROCAS AL ENEMIGO"),
                               Ataque("TERREMOTO", 85, 8, TIERRA, 75, "CAUSA UN POTENTE TERREMOTO")};

Ataque ratatadAtaques[4] = {  Ataque("TACLE", 50, 15, NORMAL, 95, "GOLPE FISICO"),
                              Ataque("RASGUÑO", 55, 10, NORMAL, 85, "ATAQUE CON LAS GARRAS"),
                              Ataque("ATAQUE RAPIDO", 45, 10, NORMAL, 99, "ATAQUE DE ALTA VELOCIDAD"),
                              Ataque("TERREMOTO", 85, 10, TIERRA, 75, "CAUSA UN POTENTE TERREMOTO")};

Ataque bulbasaurAtaques[4] = {Ataque("TACLE", 50, 15, NORMAL, 95, "GOLPE FISICO"),
                              Ataque("HOJAS NAVAJAS", 65, 8, PLANTA, 80, "ATAQUE CON HOJAS AFILADAS"),
                              Ataque("POLVO VENENO", 60, 10, BICHO, 85, "ENVENENA AL ENEMIGO"),
                              Ataque("DRENADORAS", 45, 15, NORMAL, 95, "DRENA LA VIDA DEL ENEMIGO")};

Ataque charmanderAtaques[4] = {Ataque("TACLE", 50, 15, NORMAL, 95, "GOLPE FISICO"),
                               Ataque("RASGUÑO", 55, 10, NORMAL, 85, "ATAQUE CON LAS GARRAS"),
                               Ataque("GOLPE FUEGO", 70, 8, FUEGO, 80, "GOLPEA ENVUELTO EN LLAMAS"),
                               Ataque("DIA SOLEADO", 60, 10, FUEGO, 85, "POTENCIA LOS ATAQUES DE TIPO FUEGO")};

Ataque squirtleAtaques[4] = {Ataque("TACLE", 50, 25, NORMAL, 95, "GOLPE FISICO"),
                             Ataque("CABEZAZO", 50, 25, NORMAL, 95, "GOLPE FISICO"),
                             Ataque("REFUGIO", 50, 25, NORMAL, 95, "AUMENTA LA DEFENSA"),
                             Ataque("PISTOLA DE AGUA", 50, 25, AGUA, 95, "GOLPE CON AGUA")};

Ataque charizardAtaques[4] = {Ataque("TACLE", 50, 15, NORMAL, 95, "GOLPE FISICO"),
                              Ataque("RASGUÑO", 55, 10, NORMAL, 85, "ATAQUE CON LAS GARRAS"),
                              Ataque("VUELO", 85, 10, NORMAL, 80, "ATAQUE DESDE EL CIELO"),
                              Ataque("LANZALLAMAS", 90, 5, FUEGO, 65, "LLAMARADA PODEROSA")};

Ataque blastoiseAtaques[4] = {Ataque("CABEZAZO", 75, 10, NORMAL, 80, "GOLPE DE CABEZA"),
                              Ataque("REFUGIO", 60, 15, NORMAL, 85, "GOLPEA CON SU CAPARAZON"),
                              Ataque("PISTOLA DE AGUA", 78, 10, AGUA, 85, "GOLPE CON AGUA"),
                              Ataque("HIDROBOMBA", 92, 5, AGUA, 65, "GOLPE MASIVO CON AGUA")};
/// Lista de Pokemons:
Pokemon pokedex[9] = {Pokemon("BULBASAUR", 1, PLANTA, 65, 68, bulbasaurAtaques),
                      Pokemon("CHARMANDER", 2, FUEGO, 62, 65, charmanderAtaques),
                      Pokemon("SQUIRTLE", 3, AGUA, 62, 70, squirtleAtaques),
                      Pokemon("PIKACHU", 25, ELECTRICO, 60, 62, pikachudAtaques),
                      Pokemon("RATATA", 10, NORMAL, 62, 65, ratatadAtaques),
                      Pokemon("BUTTERFREE", 11, BICHO, 60, 62, buterrfreeAtaques),
                      Pokemon("DITTO", 12, TIERRA, 60, 65, buterrfreeAtaques),
                      Pokemon("CHARIZARD", 6, FUEGO, 78, 85, charizardAtaques),
                      Pokemon("BLASTOISE", 9, AGUA, 80, 100, blastoiseAtaques)};

void listaPokemon()
{
    for(int i = 0; i < 6; i++)
    {
        cout << i+1 <<" "<< pokedex[i].getNombre() << endl;
    }
}

#endif // UTILES_H_INCLUDED

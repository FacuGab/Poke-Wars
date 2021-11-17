#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED

Ataque pikachudAtaques[4] = { Ataque(false, "Tacle", 50, 25, NORMAL, 95),            //pos 0
                              Ataque(false, "Rasguño", 55, 10, NORMAL, 80),          //pos 1
                              Ataque(false, "Ataque Rapido", 45, 10, NORMAL, 99),    //pos 2
                              Ataque(true, "Impacto Trueno", 90, 10, ELECTRICO, 80)};//pos 3
Ataque bulbasaurAtaques[4] = {Ataque(false, "Tacle", 50, 25, NORMAL, 95),
                              Ataque(false, "Tacle", 50, 25, NORMAL, 95),
                              Ataque(false, "Tacle", 50, 25, NORMAL, 95),
                              Ataque(false, "Tacle", 50, 25, NORMAL, 95)};
Ataque charmanderAtaques[4] = {Ataque(false, "Tacle", 50, 25, NORMAL, 95),
                               Ataque(false, "Tacle", 50, 25, NORMAL, 95),
                               Ataque(false, "Tacle", 50, 25, NORMAL, 95),
                               Ataque(false, "Tacle", 50, 25, NORMAL, 95)};
Ataque squirtleAtaques[4] = {Ataque(false, "Tacle", 50, 25, NORMAL, 95),
                             Ataque(false, "Tacle", 50, 25, NORMAL, 95),
                             Ataque(false, "Tacle", 50, 25, NORMAL, 95),
                             Ataque(false, "Tacle", 50, 25, NORMAL, 95)};

Pokemon pokedex[4] = {Pokemon("Bulbasaur", 1, PLANTA, 55, 60, bulbasaurAtaques),
                      Pokemon("Charmander", 2, FUEGO, 55, 62, charmanderAtaques),
                      Pokemon("Squirtle", 3, AGUA, 55, 64, squirtleAtaques),
                      Pokemon("Pikachu", 25, ELECTRICO, 50, 70, pikachudAtaques)};


#endif // UTILES_H_INCLUDED

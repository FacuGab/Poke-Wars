#ifndef LIDERES_H
#define LIDERES_H

#include <Jugador.h>

/// hijo de Jugador
class Lideres : public Jugador
{
public:
    Lideres(); /// sin uso, sacar si al final no conflictua o sigue sin uso
    Lideres(const char* nomJugador, const char* nomPokemon, int puntos, const char* nombreMedalla, const char *nombreCiudad); /// idem anterior

    void cargar();
    void mostrarLider();
    bool listarLider(Lideres *uno);
    bool grabarLider();
    bool leerLider(int pos);

private:
    char _nombreMedalla[20];
    char _nombreCiudad[20];

};

#endif // LIDERES_H

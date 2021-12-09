#include <iostream>
using namespace std;
#include "Lideres.h"
#include "rlutil.h"

/// CONSTRUCTORES:

Lideres::Lideres()
{
    // ctor, SACAR SI NO SE ENCUENTRA UTULIDAD
}


Lideres::Lideres(const char* nomJugador, const char* nomPokemon, int puntos, const char* nombreMedalla, const char *nombreCiudad)
{
    // 2do ctor, puede usarse a futuro si queremos crear un nuevo lider durante el juego, si no sacar
}

/// CARGAR:
void Lideres::cargar()
{
    Jugador::cargar();

    cout << "Ingrese puntaje maximo: ";
    cin>>_puntaje;
    cin.ignore();
    cout<< "Ingrese el nombre de la ciudad: ";
    cin.getline(_nombreCiudad, 20);
    cout << "Ingrese el nombre de la medalla ";
    cin.getline(_nombreMedalla, 20);
    cout<< "Ingrese nombre pokemon de lider: ";
    cin.getline( _nombrePokemon, 40);

}

/// MOSTRAR LIDERES:
void Lideres::mostrarLider()
{
    cout<< "LIDER DEL GIMNASIO: ";
    cout << _nombreJugador;

    cout<< endl;
    cout<< "CIUDAD: ";
    cout << _nombreCiudad;

    cout<< endl;
    cout<< "MEDALLA A OBTENER: ";
    cout << _nombreMedalla;

    cout<< endl;
    cout<< "POKEMON PRINCIPAL:  ";
    cout << _nombrePokemon;
    cout<< endl;
    cout<< "PUNTAJE MAXIMO DE LIGA:  ";
    cout << _puntaje<< " PUNTOS ";

    cout<< endl;
}

/// GRABAR:
bool Lideres::grabarLider()
{
    FILE *p;
    p = fopen("Lideres.dat","ab");
    if (p == NULL) return false;
    bool grabo = fwrite(this, sizeof(Lideres), 1, p);
    fclose(p);
    return grabo;
}

/// LEER:
bool Lideres::leerLider(int pos)
{

    FILE *p;
    p = fopen("Lideres.dat","rb");
    if(p == NULL) return false;
    fseek(p, sizeof(Lideres)*pos, 0);
    bool leyo = fread(this, sizeof(Lideres), 1, p);
    fclose(p);
    return leyo;
}

/// MOSTRAR:
bool Lideres::listarLider(Lideres *uno)
{
    int input = 0;
    do
    {
        system ("cls");
        int pos = 0;

        while(this->leerLider(pos++)) {

            this->mostrarLider();
            rlutil::setColor(11);
            cout << endl;
            cout << "----------------------------------------"<<endl;
            cout << endl;
            rlutil::setColor(10);
        }
        cout << " 1- VOLVER\n";
        cin>>input;

    } while (input != 1);

    return 0; // esto no mata todo el programa? o devuelve un false?
}

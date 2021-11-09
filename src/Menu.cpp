//Nombre:Clase Menu
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
#include "Menu.h"

// Constructor:
Menu::Menu(string p_str)
{
    _texto = p_str;
}
Menu::Menu(int p_tam)
{
    _variosTextos = new string[p_tam];
    if(_variosTextos == NULL){
        cout << "Error de asingancion\n";
        return;
    }else{
        cout << "Exito\n";
    }
    _flags = new bool[p_tam];
    if(_flags == NULL){
        cout << "Error de asingancion\n";
        return;
    }else{
        cout << "Exito\n";
    }
    _tam = p_tam;

}

Menu::~Menu()
{
    delete []_variosTextos;
    delete []_flags;
}

// Metodos:

void Menu::MostrarTexto()
{
    cout << _texto << endl;
}


//Nombre:
#include <iostream>
using namespace std;
#include "Funciones.h"

void gotoxy(short px, short py){
    COORD pos;
    pos.X = px;
    pos.Y = py;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cuadro(int coluna1, int columna2, int fila1, int fila2){

    for(int col = coluna1; col <= columna2; col++)
    {
        for(int fil = fila1; fil <= fila2; fil++)
        {
            gotoxy(col, fil);
            if((col == coluna1 || col == columna2) && (fil != fila1 || fil != fila2)){
                cout << "|";
            }else if((fil == fila1 || fil == fila2) && (col != coluna1 || col != columna2)){
                cout << "--";
            }
        }
    }
}

void cuadroPuntos(int coluna1, int columna2, int fila1, int fila2){


    for(int col = coluna1; col <= columna2; col++)
    {
        for(int fil = fila1; fil <= fila2; fil++)
        {
            gotoxy(col, fil);
            if((col == coluna1 || col == columna2) && (fil != fila1 || fil != fila2)){
                cout << "·";
            }else if((fil == fila1 || fil == fila2) && (col != coluna1 || col != columna2)){
                cout << "·";
            }
        }
    }
}

void loop()
{
    // Nada por ahora
}

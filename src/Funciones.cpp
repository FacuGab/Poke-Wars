//Nombre:
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
#include "Funciones.h"
#include "Jugador.h"

/// POS
void gotoxy(short px, short py)
{
    COORD pos;
    pos.X = px;
    pos.Y = py;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/// CUADRO
void cuadro(int coluna1, int columna2, int fila1, int fila2)
{

    for(int col = coluna1; col <= columna2; col++) {
        for(int fil = fila1; fil <= fila2; fil++) {
            gotoxy(col, fil);
            if((col == coluna1 || col == columna2) && (fil != fila1 || fil != fila2)) {
                cout << "|";
            } else if((fil == fila1 || fil == fila2) && (col != coluna1 || col != columna2)) {
                cout << "--";
            }
        }
    }
}

/// CUADROS
void cuadroPuntos(int coluna1, int columna2, int fila1, int fila2)
{

    for(int col = coluna1; col <= columna2; col++) {
        for(int fil = fila1; fil <= fila2; fil++) {
            gotoxy(col, fil);
            if((col == coluna1 || col == columna2) && (fil != fila1 || fil != fila2)) {
                cout << "и";
            } else if((fil == fila1 || fil == fila2) && (col != coluna1 || col != columna2)) {
                cout << "и";
            }
        }
    }
}

/// INTRO
void intro()
{
    short titulo[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                      0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                      0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                     };///70x12
    short titulo2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                       0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                       0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                      };
    int itr = 1;
    bool flag = true;
    cout << "Cargando sistema de micropagos ...\n";
    Sleep(1500);
    cout << "Robando informacion personal ...\n";
    Sleep(1500);
    system("pause");
    cout << "иииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии\n";
    while(flag) {
        if(kbhit()) {
            flag = false;
        }
        gotoxy(0,4);
        switch(itr) {
        case 1:

            for(int a = 1; a < 840; a++) {
                if(a == 70) cout << endl;
                else if (a == 140) cout << endl;
                else if (a == 210) cout << endl;
                else if (a == 280) cout << endl;
                else if (a == 350) cout << endl;
                else if (a == 420) cout << endl;
                else if (a == 490) cout << endl;
                else if (a == 560) cout << endl;
                else if (a == 630) cout << endl;
                else if (a == 700) cout << endl;
                else if (a == 770) cout << endl;
                else if (a == 840) cout << endl;
                else {
                    (titulo[a] == 1)? cout << " " : cout << "#";
                }
            }
            itr = 2;
            break;
        case 2:

            for(int a = 1; a < 840; a++) {
                if(a == 70) cout << endl;
                else if (a == 140) cout << endl;
                else if (a == 210) cout << endl;
                else if (a == 280) cout << endl;
                else if (a == 350) cout << endl;
                else if (a == 420) cout << endl;
                else if (a == 490) cout << endl;
                else if (a == 560) cout << endl;
                else if (a == 630) cout << endl;
                else if (a == 700) cout << endl;
                else if (a == 770) cout << endl;
                else if (a == 840) cout << endl;
                else {
                    (titulo2[a] == 1)? cout << " " : cout << "#";
                }
            }
            itr = 1;
            break;
        }
        cout << endl;
        cout << "иии UN JUEGO CREADO POR EL CULTURAL TEAM CHANELL иии\n";
        cout << endl << "Pulsa cualquier tecla\n";
        Sleep(500);
    }

    /*
    for(int a = 1; a < 840; a++) {
        if(a == 70) cout << endl;
        else if (a == 140) cout << endl;
        else if (a == 210) cout << endl;
        else if (a == 280) cout << endl;
        else if (a == 350) cout << endl;
        else if (a == 420) cout << endl;
        else if (a == 490) cout << endl;
        else if (a == 560) cout << endl;
        else if (a == 630) cout << endl;
        else if (a == 700) cout << endl;
        else if (a == 770) cout << endl;
        else if (a == 840) cout << endl;
        else {(titulo[a] == 1)? cout << " " : cout << "#";}
        if(kbhit()) {
            char opc = getch();
            switch(opc)
            {
            case 'q':
                t = 0;
                break;
            }
        }
        Sleep(t);
    }
    cout << endl;
    t = 1;

    for(int a = 1; a < 840; a++) {
        if(a == 70) cout << endl;
        else if (a == 140) cout << endl;
        else if (a == 210) cout << endl;
        else if (a == 280) cout << endl;
        else if (a == 350) cout << endl;
        else if (a == 420) cout << endl;
        else if (a == 490) cout << endl;
        else if (a == 560) cout << endl;
        else if (a == 630) cout << endl;
        else if (a == 700) cout << endl;
        else if (a == 770) cout << endl;
        else if (a == 840) cout << endl;
        else {(titulo2[a] == 1)? cout << " " : cout << "#";}
        if(kbhit()) {
            char opc = getch();
            switch(opc)
            {
            case 'q':
                t = 0;
                break;
            }
        }
        Sleep(t);
    }*/
}

/// GANADOR
void ganador(const char* nombre) /// SIN USO
{
    int cont = 1;
    bool flag = true;
    char guion = '-';
    char asterisco = '#';
    system("cls");
    cout << "Pokemon de Rival debilitado!!\n";
    cout << "GANADOR:\n";
    while(flag) {
        if(kbhit()) {
            flag = false;
        }
        gotoxy(2, 2);
        if(cont == 1) {
            cout << guion << guion << guion << guion << " " <<nombre<< " " << asterisco << asterisco << asterisco << asterisco << endl;
            cont --;
            Sleep(500);
        } else {
            cout << asterisco << asterisco << asterisco << asterisco << " " <<nombre<< " " <<  guion << guion << guion << guion<< endl;
            cont ++;
            Sleep(500);
        }
    }
}

/// MOSTRAR PARTIDAS GUARDADAS
void mostrarPartidasGuardadas()
{
    cout << "     --##################--"<<endl;
    cout << "       PARTIDAS GUARDADAS"<<endl;
    cout << "     --##################--"<<"\n\n";
    cout << " Nombre"<<"   "<<" Nombre  "<<"   "<<"Puntaje"<<endl;
    cout << " Jugador"<<"  "<<" Pokemon "<<"   "<<"obtenido  ""\n"<<endl;
    Jugador partida;
    int pos = 0;
    while(partida.cargarPartida(pos++) == true) {
        partida.mostrar();
    }
}

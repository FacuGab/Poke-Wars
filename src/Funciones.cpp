//Nombre:
#include "rlutil.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
#include "Funciones.h"
#include "Jugador.h"
#include <ctime>


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
                cout << "·";
            } else if((fil == fila1 || fil == fila2) && (col != coluna1 || col != columna2)) {
                cout << "·";
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
    short color = 9;
    cout << "Cargando sistema de micropagos ...\n";
    Sleep(1500);
    cout << "Robando informacion personal ...\n";
    Sleep(1500);
    system("pause");
    cout << "·····································································\n";

    while(flag) {

        if(kbhit()) {
            flag = false;
        }
        rlutil::locate(1,5);
        switch(itr)
        {
        case 1:
            {
            rlutil::setColor(color++);
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
            }
        case 2:
            {
            rlutil::setColor(color--);
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
        }

        rlutil::setColor(15);
        cout << endl;
        cout << "··· UN JUEGO CREADO POR EL CULTURAL TEAM CHANELL ···\n";
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

/// MOSTRAR PARTIDAS GUARDADAS
void mostrarPartidasGuardadas()
{
    rlutil::setColor(14);
    cout << "                --##################--"<<endl;
    cout << "                  PARTIDAS GUARDADAS"<<endl;
    cout << "                --##################--"<<"\n\n";
    rlutil::setColor(10);
    cout << "NOMBRE  "<<"   "<<"ULTIMO  "<<"    "<<"PUNTAJE "<<"   "<<"  FECHA" <<"    "<<"    HORA"<<" " <<endl;
    cout << "JUGADOR "<<"   "<<"POKEMON"<<"     "<<"OBTENIDO"<<"   "<<"  PARTIDA"<<"   "<<"   PARTIDA"<<" "<<endl;
    Jugador partida;
    int pos = 0;
    while(partida.cargarPartida(pos++)) {
            partida.mostrar();
    }
}
/// SACAMOS FECHA/HORA DEL SISTEMA
void obtenerFechaHora(int &dia, int &mes, int &anio, int &hora, int &minuto)
{
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);

    dia=fecha->tm_mday;
    mes=fecha->tm_mon+1;
    anio=fecha->tm_year+1900;
    hora=fecha->tm_hour;
    minuto=fecha->tm_min;
}

/// TIPO
string tipo(int tipo)
{
    string tp;
    switch(tipo)
    {
    case 0:
        tp = "FUEGO";
        break;
    case 1:
        tp = "AGUA";
        break;
    case 2:
        tp = "PLANTA";
        break;
    case 3:
        tp = "ELECTRICO";
        break;
    case 4:
        tp = "BICHO";
        break;
    case 5:
        tp = "TIERRA";
        break;
    case 6:
        tp = "NORMAL";
        break;
    }
    return tp;
}

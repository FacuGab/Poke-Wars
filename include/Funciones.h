#ifndef FUNCIONES_H
#define FUNCIONES_H

void gotoxy(short px, short py);
void cuadro(int coluna1, int columna2, int fila1, int fila2);
void cuadroPuntos(int coluna1, int columna2, int fila1, int fila2);
void intro();
void mostrarPartidasGuardadas();
void obtenerFechaHora(int &dia, int &mes, int &anio, int &hora, int &minuto);
string tipo(int);

#endif // FUNCIONES_H

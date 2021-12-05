#ifndef STATS_ATAQUES_CLASS_H_INCLUDED
#define STATS_ATAQUES_CLASS_H_INCLUDED
#include <cstring>

///TIPOS:
enum TIPO
{
    FUEGO     = 0,
    AGUA      = 1,
    PLANTA    = 2,
    ELECTRICO = 3,
    BICHO     = 4,
    TIERRA    = 5,
    NORMAL    = 6
};

// ---- ATAQUE ---- //
class Ataque
{
public:
    /// Constructores:
    Ataque()
    {
        strcpy(_nombre, "nada");
        strcpy(_descripcion, "nada");
        _potencia = 0;
        _PP = 0;
        _tipo = 6;
        _prec = 0;
    }
    Ataque(const char * nom, int potencia, int PP, int tipo, int pres, const char * desc = "nada")
    {
        strcpy(_nombre, nom);
        strcpy(_descripcion, desc);
        _potencia = potencia;
        _PP = PP;
        _tipo = tipo;
        _prec = pres;
    }

    /// Gets:
    char* getNombre() { return _nombre;}
    int getPotencia() { return _potencia; }
    int getPP()       { return _PP; }
    int getTipo()     { return _tipo; }
    int getPrec()     { return _prec; }
    char* getDesc()     { return _descripcion; }

    /// Sets:
    void setNombre(const char * cad){ strcpy(_nombre, cad); }
    void setPotencia(int num)  { _potencia = num; }
    void setPP(int num)        { _PP = num; }
    void setTipo(int num)      { _tipo = num; }
    void setPrec(int num)      { _prec = num; }

private:
    char _nombre[25]; /// Nombre
    char _descripcion[100];/// Descripcion del ataque
    int _PP;          /// Cantidad de veces que se puede usar en una batalla
    int _potencia;    /// Potencia del ataque
    int _tipo;        /// Tipo
    int _prec;        /// Precision del ataque
};
//

#endif // STATS_ATAQUES_CLASS_H_INCLUDED

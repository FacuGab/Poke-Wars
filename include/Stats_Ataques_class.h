#ifndef STATS_ATAQUES_CLASS_H_INCLUDED
#define STATS_ATAQUES_CLASS_H_INCLUDED
#include <cstring>

///ESTADOS:
enum ESTADOS
{
    Paralisis  = 0, ///(causado por un ataque de tipo Eléctrico)
	Quemado    = 1, ///(causado por un ataque de tipo Fuego)
	Envenenado = 2, ///(causado por un ataque de tipo Bicho)
	Confundido = 3, ///(causado por un ataque de tipo Tierra)
	Congelado  = 4, ///(causado por un ataque de tipo Agua)
	Dormido    = 5  ///(causado por un ataque de tipo Planta)
};

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
    /// Constructor:
    Ataque()
    {
        _especial = false; // sin uso por ahora
        strcpy(_nombre, "nada");
        _potencia = 0;
        _PP = 0; // sin uso por ahora
        _tipo = 6; // sin uso por ahora
        _pres = 0; // sin uso por ahora
    }
    Ataque(bool flg, const char * nom, int potencia, int PP, int tipo, int pres)
    {
        _especial = flg;
        strcpy(_nombre, nom);
        _potencia = potencia;
        _PP = PP;
        _tipo = tipo;
        _pres = pres;
    }

    /// Gets:
    bool getEspecial(){ return _especial; }
    char* getNombre() { return _nombre;}
    int getPotencia() { return _potencia; }
    int getPP()       { return _PP; }
    int getTipo()     { return _tipo; }
    int getPres()     { return _pres; }

    /// Sets:
    void setEspecial(bool flg) { _especial = flg; }
    void setNombre(const char * cad){ strcpy(_nombre, cad); }
    void setPotencia(int num)  { _potencia = num; }
    void setPP(int num)        { _PP = num; }
    void setTipo(int num)      { _tipo = num; }
    void setPres(int num)      { _pres = num; }

private:
    bool _especial;   /// si es especial
    char _nombre[25]; /// Nombre
    int _PP;          /// Cantidad de veces que se puede usar en una batalla
    int _potencia;    /// Potencia del ataque
    int _tipo;        /// Tipo
    int _pres;        /// Precision del ataque
};
//

/* SIN USO POR AHORA
/ ---- STATS ---- //
class Stats
{
public:
    /// Constructor:
    Stats(int p_atq, int p_atqEsp, int p_def, int p_defEsp, int p_vel)
    {
        _Atq  = p_atq;
        _AtqEsp = p_atqEsp;
        _Def = p_def;
        _DefEsp = p_defEsp;
        _Vel = p_vel;
    }
    /// Gets:
    int Get_Atq()   { return _Atq; }
    int Get_AtqEsp(){ return _AtqEsp; }
    int Get_Def()   { return _Def; }
    int Get_DefEsp(){ return _DefEsp; }
    int Get_Vel()   { return _Vel; }

    /// Sets:
    void Set_Atq(int num)   { _Atq = num; }
    void Set_AtqEsp(int num){ _AtqEsp = num; }
    void Set_AtqDef(int num){ _Def = num; }
    void Set_DefEsp(int num){ _DefEsp = num; }
    void Set_Vel(int num)   { _Vel = num; }


private:
    int _Atq;    /// ataque principal
    int _AtqEsp; /// ataque especial
    int _Def;    /// defensa principal
    int _DefEsp; /// defensa especial
    int _Vel;    /// velocidad

};
/*/
#endif // STATS_ATAQUES_CLASS_H_INCLUDED

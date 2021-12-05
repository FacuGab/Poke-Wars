#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
         Fecha(){
        _dia=0;
        _mes=0;
        _anio=0;
        }
        void setDia(int d){_dia=d;}
        void setMes(int m){_mes=m;}
        void setAnio(int a){_anio=a;}
        int  getDia(){return _dia;}
        int  getMes(){return _mes;}
        int  getAnio(){return _anio;}

    private:
        int _dia;
        int _mes;
        int _anio;
};

#endif // FECHA_H

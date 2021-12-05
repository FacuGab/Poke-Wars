#ifndef HORA_H
#define HORA_H


class Hora
{
    public:
         Hora(){
        _hora=0;
        _minuto=0;
        }

        void setHora(int h){_hora=h;}
        void setMinuto(int m){_minuto=m;}
        int  getHora(){return _hora;}
        int  getMinuto(){return _minuto;}

    private:
        int _hora;
        int _minuto;
};

#endif // HORA_H

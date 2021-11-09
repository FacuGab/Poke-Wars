#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        //Constructores y destructor
        Menu(string = "Nada");
        Menu(int tam = 1);
        ~Menu();

        //Metodos
        void MostrarTexto();

    private:
        //Atributos
        string _texto;
        string* _variosTextos = NULL;
        bool* _flags = NULL;
        int _tam;



};

#endif // MENU_H

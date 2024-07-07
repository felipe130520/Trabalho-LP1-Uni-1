#ifndef ASTRONAUTAS_H
#define ASTRONAUTAS_H
#include <algorithm>
#include <string>
#include <vector>

using std::count;
using std::find;
using std::for_each;
using std::string;
using std::vector;

class Astronautas{
    private:
    string nome;
    string cpf;
    int idade;
    vector<int> voos_participados;

    public:
    bool vivo;
    bool ocupado;

    Astronautas();

    string getnome();
    string getcpf();
    int getidade();
    bool getvivo();
    bool getocupado();
    void matar(int);
    void ocupar();
    void desocupar(int);
    void print_voos_participados();
};



#endif
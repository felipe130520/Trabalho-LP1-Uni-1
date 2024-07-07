#ifndef AGENCIA_H
#define AGENCIA_H
#include <algorithm>
#include <string>
#include <vector>

#include "voos.h"
#include "astronautas.h"

using std::count;
using std::find;
using std::for_each;
using std::string;
using std::vector;

class Agencia{
    private:
    vector<Astronautas> lista_total_de_astronautas;
    vector<Voos> lista_total_de_voos;

    public:

    void cadastrar_astronauta();

    void cadastrar_voo();

    void adicionar_astro_em_voo();

    void remover_astro_de_voo();

    void lancar_voo();

    void finalizar_voo();
   
    void explodir_voo();

    void listar_mortos();

    void printar_astronauta();

    void printar_voo();
};



#endif
#ifndef VOOS_H
#define VOOS_H
#include <algorithm>
#include <string>
#include <vector>
#include "astronautas.h"

using std::count;
using std::find;
using std::for_each;
using std::string;
using std::vector;

class Voos{
private:
    int codigo_voo; //identificação do voo 
    vector<Astronautas*> lista_de_astronautas_em_voo;



public:
    int estado; // 0 == em planejamento || 1 == em voo || 2 == destruído em orbita
    Voos();
    int getcodigo_voo();
    int getestado();
    void print_astronautas();
    void pousar();
    void lancar();
    void explodir();
    void adicionar_astronautas(Astronautas*);
    void remover_astronauta(string);
    int verificar_morto_ocupado();
    int getquantidade_de_astronautas();

};


#endif 

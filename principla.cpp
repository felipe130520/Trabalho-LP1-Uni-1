#include<iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::count;
using std::find;
using std::for_each;
using std::string;
using std::vector;

#include "astronautas.h"
#include "voos.h"
#include "agencia.h"


int main(){
    Agencia nasa;
    int escolha;
    int funcionamento = 1;
    while(funcionamento == 1){ 

        std::cout << "Digite 1 para cadastrar astronauta" << std::endl;
        std::cout << "Digite 2 para cadastrar voo" << std::endl;
        std::cout << "Digite 3 para adicionar astronauta em voo" << std::endl;
        std::cout << "Digite 4 para remover astronauta em voo" << std::endl;
        std::cout << "Digite 5 para lancar voo" << std::endl;
        std::cout << "Digite 6 para finalizar voo" << std::endl;
        std::cout << "Digite 7 para explodir voo" << std::endl;
        std::cout << "Digite 8 para listar mortos" << std::endl;
        std::cout << "Digite 9 para listar astronauta especifico" << std::endl;
        std::cout << "Digite 10 para listar voo especifico" << std::endl;
        std::cout << "Digite 00 para fechar o programa" << std::endl;

        std::cin >> escolha;
        std::cin.ignore();
        switch (escolha) {
            case 1: //
                nasa.cadastrar_astronauta();
                break;
            case 2: //
                nasa.cadastrar_voo();
                break;
            case 3: //
                nasa.adicionar_astro_em_voo();
                break;
            case 4: //
                nasa.remover_astro_de_voo();
                break;
            case 5: //
                nasa.lancar_voo();
                break;
            case 6: //
                nasa.finalizar_voo();
                break;
            case 7: //
                nasa.explodir_voo();
                break;
            case 8: //
                nasa.listar_mortos();
                break;
            case 9: //
                nasa.printar_astronauta();
                break;
            case 10: //
                nasa.printar_voo();
                break;
            case 00: //
                funcionamento = 0;
                break;
        }
    }


    return 0;
}
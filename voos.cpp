#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "voos.h"


Voos::Voos(){
    std::cout << "Digite o código identificador do voo(apenas numeros): ";
    std::cin >> this->codigo_voo;
    std::cout << std::endl;
    this->estado = 0;
}

int Voos::getcodigo_voo(){
    return this->codigo_voo;
}

int Voos::getestado(){
    return this->estado;
}

void Voos::adicionar_astronautas(Astronautas* aux){
    this->lista_de_astronautas_em_voo.push_back (aux);
}

void Voos::print_astronautas(){
    int tamanho = lista_de_astronautas_em_voo.size();
    for(int j=0; j<tamanho; j++){
        std::cout <<"Nome:" << this->lista_de_astronautas_em_voo[j]->getnome() << std::endl;
        std::cout <<"CPF:" << this->lista_de_astronautas_em_voo[j]->getcpf() << std::endl;
        std::cout <<"Idade:" << this->lista_de_astronautas_em_voo[j]->getidade() << std::endl;            
        std::cout <<"Saude:" << this->lista_de_astronautas_em_voo[j]->getvivo() << std::endl;
        std::cout <<"Condicao:" << this->lista_de_astronautas_em_voo[j]->getocupado() << std::endl;
    }
}

void Voos::remover_astronauta(string cpf){
    int tamanho = lista_de_astronautas_em_voo.size();
    int index;
    for(int i =0; i< tamanho; i++){
        if(cpf== this->lista_de_astronautas_em_voo[i]->getcpf()){
            index = i;
        }
    }
    this->lista_de_astronautas_em_voo.erase(lista_de_astronautas_em_voo.begin()+index);
}

int Voos::verificar_morto_ocupado(){
    int tamanho = lista_de_astronautas_em_voo.size();
    int achou=0;
    for(int i = 0; i<tamanho; i++ ){
        if (this->lista_de_astronautas_em_voo[i]->getocupado() == 1 ) {
            achou = 1;
            break;
        } if (this->lista_de_astronautas_em_voo[i]->getvivo() == 0 ) {
            achou = 1;
            break;
        }
    }
    return achou;
}

int Voos::getquantidade_de_astronautas(){
    return lista_de_astronautas_em_voo.size();
}

void Voos::lancar(){
    this->estado = 1;
    int tamanho = lista_de_astronautas_em_voo.size();
    for(int i = 0; i<tamanho; i++){
        this->lista_de_astronautas_em_voo[i]->ocupar();
    }
}

void Voos::explodir(){
    this->estado = 2;
    int tamanho = lista_de_astronautas_em_voo.size();
    for(int i = 0; i<tamanho; i++){
        this->lista_de_astronautas_em_voo[i]->matar(this->getcodigo_voo());
    }
}

void Voos::pousar(){
    this->estado = 0;
    int tamanho = lista_de_astronautas_em_voo.size();
    for(int i = 0; i<tamanho; i++){
        this->lista_de_astronautas_em_voo[i]->desocupar(this->getcodigo_voo());
    }
}

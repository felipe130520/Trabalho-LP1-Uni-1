#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "agencia.h"


void Agencia::cadastrar_astronauta() {
    this->lista_total_de_astronautas.resize(this->lista_total_de_astronautas.size() + 1);
}

void Agencia::cadastrar_voo() {
    this->lista_total_de_voos.resize(this->lista_total_de_voos.size() + 1);
}

void Agencia::adicionar_astro_em_voo() {
    int achou_codigo = 0, index_voo, index_astronauta, achou_cpf = 0;
    string cpf_aux;
    int codigo_aux;

    std::cout << "Digite o código do voo ao qual o astronauta será adicionado:" << std::endl;
    std::cin >> codigo_aux;

    for (int i = 0; i < this->lista_total_de_voos.size(); i++) {
        if (this->lista_total_de_voos[i].getcodigo_voo() == codigo_aux) {
            achou_codigo = 1;
            index_voo = i;
            break; 
        }
    }

    if (achou_codigo == 0) {
        std::cout << "Esse código de voo não corresponde a nenhum voo registrado." << std::endl;
        return;
    } else if (this->lista_total_de_voos[index_voo].getestado() != 0){
        std::cout << "Esse voo não esta em planejamento, nao tem como adicionar astronautas." << std::endl;
        return;
    } else{
        std::cout << "Digite o CPF do astronauta que será adicionado:" << std::endl;
        std::cin >> cpf_aux;
    }

    for (int i = 0; i < this->lista_total_de_astronautas.size(); i++) {
        if (this->lista_total_de_astronautas[i].getcpf() == cpf_aux) {
            achou_cpf = 1;
            index_astronauta = i;
            break; 
        }
    }

    if (achou_cpf == 0) {
        std::cout << "Esse CPF não corresponde a nenhum astronauta registrado." << std::endl;
        return;
    }

    if (this->lista_total_de_astronautas[index_astronauta].getvivo() == 0) {
        std::cout << "Esse astronauta esta morto, nao tem como adiciona-lo." << std::endl;
        return;
    } else {
        this->lista_total_de_voos[index_voo].adicionar_astronautas(&this->lista_total_de_astronautas[index_astronauta]);
    }
}

void Agencia::remover_astro_de_voo(){
    int achou_codigo = 0, index_voo, achou_cpf = 0;
    string cpf_aux, index_astronauta;
    int codigo_aux;

    std::cout << "Digite o código do voo ao qual o astronauta será removido:" << std::endl;
    std::cin >> codigo_aux;

    for (int i = 0; i < this->lista_total_de_voos.size(); i++) {
        if (this->lista_total_de_voos[i].getcodigo_voo() == codigo_aux) {
            achou_codigo = 1;
            index_voo = i;
            break; 
            if(this->lista_total_de_voos[i].getestado() == 1){
                std::cout << "Nao da para remover um astronauta de um voo em andamento." << std::endl;
                return;
            }else if(this->lista_total_de_voos[i].getestado() == 2){
                std::cout << "Nao da para remover um astronauta de um voo que explodiu." << std::endl;
                return;
            }
        }
    }

    if (achou_codigo == 0) {
        std::cout << "Esse código de voo não corresponde a nenhum voo registrado." << std::endl;
        return;
    } else if (this->lista_total_de_voos[index_voo].getestado() != 0){
        std::cout << "Esse voo não esta em planejamento, nao tem como remover astronautas." << std::endl;
        return;
    } else {
        std::cout << "Digite o CPF do astronauta que será removido:" << std::endl;
        std::cin >> cpf_aux;
    }

    for (int i = 0; i < this->lista_total_de_astronautas.size(); i++) {
        if (this->lista_total_de_astronautas[i].getcpf() == cpf_aux) {
            achou_cpf = 1;
            index_astronauta = this->lista_total_de_astronautas[i].getcpf();
            break; 
        }
    }

    if (achou_cpf == 0) {
        std::cout << "Esse CPF não corresponde a nenhum astronauta registrado." << std::endl;
        return;
    }else{
        this->lista_total_de_voos[index_voo].remover_astronauta(index_astronauta);
    }


}

void Agencia::printar_astronauta() {
    string cpf_aux;
    int achou = 0;
    std::cout << "Digite o cpf do astronauta(sem pontos ou hífen): ";
    std::getline (std::cin, cpf_aux);
    std::cout << std::endl;
    int tamanho_lista_total_de_astronautas;
    tamanho_lista_total_de_astronautas = this->lista_total_de_astronautas.size();
    for(int i=0; i<tamanho_lista_total_de_astronautas; i++){
        if(this->lista_total_de_astronautas[i].getcpf() == cpf_aux){
            std::cout <<"Nome:" << this->lista_total_de_astronautas[i].getnome() << std::endl;
            std::cout <<"CPF:" << this->lista_total_de_astronautas[i].getcpf() << std::endl;
            std::cout <<"Idade:" << this->lista_total_de_astronautas[i].getidade() << std::endl;
            std::cout <<"Saude:" << this->lista_total_de_astronautas[i].getvivo() << std::endl;
            std::cout <<"Condicao:" << this->lista_total_de_astronautas[i].getocupado() << std::endl;
            achou = 1;  
        }
    }
    if (achou == 0){
        std::cout << "Não foi encontrado um astronauta com esse cpf." << std::endl;
        
    }
}

void Agencia::printar_voo() {
    int codigo_aux;
    int achou = 0;
    std::cout << "Digite o codigo do voo ";
    std::cin >> codigo_aux;
    std::cin.ignore();
    int tamanho_lista_total_de_voos;
    tamanho_lista_total_de_voos = this->lista_total_de_voos.size();
    for(int i=0; i<tamanho_lista_total_de_voos; i++){
        if(this->lista_total_de_voos[i].getcodigo_voo() == codigo_aux){
            std::cout <<"Codigo do voo:" << this->lista_total_de_voos[i].getcodigo_voo() << std::endl;
            std::cout <<"estado:" << this->lista_total_de_voos[i].getestado() << std::endl;
            this->lista_total_de_voos[i].print_astronautas();
            achou = 1;        
        }
    }
    if (achou == 0){
        std::cout << "Não foi encontrado um voo com esse codigo." << std::endl;
        
    }
    
}

void Agencia::lancar_voo(){
    int achou_codigo=0, codigo_aux, index_voo;
    std::cout << "Digite o codigo do voo a ser lancado:" << std::endl;
    std::cin >> codigo_aux;

    for (int i = 0; i < this->lista_total_de_voos.size(); i++) {
        if (this->lista_total_de_voos[i].getcodigo_voo() == codigo_aux) {
            achou_codigo = 1;
            index_voo = i;
            break; 
        }
    }
    
    if (achou_codigo == 0) {
        std::cout << "Esse código de voo não corresponde a nenhum voo registrado." << std::endl;
        return;
    } if (this->lista_total_de_voos[index_voo].getquantidade_de_astronautas() < 1) {
        std::cout << "Esse voo nao tem astronautas suficientes, o minimo e 1." << std::endl;
        return;
    } if (this->lista_total_de_voos[index_voo].verificar_morto_ocupado() == 1) {
        std::cout << "Esse voo contem um(uns) astronauta(s) morto(s) ou ocupado(s), nao e possivel lancar." << std::endl;
        return;
    }
    this->lista_total_de_voos[index_voo].lancar();

}

void Agencia::explodir_voo(){
    int achou_codigo=0, codigo_aux, index_voo;
    std::cout << "Digite o codigo do voo a ser explodido:" << std::endl;
    std::cin >> codigo_aux;

    for (int i = 0; i < this->lista_total_de_voos.size(); i++) {
        if (this->lista_total_de_voos[i].getcodigo_voo() == codigo_aux) {
            achou_codigo = 1;
            index_voo = i;
            break; 
        }
    }
    
    if (achou_codigo == 0) {
        std::cout << "Esse código de voo não corresponde a nenhum voo registrado." << std::endl;
        return;
    } else if (this->lista_total_de_voos[index_voo].getestado() != 1) {
        std::cout << "Nao tem como explodir voo que nao foi lancado." << std::endl;
        return;
    }
    this->lista_total_de_voos[index_voo].explodir();
    
}

void Agencia::finalizar_voo(){
    int achou_codigo=0, codigo_aux, index_voo;
    std::cout << "Digite o codigo do voo a ser finalizado:" << std::endl;
    std::cin >> codigo_aux;

    for (int i = 0; i < this->lista_total_de_voos.size(); i++) {
        if (this->lista_total_de_voos[i].getcodigo_voo() == codigo_aux) {
            achou_codigo = 1;
            index_voo = i;
            break; 
        }
    }
    
    if (achou_codigo == 0) {
        std::cout << "Esse código de voo não corresponde a nenhum voo registrado." << std::endl;
        return;
    } else if (this->lista_total_de_voos[index_voo].getestado() != 1) {
        std::cout << "Nao tem como pousar um voo que nao foi lancado." << std::endl;
        return;
    }
    this->lista_total_de_voos[index_voo].pousar();
    
}

void Agencia::listar_mortos(){
    int tamanho = this->lista_total_de_astronautas.size();
    for (int i = 0; i < tamanho; i++) {
        if (lista_total_de_astronautas[i].getvivo() == 0) {
            std::cout << "Nome:" << lista_total_de_astronautas[i].getnome() << std::endl;
            lista_total_de_astronautas[i].print_voos_participados();
        }
    }
}

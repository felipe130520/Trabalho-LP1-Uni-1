#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "astronautas.h"


Astronautas::Astronautas(){
    std::cout << "Digite o nome do astronauta: ";
    std::getline (std::cin, this->nome);
    std::cout << std::endl;
    std::cout << "Digite o cpf do astronauta(sem pontos ou hífen): ";
    std::getline (std::cin, this->cpf);
    std::cout << std::endl;
    std::cout << "Digite a idade do astronauta: ";
    std::cin >> this->idade;
    std::cout << std::endl;
    this->vivo = true;
    this->ocupado = false;

}

string Astronautas::getnome(){
    return this->nome;

}

string Astronautas::getcpf(){
    return this->cpf;
    
}

int Astronautas::getidade(){
    return this->idade;
    
}

bool Astronautas::getvivo(){
    return this->vivo;
    
}

bool Astronautas::getocupado(){
    return this->ocupado;
    
}

void Astronautas::matar(int aux){
    this->vivo = false;
    this->ocupado = false;
    this->voos_participados.push_back(aux);
}

void Astronautas::ocupar(){
    this->ocupado = true;
}

void Astronautas::desocupar(int aux){
    this->ocupado = false;
    this->voos_participados.push_back(aux);
}

void Astronautas::print_voos_participados(){
    int tamanho = voos_participados.size();
    for(int i=0; i < tamanho; i++){
        std::cout << voos_participados[i] << std::endl;
    }
}

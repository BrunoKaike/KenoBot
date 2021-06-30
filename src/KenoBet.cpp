#include "../include/KenoBet.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

bool KenoBet::add_number( number_type spot_ ){
    for(int i=0; i<this->m_spots.size(); i++)
        if(spot_ == this->m_spots[i])
            return false;
    this->m_spots.push_back(spot_);
    
    return true;
}

bool KenoBet::set_wage( cash_type wage_ ){
    if(wage_ <= 0)
        return false;
    m_wage = wage_;
    return true;
}

void KenoBet::reset( void ){
    //ZERAR LISTAS
}

cash_type KenoBet::get_wage( void ) const{
    return m_wage;
}

size_t KenoBet::size( void ) const{
    return this->m_spots.size();
}

set_of_numbers_type KenoBet::get_hits( const set_of_numbers_type & hits_ ) const{
    set_of_numbers_type saida;

    for(int i=0; i<this->m_spots.size(); i++){
        for(int j=0; j<hits_.size(); j++)
            if(this->m_spots[i] == hits_[j]){
                saida.push_back(m_spots[i]);
                break;
            }
    }
    return saida;
}

set_of_numbers_type KenoBet::get_spots( void ) const{
    return this->m_spots;
}



//+++++++++++++NOVOS+++++++++++++
void KenoBet::set_m_sorteados(){
    int random, apto;

    //Limpar caso tiver numeros
    if(this->m_sorteados.size()>0)
        this->m_sorteados.clear();

    //Sorteio de 20 numeros
    while(this->m_sorteados.size()<20){
        apto = 1;
        random = (rand() % 80) + 1;
        for(int i=0; i<this->m_sorteados.size(); i++)
            if(this->m_sorteados[i] == random){
                apto = 0;
                break;
            }
        if(apto == 1)
            this->m_sorteados.push_back(random);
    }

}
set_of_numbers_type KenoBet::get_m_sorteados(){
    return this->m_sorteados;
}

void KenoBet::set_hits(){
    this->m_hits = get_hits(this->m_sorteados);
}

void KenoBet::print_wage(){
    cout<<this->get_wage();
}

void KenoBet::print_sorteados(){
    //Preenche m_sorteados com 20 numeros aleatorios
    set_m_sorteados();
    //Printa sorteados
    cout<<"[ ";
    for(int i=0; i<20; i++)
        cout<<this->m_sorteados[i]<<" ";
    cout<<"]"<<endl<<endl;
}

void KenoBet::print_spots(){
    set_of_numbers_type num_apostados = this->get_spots();

    cout<<"[ ";
    for(int i=0; i<this->size(); i++)
        cout<<num_apostados[i]<<" ";
    cout<<"]\n\n";
}

void KenoBet::print_hits(){
    set_hits();
    cout<<"[ ";
    for(int i=0; i<m_hits.size(); i++)
        cout<<m_hits[i]<<" ";
    cout<<"]\n\n";
}

size_t KenoBet::size_hits(){
    return this->m_hits.size();
}
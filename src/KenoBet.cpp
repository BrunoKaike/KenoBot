#include "../include/KenoBet.hpp"

using namespace std;
set_retorno tabela_de_retorno={
    {-1},
    {0, 3},
    {0, 1, 9},
    {0, 1, 2, 16},
    {0, 0.5, 2, 6, 12},
    {0, 0.5, 1, 3, 15, 50},
    {0, 0.5, 1, 2, 3, 30, 75},
    {0, 0.5, 0.5, 1, 6, 12, 36, 100},
    {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
    {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
    {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
    {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
    {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
    {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
    {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
    {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}
}; /**< Matriz de set_retorno que representa os multiplicadores de retorno */
vector<string> reacao_retorno={"Hooray! você ganhou $","Quem sabe na próxima? você manteve $","Mais sorte da próxima! você perdeu $", "Você levantou com o pé esquerdo hoje! Você perdeu $"}; /**< Vetor de string que representa as reações de resposta ao final da última rodada */

//! Uma função para adicionar um número a lista de números apostados.
/*!
* \param spot_ um number_type que representa o novo número a ser apostado.
* \return um booleano.
*/
bool KenoBet::add_number( number_type spot_ ){
    for(int i=0; i<this->m_spots.size(); i++)
        if(spot_ == this->m_spots[i])
            return false;
    this->m_spots.push_back(spot_);
    
    return true;
}

//! Uma função para settar o valor de créditos atual.
/*!
* \param wage_ um number_type que representa o novo valor de créditos.
* \return um booleano.
*/
bool KenoBet::set_wage( cash_type wage_ ){
    if(wage_ <= 0)
        return false;
    m_wage = wage_;
    return true;
}

//! Uma função para limpar todos os valores atribuidos ao final de uma rodada.
/*!
*/
void KenoBet::reset( void ){
    this->m_rounds = this->m_round_wage = this->m_wage = 0;
    this->m_spots.clear();
    this->m_hits.clear();
    this->m_sorteados.clear();
}

//! Uma função para retornar o valor de créditos atual.
/*!
* \return um cash_type.
*/
cash_type KenoBet::get_wage( void ) const{
    return m_wage;
}

//! Uma função para retornar a quantidade de números apostados.
/*!
* \return um size_t.
*/
size_t KenoBet::size( void ) const{
    return this->m_spots.size();
}

//! Uma função para retornar os números apostados.
/*!
* \param hits_ um vetor de number_type que representa os números apostados.
* \return set_of_numbers_type.
*/
set_of_numbers_type KenoBet::get_hits( const set_of_numbers_type & hits_ ) const{
    set_of_numbers_type saida; /**< set_of_numbers_type que irá armazenar os números apostados */

    for(int i=0; i<this->m_spots.size(); i++){
        for(int j=0; j<hits_.size(); j++)
            if(this->m_spots[i] == hits_[j]){
                saida.push_back(m_spots[i]);
                break;
            }
    }
    return saida;
}

//! Uma função para retornar o vetor contendo os acertos.
/*!
* \return um set_of_numbers_type.
*/
set_of_numbers_type KenoBet::get_spots( void ) const{
    return this->m_spots;
}

//! Uma função para settar a lista dos números sorteados
/*!
*/
void KenoBet::set_m_sorteados(){
    int random; /**< int que representa o número randômico */
    int apto; /**< int que representa se o número é repitido(0) ou não (1) */
    
    this->m_sorteados.clear();
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
    this->m_sorteados = sort(this->m_sorteados);
}

//! Uma função para retornar a lista dos números sorteados
/*!
* \return um set_of_numbers_type.
*/
set_of_numbers_type KenoBet::get_m_sorteados(){
    return this->m_sorteados;
}

//! Uma função para settar os acertos
/*!
* \return um set_of_numbers_type.
* \sa get_hits() 
*/
void KenoBet::set_hits(){
    this->m_hits = get_hits(this->m_sorteados);
}

//! Uma função para imprimir o valor de créditos atuais
/*!
*/
void KenoBet::print_wage(){
    cout<<this->get_wage();
}

//! Uma função para imprimir os números sorteados
/*!
* \sa set_m_sorteados() 
*/
void KenoBet::print_sorteados(){
    set_m_sorteados();
    cout<<"[ ";
    for(int i=0; i<20; i++)
        cout<<this->m_sorteados[i]<<" ";
    cout<<"]"<<endl<<endl;
}

//! Uma função para imprimir os números apostados
/*!
*/
void KenoBet::print_spots(){
    set_of_numbers_type num_apostados = this->get_spots();

    cout<<"[ ";
    for(int i=0; i<this->m_spots.size(); i++)
        cout<<num_apostados[i]<<" ";
    cout<<"]";
}

//! Uma função para imprimir os acertos
/*!
*/
void KenoBet::print_hits(){
    set_hits();
    cout<<"[ ";
    for(int i=0; i<m_hits.size(); i++)
        cout<<m_hits[i]<<" ";
    cout<<"]";
}

//! Uma função para imprimir a quantidade de acertos
/*!
* \return um size_t.
*/
size_t KenoBet::size_hits(){
    return this->m_hits.size();
}

//! Uma função para settar a quantidade de rodadas
/*!
* \param rodadas um number_type que representa a quantidade de rodadas.
*/
void KenoBet::set_rounds(number_type rodadas){
    this->m_rounds = rodadas;
}

//! Uma função para retornar a quantidade de rodadas
/*!
* \return um number_type.
*/
number_type KenoBet::get_rounds(){
    return this->m_rounds;
}

//! Uma função para settar o valor em créditos apostado por rodada.
/*!
*/
void KenoBet::set_round_wage(){
    this->m_round_wage = this->m_wage/this->m_rounds;
}

//! Uma função para retornar o valor em créditos apostado por rodada.
/*!
* \return um cash_type.
*/
cash_type KenoBet::get_round_wage(){
    return this->m_round_wage;
}

//! Uma função para retornar o valor de retorno em créditos da rodada.
/*!
* \return um cash_type.
*/
cash_type KenoBet::get_after_round_wage(){
    return this->get_round_wage()*(tabela_de_retorno[this->get_spots().size()][this->m_hits.size()]);;
}

//! Uma função para settar o novo valor atual em créditos ao final de cada rodada.
/*!
*/
void KenoBet::update_wage(){
    this->m_wage = this->m_wage - this->m_round_wage + this->get_round_wage()*(tabela_de_retorno[this->get_spots().size()][this->m_hits.size()]);
}

//! Uma função para retornar a taxa de retorno de uma rodada.
/*!
* \return um number_type.
*/
number_type KenoBet::get_retorno_round(){
    return (tabela_de_retorno[this->get_spots().size()][this->m_hits.size()]);
}

//! Uma função para settar o valor em créditos do valor apostado incialmente.
/*!
* \param wage_ um cash_type que representa o valor atual em créditos.
* \return um booleano.
*/
bool KenoBet::set_inicial_wage( cash_type wage_ ){
    if(wage_ <= 0)
        return false;
    this->inicial_m_wage = wage_;
    return true;
}

//! Uma função para retornar o valor em créditos do valor apostado incialmente.
/*!
* \return um cash_type.
*/
cash_type KenoBet::get_inicial_wage( void ) const{
    return inicial_m_wage;
}

//! Uma função para retornar o retorno esperado.
/*!
* \param a um number_type que representa a taxa de retorno com base na quantidade de números apostados.
* \param b um number_type que representa a taxa de retorno com base na quantidade de acertos.
* \return um cash_type.
*/
cash_type KenoBet::get_retorno_espe(number_type a, number_type b){
    return tabela_de_retorno[a][b];
}

//! Uma função para retornar o a reação baseado no retorno.
/*!
* \param a um inteiro que representa uma posição na lista de reações de resposta.
* \return uma string.
*/
string KenoBet::get_reacao_retorno(number_type a){
    return reacao_retorno[a];
}

//! Uma função para imprimir a reação baseado no retorno.
/*!
* \param inicial um cash_type que representa o valor em créditos da aposta inicial.
* \param final um cash_type que representa o valor em créditos da receita atual ao fim de todas as rodadas.
* \sa get_reacao_retorno() 
*/
void KenoBet::print_reacao(cash_type inicial, cash_type final){
    if(final > inicial)
        cout <<">>> "<< get_reacao_retorno(0) << final - inicial << " créditos!"<< endl;
    else if(inicial == final)
        cout <<">>> "<< get_reacao_retorno(1) << final << " créditos."<< endl;
    else if(final < inicial && final>0)
        cout <<">>> "<< get_reacao_retorno(2) << inicial - final << " créditos."<< endl;
    else
        cout <<">>> "<< get_reacao_retorno(3) << inicial - final << " créditos."<< endl;
}

//! Uma função para realizar a troca de valores entre dois iterators.
/*!
* \param first um InputIt que representa um iterator.
* \param second um InputIt que representa um iterator.
*/
template<class InputIt>
void KenoBet::swap(InputIt first, InputIt second){
    auto aux = *first;
    *first = *second;
    *second = aux;
}

//! Uma função para ordenar uma lista de set_of_numbers_type de forma crescente.
/*!
* \param lista um set_of_numbers_type que representa uma lista de números apostados/acertados/sorteados.
* \return um set_of_numbers_type.
* \sa swap() 
*/
set_of_numbers_type KenoBet::sort(set_of_numbers_type lista){
    for(int x = 0; x < lista.size()-1; x++)
      for(int i = 0; i < lista.size()-x-1; i++)
        if(lista[i] > lista[i+1])
            swap(&lista[i], &lista[i+1]);
    return lista;
}

//! Uma função para ordenar a lista de números apostados.
/*!
* \sa sort() 
*/
void KenoBet::sort_spots(){
    this->m_spots = sort(this->m_spots);
}

KenoBet::~KenoBet(){};

#ifndef VALIDATION
#define VALIDATION

#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

// Retorna true se uma string contém um número inteiro ou real
bool is_number(string entrada);

// Retorna true se uma string contém menos de 2 pontos flutuantes
bool qtd_pontos(string entrada);

// Retorna true se uma string contém uma lista de números separados por espaço
bool all_is_numbers(string linha);

// Retorna true se em uma string que contém uma lista de números separados por espaço todos os números estão no intervalo (1,80)
bool all_is_in_the_range(string linha);

// Retorna true se em uma string que contém uma lista de números separados por espaço não possui números repetidos
bool repet_num(string linha);

// Retorna true se em uma string que contém uma lista de números separados por espaço possui no mínimo 1 número e no máximo 15
bool qtd_num_aposta(string linha);

// Retorna true se o arquivo do diretório recebido existe
bool arq_inexistente(string local);

// Retorna true se o arquivo segue a formatação determinada pelo projeto
bool is_formated(std::fstream& file);

// Retorna um vetor de strings contendo os erros na validação, caso existam.
vector<string> validate(string local);

#endif

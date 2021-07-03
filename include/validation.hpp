#ifndef VALIDATION
#define VALIDATION

#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

bool is_number(string entrada);

bool all_is_numbers(string linha);

bool all_is_in_the_range(string linha);

bool repet_num(string linha);

bool qtd_num_aposta(string linha);

bool arq_inexistente(string local);

bool is_formated(std::fstream& file);

vector<string> validate(string local);

#endif
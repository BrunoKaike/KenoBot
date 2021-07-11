#include "../include/validation.hpp"


vector<string> errorMessage = {"Arquivo não encontrado! tente um novo diretório.",
"O arquivo não está de acordo com a formatação definida.",
"Uma ou mais apostas houveram repetição de números.",
"Uma ou mais apostas possuem um número inválido",
"Possui caracteres estranhos ou mais de uma entrada",
"Possui mais de um ponto flutuante",
"Quantidade de números apostados superior a 15 ou inferior a 1",
"Lista de números apostados possui caracteres estranhos",
}; /**< Vetor de string contendo todos os possíveis erros de validação */

vector<string> errors_return; /**< Vetor de string que irá armazenar os erros de validação, caso sejam encontrados */

//! Uma função para identificar se uma string contém apenas números ou pontos.
/*!
* \param entrada uma string que representa um fragmento do arquivo de texto contendo o valor apostado ou o número de rodadas.
* \return um booleano.
*/
bool is_number(string entrada){
    return !entrada.empty() && std::find_if(entrada.begin(),
        entrada.end(), [](unsigned char c) { return !std::isdigit(c) && c!='.'; }) == entrada.end();
}

//! Uma função para identificar se uma string contém mais de 1 ponto flutuante.
/*!
* \param entrada uma string que representa um fragmento do arquivo de texto contendo o valor apostado.
* \return um booleano.
*/
bool qtd_pontos(string entrada){
    int pontos = 0;
    for(auto i = entrada.begin(); i != entrada.end(); i++){
        if(*i=='.'){
            pontos++;
        }
    }
    return pontos <= 1;
}

//! Uma função para identificar se uma string contém uma lista de inteiros separados por espaço.
/*!
* \param linha uma string que representa um fragmento do arquivo de texto contendo os números apostados.
* \return um booleano.
*/
bool all_is_numbers(string linha){
    size_t start; /**< size_t representando uma posição da string, usado para definir a partir de que ponto está o valor a ser validado */
    size_t end = 0; /**< size_t representando uma posição da string, usado para definir até que ponto está o valor a ser validado */
    string aux; /**< String representando número a ser validado, caso seja um inteiro */

    while((start = linha.find_first_not_of(" ", end)) != std::string::npos){
        end = linha.find(" ", start);
        aux = linha.substr(start, end - start);

        if(!(!aux.empty() && std::find_if(aux.begin(),
        aux.end(), [](unsigned char c) { return !std::isdigit(c); }) == aux.end())){

            return false;

        }

    }

    return true;
}

//! Uma função para identificar se uma string contém uma lista de inteiros separados por espaço que estão entre o intervalo (1,80).
/*!
* \param linha uma string que representa um fragmento do arquivo de texto contendo os números apostados.
* \return um booleano.
*/
bool all_is_in_the_range(string linha){
    stringstream ss; /**< string stream que será usado para converter o fragmento de string para inteiro */
    size_t start; /**< size_t representando uma posição da string, usado para definir a partir de que ponto está o valor a ser validado */
    size_t end = 0; /**< size_t representando uma posição da string, usado para definir até que ponto está o valor a ser validado */
    int aux; /**< int representando o número a ser validado, caso não seja uma duplicata */

    while((start = linha.find_first_not_of(" ", end)) != std::string::npos){
        end = linha.find(" ", start);
        ss.clear();
        ss << linha.substr(start, end - start);
        ss >> aux;

        if(!(aux>= 1 && aux <=80)){

            return false;

        }

    }

    return true;
}

//! Uma função para identificar se uma string contém uma lista de inteiros separados por espaço que não possuem números repitidos).
/*!
* \param linha uma string que representa um fragmento do arquivo de texto contendo os números apostados.
* \return um booleano.
*/
bool repet_num(string linha){
    stringstream ss; /**< string stream que será usado para converter o fragmento de string para inteiro */
    size_t start; /**< size_t representando uma posição da string, usado para definir a partir de que ponto está o valor a ser validado */
    size_t end = 0; /**< size_t representando uma posição da string, usado para definir até que ponto está o valor a ser validado */
    int aux; /**< int representando o número a ser validado, caso não seja uma duplicata */
    vector<int> numeros;

    while((start = linha.find_first_not_of(" ", end)) != std::string::npos){
        end = linha.find(" ", start);
        ss.clear();
        ss << linha.substr(start, end - start);
        ss >> aux; 
        for(int i=0; i<numeros.size(); i++){
            if(aux==numeros[i])
                return false;
        }
        numeros.push_back(aux);
    }

    return true;
}

//! Uma função para identificar se uma string contém uma lista de 1 a 15 inteiros separados por espaço).
/*!
* \param linha uma string que representa um fragmento do arquivo de texto contendo os números apostados.
* \return um booleano.
*/
bool qtd_num_aposta(string linha){
    size_t start; /**< size_t representando uma posição da string, usado para definir a partir de que ponto está o valor a ser validado */
    size_t end = 0; /**< size_t representando uma posição da string, usado para definir até que ponto está o valor a ser validado */
    int cont=0; /**< inteiro representando a quantidade de números separados por espaço presentes na string */

    while((start = linha.find_first_not_of(" ", end)) != std::string::npos){
        end = linha.find(" ", start);
        cont++;
    }

    if(cont>=1 && cont<=15)
        return true;
    return false;
}

//! Uma função para verificar se o arquivo existe.
/*!
* \param local uma string que representa o diretório do arquivo.
* \return um booleano.
*/
bool arq_inexistente(string local){
    std::fstream file; /**< fstream representando um fluxo de entrada/saída para operar em arquivos */
    file.open (local);
    if(!file)
        return false;

    return true;
}

//! Uma função para validar a formatação do arquivo.
/*!
\param file um fstream que representa o arquivo a ser validado.
\return um booleano.
\sa is_number(), qtd_num_aposta(), all_is_numbers(), repet_num() and all_is_in_the_range()  
*/
bool is_formated(std::fstream& file){
    
    while(!file.eof()){ 
            
        string lineFromFile;
        
        //Passagem do valor
        getline( file, lineFromFile );
        if(!is_number(lineFromFile)){
            errors_return.push_back(errorMessage[4]);
            return false;
            
        }
        
        if(!qtd_pontos(lineFromFile)){
            errors_return.push_back(errorMessage[5]);
            return false;
            
        }

        //Passagem das rodadas
        getline( file, lineFromFile );
        if(!is_number(lineFromFile)){
            errors_return.push_back(errorMessage[4]);
            return false;
            
        }
        

        //Passagem dos numeros apostados
        getline(file, lineFromFile);
        if(!qtd_num_aposta(lineFromFile)){
            errors_return.push_back(errorMessage[6]);
            return false;
            
        }
        
        if(!all_is_numbers(lineFromFile)){
            errors_return.push_back(errorMessage[7]);
            return false;
            
        }
        
        if(!repet_num(lineFromFile)){
            errors_return.push_back(errorMessage[2]);
            return false;
            
        }
        
        if(!all_is_in_the_range(lineFromFile)){
            errors_return.push_back(errorMessage[3]);
            return false;
            
        }
    
    }
    
    return true;

}

//! Uma função principal para chamar as demais validações.
/*!
\param local uma string que representa o diretório do arquivo a ser validado.
\return um vetor de string.
\sa arq_inexistente() and is_formated()  
*/
vector<string> validate(string local)
{   
    
    if(arq_inexistente(local)){
        
        std::fstream file;
        file.open (local);
        if(is_formated(file)){
            
            
        } else {
        
            errors_return.push_back(errorMessage[1]);
            return errors_return;
    
        }
        
    } else {
        errors_return.push_back(errorMessage[0]);
        return errors_return;
    }
    
    return errors_return;
}

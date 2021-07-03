#include "../include/validation.hpp"

vector<string> errorMessage = {"Arquivo não encontrado! tente um novo diretório.",
"O arquivo não está de acordo com a formatação definida.",
"Uma ou mais apostas houveram repetição de números.",
"Uma ou mais apostas possuem um número inválido"};
vector<string> errors_return;

bool is_number(string entrada){
    return !entrada.empty() && std::find_if(entrada.begin(),
        entrada.end(), [](unsigned char c) { return !std::isdigit(c) && c!='.'; }) == entrada.end();
}

bool all_is_numbers(string linha){
    stringstream ss;
    size_t start;
    size_t end = 0;
    string aux;

    while((start = linha.find_first_not_of(" ", end)) != std::string::npos){
        end = linha.find(" ", start);
        ss.clear();
        ss << linha.substr(start, end - start);
        ss >> aux;

        if(!(!aux.empty() && std::find_if(aux.begin(),
        aux.end(), [](unsigned char c) { return !std::isdigit(c); }) == aux.end())){

            return false;

        }

    }

    return true;
}

bool all_is_in_the_range(string linha){
    stringstream ss;
    size_t start;
    size_t end = 0;
    int aux;

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

bool repet_num(string linha){
    stringstream ss;
    size_t start;
    size_t end = 0;
    int aux;
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

bool qtd_num_aposta(string linha){
    size_t start;
    size_t end = 0;
    int cont=0;

    while((start = linha.find_first_not_of(" ", end)) != std::string::npos){
        end = linha.find(" ", start);
        cont++;
    }

    if(cont>=1 && cont<=15)
        return true;
    return false;
}

bool arq_inexistente(string local){
    std::fstream file;
    file.open (local);
    if(!file)
        return false;

    return true;
}

bool is_formated(std::fstream& file){
    
    while(!file.eof()){ 
            
        string lineFromFile;
        
        //Passagem do valor
        getline( file, lineFromFile );
        if(!is_number(lineFromFile)){
            
            return false;
            
        }

        //Passagem das rodadas
        getline( file, lineFromFile );
        if(!is_number(lineFromFile)){
            
            return false;
            
        }
        

        //Passagem dos numeros apostados
        getline(file, lineFromFile);
        if(!qtd_num_aposta(lineFromFile)){
            
            return false;
            
        }
        
        if(!all_is_numbers(lineFromFile)){
            
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
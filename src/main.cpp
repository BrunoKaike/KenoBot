#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "../include/KenoBet.hpp"

int main(int argc, char *argv[]){
  
    //Validar arquivo de apostas
    string lineFromFile;
    stringstream ss;

    std::fstream file;
    file.open (argv[1]);
    if (!file) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    //Loop de Apostas
    while(!file.eof()){ 
    //Abertura de cada aposta do arquivo
        KenoBet aposta;
        cash_type tempF;
        number_type tempI;

        //Passagem de creditos
        getline( file, lineFromFile );
        ss.clear();
        ss << lineFromFile;  
        ss >> tempF; 
        aposta.set_wage(tempF);

        //Passagem das rodadas
        getline( file, lineFromFile );
        ss.clear();
        ss << lineFromFile;  
        ss >> tempI; 
        aposta.set_rounds(tempI);

        //Passagem dos numeros apostados
        getline( file, lineFromFile );
        size_t start;
        size_t end = 0;
        while ((start = lineFromFile.find_first_not_of(" ", end)) != std::string::npos){
            end = lineFromFile.find(" ", start);
            ss.clear();
            ss << lineFromFile.substr(start, end - start);
            ss >> tempI; 
            aposta.add_number(tempI);
        }
        
    //Play
        cout<<"\n\n\n\n=====NOVA APOSTA=====\n";

        aposta.set_round_wage();
        for(int q=1; q<=aposta.get_rounds(); q++){
            cout<<"\n-----------------"<<endl;
            cout<<"RODADA "<<q<<"\n\n";
            //Dados aposta
            cout<<"A aposta do round foi do total de: "<<aposta.get_round_wage();
            
            cout<<endl<<"Os numeros apostados foram: ";
            aposta.print_spots();

            //Numeros sorteados
            cout<<"Os 20 numeros sorteados foram: ";
            aposta.print_sorteados();

            //Hits
            cout<<"Os acertos foram: ";
            aposta.print_hits();

            //Ganho
            set_of_numbers_type hits = aposta.get_hits(aposta.get_m_sorteados());
            cout<<"Por apostar "<<aposta.get_round_wage();
            cout<<" e acertar "<<aposta.size_hits()<<"/"<<aposta.get_spots().size()<<" numeros,";
            cout<<" sua taxa de retorno é de "<<aposta.get_retorno_round();
            cout<<" e seu retorno em creditos foi de "<<aposta.get_after_round_wage()<<endl;
            aposta.update_wage();
        }
        cout<<"\n-----------------"<<endl;
        cout<<"Seu creditos finais são de: "<<aposta.get_wage()<<"\n\n";
        aposta.reset();
    }
    
    return 0;
}
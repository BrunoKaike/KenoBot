#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include "../include/KenoBet.hpp"

int main(int argc, char *argv[]){
    
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
    };

    KenoBet aposta;
    
    int NR;

    //Ler e Validar arquivo de apostas
        //Validação 
        std::fstream file;
        file.open (argv[1]);
        if (!file) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }
        //Leitura
        bool a;
        float temp;
        file>>temp;
        aposta.set_wage(temp);
        file>>NR; 

        while(file){
            file>>temp;
            a=aposta.add_number(temp);
        }
    //end

    //Play
        //Dados aposta
        cout<<"A aposta foi do total de: ";
        aposta.print_wage();
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
        cout<<"Por apostar ";
        aposta.print_wage();
        cout<<" e acertar "<<aposta.size_hits()<<"/"<<aposta.get_spots().size()<<" numeros,";
        cout<<" sua taxa de retorno é de "<<tabela_de_retorno[aposta.get_spots().size()][hits.size()];
        cout<<" e o ganho foi de "<<aposta.get_wage()*(tabela_de_retorno[aposta.get_spots().size()][hits.size()])<<"\n\n";
    //end

    return 0;
}
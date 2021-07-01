#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//#include "../include/Arquivo.hpp"
#include "../include/KenoBet.hpp"

int main(int argc, char *argv[]){

    KenoBet aposta;

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
        cash_type tempF;
        number_type tempI;
        file>>tempF;
        aposta.set_wage(tempF);
        file>>tempI; 
        aposta.set_rounds(tempI);

        while(file){
            file>>tempI;
            a=aposta.add_number(tempI);
        }
    //end
    
    //Play
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
    //end

    return 0;
}

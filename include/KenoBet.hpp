#ifndef KENOBET
#define KENOBET
#include <cstddef>
#include <vector>

using number_type = unsigned short int; //<! data type for a keno hit.
using cash_type = float; //<! Defines the wage type in this application.
using set_of_numbers_type = std::vector< number_type >;
using set_retorno = std::vector<std::vector<float>>;

class KenoBet {
    public:
        //! Creates an empty Keno bet.
        KenoBet( ) : m_wage(0)
        { /* empty */ };
        
        /*! Adds a number to the spots only if the number is not already there.
        *param spot_ The number we wish to include in the bet.
        *return T if number chosen is successfully inserted; F otherwise. */
        bool add_number( number_type spot_ );

        /*! Sets the amount of money the player is betting.
        *param wage_ The wage.
        *return True if we have a wage above zero; false otherwise. */
        bool set_wage( cash_type wage_ );

        //! Resets a bet to an empty state.
        void reset( void );

        /*! Retrieves the player's wage on this bet.
        *return The wage value. */
        cash_type get_wage( void ) const;

        /*! Returns to the current number of spots in the player's bet.
        *return Number of spots present in the bet. */
        size_t size( void ) const;

        /*! Determine how many spots match the hits passed as argument.
        *param hits_ List of hits randomly chosen by the computer.
        *return An vector with the list of hits. */
        set_of_numbers_type get_hits( const set_of_numbers_type & hits_ ) const;

        /*! Return a vector< spot_type > with the spots the player has picked so far.
        *return The vector< spot_type > with the player's spots picked so far. */
        set_of_numbers_type get_spots( void ) const;


        //++++++++++++++NOVOS+++++++++++++
        //Preenche o vetor m_sorteados com 20 num aleatorios
        void set_m_sorteados();

        //Retorna o vetor m_sorteados
        set_of_numbers_type get_m_sorteados();

        //Preenche o vetor de m_hits
        void set_hits();

        //Printa créditos 
        void print_wage();

        //Printa numeros apostados
        void print_spots();

        //Printa numeros sorteados
        void print_sorteados();

        //Printa numeros acertados
        void print_hits();

        //Retorna qtd de hits
        size_t size_hits();

    private:
        set_of_numbers_type m_spots; //<! The player's bet.
        cash_type m_wage; //<! The player's wage


        //+++++++++++++NOVOS+++++++++++++
        set_of_numbers_type m_sorteados; //NUMEROS SORTEADOS PARA A APOSTA 
        set_of_numbers_type m_hits; //NUMEROS ACERTADOS
        
};

#endif
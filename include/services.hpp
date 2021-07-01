#ifndef SERVICES
#define SERVICES

#include <vector>

using number_type = unsigned short int; //<! data type for a keno hit.
using numbers = std::vector< number_type >;
using set_of_numbers_type = std::vector< number_type >;

using namespace std;

template<class InputIt>
void swap(InputIt first, InputIt second){

    auto aux = *first;
    *first = *second;
    *second = aux;

}

set_of_numbers_type sort(set_of_numbers_type numbers , int tam)
{

    for(int x = 0; x < tam-1; x++){

      for(int i = 0; i < tam-x-1; i++){

        if(numbers[i] > numbers[i+1]){

            swap(&numbers[i], &numbers[i+1]);

        }

      }

    }

    return numbers;

}

#endif

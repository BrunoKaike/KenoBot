cmake_minimum_required(VERSION 3.5)
project(GraalLibrary VERSION 0.1 LANGUAGES CXX )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 14)
#--------------------------------

### Application target
# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.hpp"
include_directories( include )

# Cria um executável com nome "Keno", adiciona neste executável a classe KenoBet.cpp seu main.cpp
add_executable( Keno
                src/KenoBet.cpp
                src/main.cpp 
                src/validation.cpp)

# The end

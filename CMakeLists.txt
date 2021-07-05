cmake_minimum_required(VERSION 3.5)
project(GraalLibrary VERSION 0.1 LANGUAGES CXX )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 14)
#--------------------------------

### Application target
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "Keno", adiciona neste executável a classe KenoBet.cpp, main.cpp e validation.cpp
add_executable( Keno
                src/KenoBet.cpp
                src/main.cpp 
                src/validation.cpp)

# The end

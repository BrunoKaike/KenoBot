# Trabalho 1: Keno
Repositório contendo as especificações do Trabalho 1 da disciplina de LP1

## Compilando com cmake
```
mkdir build
cd build
cmake ..
cmake --build .
```

A compilação gera um executável com o nome Keno dentro da pasta build. Logo após a compilação, para executar o programa gerado para cada teste use os comandos:

Teste 1 (OK)
```
./Keno ../data/teste1.dat
```

Teste 2 (Formatação diferente)
```
./Keno ../data/teste2.dat
```

Teste 3 (Numero apostado menor que 1 ou maior que 80)
```
./Keno ../data/teste3.dat
```

Teste 4 (Repetição de números)
```
./Keno ../data/teste4.dat
```

Teste 5 (OK)
```
./Keno ../data/teste5.dat
```
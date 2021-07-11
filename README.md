# Projeto KenoBot
KenoBot é um projeto para executar apostas de Keno baseada em arquivos de texto.

## Objetivos

Projeto desenvolvido e apresentado ao curso de Tecnologia da Informação da Universidade Federal do Rio Grande do Norte, como requisito parcial para obtenção de nota na disciplina de Linguagem de Programação I, ministrada pelo professor Julio Cesar Paulino de Melo(*<julio.melo@imd.ufrn.br>*).

## O que é Keno?

O Keno é um jogo de loteria muito popular nos casinos modernos, e utilizado igualmente nas loterias estatais.

Num casino tradicional, o jogo do Keno é composto por uma tômbola com 80 bolas numeradas. Os jogadores marcam nos seus cartões (numerados de 1 a 80) alguns dos números. O montante de números marcados varia de casino para casino, mas geralmente varia entre um e quinze.

## Sobre o projeto
<center>
<img src="img/keno (1).png">
</center>
O projeto KenoBot foi desenvolvido utilizando da linguagem C++ e do gerador de sistema de compilação Cmake.

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

Teste 2 (Possui mais de uma entrada)
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

Teste 6 (Possui mais de um ponto flutuante)
```
./Keno ../data/teste6.dat
```

Teste 7 (Quantidade de números apostados superior a 15 ou inferior a 1)
```
./Keno ../data/teste7.dat
```

Teste 8 (Lista de números apostados possui caracteres estranhos)
```
./Keno ../data/teste8.dat
```

## Autores

Bruno Kaike do Nascimento Batista -
[GitHub](https://github.com/BrunoKaike)

Angelo Gustavo Souza Marinho Morais de Sales -
[GitHub](https://github.com/AngeloGustavo)

## Contato

Bruno Kaike do Nascimento Batista -
*<brunokaike@ufrn.edu.br>*

Angelo Gustavo Souza Marinho Morais de Sales -
*<angelo.sales.703@ufrn.edu.br>*

Link do projeto: [https://github.com/JulioMelo-Classes/trabalho-1-BrunoKaike.git](https://github.com/JulioMelo-Classes/trabalho-1-BrunoKaike.git)

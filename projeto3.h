#ifndef PROJETO3_H
#define PROJETO3_H

#include <string>
#include <prglib.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace prglib;

struct Qnt_filmes_ano{ //Declaração da struct.
    string Ator;     //Variável dentro da struct.
    int Qnt_filme_atuado; //Variável dentro da struct.

};
void Filmes_atuados_ano(thash<lista<string>> Tabela_Ator,thash<int> Tabela_filme_ano,string ator); //Função lista os filmes atuados ordenados pelo ano de acordo com um ator passado por parâmetro.
void Lista_ordenada_filmes_atuados(thash<lista<string>> & Tab_ator); //Função lista ordenadamente filmes atuados por um limitador de top.
void Atores_trabalharam_atores(string Ator_base,thash<lista<string>> & Tab_ator,thash<lista<string>> & Tab_Filme); //Função lista ordenadamente atores que trabalharam com um determinado ator passado por parâmetro.
lista<string> separa(const string & texto, const string & sep); //Função realiza separação de substrings de uma string de acordo com um separador e anexa em uma lista.
void leitura_arquivo(thash<lista<string>> & tab_filmes,thash<lista<string>> & tab_atores,thash<int> & tab_ano); //Função realiza a leitura do arquivo obtendo duas tabelas hashs uma de nome tab_filmes e outra de nome tab_atores.
void todos_atores_atuaram_conj_filme(thash<lista<string>> & tab_filmes,lista<string> conj_filmes); //Função imprime todos os atores que atuaram em um conjunto de filmes passado por parãmetro.
void list_ord_de_acordo_popularidades(thash<lista<string>> & tab_filmes,thash<lista<string>> & tab_atores,int top);//Função listagem de popularidade de acordo com um ator passado por parâmetro.
void menu ();
int realizar_funcoes();

#endif
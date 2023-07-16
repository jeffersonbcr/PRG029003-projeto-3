#include "projeto3.h"

struct Qnt_filmes_ano{ //Declaração da struct.
    string Ator;     //Variável dentro da struct.
    int Qnt_filme_atuado; //Variável dentro da struct.

    bool operator < (const Qnt_filmes_ano & outra){ //Sobrecarga de operador dentro da struct.
        bool booleano = Qnt_filme_atuado < outra.Qnt_filme_atuado; //Variável recebe o valor da comparação entre uma struct e outra por suas variáveis de inteiro dentro da struct.
        return booleano; //Retorna variável booleano.
    }
};

void Filmes_atuados_ano(thash<lista<string>> Tabela_Ator,thash<int> Tabela_filme_ano,string ator){ //Função lista os filmes atuados ordenados pelo ano de acordo com um ator passado por parâmetro.
    if(Tabela_Ator.existe(ator)){ //Condicional verifica se chave existe.
        lista<string> l_filmes_atores=Tabela_Ator[ator]; //Recebendo valor referente a chave da tabela hash de nome Tabela_Ator.
        lista<Qnt_filmes_ano> l_ano; //Declaração de variável.
        l_filmes_atores.inicia(); //Inicia iteração da lista.
        while(!l_filmes_atores.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
            string apoio=l_filmes_atores.proximo(); //Recebendo dado da lista.
            Qnt_filmes_ano st_aux; //Declaração de variável.
            st_aux.Ator=apoio; //Struct recebe valor da variável apoio.
            st_aux.Qnt_filme_atuado=Tabela_filme_ano[apoio]; //Recebendo valor referente a chave apoio.
            l_ano.anexa(st_aux); //Anexa struct na lista.
        }
        l_ano.ordena(); //Ordena lista.
        l_ano.inicia(); //Inicia iteração da lista.
        while(!l_ano.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
            Qnt_filmes_ano st_aux=l_ano.proximo(); //Recebendo dado dentro da lista.
            cout<<"Filme: "<<st_aux.Ator<< "Ano: "<<st_aux.Qnt_filme_atuado<<endl; //Imprime texto na tela.
        }
        cout<<endl<<endl; //Quebra de linha.
    }else{
        cout<<"Ator invalido"<<endl; //Imprime texto na tela.
    }
}

void Lista_ordenada_filmes_atuados(thash<lista<string>> & Tab_ator){ //Função lista ordenadamente filmes atuados por um limitador de top.
    auto chaves=Tab_ator.chaves(); //Recebendo uma lista contendo as chaves da tabela hash de nome tab_ator.
    lista<Qnt_filmes_ano> l_atores_qnt_filme; //Declaração de uma lista de struct.
    chaves->inicia(); //Iniciando iteração da lista chaves.
    while(!chaves->fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        string apoio_str=chaves->proximo(); //Recebendo dado dentro da lista e jogando na variável de nome apoio.
        Qnt_filmes_ano apoio; //Declaração de struct.
        apoio.Ator=apoio_str; //Struct recebe valor da variável apoio_str.
        apoio.Qnt_filme_atuado=Tab_ator[apoio_str].comprimento(); //Struct recebe o valor do comprimento da lista que esta na tabela hash de nome tab_ator.
        l_atores_qnt_filme.anexa(apoio); //Anexando struct na lista de struct.
    }

    l_atores_qnt_filme.ordena(); //Ordena lista de acordo com a sobrecarga de operador da struct.
    l_atores_qnt_filme.inverte(); //Inverte a lista de struct.
    l_atores_qnt_filme.inicia(); //Inicia iteração da lista.
    int contagem=0; //Declaração de variáveis.
    while(!l_atores_qnt_filme.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        Qnt_filmes_ano mensagem_saida=l_atores_qnt_filme.proximo(); //Recebendo dado dentro da lista.
        cout<<contagem+1<<")"<<mensagem_saida.Ator<< "__________Quantidade:"<< mensagem_saida.Qnt_filme_atuado<<endl; //Imprime mensagem na tela.
        contagem++; //Incrimentação da variável contagem.
        if(contagem==150)break; //Se condicional for verdadeiro para loop.
    }
    cout<<endl<<endl; //Quebra de linha.
}

void Atores_trabalharam_atores(string Ator_base,thash<lista<string>> & Tab_ator,thash<lista<string>> & Tab_Filme){ //Função lista ordenadamente atores que trabalharam com um determinado ator passado por parâmetro.
    if(Tab_ator.existe(Ator_base)){ //Se o ator existe dentro da tabela hash de nome Tab_ator faz:
        lista<string> l_apoio_filmes=Tab_ator[Ator_base]; //Lista de string recebe valor de acordo com a chave de nome Ator_base dentro da tabela hash Tab_ator.
        thash<int> tabela_atores_ligados(2000); //Declaração de variável.
        l_apoio_filmes.inicia(); //Inicia iteração da lista.
        while(!l_apoio_filmes.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
            string s_apoio_filme=l_apoio_filmes.proximo(); //variável recebe valor dentro da lista.
            lista<string> l_apoio_atores=Tab_Filme[s_apoio_filme]; // /Lista de string recebe valor de acordo com a chave de nome s_apoio_filme dentro da tabela hash Tab_filme.
            l_apoio_atores.inicia(); //Inicia iteração da lista.
            while(!l_apoio_atores.fim()) { //Loop ocorre enquanto não estiver no fim da lista.
                string s_apoio_atores=l_apoio_atores.proximo(); //Variável recebendo dado dentro da lista.
                if (tabela_atores_ligados.existe(s_apoio_atores))tabela_atores_ligados[s_apoio_atores]++; //Se a chave existe na tabela, incrimenta valor de acordo com a chave que existe.
                else {
                    tabela_atores_ligados.adiciona(s_apoio_atores, 1); //Se a chave não existe adiciona na tabela hash a chave inexistente e com valor 1.
                }
            }
        }
        auto chaves=tabela_atores_ligados.chaves(); //Recebendo uma lista contendo as chaves da tabela de nome tabela_atores_ligados.
        chaves->ordena(); //Ordena a lista de chaves.
        chaves->escrevaSe(cout); //Imprime a lista das chaves com quebra de linha.
        cout<<endl<<endl; //Quebra de linha;
    }else{ //Caso o ator não exista na tabela hash de nome Tab_ator.
        cout<< "Ator_invalido"<<endl<<endl; //Imprime mensagem na tela.
    }
}

lista<string> separa(const string & texto, const string & sep){ //Função realiza separação de substrings de uma string de acordo com um separador e anexa em uma lista.
    int pos = 0; //Declaração de variável.
    int pos0 = 0; //Declaração de variável.
    lista<string> l; //Declaração de variável.
    string palavra; //Declaração de variável.
    if (texto.size() > 0) //Se a variável possuir tamanho maior que zero faça:
    {
        do { //Faça:
            pos = texto.find_first_not_of(sep,pos); //Inteiro de nome pos recebe posição da string.
            pos0 = texto.find_first_of(sep,pos); //Inteiro de nome pos0 recebe posição da string.
            palavra = texto.substr(pos,pos0 - pos); //Gerando uma substring de acordo com as posições obtidas pelos inteiros pos e pos0.
            l.anexa(palavra); //Anexa na lista a substring gerado.
            if(texto.find_first_not_of(sep,pos) == string::npos) break; //Se condicional estiver no fim da string, para o loop que está em execução.
            pos = texto.find_first_not_of(sep,pos0); //Inteiro de nome pos recebe nova posição da string.
        } while (pos != string::npos); //Enquanto não estiver no fim da string.
    }
    return l; //Retorna a lista de nome l.
}

void leitura_arquivo(thash<lista<string>> & tab_filmes,thash<lista<string>> & tab_atores,thash<int> & tab_ano){ //Função realiza a leitura do arquivo obtendo duas tabelas hashs uma de nome tab_filmes e outra de nome tab_atores.
    ifstream arq("../dados.txt"); //Declaração de variável.
    lista<string> l; //Declaração de variável.
    string line; //Declaração de variável.
    if(arq.is_open()){ //Se o arquivo estiver aberto faça:
        while(getline(arq,line)){ //Enquanto o arquivo pegar linhas do arquivo e jogar na variável de nome line:
            l = separa(line,";"); //Variável de nome l recebe o retorno da função chamada separa.
            try {
                if (l.comprimento() == 3) { //Se o comprimento da lista for igual a três:
                    string nome_filme = l.remove(
                            0); //Obtendo o nome do filme do retorno de remover o dado que está na posição zero da lista.
                    tab_ano.adiciona(nome_filme, stoi(l.remove(0)));
                    lista<string> atores = separa(l.remove(0),
                                                  ","); //obtendo uma lista de strings que contêm os nomes dos atores que atuaram naquele filme a partir da posição um da lista.
                    tab_filmes.adiciona(nome_filme,
                                        atores); //Adiciona na tabela hash de nome tab_filmes, a chave como valor da variável nome_filme e valor da chave como valor da variável atores.
                    atores.inicia(); //Inicia iteração da lista.
                    while (!atores.fim()) { //Loop ocorre enquanto não estiver no fim da lista.
                        string apoio_ator = atores.proximo(); //Variável recebe valor dentro da lista.
                        if (tab_atores.existe(apoio_ator)) { //Se a chave existe na tabela hash de nome tab_atores:
                            tab_atores[apoio_ator].anexa(nome_filme); //O valor da chave da tabela anexa o nome_filme.
                        } else { //Senão chave não existe.
                            lista<string> l_add; //Declaração de variável.
                            l_add.anexa(nome_filme); //Anexa nome do filme na lista de nome l_add.
                            tab_atores.adiciona(apoio_ator,
                                                l_add); //adiciona na tabela uma chave que não existia até o momento e com valor de uma lista de nome l_add.
                        }
                    }
                }
            }catch(...){}

        }
    }
}
void todos_atores_atuaram_conj_filme(thash<lista<string>> & tab_filmes,lista<string> conj_filmes){ //Função imprime todos os atores que atuaram em um conjunto de filmes passado por parãmetro.
    string filme,ator; //Declaração de variáveis.
    lista<string> l_atores; //Declaração de variável.
    thash<int> tab_oa(tab_filmes.tamanho()); //Declaração de variável.
    conj_filmes.inicia(); //Inicia iteração da lista.
    while(! conj_filmes.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        filme = conj_filmes.proximo(); //Recebendo dado dentro da lista.
        l_atores = tab_filmes[filme]; //Recebendo valor da tabela hash de acordo com a chave de nome filme.
        l_atores.inicia(); //Inicia iteração da lista.
        while(!l_atores.fim()) { //Loop ocorre enquanto não estiver no fim da lista.
            ator = l_atores.proximo(); //Recebendo dado dentro da lista.
            if (tab_oa.existe(ator)) { //Se a chave existe na tabela hash de nome tab_oa:
                tab_oa[ator]++; //Incrimenta valor da chave que existe.
            } else { //Senão a chave não existe.
                tab_oa.adiciona(ator, 1); //Adiciona na tabela hash de nome tab_oa a chave do valor da variável ator e com valor 1.
            }
        }
    }
    auto chaves_oa = tab_oa.chaves(); //Recebendo as chaves da tabela hash de nome tab_oa.
    bool retorno=true; //Declaração de variável.
    chaves_oa->inicia(); //Inicia iteração da lista.
    while(! chaves_oa->fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        string chave_oa = chaves_oa->proximo(); //Recebendo dado dentro da lista.
        int valor_oa = tab_oa[chave_oa]; //Variável recebe valor de acordo com a chave da tabela hash de nome tab_oa.
        if(valor_oa == conj_filmes.comprimento()){ //Caso a variável tenha o mesmo valor do comprimento da lista de nome conj_filmes:
            cout << chave_oa << endl; //Imprime na tela texto.
            retorno=false; //Variável recebe novo estado.
        }
    }
    if(retorno)cout<<"Nenhum ator em comum"<<endl<<endl; //Caso condicional for verdadeiro imprime texto na tela.
}


void list_ord_de_acordo_popularidades(thash<lista<string>> & tab_filmes,thash<lista<string>> & tab_atores,int top){ //Função listagem de popularidade de acordo com um ator passado por parâmetro.
    lista<Qnt_filmes_ano> lista_de_contagem; //Declaração de variável.
    thash<thash<int>> Tab_contagem(24500); //Declaração de variável.
    lista<string> l_atores_populares; //Declaração de varáivel.
    auto chaves_atores=tab_atores.chaves(); //Recebendo as chaves da tabela hash de nome tab_atores.
    chaves_atores->inicia(); //Inicia iteração da lista.
    while(!chaves_atores->fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        string apoio=chaves_atores->proximo(); //Recebendo dado da lista.
        if(tab_atores[apoio].comprimento()>10)l_atores_populares.anexa(apoio); //Verifica se comprimento do valor que é uma lista da chave apoio é maior que dez, se for anexa na lista de nome l_atores_populares.
    }
    l_atores_populares.inicia(); //Inicia iteração da lista.
    while(!l_atores_populares.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        string l_popular=l_atores_populares.proximo(); //Recebendo dado dentro da lista.
        lista<string> l_filmes_atuados=tab_atores[l_popular]; //Cria uma lista de nome l_filmes_atuados a partir do valor da chave l_popular da tabela hash de nome tab_atores.
        thash<int> Tab_filmes_atuados(100); //Declaração de variável.
        l_filmes_atuados.inicia(); //Inicia iteração da lista.
        while(!l_filmes_atuados.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
            string filme_apoio=l_filmes_atuados.proximo(); //Recebendo dado da lista.
            lista<string> atores_do_filme=tab_filmes[filme_apoio]; //Cria uma lista de nome atores_do_filme a partir do valor da chave filme_apoio da tabela hash de nome tab_filmes.
            atores_do_filme.inicia(); //Inicia iteração da lista.
            while(!atores_do_filme.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
                string apoio=atores_do_filme.proximo(); //Recebendo dado da lista.
                if(!Tab_filmes_atuados.existe(apoio) && apoio != l_popular)Tab_filmes_atuados.adiciona(apoio,1); //Verificação da chave existente na Tab_filmes_atuados e se a variável de apoio é diferente do l_popular, se for adiciona na tabela hash.
            }
        }
        Tab_contagem.adiciona(l_popular,Tab_filmes_atuados); //Adiciona nome do ator e uma tabela hash contendo como chave atores que atuaram com ele e valor da chave um inteiro.
    }


    auto chaves=Tab_contagem.chaves(); //Recebendo as chaves da tabela hash de nome Tab_contagem.
    chaves->inicia(); //Inicia iteração da lista.
    while(!chaves->fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        string apoio=chaves->proximo(); //Recebendo dado da lista.
        Qnt_filmes_ano st_apoio; //Declaração de variável.
        st_apoio.Ator=apoio; //Struct recebe valor da chave.
        st_apoio.Qnt_filme_atuado=Tab_contagem[apoio].tamanho(); //Struct recebe o comprimento do valor da chave dentro da tabela hash de nome Tab_contagem.
        lista_de_contagem.anexa(st_apoio); //Anexa struct em uma lista.
    }
    lista_de_contagem.ordena(); //Ordena lista.
    lista_de_contagem.inverte(); //inverte lista.

    int contagem=0; //Declaração de variável.
    lista_de_contagem.inicia(); //Inicia iteração da lista.
    while(!lista_de_contagem.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        Qnt_filmes_ano apoio_cout=lista_de_contagem.proximo(); //Recebendo dado da lista.
        contagem++; //Incrimenta variável.
        cout<<contagem<<")Ator:  "<<apoio_cout.Ator<<"_________Quantidade: "<<apoio_cout.Qnt_filme_atuado<<endl; //Imprime texto na tela.
        if(contagem==top)break; //Condicional de parada do loop.
    }
    cout<<endl<<endl; //Quebra de linha.
}

void menu () //Função de interface menu.
{
    cout <<"Digite: 1 para opção:Os filmes em que um ator atuou "<< endl; //Imprime texto na tela.
    cout <<"Digite: 2 para opção:Os atores que atuaram em todos os filmes de um certo conjunto de filmes"<< endl; //Imprime texto na tela.
    cout <<"Digite: 3 para opção:Os atores que trabalharam com um dado ator"<< endl; //Imprime texto na tela.
    cout <<"Digite: 4 para opção:A listagem ordenada de atores, de acordo com suas popularidades (a popularidade é dada pela quantidade de atores com que um dado ator trabalhou)"<< endl; //Imprime texto na tela.
    cout <<"Digite: 5 para opção:A listagem ordenada de atores, de acordo com a quantidade de filmes em que atuaram"<< endl; //Imprime texto na tela.
    cout <<"Digite: 0 para opção:Sair do programa"<< endl; //Imprime texto na tela.

}

int realizar_funcoes(){
    int opcao; //Declaração de variável.
    cin>>opcao; //lendo opcao do teclado.
    thash<lista<string>> Tabela_Ator(1000); //Declaração de variável.
    thash<lista<string>> Tabela_Filme(1000); //Declaração de variável.
    thash<int> Tabela_filme_ano(1000); //Declaração de variável.
    leitura_arquivo(Tabela_Filme,Tabela_Ator,Tabela_filme_ano); //Chama função para ler o arquivo e criar duas tabelas.
    switch (opcao){ //Opcao
        case 1: { //Caso 1.
            string apoio;
            cout<<"Digite o nome do ator desejado"<<endl; //Imprime texto na tela.
            getchar();
            getline(cin,apoio); //Recebendo dado do usuário através.
            Filmes_atuados_ano(Tabela_Ator,Tabela_filme_ano,apoio);
            break;
        }
        case 2: { //Caso 2.
            string teclado; //Declaração de variável.
            lista<string> conj_filmes; //Declaração de variável.
            do{
                cout << "Digite o nome de um filme: "; //Imprime texto na tela.
                getchar();
                getline(cin,teclado); //Recebendo dado do usuário através do teclado.
                conj_filmes.anexa(teclado); //Anexa variável teclado na lista.
            } while(! teclado.empty()); //Loop acontece enquanto variável teclado não estiver vazia.
            todos_atores_atuaram_conj_filme(Tabela_Filme, conj_filmes); //Chama função todos_atores_atuaram_conj_filme.
            break;
        }
        case 3: { //Caso 3.
            string apoio; //Declaração de variável.
            cout<<"Digite o nome do ator desejado"<<endl; //Imprime texto na tela.
            getchar();
            getline(cin,apoio); //Recebendo dado do usuário através do teclado.
            Atores_trabalharam_atores(apoio,Tabela_Ator,Tabela_Filme); //Chama função atores_trabalharam_atores.
            break;
        }
        case 4: { //Caso 4.
            cout<<"Digite a quantidade que você deseja na classificação"<<endl;
            int top_x;
            cin>>top_x;
            list_ord_de_acordo_popularidades(Tabela_Filme,Tabela_Ator,top_x); //Chama função list_ord_acordo_popularidades.
            break;
        }
        case 5: { //Caso 5.
            Lista_ordenada_filmes_atuados(Tabela_Ator); //Chama função Lista_ordenada_filmes_atuados.
            break;
        }
        case 0: //Caso 0.
            break;
        default: //Nenhuma opção dentre os possíveis de casos.
            cout<< "Operação invalida"<<endl; //Imprime texto na tela.
    }
    return opcao; //Retorna valor da variável opcao.
}

# Prglib: biblioteca de estruturas de dados elementares

A [Prglib](https://wiki.sj.ifsc.edu.br/wiki/index.php/PRG29003:_Etapa_2:_A_constru%C3%A7%C3%A3o_da_prglib) é uma pequena biblioteca contendo estruturas de dados para fins didáticos. Ela foi escrita para a disciplina de [Programação II](https://wiki.sj.ifsc.edu.br/wiki/index.php/PRG29003:_Introdu%C3%A7%C3%A3o_a_C%2B%2B) da [Engenharia de Telecomunicações](https://wiki.sj.ifsc.edu.br/wiki/index.php/Curso_de_Engenharia_de_Telecomunica%C3%A7%C3%B5es) do [IFSC Câmpus São José](http://www.sj.ifsc.edu.br/). E contém as seguintes estruturas de dados:
* __Fila__: uma fila circular com capacidade definido no momento de sua criação
* __Pilha__: uma pilha cuja capacidade também é definida no instante de sua criação
* __Lista__: uma lista duplamente encadeada, e possivelmente circular (depende da implementação do estudante)
* __Tabela hash__: uma tabela hash com quantidade de linhas (buckets) definida no instante de sua criação. Além disso, por simplicidade as chaves são do tipo string
* __Árvore de pesquisa binária__: uma árvore com operações de balanceamento com algoritmo [AVL](https://en.wikipedia.org/wiki/AVL_tree)

# Projeto 3
Este projeto consiste em um programa que realiza estatísticas sobre atores e filmes. O programa permite a busca de informações sobre os filmes em que um ator atuou, os atores que atuaram em um determinado filme, os atores que trabalharam com um dado ator, a listagem ordenada de atores de acordo com suas popularidades e a listagem ordenada de atores de acordo com a quantidade de filmes em que atuaram.

## Funcionalidades
O programa oferece as seguintes funcionalidades:

Os filmes em que um ator atuou: Permite buscar os filmes em que um determinado ator atuou. A função Filmes_atuados_ano lista os filmes atuados ordenados pelo ano de acordo com o ator fornecido como parâmetro.

Os atores que atuaram em todos os filmes de um certo conjunto de filmes: Permite buscar os atores que atuaram em todos os filmes de um determinado conjunto de filmes. A função todos_atores_atuaram_conj_filme imprime todos os atores que atuaram nos filmes do conjunto fornecido como parâmetro.

Os atores que trabalharam com um dado ator: Permite buscar os atores que trabalharam com um determinado ator. A função Atores_trabalharam_atores lista ordenadamente os atores que trabalharam com o ator fornecido como parâmetro.

A listagem ordenada de atores, de acordo com suas popularidades: Permite listar os atores de forma ordenada de acordo com suas popularidades. A popularidade de um ator é determinada pela quantidade de atores com os quais ele trabalhou. A função list_ord_de_acordo_popularidades realiza essa listagem de acordo com um valor limite fornecido como parâmetro.

A listagem ordenada de atores, de acordo com a quantidade de filmes em que atuaram: Permite listar os atores de forma ordenada de acordo com a quantidade de filmes em que atuaram. A função Lista_ordenada_filmes_atuados realiza essa listagem.

## Utilização
Para utilizar o programa, siga os seguintes passos:

Compile e execute o código do projeto utilizando um compilador C++.

O programa exibirá um menu com as opções disponíveis. Digite o número correspondente à opção desejada.

Dependendo da opção escolhida, o programa solicitará informações adicionais, como o nome de um ator, o nome de um filme ou a quantidade de atores a serem listados.

O programa exibirá os resultados na tela de acordo com a opção selecionada.

Repita o processo para realizar outras consultas ou digite 0 para sair do programa.
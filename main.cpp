#include "projeto3.h"

int main () {
    int opcao; 
    do{
        menu();
        opcao = realizar_funcoes();
    } while (opcao != 0);
    return 0;
}

//Curso de Programação C | Operação push. Como empilhar um dado na estrutura de dados pilha | aula 224

#include <stdio.h>
#include <stdlib.h>

/*
        Estruturas de dados dinâmicos
*/

typedef struct{
    int dia,mes,ano;
}Data;

typedef struct {
    char nome [50];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo; //Ponteiro para o proximo no
}No;

Pessoa ler_pessoa() {
    Pessoa p;

    printf("\nDigite o nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa(Pessoa p) {
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

//Função para a operação PUSH (empilhar)
No* empilhar (No*topo) {
    No *novo = malloc(sizeof(No));

    //verificar se a alocação de memoria funcionou
    if(novo) {
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    }
    else
        printf("\nErro ao alocar a memoria\n");
    return NULL;
}
//Função para a operação POP (desempilhar)
No* desempilhar(No **topo) {
    if (*topo != NULL) {
         No *remover = *topo;
         *topo = remover ->proximo;
         return remover;
    }
    else
        printf("\nPilha vazia\n");
   return NULL;
}        

int main () {

    No *remover, *topo = NULL; //pilha
    int opcao;

    do {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar(); //limpar buffer do teclado

        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar (&topo);
            if(remover){
               printf("\nElemento removido com sucesso\n");
               imprimir_pessoa(remover->p);
            }
            else
                printf("\nSem no a remover.\n");   
            break;  
        case 3:
            /* code */
            break;              
        
        default:
            if(opcao !=0)
                printf("\nOpcao invalida\n");
            
        }
    } while(opcao !=0);
    return 0;
}
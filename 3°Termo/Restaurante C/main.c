#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Restaurante
{
    char nome[40];
    char endereco[40];
    char tipocomida[20];
    int nota;
    struct Restaurante *prox;
};

void addRest(struct Restaurante* *lista, struct Restaurante novoRest)
{
    struct Restaurante *novo = (struct Restaurante*)malloc(sizeof(struct Restaurante));
    *novo = novoRest;
    novo->prox = *lista;
    *lista = novo;
    printf("\nRestaurante inserido\n\n");
}

void ListarRestaurantes(struct Restaurante *lista)
{
    if (lista == NULL)
    {
        printf("\nNenhum restaurante cadastrado!\n\n");
        return;
    }
    printf("\nRestaurantes listados:\n");
    while(lista != NULL)
    {
        printf("\nNome: %s", lista->nome);
        printf("Endereço: %s", lista->endereco);
        printf("Tipo de Comida: %s", lista->tipocomida);
        printf("Avaliacao do Restaurante: %d\n\n", lista->nota);
        lista = lista->prox;
    }
    
}

void ListarPorNota(struct Restaurante *lista, int notaref)
{
    printf("\nRestaurantes com nota superior a %d\n", notaref);
    while(lista != NULL)
    {
        if(lista->nota > notaref)
        {
            printf("\nNome: %s", lista->nome);
            printf("Endereço: %s", lista->endereco);
            printf("Tipo de Comida: %s", lista->tipocomida);
            printf("Avaliacao do Restaurante: %d\n\n", lista->nota);
        }
        lista = lista->prox;
    }
    
}

void ListarPorComida(struct Restaurante* lista, char comidaref[])
{
    printf("\nRestaurantes com comida %s\n", comidaref);
    while(lista != NULL)
    {
        if(strcmp(lista->tipocomida, comidaref) == 0)
        {
            printf("Nome: %s", lista->nome);
            printf("Endereço: %s", lista->endereco);
            printf("Tipo de Comida: %s", lista->tipocomida);
            printf("Avaliacao do Restaurante: %d\n\n", lista->nota);
        }
        lista = lista->prox;
    }
    
}

void atualizarRest(struct Restaurante* lista, char nomeref[])
{
    while(lista != NULL)
    {
        if(strcmp(lista->nome, nomeref) == 0)
        {
            printf("Atualizando as informações do restaurante %s: \n", nomeref);
            printf("Endereço: ");
            fgets(lista->endereco, sizeof(lista->endereco), stdin);
            printf("Tipo de Comida: ");
            fgets(lista->tipocomida, sizeof(lista->tipocomida), stdin);
            printf("Avaliacao do Restaurante: ");
            while(1)
            {
                scanf("%d", &(lista->nota));
                if(lista->nota >= 0 && lista->nota <= 5)
                {break;}
                else
                {
                    printf("\nNota Invalida! O valor deve ser um inteiro entre 0 a 5\n");
                    printf("Avaliacao do Restaurante: ");
                }
            }
            

            printf("Informações atualizadas com sucesso!\n\n");
            return;
        }
    lista = lista->prox;
    }
    printf("Restaurante %s não encontrado\n", nomeref);
}

void delRest(struct Restaurante* *lista, char nomeref[])
{
    struct Restaurante *atual = *lista;
    struct Restaurante *anterior = NULL;

    if(atual != NULL && strcmp(atual->nome, nomeref) == 0)
    {
        *lista = atual->prox;
        free(atual);
        printf("Restaurante %s deletado com sucesso!\n\n", nomeref);
        return;
    }

    while(atual != NULL && strcmp(atual->nome, nomeref) != 0)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) 
    {
        printf("Restaurante %s não encontrado!\n\n", nomeref);
        return;
    }

    anterior->prox = atual->prox;
    free(atual);
    printf("Restaurante %s deletado com sucesso!\n\n", nomeref);
}

int main()
{
    struct Restaurante *lista = NULL;
    int opcao;

    do
    {
        printf("[1] Inserir novo restaurante\n");
        printf("[2] Listar restaurantes\n");
        printf("[3] Filtrar restaurantes por nota\n");
        printf("[4] Filtrar restaurantes por tipo de comida\n");
        printf("[5] Atualizar informações sobre um restaurantes\n");
        printf("[6] Deletar um restaurante cadastrado\n");
        printf("[0] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o caractere de nova linha do buffer

        switch (opcao)
        {
            case 1: 
            {
                struct Restaurante RestNovo;
                printf("\nNome: ");
                fgets(RestNovo.nome, sizeof(RestNovo.nome), stdin);
                printf("Endereço: ");
                fgets(RestNovo.endereco, sizeof(RestNovo.endereco), stdin);
                printf("Tipo de Comida: ");
                fgets(RestNovo.tipocomida, sizeof(RestNovo.tipocomida), stdin);
                printf("Nota de Cozinha: ");
                while(1)
                {
                scanf("%d", &RestNovo.nota);
                if(RestNovo.nota >= 0 && RestNovo.nota <= 5)
                {break;}
                else
                {
                    printf("\nNota Invalida! O valor deve ser um inteiro entre 0 a 5\n");
                    printf("Nota de Cozinha: ");
                }
                }
                addRest(&lista, RestNovo);
                break;
            }
            case 2:
            {
                ListarRestaurantes(lista);
                break;
            }
            case 3: 
            {
                int valorNota;
                printf("Digite o valor mínimo da nota de cozinha: ");
                scanf("%d", &valorNota);
                ListarPorNota(lista, valorNota);
                break;
            }
            case 4: 
            {
                char tipoComida[20];
                printf("Digite o tipo de comida desejado: ");
                fgets(tipoComida, sizeof(tipoComida), stdin);
                ListarPorComida(lista, tipoComida);
                break;
            }
            case 5: 
            {
                char nome[40];
                printf("Digite o nome do restaurante a ser atualizado: ");
                fgets(nome, sizeof(nome), stdin);
                atualizarRest(lista, nome);
                break;
            }
            case 6: 
            {
                char nome[40];
                printf("Digite o nome do restaurante a ser deletado: ");
                fgets(nome, sizeof(nome), stdin);
                delRest(&lista, nome);
                break;
            }
            case 0:
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);
}
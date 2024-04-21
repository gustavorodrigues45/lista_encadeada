#include <stdio.h>
#include <stdlib.h>

// Definicao da estrutura do no da lista encadeada
struct No {
    int data;
    struct No* next;
};

// Funcao para inserir um elemento no inicio da lista
void inserirNoInicio(struct No** headRef, int newData) {
    // Aloca memoria para o novo no
    struct No* newNo = (struct No*)malloc(sizeof(struct No));
    // Define os dados do novo no
    newNo->data = newData;
    // Faz o novo no apontar para o no seguinte
    newNo->next = *headRef;
    // Faz o ponteiro de cabeca (head) apontar para o novo no
    *headRef = newNo;
}

// Funcao para imprimir os elementos da lista
void printList(struct No* no) {
    while (no != NULL) {
        printf("%d ", no->data);
        no = no->next;
    }
    printf("\n");
}

// Funcao para remover um elemento em uma posicao especifica da lista
struct No* remove_elemento(struct No* lista, int posicao) {
    if (lista == NULL)
        return lista;

    struct No* temp = lista;

    // Se posicao for 0, remove o primeiro no
    if (posicao == 0) {
        lista = temp->next; // Move o ponteiro da lista para o proximo nó
        free(temp); // Libera a memoria do no removido
        return lista;
    }

    // Encontra o no anterior ao no que sera removido
    for (int i = 0; temp != NULL && i < posicao - 1; i++)
        temp = temp->next;

    // Se a posicao for maior que o numero de elementos na lista
    if (temp == NULL || temp->next == NULL)
        return lista;

    // Guarda o no que sera removido
    struct No* next_no = temp->next->next;

    // Libera a memoria do no removido
    free(temp->next);

    // Reconecta os nós
    temp->next = next_no;

    return lista;
}

int main() {
    // Inicializa a lista como vazia
    struct No* head = NULL;

    // Insere alguns elementos na lista
    inserirNoInicio(&head, 5);
    inserirNoInicio(&head, 7);
    inserirNoInicio(&head, 3);

    // Imprime os elementos da lista antes da remocao
    printf("Lista encadeada antes da remocao: ");
    printList(head);

    // Remove o elemento na posicao 1 (segundo elemento)
    head = remove_elemento(head, 1);

    // Imprime os elementos da lista apos a remocao
    printf("Lista encadeada apos a remocao: ");
    printList(head);

    return 0;
}

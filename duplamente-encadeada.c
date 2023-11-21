#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista duplamente encadeada
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Função para inserir um nó no início da lista
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Função para inserir um nó no final da lista
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Função para inserir um nó em uma posição específica da lista
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Posição inválida\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; ++i) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Posição inválida\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Função para excluir o nó do início da lista
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Lista vazia\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Função para excluir o nó do final da lista
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Lista vazia\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(temp);
}

// Função para excluir o nó de uma posição específica da lista
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Posição inválida\n");
        return;
    }

    struct Node* temp = *head;

    for (int i = 1; i < position && temp != NULL; ++i) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Posição inválida\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Função para buscar um nó com dado valor na lista
struct Node* searchNode(struct Node* head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Função para exibir os nós da lista
void displayNodes(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    struct Node* head = NULL;

    // Exemplos de operações na lista
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 5);
    insertAtBeginning(&head, 1);
    insertAtPosition(&head, 4, 3);

    printf("Lista Duplamente Encadeada:\n");
    displayNodes(head);

    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteFromPosition(&head, 2);

    printf("Lista após exclusões:\n");
    displayNodes(head);

    // Exemplo de busca na lista
    struct Node* searchResult = searchNode(head, 5);
    if (searchResult != NULL) {
        printf("Nó encontrado: %d\n", searchResult->data);
    } else {
        printf("Nó não encontrado\n");
    }

    return 0;
}

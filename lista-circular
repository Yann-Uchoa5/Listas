#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista circular
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no início da lista circular
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Função para inserir um nó no final da lista circular
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Função para inserir um nó em uma posição específica da lista circular
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
    temp->next = newNode;
}

// Função para excluir o nó do início da lista circular
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Lista vazia\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    if (*head == temp) {
        *head = NULL;
    } else {
        temp->next = (*head)->next;
        *head = (*head)->next;
    }

    free(temp);
}

// Função para excluir o nó do final da lista circular
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Lista vazia\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != *head) {
        temp = temp->next;
    }

    struct Node* lastNode = temp->next;
    temp->next = *head;
    free(lastNode);
}

// Função para excluir o nó de uma posição específica da lista circular
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Posição inválida\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    struct Node* temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; ++i) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == *head) {
        printf("Posição inválida\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Função para buscar um nó com dado valor na lista circular
struct Node* searchNode(struct Node* head, int data) {
    struct Node* temp = head;
    if (temp != NULL) {
        do {
            if (temp->data == data) {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);
    }
    return NULL;
}

// Função para exibir os nós da lista circular
void displayNodes(struct Node* head) {
    struct Node* temp = head;
    if (temp != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("NULL\n");
}

// Função principal
int main() {
    struct Node* head = NULL;

    // Exemplos de operações na lista circular
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 5);
    insertAtBeginning(&head, 1);
    insertAtPosition(&head, 4, 3);

    printf("Lista Circular:\n");
    displayNodes(head);

    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteFromPosition(&head, 2);

    printf("Lista após exclusões:\n");
    displayNodes(head);

    // Exemplo de busca na lista circular
    struct Node* searchResult = searchNode(head, 5);
    if (searchResult != NULL) {
        printf("Nó encontrado: %d\n", searchResult->data);
    } else {
        printf("Nó não encontrado\n");
    }

    return 0;
}

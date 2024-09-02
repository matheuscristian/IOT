#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ANDARES 10 // Número máximo de andares

// Estrutura para representar o elevador
typedef struct {
    int andarAtual;
    int andarDestino;
    bool emMovimento;
} Elevador;

// Função para inicializar o elevador
void inicializarElevador(Elevador *elevador) {
    elevador->andarAtual = 0;
    elevador->andarDestino = -1; // Indica que não há destino
    elevador->emMovimento = false;
}

// Função para solicitar um andar
void solicitarAndar(Elevador *elevador, int andar) {
    if (andar < 0 || andar >= ANDARES) {
        printf("Andar inválido. Escolha um andar entre 0 e %d.\n", ANDARES - 1);
        return;
    }

    if (andar == elevador->andarAtual) {
        printf("O elevador já está no andar %d.\n", andar);
        return;
    }

    elevador->andarDestino = andar;
    elevador->emMovimento = true;
    printf("Solicitação recebida. Elevador indo para o andar %d.\n", andar);
}

// Função para mover o elevador
void moverElevador(Elevador *elevador) {
    if (!elevador->emMovimento) {
        printf("O elevador não está em movimento.\n");
        return;
    }

    if (elevador->andarAtual < elevador->andarDestino) {
        elevador->andarAtual++;
        printf("Elevador subindo. Andar atual: %d\n", elevador->andarAtual);
    } else if (elevador->andarAtual > elevador->andarDestino) {
        elevador->andarAtual--;
        printf("Elevador descendo. Andar atual: %d\n", elevador->andarAtual);
    }

    if (elevador->andarAtual == elevador->andarDestino) {
        elevador->emMovimento = false;
        elevador->andarDestino = -1; // Destino alcançado
        printf("Elevador chegou ao andar %d.\n", elevador->andarAtual);
    }
}

int main() {
    Elevador elevador;
    inicializarElevador(&elevador);

    int opcao, andar;

    while (1) {
        printf("\n1. Solicitar andar\n");
        printf("2. Mover elevador\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o andar para o qual deseja ir (0 a %d): ", ANDARES - 1);
                scanf("%d", &andar);
                solicitarAndar(&elevador, andar);
                break;
            case 2:
                moverElevador(&elevador);
                break;
            case 3:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

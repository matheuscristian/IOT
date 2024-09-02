#include <stdio.h>
#include <stdbool.h>

// Função para verificar se o padrão está presente no vetor de dados
bool reconhecerPadrao(int dados[], int tamanhoDados, int padrao[], int tamanhoPadrao) {
    for (int i = 0; i <= tamanhoDados - tamanhoPadrao; i++) {
        bool encontrado = true;

        for (int j = 0; j < tamanhoPadrao; j++) {
            if (dados[i + j] != padrao[j]) {
                encontrado = false;
                break;
            }
        }

        if (encontrado) {
            return true; // Padrão encontrado
        }
    }
    return false; // Padrão não encontrado
}

int main() {
    // Dados e padrão de exemplo
    int dados[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamanhoDados = sizeof(dados) / sizeof(dados[0]);

    int padrao[] = {4, 5, 6};
    int tamanhoPadrao = sizeof(padrao) / sizeof(padrao[0]);

    // Verificar se o padrão está presente nos dados
    if (reconhecerPadrao(dados, tamanhoDados, padrao, tamanhoPadrao)) {
        printf("Padrão encontrado no vetor de dados.\n");
    } else {
        printf("Padrão não encontrado no vetor de dados.\n");
    }

    return 0;
}

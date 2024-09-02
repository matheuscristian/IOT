#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para comprimir uma string usando RLE
void compressaoRLE(const char *input, char *output) {
    int n = strlen(input);
    int i = 0, j = 0;

    while (i < n) {
        // Contar a quantidade de caracteres iguais consecutivos
        int count = 1;
        while (i + 1 < n && input[i] == input[i + 1]) {
            i++;
            count++;
        }

        // Armazenar o caractere e sua contagem
        output[j++] = input[i];
        output[j++] = count + '0'; // Converte a contagem para caractere

        i++;
    }

    output[j] = '\0'; // Finaliza a string comprimida
}

// Função para descomprimir uma string usando RLE
void descompressaoRLE(const char *input, char *output) {
    int i = 0, j = 0;

    while (input[i] != '\0') {
        char ch = input[i++];
        int count = input[i++] - '0'; // Converte o caractere para um número

        // Adiciona o caractere 'count' vezes
        for (int k = 0; k < count; k++) {
            output[j++] = ch;
        }
    }

    output[j] = '\0'; // Finaliza a string descomprimida
}

int main() {
    const char *original = "AAAABBBCCDAA";
    char comprimido[100];
    char descomprimido[100];

    // Comprimir a string
    compressaoRLE(original, comprimido);
    printf("Comprimido: %s\n", comprimido);

    // Descomprimir a string
    descompressaoRLE(comprimido, descomprimido);
    printf("Descomprimido: %s\n", descomprimido);

    return 0;
}

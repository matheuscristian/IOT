#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, isPalindrome = 1;

    printf("Digite uma palavra ou numero: ");
    scanf("%s", str);

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("%s eh um palindromo\n", str);
    } else {
        printf("%s nao eh um palindromo\n", str);
    }
} 

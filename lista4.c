#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ehPalindromo(char *p, int f, int l) {
    if (f >= l) {
        return true;
    }
    if (p[f] != p[l]) {
        return false;
    }

    return ehPalindromo(p, f+1, l-1);

}

int somaPares(int n[], int l) {
    int soma = 0;
    if (l == 0) return 0;

    if (n[l-1] % 2 == 0) soma += n[l-1];

    return soma;
}

int main(void) {
    char *p = "ovo";
    int tam = strlen(p);

    if (ehPalindromo(p, 0, tam-1)) {
        printf("Eh palindromo: %s \n", p);
    }else printf("Nao eh palindromo: %s \n", p);

    int nums[] = {1,2,3,4,5};
    printf("%d\n", somaPares(nums, 5));

    return 0;
}

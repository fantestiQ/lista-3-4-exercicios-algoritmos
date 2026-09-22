#include <stdlib.h>
#include <stdio.h>



int fatorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fatorial(n - 1);
}

int potencia(int n, int e) {
    if (e == 0) {
        return 1;
    }
    return n * potencia(n, e - 1);
}

int somaArray(int a[], int n) {
    if (n == 0) {
        return 0;
    }
    return   a[n-1] + somaArray(a, n - 1);
}
int produtoArray(int a[], int n) {
    if (n == 0) {
        return 0;
    }
    return   a[n-1] * somaArray(a, n - 1);
}

int main() {
    printf("Fatorial: %d\n", fatorial(5));
    printf("Potencia: %d\n", potencia(2,8));
    int arr[] = {1,2,3,4,5};
    printf("Soma: %d\n", somaArray(arr,5));
    printf("Produto: %d\n", produtoArray(arr,5));
}
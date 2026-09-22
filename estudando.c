#include <stdio.h>
#include <stdlib.h>


int buscaBinaria (int lista[], int valor, int n) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim)  {
        int meio = (inicio + fim) / 2;
        int chute = lista[meio];
        if (chute == valor) {
            return meio;
        }
        else if (chute > valor) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }
    return -1;
}
int main () {
    int arr[] = {1,2,3,6,7,10,12};
    printf ("%d", buscaBinaria (arr, 10, 7));
}
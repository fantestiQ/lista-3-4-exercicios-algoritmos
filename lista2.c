#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Endereco {
    char rua[50];
    int numero;
    char cidade[50];
}Endereco;

typedef struct Pessoa {
    char nome[50];
    int idade;
    float altura;
    Endereco endereco;
}Pessoa;

void imprimeEndereco (Pessoa p) {
    printf("Rua: %s\nNumero: %d\nCidade: %s\n", p.endereco.rua, p.endereco.numero, p.endereco.cidade);
}

void imprime(Pessoa p) {
    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", p.nome, p.idade, p.altura);
}

void limpaBuffer () {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Pessoa criaPessoa() {
    Pessoa p;
    printf("Informe seu nome: ");
    fgets(p.nome, 50, stdin);
    printf("Informe sua idade: ");
    scanf("%d", &p.idade);
    printf("Informe sua altura: ");
    scanf("%f%*c", &p.altura);


    printf("Informe sua cidade: ");
    fgets(p.endereco.cidade, 50, stdin);
    printf("Informe sua rua: ");
    fgets(p.endereco.rua, 50, stdin);

    printf("Informe sua numero: ");
    scanf("%d", &p.endereco.numero);
    limpaBuffer();

    p.nome[strcspn(p.nome, "\n")] = '\0';
    p.endereco.cidade[strcspn(p.endereco.cidade, "\n")] = '\0';
    p.endereco.rua[strcspn(p.endereco.rua, "\n")] = '\0';
    return p;
}

void buscaPessoa(Pessoa ps[],int n, char nome[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ps[i].nome, nome) == 0) {
            imprime(ps[i]);
        }
    }
}

void modificaValor(int *p) {
    *p += 10;
}

int somaPonteiros(int *value1, int *value2) {
    return *value1 + *value2;
}

void swap(int *value1, int *value2) {
    int aux;
    aux = *value1;
    *value1 = *value2;
    *value2 = aux;
}

int main () {
    Pessoa p = criaPessoa();
    Pessoa p2 = criaPessoa();
    Pessoa p3 = criaPessoa();

    Pessoa pessoas[] = {p, p2, p3};

    buscaPessoa(pessoas, 3, "isac");
    imprime(p);
    imprimeEndereco(p);

    int num = 30;
    int *ponteiro = &num;

    printf("Poteiro 1 Endereco: %p\n", ponteiro);
    printf("Poteiro 1 Valor: %d\n",  *ponteiro);

    modificaValor(ponteiro);

    printf("Modificado Poteiro 1 Endereco: %p\n", ponteiro);
    printf("Modificado Poteiro 1 Valor: %d\n",  *ponteiro);

    int num2 = 20;
    int *ponteiro2 = &num2;

    printf("Poteiro 2 Endereco: %p\n", ponteiro2);
    printf("Poteiro 2 Valor: %d\n",  *ponteiro2);

    printf("Soma ponteiros: %d\n", somaPonteiros(ponteiro, ponteiro2));

    swap(ponteiro, ponteiro2);
    printf("Poteiro 1 Valor apos swap: %d\n",  *ponteiro);
    printf("Poteiro 2 Valor apos swap: %d\n",  *ponteiro2);

}
#include <stdio.h>
#include <string.h>

struct Carta {
    int codigo;
    char estado[50];
    char cidade[50];
    long populacao;
    float area;  // em km²
    float pib;   // em bilhões
    int pontos_turisticos;
};

void lerCarta(struct Carta *carta, int numero) {
    char linha[100];

    printf("=== Digite os dados da carta %d ===\n", numero);

    printf("Código:\n");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d", &carta->codigo);

    printf("Estado:\n");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = '\0';

    printf("Cidade:\n");
    fgets(carta->cidade, sizeof(carta->cidade), stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = '\0';

    printf("População:\n");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%ld", &carta->populacao);

    printf("Área (em km²):\n");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%f", &carta->area);

    printf("PIB (em bilhões):\n");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%f", &carta->pib);

    printf("Nº de pontos turísticos:\n");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d", &carta->pontos_turisticos);

    printf("\n");
}

void exibirCarta(struct Carta carta, int numero) {
    printf("=== Carta %d ===\n", numero);
    printf("Código: %d\n", carta.codigo);
    printf("Estado: %s\n", carta.estado);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %ld\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("\n");
}

int main() {
    struct Carta carta1, carta2;

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    printf("===== DADOS DIGITADOS =====\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}

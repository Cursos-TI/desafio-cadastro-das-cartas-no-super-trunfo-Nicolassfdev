#include <stdio.h>
#include <string.h>
#define MAX_CARTAS 2

struct Carta{

    char codigo_da_carta[20];
    char estado[20];
    char nome_da_cidade[30];
    unsigned long int populacao;
    float area_em_km2;
    float PIB;
    int numero_de_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float superpoder;

};

int main(void) {
    struct Carta cartas [MAX_CARTAS];
    char linha[100];

for (int i = 0; i < MAX_CARTAS; i++){
    printf("=== Digite os dados da carta %d ===\n", i + 1);

    printf("Digite o código da carta:\n");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%s", cartas[i].codigo_da_carta);

    printf("Digite seu estado:\n");
    fgets(cartas[i].estado, sizeof(cartas[i].estado), stdin);
    cartas[i].estado[strcspn(cartas[i].estado,"\n")] = '\0'; 

    printf("Digite o nome da cidade:\n");
    fgets(cartas[i].nome_da_cidade, sizeof(cartas[i].nome_da_cidade), stdin);
    cartas[i].nome_da_cidade[strcspn(cartas[i].nome_da_cidade, "\n")] = '\0';

    printf("Digite a população:\n");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%lu", &cartas[i].populacao);

    printf("Digite a área em km²:\n");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%f", &cartas[i].area_em_km2); 

    printf("Digite o PIB:\n");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%f", &cartas[i].PIB);

    printf("Digite a quantidade de pontos turisticos:\n");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d", &cartas[i].numero_de_pontos_turisticos);

    cartas[i].densidade_populacional = 0;
    cartas[i].densidade_populacional = cartas[i].populacao /  cartas[i].area_em_km2;


    cartas[i].pib_per_capita = cartas[i].PIB / cartas[i].populacao;

    cartas[i].superpoder = cartas[i].populacao +
                               cartas[i].area_em_km2 +
                               cartas[i].PIB +
                               cartas[i].numero_de_pontos_turisticos +
                               cartas[i].pib_per_capita +
                               (1.0f / cartas[i].densidade_populacional);



}
for (int i = 0; i < MAX_CARTAS; i++){
    printf("\n=== Dados da Carta %d ===\n", i + 1);
    printf("Código da carta: %s\n", cartas[i].codigo_da_carta);
    printf("Estado: %s\n", cartas[i].estado);
    printf("Cidade: %s\n", cartas[i].nome_da_cidade);
    printf("População: %d\n", cartas[i].populacao);
    printf("Área: %.2f km²\n", cartas[i].area_em_km2);
    printf("PIB: %.2f\n", cartas[i].PIB);
    printf("Pontos turisticos: %d\n", cartas[i].numero_de_pontos_turisticos);
    printf("Densidade populacional: %d\n", cartas[i].densidade_populacional);
    printf("PIB per capita: %.2f\n", cartas[i].pib_per_capita);
    printf("Superpoder: %.2f\n", cartas[i].superpoder);
  } 

    printf("\n=== Comparação de Cartas ===\n");
    printf("Populaçao: Carta 1 venceu(%d)\n", cartas[0].populacao > cartas[1].populacao);
    printf("Área: Carta 1 venceu (%d)\n", cartas[0].area_em_km2 > cartas[1].area_em_km2);
    printf("PIB: Carta 1 vence (%d)\n", cartas[0].PIB > cartas[1].PIB);
    printf("Pontos turísticos:(%d)\n", cartas[0].numero_de_pontos_turisticos > cartas[1].numero_de_pontos_turisticos);
    printf("Densidade populacional: (%d)\n", cartas[0].densidade_populacional <  cartas[1].densidade_populacional);
    printf("PIB per capita: Carta 1 venceu (%d)\n", cartas[0].pib_per_capita > cartas[1].pib_per_capita);
    printf("Superpoder: Carta 1 venceu (%d)\n", cartas[0].superpoder > cartas[1].superpoder);

    return 0;
}

#include <stdio.h>

/*
 Desafio Super Trunfo - Países
 Nível: Mestre (Avançado)
 
 Objetivo: Cadastro, Cálculos e Comparação de Cartas sem uso de condicionais (if/else).
*/

int main() {
    // --- Declaração de Variáveis para a Carta 1 ---
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1; // Requisito: unsigned long int
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;

    // --- Declaração de Variáveis para a Carta 2 ---
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    // Variáveis para armazenar o resultado das comparações (0 ou 1)
    int compPopulacao, compArea, compPib, compPontos, compDensidade, compPibPerCapita, compSuperPoder;

    printf("=== Cadastro das Cartas do Super Trunfo ===\n\n");

    // --- Leitura da Carta 1 ---
    printf("Digite os dados da Carta 1:\n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &estado1); // Espaço antes do %c para limpar o buffer

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1); // Lê string com espaços (ex: São Paulo)

    printf("População: ");
    scanf("%lu", &populacao1); // %lu para unsigned long int

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- Leitura da Carta 2 ---
    printf("\nDigite os dados da Carta 2:\n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Cálculos ---
    
    // Carta 1
    // Casting (float) na população para garantir divisão correta com decimais
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = pib1 / (float)populacao1; 
    
    // Cálculo do Super Poder Carta 1
    // Soma de todos os atributos + inverso da densidade (1/densidade)
    // O inverso é usado porque "menor densidade" é melhor, então invertendo, o valor fica maior para densidades menores.
    superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 + pibPerCapita1 + (1.0f / densidadePopulacional1);

    // Carta 2
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = pib2 / (float)populacao2;
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 + pibPerCapita2 + (1.0f / densidadePopulacional2);

    // --- Exibição dos Dados Cadastrados ---
    printf("\n----------------------------------\n");
    
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1); // Nota: O valor será pequeno se o PIB for inserido como bilhões (ex: 699.28) sem conversão, seguindo a lógica estrita.

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    // --- Lógica de Comparação (Sem if/else) ---
    // Resultado 1 = Carta 1 venceu. Resultado 0 = Carta 2 venceu.
    
    compPopulacao = populacao1 > populacao2;
    compArea = area1 > area2;
    compPib = pib1 > pib2;
    compPontos = pontosTuristicos1 > pontosTuristicos2;
    compPibPerCapita = pibPerCapita1 > pibPerCapita2;
    compSuperPoder = superPoder1 > superPoder2;
    
    // Densidade Populacional: Vence a MENOR densidade.
    // Então verificamos se densidade1 é MENOR que densidade2.
    compDensidade = densidadePopulacional1 < densidadePopulacional2;

    // --- Exibição dos Resultados das Comparações ---
    printf("\n----------------------------------\n");
    printf("Comparação de Cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", compPopulacao);
    printf("Área: Carta 1 venceu (%d)\n", compArea);
    printf("PIB: Carta 1 venceu (%d)\n", compPib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", compPontos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", compDensidade);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", compPibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", compSuperPoder);

    return 0;
}

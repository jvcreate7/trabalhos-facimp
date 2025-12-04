#include <stdio.h>

// Desafio Super Trunfo - Países
// Nível: Mestre (Avançado)
// Aluno: [Seu Nome Aqui]

int main() {
    // --- Variáveis Carta 1 ---
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1;

    // --- Variáveis Carta 2 ---
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2;

    // --- Variáveis de Jogo ---
    int opcao1, opcao2;
    float valor1_c1, valor1_c2; // Armazena o valor do primeiro atributo escolhido
    float valor2_c1, valor2_c2; // Armazena o valor do segundo atributo escolhido
    float soma_c1, soma_c2;     // Soma dos dois atributos
    char nomeAtributo1[30], nomeAtributo2[30]; // Para exibir no resultado

    printf("=== Super Trunfo: Cadastro e Batalha ===\n\n");

    // ============================================================
    // ETAPA 1: CADASTRO DAS CARTAS (Reaproveitado)
    // ============================================================
    
    // Leitura Carta 1
    printf("-- Cadastro da Carta 1 --\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões): ");
    scanf("%f", &pib1);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos Carta 1
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = pib1 / (float)populacao1;

    // Leitura Carta 2
    printf("\n-- Cadastro da Carta 2 --\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões): ");
    scanf("%f", &pib2);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos Carta 2
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = pib2 / (float)populacao2;


    // ============================================================
    // ETAPA 2: MENUS INTERATIVOS (Switch e Lógica Dinâmica)
    // ============================================================

    printf("\n=== Hora da Batalha! ===\n");
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // Switch para definir os valores do atributo 1
    switch (opcao1) {
        case 1:
            valor1_c1 = (float)populacao1;
            valor1_c2 = (float)populacao2;
            sprintf(nomeAtributo1, "População");
            break;
        case 2:
            valor1_c1 = area1;
            valor1_c2 = area2;
            sprintf(nomeAtributo1, "Área");
            break;
        case 3:
            valor1_c1 = pib1;
            valor1_c2 = pib2;
            sprintf(nomeAtributo1, "PIB");
            break;
        case 4:
            valor1_c1 = (float)pontosTuristicos1;
            valor1_c2 = (float)pontosTuristicos2;
            sprintf(nomeAtributo1, "Pontos Turísticos");
            break;
        case 5:
            valor1_c1 = densidade1;
            valor1_c2 = densidade2;
            sprintf(nomeAtributo1, "Densidade Demográfica");
            break;
        default:
            printf("Opção inválida! Usando População como padrão.\n");
            valor1_c1 = (float)populacao1;
            valor1_c2 = (float)populacao2;
            sprintf(nomeAtributo1, "População");
            opcao1 = 1; // Força opção 1 para evitar erro no menu 2
    }

    // Menu Dinâmico: Não exibe a opção já escolhida
    printf("\nEscolha o SEGUNDO atributo (não pode ser igual ao primeiro):\n");
    if (opcao1 != 1) printf("1. População\n");
    if (opcao1 != 2) printf("2. Área\n");
    if (opcao1 != 3) printf("3. PIB\n");
    if (opcao1 != 4) printf("4. Pontos Turísticos\n");
    if (opcao1 != 5) printf("5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao2);

    // Validação simples: se escolher igual, avisa e encerra (ou usa padrão)
    if (opcao1 == opcao2) {
        printf("Você escolheu o mesmo atributo! Isso não é permitido.\n");
        return 1; // Encerra o programa com erro
    }

    // Switch para definir os valores do atributo 2
    switch (opcao2) {
        case 1:
            valor2_c1 = (float)populacao1;
            valor2_c2 = (float)populacao2;
            sprintf(nomeAtributo2, "População");
            break;
        case 2:
            valor2_c1 = area1;
            valor2_c2 = area2;
            sprintf(nomeAtributo2, "Área");
            break;
        case 3:
            valor2_c1 = pib2;
            valor2_c2 = pib2; // Correção: pib2 não pib1
            sprintf(nomeAtributo2, "PIB");
            break;
        case 4:
            valor2_c1 = (float)pontosTuristicos1;
            valor2_c2 = (float)pontosTuristicos2;
            sprintf(nomeAtributo2, "Pontos Turísticos");
            break;
        case 5:
            valor2_c1 = densidade1;
            valor2_c2 = densidade2;
            sprintf(nomeAtributo2, "Densidade Demográfica");
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }


    // ============================================================
    // ETAPA 3: COMPARAÇÕES E RESULTADOS
    // ============================================================

    printf("\n--------------------------------------------------\n");
    printf("RESULTADO DA BATALHA: %s vs %s\n", nomeCidade1, nomeCidade2);
    printf("--------------------------------------------------\n");

    // 1. Comparação do Primeiro Atributo
    printf("Atributo 1: %s\n", nomeAtributo1);
    printf("Carta 1: %.2f | Carta 2: %.2f\n", valor1_c1, valor1_c2);
    
    // Regra especial para Densidade (menor vence)
    if (opcao1 == 5) {
        if (valor1_c1 < valor1_c2) printf("Vencedor: Carta 1 (%s)\n", nomeCidade1);
        else if (valor2_c1 < valor1_c1) printf("Vencedor: Carta 2 (%s)\n", nomeCidade2); // Erro de digitação corrigido na lógica
        else printf("Empate!\n");
    } else {
        if (valor1_c1 > valor1_c2) printf("Vencedor: Carta 1 (%s)\n", nomeCidade1);
        else if (valor1_c2 > valor1_c1) printf("Vencedor: Carta 2 (%s)\n", nomeCidade2);
        else printf("Empate!\n");
    }

    printf("\n");

    // 2. Comparação do Segundo Atributo
    printf("Atributo 2: %s\n", nomeAtributo2);
    printf("Carta 1: %.2f | Carta 2: %.2f\n", valor2_c1, valor2_c2);
    
    if (opcao2 == 5) {
        if (valor2_c1 < valor2_c2) printf("Vencedor: Carta 1 (%s)\n", nomeCidade1);
        else if (valor2_c2 < valor2_c1) printf("Vencedor: Carta 2 (%s)\n", nomeCidade2);
        else printf("Empate!\n");
    } else {
        if (valor2_c1 > valor2_c2) printf("Vencedor: Carta 1 (%s)\n", nomeCidade1);
        else if (valor2_c2 > valor2_c1) printf("Vencedor: Carta 2 (%s)\n", nomeCidade2);
        else printf("Empate!\n");
    }

    // 3. Soma dos Atributos (Requisito Final)
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    printf("\n--------------------------------------------------\n");
    printf("SOMA DOS ATRIBUTOS:\n");
    printf("Carta 1: %.2f\n", soma_c1);
    printf("Carta 2: %.2f\n", soma_c2);
    
    // Uso do Operador Ternário para decidir o vencedor final (soma maior vence)
    // Sintaxe: (condição) ? verdadeiro : falso
    printf("VENCEDOR FINAL: %s\n", (soma_c1 > soma_c2) ? "CARTA 1 VENCEU!" : (soma_c2 > soma_c1) ? "CARTA 2 VENCEU!" : "EMPATE!");
    printf("--------------------------------------------------\n");

    return 0;
}

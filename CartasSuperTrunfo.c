#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4

// Estrutura para representar uma cidade
typedef struct {
    char codigo[4];
    int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    double pib_per_capita;
} Cidade;

void calcularPropriedades(Cidade *cidade) {
    cidade->densidade_populacional = cidade->populacao / cidade->area;
    cidade->pib_per_capita = cidade->pib / cidade->populacao;
}

void cadastrarCidades(Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            snprintf(cidades[i][j].codigo, sizeof(cidades[i][j].codigo), "%c%02d", estados[i], j + 1);
            printf("Cadastro da cidade %s:\n", cidades[i][j].codigo);
            printf("Populacao: ");
            scanf("%d", &cidades[i][j].populacao);
            printf("Area (km²): ");
            scanf("%f", &cidades[i][j].area);
            printf("PIB (em bilhões): ");
            scanf("%lf", &cidades[i][j].pib);
            printf("Numero de pontos turisticos: ");
            scanf("%d", &cidades[i][j].pontos_turisticos);
            calcularPropriedades(&cidades[i][j]);
            printf("\n");
        }
    }
}

void exibirCidades(Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    printf("=== Dados das Cidades Cadastradas ===\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            printf("Codigo: %s\n", cidades[i][j].codigo);
            printf("Populacao: %d\n", cidades[i][j].populacao);
            printf("Area: %.2f km²\n", cidades[i][j].area);
            printf("PIB: %.2lf bilhões\n", cidades[i][j].pib);
            printf("Pontos turisticos: %d\n", cidades[i][j].pontos_turisticos);
            printf("Densidade Populacional: %.2f hab/km²\n", cidades[i][j].densidade_populacional);
            printf("PIB per Capita: %.2lf bilhões\n", cidades[i][j].pib_per_capita);
            printf("-----------------------------\n");
        }
    }
}

Cidade compararCartas(Cidade c1, Cidade c2) {
    int c1_super_poder = c1.populacao + c1.area + c1.pib + c1.pontos_turisticos;
    int c2_super_poder = c2.populacao + c2.area + c2.pib + c2.pontos_turisticos;
    
    return (c1_super_poder > c2_super_poder) ? c1 : c2;
}

void compararCidades(Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    char cod1[4], cod2[4];
    Cidade *c1 = NULL, *c2 = NULL;
    
    printf("Digite o código da primeira cidade: ");
    scanf("%s", cod1);
    printf("Digite o código da segunda cidade: ");
    scanf("%s", cod2);
    
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            if (strcmp(cidades[i][j].codigo, cod1) == 0) {
                c1 = &cidades[i][j];
            }
            if (strcmp(cidades[i][j].codigo, cod2) == 0) {
                c2 = &cidades[i][j];
            }
        }
    }
    
    if (c1 && c2) {
        Cidade vencedora = compararCartas(*c1, *c2);
        printf("A cidade vencedora é: %s\n", vencedora.codigo);
    } else {
        printf("Códigos inválidos!\n");
    }
}

int main() {
    Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO];
    
    printf("Bem-vindo ao Super Trunfo - Cadastro de Cidades!\n\n");
    cadastrarCidades(cidades);
    exibirCidades(cidades);
    
    printf("\nAgora vamos comparar duas cidades!\n");
    compararCidades(cidades);
    
    return 0;
}

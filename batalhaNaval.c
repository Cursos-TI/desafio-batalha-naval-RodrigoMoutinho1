#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // Coordenadas iniciais dos navios
    int linhaNavio1 = 2, colunaNavio1 = 4; // Horizontal
    int linhaNavio2 = 5, colunaNavio2 = 7; // Vertical

    // Inicializa o tabuleiro com água
    for (i = 0; i < TAMANHO_TABULEIRO; i++) 
    {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) 
        {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Validação do navio 1 (horizontal)
    if (colunaNavio1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) 
    {
        for (i = 0; i < TAMANHO_NAVIO; i++) 
        {
            tabuleiro[linhaNavio1][colunaNavio1 + i] = NAVIO;
        }
    } else {
        printf("Erro: Navio 1 fora dos limites!\n");
        return 1;
    }

    // Validação do navio 2 (vertical) e sobreposição
    if (linhaNavio2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) 
    {
        for (i = 0; i < TAMANHO_NAVIO; i++) 
        {
            if (tabuleiro[linhaNavio2 + i][colunaNavio2] == NAVIO) 
            {
                printf("Erro: Sobreposição de navios!\n");
                return 1;
            }
            tabuleiro[linhaNavio2 + i][colunaNavio2] = NAVIO;
        }
    } else {
        printf("Erro: Navio 2 fora dos limites!\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) 
    {
        for (j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

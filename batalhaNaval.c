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
    int linhaNavio3 = 0, colunaNavio3 = 0; // Diagonal 1
    int linhaNavio4 = 0, colunaNavio4 = 9; // Diagonal 2

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

    // Validação do navio 3 (Diagonal)
    if (linhaNavio3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaNavio3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)
    {
        for (i = 0; i < TAMANHO_NAVIO; i++)
        {
            if (tabuleiro[linhaNavio3 + i][colunaNavio3 + i] == NAVIO)
            {
               printf("Erro: Sobreposição de navios!\n");
               return 1;
            }
            tabuleiro[linhaNavio3 + i][colunaNavio3 + i] = NAVIO;
        }
        
    } else {
        printf("Erro: Navio 3 fora dos limites!\n");
        return 1;
    }
    
    // Validação do navio 4 (diagonal)
    if (linhaNavio4 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaNavio4 - (TAMANHO_NAVIO - 1) >= 0)
    {
        for (i = 0; i < TAMANHO_NAVIO; i++)
        {
            if (tabuleiro[linhaNavio4 + i][colunaNavio4 - i] == NAVIO)
            {
                printf("Erro: Sobreposição de navios!\n");
                return 1;
            }
            tabuleiro[linhaNavio4 + i][colunaNavio4 - i] = NAVIO;
        }
        
    } else {
        printf("Erro: Navio 4 fora dos limites!\n");
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

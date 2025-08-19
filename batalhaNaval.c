#include <stdio.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define HSIZE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para exibir qualquer matriz 5x5
void mostrarMatriz(int mat[HSIZE][HSIZE]) {
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar habilidade no tabuleiro
void aplicarHabilidade(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                       int hab[HSIZE][HSIZE], int origemLinha, int origemColuna) {
    int offset = HSIZE/2;
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (hab[i][j] == 3) {
                int linhaTab = origemLinha + (i - offset);
                int colTab = origemColuna + (j - offset);
                if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                    colTab >= 0 && colTab < TAMANHO_TABULEIRO &&
                    tab[linhaTab][colTab] == AGUA) {
                    tab[linhaTab][colTab] = HABILIDADE;
                }
            }
        }
    }
}

// Função para mostrar tabuleiro
void mostrarTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tab[i][j] == AGUA) printf("~ ");
            else if (tab[i][j] == NAVIO) printf("N ");
            else if (tab[i][j] == HABILIDADE) printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // Inicializa tabuleiro com água
    for (i = 0; i < TAMANHO_TABULEIRO; i++)
        for (j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = AGUA;

    // Posicionar navios (exemplo)
    tabuleiro[2][4] = NAVIO; tabuleiro[2][5] = NAVIO; tabuleiro[2][6] = NAVIO; // horizontal
    tabuleiro[5][7] = NAVIO; tabuleiro[6][7] = NAVIO; tabuleiro[7][7] = NAVIO; // vertical
    tabuleiro[0][0] = NAVIO; tabuleiro[1][1] = NAVIO; tabuleiro[2][2] = NAVIO; // diagonal
    tabuleiro[0][9] = NAVIO; tabuleiro[1][8] = NAVIO; tabuleiro[2][7] = NAVIO; // diagonal invertida

    // Criar matrizes de habilidade
    int cone[HSIZE][HSIZE];
    int cruz[HSIZE][HSIZE];
    int octaedro[HSIZE][HSIZE];

    // === Cone ===
    for (i = 0; i < HSIZE; i++)
        for (j = 0; j < HSIZE; j++)
            if (i == 0 && j == 2) cone[i][j] = 3;
            else if (i == 1 && j >= 1 && j <= 3) cone[i][j] = 3;
            else if (i == 2) cone[i][j] = 3;
            else cone[i][j] = 0;

    printf("Matriz Cone (5x5):\n");
    mostrarMatriz(cone);
    printf("\n");
    aplicarHabilidade(tabuleiro, cone, 2, 2);

    // === Cruz ===
    for (i = 0; i < HSIZE; i++)
        for (j = 0; j < HSIZE; j++)
            if (i == 2 || j == 2) cruz[i][j] = 3;
            else cruz[i][j] = 0;

    printf("Matriz Cruz (5x5):\n");
    mostrarMatriz(cruz);
    printf("\n");
    aplicarHabilidade(tabuleiro, cruz, 5, 5);

    // === Octaedro ===
    for (i = 0; i < HSIZE; i++)
        for (j = 0; j < HSIZE; j++)
            if ((i == 0 && j == 2) ||
                (i == 1 && j >= 1 && j <= 3) ||
                (i == 2 && j == 2))
                octaedro[i][j] = 3;
            else
                octaedro[i][j] = 0;

    printf("Matriz Octaedro (5x5):\n");
    mostrarMatriz(octaedro);
    printf("\n");
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);

    // Mostrar tabuleiro final
    printf("Tabuleiro Final com Habilidades Aplicadas:\n");
    mostrarTabuleiro(tabuleiro);

    return 0;
}

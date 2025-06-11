#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// fixando agua e os navios
void inicializaTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Colocando alguns navios
    tabuleiro[3][1] = 3;
    tabuleiro[3][2] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[6][1] = 3;
    tabuleiro[6][2] = 3;
    tabuleiro[6][3] = 3;
}

// Matriz cone
void criaMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= (TAM_HABILIDADE / 2) - i && j <= (TAM_HABILIDADE / 2) + i && i <= TAM_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

//matriz  cruz
void criaMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == meio || j == meio) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

//  matriz losango
void criaMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// matriz sobreposta
void sobreporHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    int meio = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha_tab = origem_linha - meio + i;
            int coluna_tab = origem_coluna - meio + j;

            if (linha_tab >= 0 && linha_tab < TAM_TABULEIRO && coluna_tab >= 0 && coluna_tab < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }
}

// tabuleiro numerado por linha e coluna, não ficou interessante
void exibeTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n   ");
    // linha de A a J
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        // Coluna 1 a 10
        if (i < 9)
            printf(" %d ", i + 1);
        else
            printf("%d ", i + 1);

        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0");
            else if (tabuleiro[i][j] == 3)
                printf("3");
            else if (tabuleiro[i][j] == 5)
                printf("5");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int matrizCone[TAM_HABILIDADE][TAM_HABILIDADE];
    int matrizCruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int matrizOctaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializaTabuleiro(tabuleiro);

    criaMatrizCone(matrizCone);
    criaMatrizCruz(matrizCruz);
    criaMatrizOctaedro(matrizOctaedro);

    int origemConeLinha = 2, origemConeColuna = 2;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaedroLinha = 7, origemOctaedroColuna = 7;

    sobreporHabilidade(tabuleiro, matrizCone, origemConeLinha, origemConeColuna);
    sobreporHabilidade(tabuleiro, matrizCruz, origemCruzLinha, origemCruzColuna);
    sobreporHabilidade(tabuleiro, matrizOctaedro, origemOctaedroLinha, origemOctaedroColuna);

    exibeTabuleiro(tabuleiro);

    return 0;
}

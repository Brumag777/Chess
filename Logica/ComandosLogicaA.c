#include "../Xadrez.h"

// Encontra as possíveis jogadas de uma peça
int encontraJogadas (int l, char c, int Jogadas [8][8], Info I) {

    // Armazena a peça
    char p = I -> Tab [l - 1][c - 'a'];

    // A peça é um peão
    if (p == 'P') return encontraJogadasPeaoB (l, c, Jogadas, I);
    if (p == 'p') return encontraJogadasPeaoP (l, c, Jogadas, I);

    // A peça é uma torre
    if (p == 'T' || p == 't') return encontraJogadasTorre (l, c, Jogadas, I);

    // A peça é um cavalo
    if (p == 'C' || p == 'c') return encontraJogadasCavalo (l, c, Jogadas, I);

    // A peça é um bispo
    if (p == 'B' || p == 'b') return encontraJogadasBispo (l, c, Jogadas, I);

    // A peça é uma rainha
    if (p == 'Q' || p == 'q') return encontraJogadasRainha (l, c, Jogadas, I);

    // A peça é um rei
    return encontraJogadasRei (l, c, Jogadas, I);
}



// Imprime o tabuleiro destacando as casas para as quais a peça se pode mover
void imprimeJogadas (int l, char c, char Tab [8][9], int Jogadas [8][8]) {

    // Avança para a linha seguinte
    printf ("\n    ");

    // Imprime o índice das colunas
    for (int j = 0; j < 8; j++) printf ("%c ", 'a' + j);
    printf ("\n    ");

    // Imprime os '-' em baixo dos índices das colunas
    for (int j = 0; j < 8; j++) printf ("- ");
    putchar ('\n');

    // Imprime o tabuleiro linha a linha
    for (int i = 0; i < 8; i++) {

        // Imprime o índice das linhas
        printf ("%d | ", i + 1);

        // Imprime a linha atual
        for (int j = 0; j < 8; j++) {
            if (i + 1 == l && j + 'a' == c) {
                printf (MAGENTA);
                imprimePeca (Tab [i][j]);
            } else if (Tab [i][j] == '#') {
                if (Jogadas [i][j]) printf (VERDE "○ ");
                else printf ("  ");
            } else {
                if (Jogadas [i][j]) printf (VERMELHO);
                else if (eMinuscula (Tab [i][j])) printf (PRETO);
                imprimePeca (Tab [i][j]);
            } printf (RESET);
        }

        // Avança para a linha seguinte
        putchar ('\n');
    }

    // Avança para a linha seguinte
    putchar ('\n');
}



// Encontra os possíveis ataques de uma peça
void encontraAtaques (int l, char c, int Ataques [8][8], Info I) {

    // Armazena a peça
    char p = I -> Tab [l - 1][c - 'a'];

    // A peça é um peão
    if (p == 'P') encontraAtaquesPeaoB (l, c, Ataques);
    else if (p == 'p') encontraAtaquesPeaoP (l, c, Ataques);

    // A peça é uma torre
    else if (p == 'T' || p == 't') encontraAtaquesTorre (l, c, Ataques, I);

    // A peça é um cavalo
    else if (p == 'C' || p == 'c') encontraAtaquesCavalo (l, c, Ataques, I);

    // A peça é um bispo
    else if (p == 'B' || p == 'p') encontraAtaquesBispo (l, c, Ataques, I);

    // A peça é uma rainha
    else if (p == 'Q' || p == 'q') encontraAtaquesRainha (l, c, Ataques, I);
}



// Verifica se o jogo já terminou
int fimJogo (Info I) {

    // Verifica se houve stalemate ou cheque-mate
    if (mate (I)) return 1;

    // Verifica se houve empate por repetição
    if (triplaRepeticao (I)) {
        printf (VERDE "É empate por repetição!\n\n" RESET);
        return 1;
    }

    // Verifica a regra dos 50 lances
    if (I -> NJogada - I -> UltimoAvanco == 50) {
        printf (VERDE "É empate pela regra dos 50 lances!\n\n" RESET);
        return 1;
    }

    // Verifica se há material insuficiente para dar cheque-mate
    if (materialInsuficiente (I)) {
        printf (VERDE "É empate por material insuficiente!\n\n" RESET);
        return 1;
    }

    // O jogo ainda não terminou
    return 0;
}
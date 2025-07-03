#include "../Xadrez.h"

// Verifica se o rei branco está em cheque
int reiBrancoCheque (Info I) {

    // Coordenadas do rei branco
    int l = 0;
    char c = 0;

    // Procura o rei branco
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (I -> Tab [i][j] == 'R') {
                l = i + 1;
                c = j + 'a';
                break;
            }

    // Verifica se alguma peça preta coloca o rei em cheque
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (eMinuscula (I -> Tab [i][j])) {

                // Cria um tabuleiro que indica os possíveis ataques da peça
                int Ataques [8][8] = {0};

                // Encontra os ataques da peça
                encontraAtaques (i + 1, j + 'a', Ataques, I);

                // Verifica se a peça está a atacar o rei
                if (Ataques [l - 1][c - 'a']) return 1;
            }

    // O rei não está em cheque
    return 0;
}



// Verifica se o rei preto está em cheque
int reiPretoCheque (Info I) {

    // Coordenadas do rei branco
    int l = 0;
    char c = 0;

    // Procura o rei branco
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (I -> Tab [i][j] == 'r') {
                l = i + 1;
                c = j + 'a';
                break;
            }

    // Verifica se alguma peça preta coloca o rei em cheque
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (eMaiuscula (I -> Tab [i][j])) {

                // Cria um tabuleiro que indica os possíveis ataques da peça
                int Ataques [8][8] = {0};

                // Encontra os ataques da peça
                encontraAtaques (i + 1, j + 'a', Ataques, I);

                // Verifica se a peça está a atacar o rei
                if (Ataques [l - 1][c - 'a']) return 1;
            }

    // O rei não está em cheque
    return 0;
}



// Verifica se, ao realizar uma jogada, o rei fica em cheque
int colocaReiCheque (int li, char ci, int lf, char cf, Info I) {

    // Armazena as duas peças
    char pi = I -> Tab [li - 1][ci - 'a'];
    char pf = I -> Tab [lf - 1][cf - 'a'];

    // Realiza a jogada
    I -> Tab [li - 1][ci - 'a'] = '#';
    I -> Tab [lf - 1][cf - 'a'] = pi;

    // Inteiro que indica se o rei ficou ou não em cheque
    int EmCheque = 0;

    // Verifica se o rei ficou em cheque
    if (eMaiuscula (pi)) EmCheque = reiBrancoCheque (I);
    else EmCheque = reiPretoCheque (I);

    // Desfaz a jogada
    I -> Tab [li - 1][ci - 'a'] = pi;
    I -> Tab [lf - 1][cf - 'a'] = pf;

    // Indica se o rei ficou ou não em cheque
    return EmCheque;
}
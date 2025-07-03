#include "../Xadrez.h"

// Encontra os ataques de um peão branco
void encontraAtaquesPeaoB (int l, char c, int Ataques [8][8]) {

    // Verifica a possibilidade de captura à esquerda
    if (c != 'a') Ataques [l][c - 1 - 'a'] = 1;

    // Verifica a possibilidade de captura à direita
    if (c != 'h') Ataques [l][c + 1 - 'a'] = 1;
}



// Encontra os ataques de um peão preto
void encontraAtaquesPeaoP (int l, char c, int Ataques [8][8]) {

    // Verifica a possibilidade de captura à esquerda
    if (c != 'a') Ataques [l - 2][c - 1 - 'a'] = 1;

    // Verifica a possibilidade de captura à direita
    if (c != 'h') Ataques [l - 2][c + 1 - 'a'] = 1;
}



// Encontra os ataques de uma torre
void encontraAtaquesTorre (int l, char c, int Ataques [8][8], Info I) {

    // Verifica acima da torre
    for (int i = l - 1; i >= 1; i--) {
        if (I -> Tab [i - 1][c - 'a'] == '#') {
            Ataques [i - 1][c - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [i - 1][c - 'a'])) Ataques [i - 1][c - 'a'] = 2;
            break;
        }
    }

    // Verifica abaixo da torre
    for (int i = l + 1; i <= 8; i++) {
        if (I -> Tab [i - 1][c - 'a'] == '#') {
            Ataques [i - 1][c - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [i - 1][c - 'a'])) Ataques [i - 1][c - 'a'] = 2;
            break;
        }
    }

    // Verifica à esquerda da torre
    for (char j = c - 1; j >= 'a'; j--) {
        if (I -> Tab [l - 1][j - 'a'] == '#') {
            Ataques [l - 1][j - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l - 1][j - 'a'])) Ataques [l - 1][j - 'a'] = 2;
            break;
        }
    }

    // Verifica à direita da torre
    for (char j = c + 1; j <= 'h'; j++) {

        // A casa não possui nenhuma peça
        if (I -> Tab [l - 1][j - 'a'] == '#') {
            Ataques [l - 1][j - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l - 1][j - 'a'])) Ataques [l - 1][j - 'a'] = 2;
            break;
        }
    }
}



// Encontra os ataques de um cavalo
void encontraAtaquesCavalo (int l, char c, int Ataques [8][8], Info I) {

    // Arrays que indicam os possíveis destinos do cavalo
    int linhas [8] = {l + 2, l + 2, l + 1, l + 1, l - 1, l - 1, l - 2, l - 2};
    char colunas [8] = {c + 1, c - 1, c + 2, c - 2, c + 2, c - 2, c + 1, c - 1};

    // Testa as 8 possibilidades
    for (int i = 0; i < 8; i++) {
        if (coordenadaValida (linhas [i], colunas [i])) {
            if (I -> Tab [linhas [i] - 1][colunas [i] - 'a'] == '#') {
                Ataques [linhas [i] - 1][colunas [i] - 'a'] = 1;
            } else if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [linhas [i] - 1][colunas [i] - 'a']))
                Ataques [linhas [i] - 1][colunas [i] - 'a'] = 2;
        }
    }
}



// Encontra os ataques de um bispo
void encontraAtaquesBispo (int l, char c, int Ataques [8][8], Info I) {

    // Verifica o canto superior esquerdo
    for (int i = 1; coordenadaValida (l - i, c - i); i++) {
        if (I -> Tab [l - i - 1][c - i - 'a'] == '#') {
            Ataques [l - i - 1][c - i - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l - i - 1][c - i - 'a'])) Ataques [l - i - 1][c - i - 'a'] = 2;
            break;
        }
    }

    // Verifica o canto superior direito
    for (int i = 1; coordenadaValida (l - i, c + i); i++) {
        if (I -> Tab [l - i - 1][c + i - 'a'] == '#') {
            Ataques [l - i - 1][c + i - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l - i - 1][c + i - 'a'])) Ataques [l - i - 1][c + i - 'a'] = 2;
            break;
        }
    }

    // Verifica o canto inferior esquerdo
    for (int i = 1; coordenadaValida (l + i, c - i); i++) {
        if (I -> Tab [l + i - 1][c - i - 'a'] == '#') {
            Ataques [l + i - 1][c - i - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l + i - 1][c - i - 'a'])) Ataques [l + i - 1][c - i - 'a'] = 2;
            break;
        }
    }

    // Verifica o canto inferior direito
    for (int i = 1; coordenadaValida (l + i, c + i); i++) {
        if (I -> Tab [l + i - 1][c + i - 'a'] == '#') {
            Ataques [l + i - 1][c + i - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l + i - 1][c + i - 'a'])) Ataques [l + i - 1][c + i - 'a'] = 2;
            break;
        }
    }
}



// Encontra os ataques de uma rainha
void encontraAtaquesRainha (int l, char c, int Jogadas [8][8], Info I) {

    // Testa os ataques da torre
    encontraAtaquesTorre (l, c, Jogadas, I);

    // Testa os ataqyes do bispo
    encontraAtaquesBispo (l, c, Jogadas, I);
}
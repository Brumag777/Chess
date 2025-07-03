#include "../Xadrez.h"

// Verifica se um peão branco pode realizar 'En Passant'
int enPassantB (int l, char c, int Jogadas [8][8], Info I) {

    // Verifica se ainda não foi feita nenhuma jogada
    if (I -> NJogada == 1) return 0;

    // Inteiro que indica se a peça possui ou não alguma jogada disponível
    int JogadaDisponivel = 0;

    // Cria uma lista nova
    Historico H = I -> H;

    // Percorre a lista até ao fim
    while (H -> Proximo) H = H -> Proximo;

    // Verifica se o peão está na linha correta e se a jogada anterior foi um avanço duplo de um peão
    if (l == 5 && H -> J.pi == 'p' && H -> J.li == 7 && H -> J.lf == 5) {

        // Verifica se o peão está à esquerda de peão preto
        if (c + 1 == H -> J.ci) {
            if (!colocaReiCheque (l, c, 6, c + 1, I)) Jogadas [5][c + 1 - 'a'] = JogadaDisponivel = 3;
        }

        // Verifica se o peão está à direita do peão preto
        else if (c - 1 == H -> J.ci)
            if (!colocaReiCheque (l, c, 6, c - 1, I)) Jogadas [5][c - 1 - 'a'] = JogadaDisponivel = 3;
    }

    // Indica se a peça possui ou não jogadas disponíveis
    return JogadaDisponivel;
}



// Encontra as jogadas de um peão branco
int encontraJogadasPeaoB (int l, char c, int Jogadas [8][8], Info I) {

    // Inteiro que indica se a peça possui ou não alguma jogada disponível
    int JogadaDisponivel = 0;

    // Verifica as possibilidades de 'En Passant'
    JogadaDisponivel = enPassantB (l, c, Jogadas, I);

    // Verifica a possibilidade de mover uma casa
    if (I -> Tab [l][c - 'a'] == '#') {

        // É possível mover uma casa
        if (!colocaReiCheque (l, c, l + 1, c, I)) Jogadas [l][c - 'a'] = JogadaDisponivel = 1;

        // Verifica a possibilidade de mover duas casas
        if (l == 2 && I -> Tab [l + 1][c - 'a'] == '#')
            if (!colocaReiCheque (l, c, l + 2, c, I)) Jogadas [l + 1][c - 'a'] = 1;
    }

    // Verifica as possibilidades de captura
    if (c != 'a' && eMinuscula (I -> Tab [l][c - 1 - 'a']))
        if (!colocaReiCheque (l, c, l + 1, c - 1, I)) Jogadas [l][c - 1 - 'a'] = JogadaDisponivel = 2;
    if (c != 'h' && eMinuscula (I -> Tab [l][c + 1 - 'a']))
        if (!colocaReiCheque (l, c, l + 1, c + 1, I)) Jogadas [l][c + 1 - 'a'] = JogadaDisponivel = 2;

    // Indica se a peça possui ou não jogadas disponíveis
    return JogadaDisponivel;
}



// Verifica se um peão preto pode realizar 'En Passant'
int enPassantP (int l, char c, int Jogadas [8][8], Info I) {

    // Verifica se ainda não foi feita nenhuma jogada
    if (I -> NJogada == 1) return 0;

    // Inteiro que indica se a peça possui ou não alguma jogada disponível
    int JogadaDisponivel = 0;

    // Cria uma lista nova
    Historico H = I -> H;

    // Percorre a lista até ao fim
    while (H -> Proximo) H = H -> Proximo;

    // Verifica se o peão está na linha correta e se a jogada anterior foi um avanço duplo de um peão
    if (l == 4 && H -> J.pi == 'P' && H -> J.li == 2 && H -> J.lf == 4) {

        // Verifica se o peão está à esquerda de peão preto
        if (c + 1 == H -> J.ci) {
            if (!colocaReiCheque (l, c, 3, c + 1, I)) Jogadas [2][c + 1 - 'a'] = JogadaDisponivel = 3;
        }

        // Verifica se o peão está à direita do peão preto
        else if (c - 1 == H -> J.ci)
            if (!colocaReiCheque (l, c, 3, c - 1, I)) Jogadas [2][c - 1 - 'a'] = JogadaDisponivel = 3;
    }

    // Indica se a peça possui ou não jogadas disponíveis
    return JogadaDisponivel;
}



// Encontra as jogadas de um peão preto
int encontraJogadasPeaoP (int l, char c, int Jogadas [8][8], Info I) {

    // Inteiro que indica se a peça possui ou não alguma jogada disponível
    int JogadaDisponivel = 0;

    // Verifica as possibilidades de 'En Passant'
    JogadaDisponivel = enPassantP (l, c, Jogadas, I);

    // Verifica a possibilidade de mover uma casa
    if (I -> Tab [l - 2][c - 'a'] == '#') {

        // É possível mover uma casa
        if (!colocaReiCheque (l, c, l - 1, c, I)) Jogadas [l - 2][c - 'a'] = JogadaDisponivel = 1;

        // Verifica a possibilidade de mover duas casas
        if (l == 7 && I -> Tab [l - 3][c - 'a'] == '#')
            if (!colocaReiCheque (l, c, l - 2, c, I)) Jogadas [l - 3][c - 'a'] = 1;
    }

    // Verifica as possibilidades de captura
    if (c != 'a' && eMaiuscula (I -> Tab [l - 2][c - 1 - 'a']))
        if (!colocaReiCheque (l, c, l - 1, c - 1, I)) Jogadas [l - 2][c - 1 - 'a'] = JogadaDisponivel = 2;
    if (c != 'h' && eMaiuscula (I -> Tab [l - 2][c + 1 - 'a']))
        if (!colocaReiCheque (l, c, l - 1, c + 1, I)) Jogadas [l - 2][c + 1 - 'a'] = JogadaDisponivel = 2;

    // Indica se a peça possui ou não jogadas disponíveis
    return JogadaDisponivel;
}



// Encontra as jogadas de uma torre
int encontraJogadasTorre (int l, char c, int Jogadas [8][8], Info I) {

    // Inteiro que indica se a peça possui ou não alguma jogada disponível
    int JogadaDisponivel = 0;

    // Verifica acima da torre
    for (int i = l - 1; i >= 1; i--) {
        if (I -> Tab [i - 1][c - 'a'] == '#') {
            if (!colocaReiCheque (l, c, i, c, I)) Jogadas [i - 1][c - 'a'] = JogadaDisponivel = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [i - 1][c - 'a']))
                if (!colocaReiCheque (l, c, i, c, I)) Jogadas [i - 1][c - 'a'] = JogadaDisponivel = 2;
            break;
        }
    }

    // Verifica abaixo da torre
    for (int i = l + 1; i <= 8; i++) {
        if (I -> Tab [i - 1][c - 'a'] == '#') {
            if (!colocaReiCheque (l, c, i, c, I)) Jogadas [i - 1][c - 'a'] = JogadaDisponivel = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [i - 1][c - 'a']))
                if (!colocaReiCheque (l, c, i, c, I)) Jogadas [i - 1][c - 'a'] = JogadaDisponivel = 2;
            break;
        }
    }

    // Verifica à esquerda da torre
    for (char j = c - 1; j >= 'a'; j--) {
        if (I -> Tab [l - 1][j - 'a'] == '#') {
            if (!colocaReiCheque (l, c, l, j, I)) Jogadas [l - 1][j - 'a'] = JogadaDisponivel = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l - 1][j - 'a']))
                if (!colocaReiCheque (l, c, l, j, I)) Jogadas [l - 1][j - 'a'] = JogadaDisponivel = 2;
            break;
        }
    }

    // Verifica à direita da torre
    for (char j = c + 1; j <= 'h'; j++) {

        // A casa não possui nenhuma peça
        if (I -> Tab [l - 1][j - 'a'] == '#') {
            if (!colocaReiCheque (l, c, l, j, I)) Jogadas [l - 1][j - 'a'] = JogadaDisponivel = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l - 1][j - 'a']))
                if (!colocaReiCheque (l, c, l, j, I)) Jogadas [l - 1][j - 'a'] = JogadaDisponivel = 2;
            break;
        }
    }

    // Indica se a peça possui ou não jogadas disponíveis
    return JogadaDisponivel;
}



// Encontra as jogadas de um cavalo
int encontraJogadasCavalo (int l, char c, int Jogadas [8][8], Info I) {

    // Inteiro que indica se a peça possui ou não alguma jogada disponível
    int JogadaDisponivel = 0;

    // Arrays que indicam os possíveis destinos do cavalo
    int linhas [8] = {l + 2, l + 2, l + 1, l + 1, l - 1, l - 1, l - 2, l - 2};
    char colunas [8] = {c + 1, c - 1, c + 2, c - 2, c + 2, c - 2, c + 1, c - 1};

    // Testa as 8 possibilidades
    for (int i = 0; i < 8; i++) {
        if (coordenadaValida (linhas [i], colunas [i])) {
            if (I -> Tab [linhas [i] - 1][colunas [i] - 'a'] == '#') {
                if (!colocaReiCheque (l, c, linhas [i], colunas [i], I)) Jogadas [linhas [i] - 1][colunas [i] - 'a'] = JogadaDisponivel = 1;
            } else if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [linhas [i] - 1][colunas [i] - 'a']))
                if (!colocaReiCheque (l, c, linhas [i], colunas [i], I)) Jogadas [linhas [i] - 1][colunas [i] - 'a'] = JogadaDisponivel = 2;
        }
    }

    // Indica se a peça possui ou não jogadas disponíveis
    return JogadaDisponivel;
}



// Encontra as jogadas de um bispo
int encontraJogadasBispo (int l, char c, int Jogadas [8][8], Info I) {

    // Inteiro que indica se a peça possui ou não alguma jogada disponível
    int JogadaDisponivel = 0;

    // Verifica o canto superior esquerdo
    for (int i = 1; coordenadaValida (l - i, c - i); i++) {
        if (I -> Tab [l - i - 1][c - i - 'a'] == '#') {
            if (!colocaReiCheque (l, c, l - i, c - i, I)) Jogadas [l - i - 1][c - i - 'a'] = JogadaDisponivel = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l - i - 1][c - i - 'a']))
                if (!colocaReiCheque (l, c, l - i, c - i, I)) Jogadas [l - i - 1][c - i - 'a'] = JogadaDisponivel = 2;
            break;
        }
    }

    // Verifica o canto superior direito
    for (int i = 1; coordenadaValida (l - i, c + i); i++) {
        if (I -> Tab [l - i - 1][c + i - 'a'] == '#') {
            if (!colocaReiCheque (l, c, l - i, c + i, I)) Jogadas [l - i - 1][c + i - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l - i - 1][c + i - 'a']))
                if (!colocaReiCheque (l, c, l - i, c + i, I)) Jogadas [l - i - 1][c + i - 'a'] = JogadaDisponivel = 2;
            break;
        }
    }

    // Verifica o canto inferior esquerdo
    for (int i = 1; coordenadaValida (l + i, c - i); i++) {
        if (I -> Tab [l + i - 1][c - i - 'a'] == '#') {
            if (!colocaReiCheque (l, c, l + i, c - i, I)) Jogadas [l + i - 1][c - i - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l + i - 1][c - i - 'a']))
                if (!colocaReiCheque (l, c, l + 1, c - i, I)) Jogadas [l + i - 1][c - i - 'a'] = JogadaDisponivel = 2;
            break;
        }
    }

    // Verifica o canto inferior direito
    for (int i = 1; coordenadaValida (l + i, c + i); i++) {
        if (I -> Tab [l + i - 1][c + i - 'a'] == '#') {
            if (!colocaReiCheque (l, c, l + i, c + i, I)) Jogadas [l + i - 1][c + i - 'a'] = 1;
        } else {
            if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [l + i - 1][c + i - 'a']))
                if (!colocaReiCheque (l, c, l + 1, c + 1, I)) Jogadas [l + i - 1][c + i - 'a'] = JogadaDisponivel = 2;
            break;
        }
    }

    // Indica se a peça possui ou não jogadas disponíveis
    return JogadaDisponivel;
}



// Encontra as jogadas de uma rainha
int encontraJogadasRainha (int l, char c, int Jogadas [8][8], Info I) {

    // Inteiro que indica se a peça possui ou não alguma jogada disponível
    int JogadaDisponivel = 0;

    // Testa as jogadas da torre
    JogadaDisponivel = encontraJogadasTorre (l, c, Jogadas, I);

    // Testa as jogadas do bispo
    JogadaDisponivel = encontraJogadasBispo (l, c, Jogadas, I);

    // Indica se a peça possui ou não jogadas disponíveis
    return JogadaDisponivel;
}



// Verifica as possibilidades de 'Castle'
int castle (int l, char c, int Jogadas [8][8], Info I) {

    // Inteiro que indica se a peça possui ou não alguma jogada disponível
    int JogadaDisponivel = 0;

    // É um rei branco
    if (I -> Tab [l - 1][c - 'a'] == 'R') {

        // Guarda a linha original
        char Linha [9] = {0};
        strcpy (Linha, I -> Tab [0]);

        // Verifica a possibilidade de 'Castle' na esquerda
        if (I -> CastleEsqB && I -> Tab [0][1] == '#' && I -> Tab [0][2] == '#' && I -> Tab [0][3] == '#') {

            // Verifica se, ao mover o rei para uma das casas à esquerda, este fica em cheque
            I -> Tab [0][4] = '#';
            I -> Tab [0][3] = 'R';
            if (!reiBrancoCheque (I)) {
                I -> Tab [0][3] = '#';
                I -> Tab [0][2] = 'R';
                if (!reiBrancoCheque (I)) Jogadas [0][2] = JogadaDisponivel = 1;
            }

        }

        // Verifica a possibilidade de 'Castle' na direita
        if (I -> CastleDirB && I -> Tab [0][5] == '#' && I -> Tab [0][6]) {

            // Verifica se, ao mover o rei para uma das casa à direita, teste fica em cheque
            I -> Tab [0][4] = '#';
            I -> Tab [0][5] = 'R';
            if (!reiBrancoCheque (I)) {
                I -> Tab [0][5] = '#';
                I -> Tab [0][6] = 'R';
                if (!reiBrancoCheque (I)) Jogadas [0][6] = JogadaDisponivel = 1;
            }
        }

        // Retorna à linha original
        strcpy (I -> Tab [0], Linha);
    }

    // É um rei preto
    else {

        // Guarda a linha original
        char Linha [9] = {0};
        strcpy (Linha, I -> Tab [7]);

        // Verifica a possibilidade de 'Castle' na esquerda
        if (I -> CastleEsqP && I -> Tab [7][1] == '#' && I -> Tab [7][2] == '#' && I -> Tab [7][3] == '#') {

            // Verifica se, ao mover o rei para uma das casas à esquerda, este fica em cheque
            I -> Tab [7][4] = '#';
            I -> Tab [7][3] = 'r';
            if (!reiPretoCheque (I)) {
                I -> Tab [7][3] = '#';
                I -> Tab [7][2] = 'r';
                if (!reiPretoCheque (I)) Jogadas [7][2] = JogadaDisponivel = 1;
            }

        }

        // Verifica a possibilidade de 'Castle' na direita
        if (I -> CastleDirB && I -> Tab [7][5] == '#' && I -> Tab [7][6] == '#') {

            // Verifica se, ao mover o rei para uma das casa à direita, teste fica em cheque
            I -> Tab [7][4] = '#';
            I -> Tab [7][5] = 'r';
            if (!reiPretoCheque (I)) {
                I -> Tab [7][5] = '#';
                I -> Tab [7][6] = 'r';
                if (!reiPretoCheque (I)) Jogadas [7][6] = JogadaDisponivel = 1;
            }
        }

        // Retorna à linha original
        strcpy (I -> Tab [7], Linha);
    }

    // Indica se a peça possui ou não jogadas disponíveis
    return JogadaDisponivel;
}



// Encontra as jogadas de um rei
int encontraJogadasRei (int l, char c, int Jogadas [8][8], Info I) {

    // Inteiro que indica se a peça possui ou não alguma jogada disponível
    int JogadaDisponivel = 0;

    // Verifica as possibilidades de 'Castle'
    JogadaDisponivel = castle (l, c, Jogadas, I);

    // Arrays que indicam os possíveis destinos do rei
    int linhas [8] = {l - 1, l - 1, l - 1, l, l, l + 1, l + 1, l + 1};
    char colunas [8] = {c - 1, c, c + 1, c - 1, c + 1, c - 1, c, c + 1};

    // Testa as 8 possibilidades
    for (int i = 0; i < 8; i++) {
        if (coordenadaValida (linhas [i], colunas [i])) {
            if (I -> Tab [linhas [i] - 1][colunas [i] - 'a'] == ' ') {
                if (!colocaReiCheque (l, c, linhas [i], colunas [i], I)) Jogadas [linhas [i] - 1][colunas [i] - 'a'] = JogadaDisponivel = 1;
            } else if (!mesmaCor (I -> Tab [l - 1][c - 'a'], I -> Tab [linhas [i] - 1][colunas [i] - 'a']))
                if (!colocaReiCheque (l, c, linhas [i], colunas [i], I)) Jogadas [linhas [i] - 1][colunas [i] - 'a'] = JogadaDisponivel = 2;
        }
    }

    // Indica se a peça possui ou não jogadas disponíveis
    return JogadaDisponivel;
}
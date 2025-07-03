#include "../Xadrez.h"

// Verifica se um caractere é uma letra maiúscula
int eMaiuscula (char c) {
    return c >= 'A' && c <= 'Z';
}



// Verifica se um caractere é uma letra minúscula
int eMinuscula (char c) {
    return c >= 'a' && c <= 'z';
}



// Verifica se uma coordenada é válida
int coordenadaValida (int l, char c) {
    return l >= 1 && l <= 8 && c >= 'a' && c <= 'h';
}



// Valor absoluto
int abs (int n) {
    if (n > 0) return n;
    return -n;
}



// Verifica se duas peças são da mesma cor
int mesmaCor (char p1, char p2) {
    return (eMaiuscula (p1) && eMaiuscula (p2)) || (eMinuscula (p1) && eMinuscula (p2));
}



// Verifica se um caractere é válido
int caractereValido (char c) {
    return c == 'p' || c == 'P' || c == 't' || c == 'T' || c == 'c' || c == 'C' || c == 'b' || c == 'B' ||
           c == 'q' || c == 'Q' || c == 'r' || c == 'R' || c == '#';
}



// Verifica se duas jogadas são iguais
int jogadasIguais (Jogada J1, Jogada J2) {
    return J1.li == J2.li && J1.lf == J2.lf && J1.ci == J2.ci &&
           J1.cf == J2.cf && J1.pi == J2.pi && J1.pf == J2.pf;
}



// Verifica se houve stalemate ou cheque-mate
int mate (Info I) {

    // Inteiro que indica se o jogador possui jogadas disponíveis
    int JogadasDisponiveis = 0;

    // Verifica de quem é a próxima jogada
    if (I -> NJogada % 2) {

        // Verifica se o jogador branco tem jogadas disponíveis
        for (int i = 0; i < 8 && JogadasDisponiveis == 0; i++)
            for (int j = 0; j < 8 && JogadasDisponiveis == 0; j++)
                if (eMaiuscula (I -> Tab [i][j])) {
                    int Jogadas [8][8] = {0};
                    if (encontraJogadas (i + 1, j + 'a', Jogadas, I)) JogadasDisponiveis = 1;
                }

        // Houve stalemate ou cheque-mate
        if (JogadasDisponiveis == 0) {
            if (reiBrancoCheque (I)) printf (VERDE "O jogador preto ganhou por cheque-mate!\n\n" RESET);
            else printf (VERDE "É empate por stalemate!\n\n" RESET);
            return 1;
        }
    } else {

        // Verifica se o jogador preto tem jogadas disponíveis
        for (int i = 0; i < 8 && JogadasDisponiveis == 0; i++)
            for (int j = 0; j < 8 && JogadasDisponiveis == 0; j++)
                if (eMinuscula (I -> Tab [i][j])) {
                    int Jogadas [8][8] = {0};
                    if (encontraJogadas (i + 1, j + 'a', Jogadas, I)) JogadasDisponiveis = 1;
                }

        // Houve stalemate ou cheque-mate
        if (JogadasDisponiveis == 0) {
            if (reiPretoCheque (I)) printf (VERDE "O jogador branco ganhou por cheque-mate!\n\n" RESET);
            else printf (VERDE "É empate por stalemate!\n\n" RESET);
            return 1;
        }
    }

    // Não houve mate
    return 0;
}



// Verifica se houve empate por tripla repetição
int triplaRepeticao (Info I) {

    // Verifica ainda não foram feitas pelo menos 4 jogadas por cada jogador
    if (I -> NJogada < 9) return 0;

    // Cria uma cópia do histórico
    Historico H = I -> H;

    // Percorre o histórico até ao fim
    while (H -> Proximo) H = H -> Proximo;

    // Cria uma cópia do tabuleiro
    char Tab [8][9] = {0};

    // Copia o tabuleiro
    for (int i = 0; i < 8; i++) strcpy (Tab [i], I -> Tab [i]);

    // Verifica se os tabuleiros anteriores são iguais
    for (int i = 0; i < 2; i++) {

        // Realiza as últimas 4 jogadas
        for (int j = 0; j < 4; j++) {
            Tab [H -> J.li - 1][H -> J.ci - 'a'] = H -> J.pi;
            Tab [H -> J.lf - 1][H -> J.cf - 'a'] = H -> J.pf;
            H = H -> Anterior;
        }

        // Verifica se os tabuleiros são iguais
        for (int j = 0; j < 8; j++) if (strcmp (Tab [j], I -> Tab [j])) return 0;
    }

    // Houve empate por tripla repetição
    return 1;
}



// Verifica se há material insuficiente para dar cheque-mate
int materialInsuficiente (Info I) {

    // Inteiros que indicam a frequência dos cavalos e dos bispos
    int nCB = 0, nCP = 0, nBB = 0, nBP = 0;
    
    // Inteiros que indicam a cor das casas dos bispos
    int cBB = 0, cBP = 0;

    // Percorre o tabuleiro
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            
            // Armazena o caractere
            char c = I -> Tab [i][j];

            // Verifica se a peça elimina a possibilidade de material insuficiente
            if (c == 'q' || c == 'Q' || c == 't' || c == 'T' || c == 'p' || c == 'P') return 0;

            // Conta se a peça for um cavalo ou um bispo
            if (c == 'c') nCP++;
            else if (c == 'C') nCB++;
            else if (c == 'b') {
                nBP++;
                cBP = (i + j) % 2;
            } else if (c == 'B') {
                nBB++;
                cBB = (i + j) % 2;
            }
        }

    // Verifica todos os casos
    if (nCB + nBB > 1 || nCP + nBP > 1) return 0;
    if (nBB == 1 && nBP == 1) return cBB == cBP;
    return 1;
}



// Promove um peão
void promovePeao (int lf, char cf, Info I) {

    // Pergunta ao jogador para qual peça pretende promover
    printf ("\nPara qual peça pretende promover?\n\n");

    // Inteiro que indica se a peça é ou não branca
    int eBranca = eMaiuscula (I -> Tab [lf - 1][cf - 'a']);

    // Peça final
    char p = 0;

    // Pede ao jogador o input
    while (p == 0) {

        // Recebe o input
        if (scanf (" %c", &p) != 1) {
            if (eBranca) printf (VERMELHO "\n1 Resposta inválida." RESET " Deve responder " AZUL "T, B, C ou Q.\n\n" RESET);
            else printf (VERMELHO "\n2 Resposta inválida." RESET " Deve responder " AZUL "t, b, c ou q.\n\n" RESET);
            p = 0;
        }

        // Verifica se a resposta é válida
        else if (!(eBranca && (p == 'T' || p == 'B' || p == 'C' || p == 'Q')) && 
            !(!eBranca && (p == 't' || p == 'b' || p == 'c' || p == 'q'))) {
                if (eBranca) printf (VERMELHO "\n3 Resposta inválida." RESET " Deve responder " AZUL "T, B, C ou Q.\n\n" RESET);
                else printf (VERMELHO "\n4 Resposta inválida." RESET " Deve responder " AZUL "t, b, c ou q.\n\n" RESET);
                p = 0;
            }
    }

    // Limpa o stdin
    int ch;
    while ((ch = getchar ()) != '\n' && ch != EOF);

    // Promove o peão
    I -> Tab [lf - 1][cf - 'a'] = p;
}
#include "../Xadrez.h"

// Verifica as restrições do comando 's'
int restricoesSair (int NArgs) {

    // Verifica se o número de argumentos é excessivo
    if (NArgs > 0) return 1;

    // O comando foi invocado corretamente
    return 0;
}



// Verifica as restrições do comando 'p'
int restricoesPlay (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024]) {

    // Verifica se o número de argumentos é excessivo
    if (NArgs > 2) return 1;

    // Verifica se há um défice de argumentos
    if (NArgs < 2) return 2;

    // Verifica se o primeiro argumento é inválido
    if (PrimeiroArg [1] || (PrimeiroArg [0] != 'c' && PrimeiroArg [0] != 'e')) return 3;

    // Converte o segundo argumento em inteiro
    int NTemplate = atoi (SegundoArg);

    // Caso em que foi dado um número
    if (NTemplate > 0) {

        // Verifica se o número não é um natural
        if (NTemplate < 1) return 4;

        // Verifica se o número é maior que 8
        if (NTemplate > 8) return 5;
    }

    // Verifica se o segundo argumento é válido
    else if (SegundoArg [1] || SegundoArg [0] != 'c') return 4;

    // O comando foi invocado corretamente
    return 0;
}



// Verifica as restrições do comando 't'
int restricoesTemplate (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024]) {

    // Verifica se o número de argumentos é excessivo
    if (NArgs > 2) return 1;

    // Verifica se há um défice de argumentos
    if (NArgs < 2) return 2;

    // Verifica se o primeiro argumento é inválido
    if (PrimeiroArg [1] || (PrimeiroArg [0] != 'e' && PrimeiroArg [0] != 'v')) return 3;

    // Converte o segundo argumento em inteiro
    int NTemplate = atoi (SegundoArg);

    // Verifica se o segundo argumento não é um número natural
    if (NTemplate < 1) return 4;

    // Verifica se o segundo argumento é maior que 8
    if (NTemplate > 8) return 5;

    // O comando foi invocado corretamente
    return 0;
}



// Verifica as restrições do comando 'h'
int restricoesHelp (int NArgs, char PrimeiroArg [1024]) {

    // Verifica se o número de argumentos é excessivo
    if (NArgs > 1) return 1;

    // Verifica se o comando dado é inválido
    if (NArgs == 1) {

        // Verifica se o argumento é mais que um caractere
        if (PrimeiroArg [1]) return 2;

        // Verifica se o comando dado não existe
        if (PrimeiroArg [0] != 's' && PrimeiroArg [0] != 'p' && PrimeiroArg [0] != 't' && PrimeiroArg [0] != 'h' && PrimeiroArg [0] != 'v' &&
            PrimeiroArg [0] != 'j' && PrimeiroArg [0] != 'm' && PrimeiroArg [0] != 'r' && PrimeiroArg [0] != 'e') return 3;
    }

    // O comando foi invocado corretamente
    return 0;
}



// Verifica as restrições do comando 'v'
int restricoesVisualizar (int NArgs) {

    // Verifica se o número de argumentos é excessivo
    if (NArgs > 0) return 1;

    // O comando foi invocado corretamente
    return 0;
}



// Verifica as restrições do comando 'j'
int restricoesJogada (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024], Info I) {

    // Verifica se o número de argumentos é excessivo
    if (NArgs > 2) return 1;

    // Verifica se há um défice de argumentos
    if (NArgs < 2) return 2;

    // Separa o primeiro argumento
    int li = atoi (PrimeiroArg + 1);
    char ci = PrimeiroArg [0];

    // Verifica se o primeiro argumento é inválido
    if (li < 1 || li > 8 || ci < 'a' || ci > 'h') return 3;   

    // Separa o segundo argumento
    int lf = atoi (SegundoArg + 1);
    char cf = SegundoArg [0];

    // Verifica se o segundo argumento é inválido
    if (lf < 1 || lf > 8 || cf < 'a' || cf > 'h') return 4;

    // Verifica se não existe uma peça na casa dada pelo primeiro argumento
    if (I -> Tab [li - 1][ci - 'a'] == '#') return 5;

    // Verifica se a peça é da for errada
    if (I -> NJogada % 2 == 0 && eMaiuscula (I -> Tab [li - 1][ci - 'a'])) return 6;
    if (I -> NJogada % 2 && eMinuscula (I -> Tab [li - 1][ci - 'a'])) return 7;

    // Cria um tabuleiro que indica as possíveis jogadas da peça
    int Jogadas [8][8] = {0};

    // Encontra as jogadas da peça
    encontraJogadas (li, ci, Jogadas, I);

    // Verifica se a jogada é inválida
    if (Jogadas [lf - 1][cf - 'a'] == 0) return 8;

    // O comando foi invocado corretamente
    return 0;
}



// Verifica as restrições do comando 'm'
int restricoesMovimentos (int NArgs, char PrimeiroArg [1024], char Tab [8][9]) {

    // Verifica se o número de argumentos é excessivo
    if (NArgs > 1) return 1;

    // Verifica se não foi recebido um argumento
    if (NArgs == 0) return 2;

    // Separa o argumento
    int l = atoi (PrimeiroArg + 1);
    char c = PrimeiroArg [0];

    // Verifica se o argumento é inválido
    if (l < 1 || l > 8 || c < 'a' || c > 'h') return 3;

    // Verifica se não existe uma peça na casa dada
    if (Tab [l - 1][c - 'a'] == '#') return 4;

    // O comando foi invocado corretamente
    return 0;
}



// Verifica as restrições do comando 'r'
int restricoesResign (int NArgs, char PrimeiroArg [1024]) {

    // Verifica se o número de argumentos é excessivo
    if (NArgs > 1) return 1;

    // Verifica se não foi recebido um argumento
    if (NArgs == 0) return 2;

    // Verifica se o argumento é inválido
    if (PrimeiroArg [1] || (PrimeiroArg [0] != 'b' && PrimeiroArg [0] != 'p')) return 3;

    // O comando foi invocado corretamente
    return 0;
}



// Verifica as restrições do comando 'e'
int restricoesEmpate (int NArgs) {

    // Verifica se o número de argumentos é excessivo
    if (NArgs > 0) return 1;

    // O comando foi invocado corretamente
    return 0;
}
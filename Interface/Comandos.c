#include "../Xadrez.h"

// Realiza o comando 's'
void comandoSair (int NArgs, int *Running) {

    // Verifica as restrições do comando
    int n = restricoesSair (NArgs);

    // Avisa se o número de argumentos é excessivo
    if (n == 1) fprintf (stderr, VERMELHO "\nErro: " RESET "O comando " AZUL "s" RESET " não precisa de argumentos.\n\n");

    // Realiza a lógica do comando
    else logicaSair (Running);
}



// Realiza o comando 'p'
void comandoPlay (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024]) {

    // Verifica as restrições do comando
    int n = restricoesPlay (NArgs, PrimeiroArg, SegundoArg);

    // Avisa se o número de argumentos é excessivo
    if (n == 1) fprintf (stderr, VERMELHO "\nErro: " RESET "Número de argumentos excessivo.\n\n");

    // Avisa se há um défice de argumentos
    else if (n == 2) fprintf (stderr, VERMELHO "\nErro: " RESET "O comando " AZUL "p" RESET " precisa de dois argumentos.\n\n");

    // Avisa se o primeiro argumento é inválido
    else if (n == 3) fprintf (stderr, VERMELHO "\nErro: " RESET "O primeiro argumento é inválido.\n\n");

    // Avisa se o segundo argumento é inválido
    else if (n == 4) fprintf (stderr, VERMELHO "\nErro: " RESET "O segundo argumento é inválido.\n\n");

    // Avisa se o segundo argumento é maior que 8
    else if (n == 5) fprintf (stderr, VERMELHO "\nErro: " RESET "Apenas existem oito templates.\n\n");

    // Realiza a lógica do comando
    else logicaPlay (PrimeiroArg [0] == 'e', SegundoArg [0] != 'c', SegundoArg [0] - '0');
}



// Realiza o comando 't'
void comandoTemplate (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024]) {

    // Verifica as restrições do comando
    int n = restricoesTemplate (NArgs, PrimeiroArg, SegundoArg);

    // Avisa se o número de argumentos é excessivo
    if (n == 1) fprintf (stderr, VERMELHO "\nErro: " RESET "Número de argumentos excessivo.\n\n");

    // Avisa se há um défice de argumentos
    else if (n == 2) fprintf (stderr, VERMELHO "\nErro: " RESET "O comando " AZUL "t" RESET " precisa de dois argumentos.\n\n");

    // Avisa se o primeiro argumento é inválido
    else if (n == 3) fprintf (stderr, VERMELHO "\nErro: " RESET "O primeiro argumento é inválido.\n\n");

    // Avisa se o segundo argumento não é um número natural
    else if (n == 4) fprintf (stderr, VERMELHO "\nErro: " RESET "O segundo argumento deve ser um número natural.\n\n");

    // Avisa se o segundo argumento é maior que 8
    else if (n == 5) fprintf (stderr, VERMELHO "\nErro: " RESET "Apenas existem oito templates.\n\n");

    // Realiza a lógica do comando
    else logicaTemplate (PrimeiroArg [0] == 'e', SegundoArg [0] - '0');
}



// Realiza o comando 'h'
void comandoHelp (int NArgs, char PrimeiroArg [1024]) {

    // Verifica as restrições do comando
    int n = restricoesHelp (NArgs, PrimeiroArg);

    // Avisa se o número de argumentos é excessivo
    if (n == 1) fprintf (stderr, VERMELHO "\nErro: " RESET "Número de argumentos excessivo.\n\n");

    // Avisa se foi dado um argumento com mais que um caractere
    else if (n == 2) fprintf (stderr, VERMELHO "\nErro: " RESET "Os comandos são apenas um caractere.\n\n");

    // Avisa se o comando dado não existe
    else if (n == 3) fprintf (stderr, VERMELHO "\nErro: " RESET "Esse comando não existe.\n\n");

    // Realiza a lógica do comando
    else logicaHelp (PrimeiroArg [0]);
}



// Realiza o comando 'v'
void comandoVisualizar (int NArgs, Info I) {

    // Verifica as restrições do comando
    int n = restricoesVisualizar (NArgs);

    // Avisa se o número de argumentos é excessivo
    if (n == 1) fprintf (stderr, VERMELHO "\nErro: " RESET "O comando " AZUL "v" RESET " não precisa de argumentos.\n\n");

    // Realiza a lógica do comando
    else logicaVisualizar (I);
}



// Realiza o comando 'j'
void comandoJogada (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024], Info I, int *Running) {

    // Verifica as restrições do comando
    int n = restricoesJogada (NArgs, PrimeiroArg, SegundoArg, I);

    // Avisa se o número de argumentos é excessivo
    if (n == 1) fprintf (stderr, VERMELHO "\nErro: " RESET "Número de argumentos excessivo.\n\n");

    // Avisa se há um défice de argumentos
    else if (n == 2) fprintf (stderr, VERMELHO "\nErro: " RESET "O comando " AZUL "j" RESET " precisa de dois argumentos.\n\n");

    // Avisa se o primeiro argumento é inválido
    else if (n == 3) fprintf (stderr, VERMELHO "\nErro: " RESET "O primeiro argumento é inválido.\n\n");

    // Avisa se o segundo argumento é inválido
    else if (n == 4) fprintf (stderr, VERMELHO "\nErro: " RESET "O segundo argumento é inválido.\n\n");

    // Avisa se não existe uma peça na casa dada
    else if (n == 5) fprintf (stderr, VERMELHO "\nErro: " RESET "Não existe uma peça na casa %s.\n\n", PrimeiroArg);

    // Avisa se a peça na cada dada é da cor branca
    else if (n == 6) fprintf (stderr, VERMELHO "\nErro: " RESET "É o turno do jogador preto.\n\n");
    
    // Avisa se a peça na cada dada é da cor preta
    else if (n == 7) fprintf (stderr, VERMELHO "\nErro: " RESET "É o turno jogador branco.\n\n");

    // Avisa se a jogada é inválida
    else if (n == 8) fprintf (stderr, VERMELHO "\nErro: " RESET "Jogada inválida.\n\n");

    // Realiza a lógica do comando
    else logicaJogada (PrimeiroArg [1] - '0', PrimeiroArg [0], SegundoArg [1] - '0', SegundoArg [0], I, Running);
}



// Realiza o comando 'm'
void comandoMovimentos (int NArgs, char PrimeiroArg [1024], Info I) {

    // Verifica as restrições do comando
    int n = restricoesMovimentos (NArgs, PrimeiroArg, I -> Tab);

    // Avisa se o número de argumentos é excessivo
    if (n == 1) fprintf (stderr, VERMELHO "\nErro: " RESET "Número de argumentos excessivo.\n\n");

    // Avisa se não foi dado um argumento
    else if (n == 2) fprintf (stderr, VERMELHO "\nErro " RESET "O comando " AZUL "m" RESET " precisa de um argumento.\n\n");

    // Avisa se o argumento é inválido
    else if (n == 3) fprintf (stderr, VERMELHO "\nErro: " RESET "Argumento inválido.\n\n");

    // Avisa se não existe uma peça na casa dada
    else if (n == 4) fprintf (stderr, VERMELHO "\nErro: " RESET "Não existe uma peça na casa %s.\n\n", PrimeiroArg);

    // Realiza a lógica do comando
    else logicaMovimentos (PrimeiroArg [1] - '0', PrimeiroArg [0], I);
}



// Realiza o comando 'r'
void comandoResign (int NArgs, char PrimeiroArg [1024], int *Running) {

    // Verifica as restrições do comando
    int n = restricoesResign (NArgs, PrimeiroArg);

    // Avisa se o número de argumentos é excessivo
    if (n == 1) fprintf (stderr, VERMELHO "\nErro: " RESET "Número de argumentos excessivo.\n\n");
    
    // Avisa se não foi dado um argumento
    else if (n == 2) fprintf (stderr, VERMELHO "\nErro: " RESET "O comando " AZUL "r" RESET " precisa de um argumento.\n\n");

    // Avisa se o argumento é inválido
    else if (n == 3) fprintf (stderr, VERMELHO "\nErro: " RESET "Argumento inválido.\n\n");

    // Realiza a lógica do comando
    else logicaResign (PrimeiroArg [0] == 'b', Running);
}



// Realiza o comando 'e'
void comandoEmpate (int NArgs, int *Running) {

    // Verifica as restrições do comando
    int n = restricoesEmpate (NArgs);

    // Avisa se o número de argumentos é excessivo
    if (n == 1) fprintf (stderr, VERMELHO "\nErro: " RESET "O comando " AZUL "e" RESET " não precisa de argumentos.\n\n");

    // Realiza a lógica do comando
    else logicaEmpate (Running);
}
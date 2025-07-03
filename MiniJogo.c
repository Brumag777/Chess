#include "Xadrez.h"

// Corre um mini-jogo
void miniJogo (Info I) {
    
    // Inteiro que indica se o mini-jogo está a correr
    int Running = 1;

    // Indica que o mini-jogo foi aberto corretamente
    printf (VERDE "\nMini-jogo iniciado com sucesso.\n" RESET);

    // Imprime o tabuleiro
    imprimeTabuleiro (I -> Tab, 1);

    // Corre o mini-jogo
    while (Running) {

        // Indica ao jogador que deve usar um comando
        printf ("> ");

        // Input do jogador
        char Input [1024] = {0};

        // Recebe o input
        if (fgets (Input, 1024, stdin)) {

            // Verifica se o input é válido
            if (Input [1] == 0 || Input [1] == '\n' || Input [1] == ' ') {

                // Separa o input
                char Comando = 0, PrimeiroArg [1024] = {0}, SegundoArg [1024] = {0}, Resto [1024] = {0};
                int NArgs = sscanf (Input, "%c %s %s %[^\n]", &Comando, PrimeiroArg, SegundoArg, Resto) - 1;

                // Verifica se foi invocado algum comando
                if (Comando == 's') {
                    comandoSair (NArgs, &Running);
                    printf (VERDE "\nO mini-jogo foi terminado.\n\n" RESET);
                } else if (Comando == 'h') comandoHelp (NArgs, PrimeiroArg);
                else if (Comando == 'v') comandoVisualizar (NArgs, I);
                else if (Comando == 'j') comandoJogada (NArgs, PrimeiroArg, SegundoArg, I, &Running);
                else if (Comando == 'm') comandoMovimentos (NArgs, PrimeiroArg, I);
                else if (Comando == 'r') comandoResign (NArgs, PrimeiroArg, &Running);
                else if (Comando == 'e') comandoEmpate (NArgs, &Running);

                // Verifica se foi invocado algum comando do menu principal
                else if (Comando == 'p' || Comando == 't')
                    fprintf (stderr, VERMELHO "\nErro: " RESET "O comando " AZUL "%c" RESET " só pode ser usado no menu principal.\n\n", Comando);

                // Nenhum dos comandos foi invocado
                else fprintf (stderr, VERMELHO "\nErro: " RESET "Comando inválido.\n\n");
            }

            // O input é inválido
            else fprintf (stderr, VERMELHO "\nErro: " RESET "Os comandos são apenas um caractere.\n\n");
        }

        // Houve um erro ao ler o input
        else fprintf (stderr, VERMELHO "\nErro: " RESET "Houve um erro ao ler o input.\n\n");
    }
}
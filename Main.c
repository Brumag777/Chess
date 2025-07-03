#include "Xadrez.h"

// Função principal
int main () {

    // Indica se o jogo está a correr
    int Running = 1;

    // Imprime uma mensagem inicial
    imprimeMensagemInicial ();

    // Corre o jogo
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

                // Verifica se foi invocado algum comando do menu principal
                if (Comando == 's') comandoSair (NArgs, &Running);
                else if (Comando == 'p') comandoPlay (NArgs, PrimeiroArg, SegundoArg);
                else if (Comando == 't') comandoTemplate (NArgs, PrimeiroArg, SegundoArg);
                else if (Comando == 'h') comandoHelp (NArgs, PrimeiroArg);

                // Verifica se foi invocado algum comando dos mini-jogos
                else if (Comando == 'v' || Comando == 'j' || Comando == 'm' || Comando == 'r' || Comando == 'e')
                    fprintf (stderr, VERMELHO "\nErro: " RESET "Ainda não foi iniciado um mini-jogo.\n\n");

                // Nenhum dos comandos foi invocado
                else fprintf (stderr, VERMELHO "\nErro: " RESET "Comando inválido.\n\n");
            }

            // O input é inválido
            else fprintf (stderr, VERMELHO "\nErro: " RESET "Os comandos são apenas um caractere.\n\n");
        }

        // Houve um erro ao ler o input
        else fprintf (stderr, VERMELHO "\nErro: " RESET "Houve um erro ao ler o input.\n\n");
    }

    // Termina o jogo
    return 0;
}
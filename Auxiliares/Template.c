#include "../Xadrez.h"

// Lê um template
int leTemplate (char NomeFicheiro [17], char Tab [8][9]) {

    // Abre o ficheiro
    FILE *F = fopen (NomeFicheiro, "r");

    // Lê o template
    for (int i = 0; i < 8; i++)
        if (fscanf (F, "%s", Tab [i]) != 1) {
            fprintf (stderr, VERMELHO "\nErro: " RESET "Não foi possível ler o template.\n\n");
            return 1;
        }

    // Fecha o ficheiro
    fclose (F);

    // Avisa que a função funcionou corretamente
    return 0;
}



// Guarda um template
void guardaTemplate (char NomeFicheiro [17], char Tab [8][9]) {

    // Abre o ficheiro
    FILE *F = fopen (NomeFicheiro, "w");

    // Guarda o novo template
    for (int i = 0; i < 8; i++) fprintf (F, "%s\n", Tab [i]);

    // Fecha o ficheiro
    fclose (F);

    // Avisa do sucesso do comando
    printf ("\nTemplate editado com sucesso.\n\n");
}



// Imprime um template
int imprimeTemplate (char NomeFicheiro [17]) {

    // Cria um tabuleiro
    char Tab [8][9] = {0};

    // Lê o template
    if (leTemplate (NomeFicheiro, Tab)) return 1;

    // Imprime o template
    imprimeTabuleiro (Tab, NomeFicheiro [11] - '0');

    // Avisa que a função funcionou corretamente
    return 0;
}



// Edita um template
void editaTemplate (char NomeFicheiro [17]) {

    // Cria um tabuleiro
    char Tab [8][9] = {0};

    // Pede ao jogador para digitar o novo tabuleiro
    printf ("Digite o novo tabuleiro:\n\n");

    // Inteiros que indicam quantos reis de cada cor existem
    int nReisBrancos = 0, nReisPretos = 0;

    // Recebe o input do jogador
    for (int i = 0; i < 8; i++) {

        // Input do jogador
        char Input [1024] = {0};

        // Recebe o input
        if (scanf ("%s", Input) != 1) {
            fprintf (stderr, VERMELHO "\nErro: " RESET "Não foi possível ler o input.\n\n");
            return;
        } else if (strlen (Input) != 8) {
            fprintf (stderr, VERMELHO "\nErro: " RESET "Número de colunas inválido.\n\n");
            return;
        } else {
            for (int j = 0; j < 8; j++)
                if (!caractereValido (Input [j])) {
                fprintf (stderr, VERMELHO "\nErro: " RESET "Caractere(s) inválido(s).\n\n");
                return;
                } else if (Input [j] == 'r') nReisPretos++;
                else if (Input [j] == 'R') nReisBrancos++;
            strcpy (Tab [i], Input);
        }
    }


    // Verifica se o número de reis é válido
    if (nReisBrancos != 1 || nReisPretos != 1) fprintf (stderr, VERMELHO "\nErro: " RESET "Deve existir um único rei de cada cor.\n\n");

    // Guarda o template novo
    else guardaTemplate (NomeFicheiro, Tab);
}



// Imprime um tabuleiro
void imprimeTabuleiro (char Tab [8][9], int N) {

    // Imprime o número da jogada
    if (N < 10) printf ("\n%d   ", N);
    else if (N < 100) printf ("\n%d  ", N);
    else printf ("\n%d ", N);

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
            if (eMinuscula (Tab [i][j])) printf (PRETO);
            imprimePeca (Tab [i][j]);
            printf (RESET);
        }

        // Avança para a linha seguinte
        putchar ('\n');
    }

    // Avança para a linha seguinte
    putchar ('\n');
}
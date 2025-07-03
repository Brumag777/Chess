#include "../Xadrez.h"

// Realiza a lógica do comando 's'
void logicaSair (int *Running) {

    // Termina o jogo
    *Running = 0;
}



// Realiza a lógica do comando 'p'
void logicaPlay (int EExplosivo, int ETemplate, int NTemplate) {

    // Aloca memória para o mini-jogo
    Info I = iniciaMiniJogo (EExplosivo);

    // Nome do ficheiro
    char NomeFicheiro [17] = {0};

    // Forma o nome do ficheiro
    if (ETemplate) sprintf (NomeFicheiro, "Templates/T%d.txt", NTemplate);
    else sprintf (NomeFicheiro, "Templates/T0.txt");

    // Lê o template escolhido
    leTemplate (NomeFicheiro, I -> Tab);

    // Define as possibilidades de 'Castle'
    I -> CastleEsqB = I -> Tab [0][0] == 'T' && I -> Tab [0][4] == 'R';
    I -> CastleDirB = I -> Tab [0][4] == 'R' && I -> Tab [0][7] == 'T';
    I -> CastleEsqP = I -> Tab [7][0] == 't' && I -> Tab [7][4] == 'r';
    I -> CastleDirP = I -> Tab [7][4] == 'r' && I -> Tab [7][7] == 't';

    // Inicia o mini-jogo
    miniJogo (I);

    // Liberta a memória alocada para o mini-jogo
    finalizaMiniJogo (I);
}



// Realiza a lógica do comando 't'
void logicaTemplate (int EEdicao, int NTemplate) {

    // Cria o nome do ficheiro
    char NomeFicheiro [17] = {0};
    sprintf (NomeFicheiro, "Templates/T%d.txt", NTemplate);

    // Imprime o template
    if (imprimeTemplate (NomeFicheiro)) return;

    // Verifica se o jogador pretende editar o template
    if (EEdicao) {

        // Edita o template
        editaTemplate (NomeFicheiro);

        // Limpa o stdin
        int ch;
        while ((ch = getchar ()) != '\n' && ch != EOF);
    }
}



// Realiza a lógica do comando 'h'
void logicaHelp (char Comando) {

    // Verifica se o jogador pretende saber mais sobre algum comando
    if (Comando == 's') explicaSair ();
    else if (Comando == 'p') explicaPlay ();
    else if (Comando == 't') explicaTemplate ();
    else if (Comando == 'h') explicaHelp ();
    else if (Comando == 'v') explicaVisualizarTabuleiro ();
    else if (Comando == 'j') explicaJogada ();
    else if (Comando == 'm') explicaMovimentos ();
    else if (Comando == 'r') explicaResign ();
    else if (Comando == 'e') explicaEmpate ();

    // O jogador pretende ver a lista dos comandos
    else imprimeListaComandos ();
}



// Realiza a lógica do comando 'v'
void logicaVisualizar (Info I) {

    // Imprime o tabuleiro do jogo
    imprimeTabuleiro (I -> Tab, I -> NJogada);
}



// Realiza a lógica do comando 'j'
void logicaJogada (int li, char ci, int lf, char cf, Info I, int *Running) {

    // Cria uma jogada nova
    Jogada J;

    // Define as compontentes do struct
    J.li = li; J.ci = ci; J.pi = I -> Tab [li - 1][ci - 'a'];
    J.lf = lf; J.cf = cf; J.pf = I -> Tab [lf - 1][cf - 'a'];

    // Adiciona a jogada ao histórico de jogadas
    addJogada (&(I -> H), J);

    // Realiza a jogada
    I -> Tab [li - 1][ci - 'a'] = '#';
    I -> Tab [lf - 1][cf - 'a'] = J.pi;

    // Verifica se é uma promoção de um peão
    if ((J.pi == 'P' && lf == 8) || (J.pi == 'p' && lf == 1)) promovePeao (lf, cf, I);

    // Verifica se é 'Castle'
    else if (J.pi == 'R' && J.ci == 'e' && J.cf == 'c') {
        I -> Tab [0][0] = '#';
        I -> Tab [0][3] = 'T';
    } else if (J.pi == 'R' && J.ci == 'e' && J.cf == 'g') {
        I -> Tab [0][7] = '#';
        I -> Tab [0][5] = 'T';
    } else if (J.pi == 'r' && J.ci == 'e' && J.cf == 'c') {
        I -> Tab [7][0] = '#';
        I -> Tab [7][3] = 't';
    } else if (J.pi == 'r' && J.ci == 'e' && J.cf == 'g') {
        I -> Tab [7][7] = '#';
        I -> Tab [7][5] = 't';
    }

    // Verifica se é 'En Passant'
    else if (J.pi == 'P' && J.ci != J.cf && J.pf == '#') I -> Tab [4][J.cf - 'a'] = '#';
    else if (J.pi == 'p' && J.ci != J.cf && J.pf == '#') I -> Tab [3][J.cf - 'a'] = '#';

    // Verifica se foram eliminanadas as possibilidades de 'Castle'
    if (J.pi == 'R') I -> CastleEsqB = I -> CastleDirB = 0;
    else if (J.pi == 'r') I -> CastleEsqP = I -> CastleDirP = 0;
    else if (J.pi == 'T' && J.ci == 'a') I -> CastleEsqB = 0;
    else if (J.pi == 'T' && J.ci == 'h') I -> CastleDirB = 0;
    else if (J.pi == 't' && J.ci == 'a') I -> CastleEsqP = 0;
    else if (J.pi == 't' && J.ci == 'h') I -> CastleDirP = 0;

    // Explode as peças próximas
    if (J.pf != '#' && I -> EExplosivo) {
        if (lf > 1 && I -> Tab [lf - 2][cf - 'a'] != 'R' && I -> Tab [lf - 2][cf - 'a'] != 'r') I -> Tab [lf - 2][cf - 'a'] = '#';
        if (lf < 8 && I -> Tab [lf + 0][cf - 'a'] != 'R' && I -> Tab [lf + 0][cf - 'a'] != 'r') I -> Tab [lf + 0][cf - 'a'] = '#';
        if (cf > 'a' && I -> Tab [lf - 1][cf - 'a' - 1] != 'R' && I -> Tab [lf - 1][cf - 'a' - 1] != 'r') I -> Tab [lf - 1][cf - 'a' - 1] = '#';
        if (cf < 'h' && I -> Tab [lf - 1][cf - 'a' + 1] != 'R' && I -> Tab [lf - 1][cf - 'a' + 1] != 'r') I -> Tab [lf - 1][cf - 'a' + 1] = '#';
    }

    // Incrementa o número da jogada
    I -> NJogada++;

    // Atualiza o último avanço
    if (J.pi == 'P' || J.pi == 'p' || J.pf != '#') I -> UltimoAvanco = I -> NJogada;

    // Imprime o tabuleiro
    imprimeTabuleiro (I -> Tab, I -> NJogada);

    // Verifica se o rei foi colocado em cheque
    if (I -> NJogada % 2 == 0) {
        if (reiPretoCheque (I)) printf (VERMELHO "O rei preto está em cheque!\n\n" RESET);
    } else if (reiBrancoCheque (I)) printf (VERMELHO "O rei branco está em cheque!\n\n" RESET);

    // Verifica se o jogo terminou
    if (fimJogo (I)) *Running = 0;
}



// Realiza a lógica do comando 'm'
void logicaMovimentos (int l, char c, Info I) {

    // Cria um tabuleiro para indicar as possíveis jogadas da peça
    int Jogadas [8][8] = {0};

    // Encontra as possíveis jogadas da peça
    encontraJogadas (l, c, Jogadas, I);

    // Imprime o tabuleiro destacando as casas para as quais a peça se pode mover
    imprimeJogadas (l, c, I -> Tab, Jogadas);
}



// Realiza a lógica do comando 'r'
void logicaResign (int EBranco, int *Running) {

    // Avisa do fim do jogo
    if (EBranco) printf (VERDE "\nO jogador branco desistiu! O jogador preto ganhou!\n\n" RESET);
    else printf (VERDE "\nO jogador preto desistiu! O jogador branco ganhou!\n\n" RESET);

    // Termina o mini-jogo
    *Running = 0;
}



// Realiza a lógica do comando 'e'
void logicaEmpate (int *Running) {

    // Avisa do fim do jogo
    printf (VERDE "\nEmpate!\n\n" RESET);

    // Termina o mini-jogo
    *Running = 0;
}
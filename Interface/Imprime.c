#include "../Xadrez.h"

// Imprime uma mensagem inicial
void imprimeMensagemInicial () {
    printf ("_______________________________________________________________________________________________________________________________________________________________________________________________________\n\n"
            "                                                                        ██╗  ██╗ █████╗ ██████╗ ██████╗ ███████╗███████╗\n"
            "                                                                        ╚██╗██╔╝██╔══██╗██╔══██╗██╔══██╗██╔════╝╚══███╔╝\n"
            "                                                                         ╚███╔╝ ███████║██║  ██║██████╔╝█████╗    ███╔╝ \n"
            "                                                                         ██╔██╗ ██╔══██║██║  ██║██╔══██╗██╔══╝   ███╔╝  \n"
            "                                                                        ██╔╝ ██╗██║  ██║██████╔╝██║  ██║███████╗███████╗\n"
            "                                                                        ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝\n"
            AZUL "                                                                       Pressione h para saber a lista de comandos!\n" RESET
            "________________________________________________________________________________________________________________________________________________________________________________________________________\n\n");
}



// Imprime a lista de comandos do jogo
void imprimeListaComandos () {
    printf (MAGENTA "\nComandos Diversos\n\n"
            AZUL "s:" RESET " Termina o jogo ou o mini-jogo.\n"
            AZUL "p:" RESET " Seleciona o modo de jogo.\n"
            AZUL "t:" RESET " Permite editar ou visualizar um template de tabuleiro inicial.\n"
            AZUL "h:" RESET " Lista ou explica os comandos do jogo.\n"
            MAGENTA "\nComandos Para Jogar\n\n"
            AZUL "v:" RESET " Revela o tabuleiro.\n"
            AZUL "j:" RESET " Faz uma jogada com uma peça.\n"
            AZUL "m:" RESET " Destaca os movimentos que uma peça pode realizar.\n"
            AZUL "r:" RESET " Permite a um jogador resignar.\n"
            AZUL "e:" RESET " Permite aos jogadores empatar.\n\n"
            MAGENTA "Nota: " RESET "Se pretende saber mais sobre algum comando, use o comando " AZUL "h" RESET " dando como argumento o comando desejado.\n\n");
}



// Explica o comando 's'
void explicaSair () {
    printf ("\nO comando " AZUL "s" RESET " termina o jogo ou o mini-jogo.\n\n");
}



// Explica o comando 'p'
void explicaPlay () {
    printf ("\nO comando " AZUL "p" RESET " permite ao jogador iniciar um mini-jogo. Pode ser usado de duas formas:\n\n"
            AZUL "p c: " RESET "Seleciona o modo de jogo 'Clássico'.\n"
            AZUL "p e: " RESET "Seleciona o modo de jogo 'Explosivo'.\n\n"
            MAGENTA "Exemplos:\n\n"
            AZUL "p c c" RESET " seleciona o modo de jogo 'Clássico' no template clássico.\n"
            AZUL "p e 3" RESET " seleciona o modo de jogo 'Explosivo' no template 3.\n\n");
}



// Explica o comando 't'
void explicaTemplate () {
    printf ("\nO comando " AZUL "t" RESET " permite ao jogador editar ou visualizar um template. Por exemplo:\n\n"
            AZUL "t v 2" RESET " revela o template 2.\n"
            AZUL "t e 6" RESET " permite editar o template 6.\n\n");
}



// Explica o comando 'h'
void explicaHelp () {
    printf ("\nO comando " AZUL "h" RESET " lista ou explica os comandos do jogo.\n\n"
            "Se for usado " AZUL "sem argumento," RESET " lista todos os comandos do jogo.\n"
            "Se for usado " AZUL "com argumento, o comando pretendido," RESET " explica o comando selecionado.\n\n");
}



// Explica o comando 'v'
void explicaVisualizarTabuleiro () {
    printf ("\nO comando " AZUL "v" RESET " revela o tabuleiro do jogo.\n\n"
            MAGENTA "Nota: " RESET "Este comando só pode ser usado se um mini-jogo estiver aberto.\n\n");
}



// Explica o comando 'j'
void explicaJogada () {
    printf ("\nO comando " AZUL "j" RESET " permite ao jogador realizar uma jogada. Por exemplo:\n\n"
            AZUL "j h1 h3" RESET " move uma peça da cada h1 à casa h3, se essa jogada for válida.\n\n"
            MAGENTA "Nota: " RESET "Este comando só pode ser usado se um mini-jogo estiver aberto.\n\n");
}



// Explica o comando 'm'
void explicaMovimentos () {
    printf ("\nO comando " AZUL "m" RESET " destaca todas as jogadas válidas para uma dada peça. Por exemplo:\n\n"
            AZUL "m d4" RESET " destaca todas as casas para as quais a peça na casa d4 pode mover na próxima jogada.\n\n"
            MAGENTA "Nota: " RESET "Este comando só pode ser usado se um mini-jogo estiver aberto.\n\n");
}



// Explica o comando 'r'
void explicaResign () {
    printf ("\nO comando " AZUL "r" RESET " permite a um jogador resignar, dando a vitória ao oponente.\n\n"
            MAGENTA "Exemplos:\n\n"
            AZUL "r b" RESET " dá a vitória ao jogador preto.\n"
            AZUL "r p" RESET " dá a vitória ao jogador branco.\n\n"
            MAGENTA "Nota: " RESET "Este comando só pode ser usado se um mini-jogo estiver aberto.\n\n");
}



// Explica o comando 'e'
void explicaEmpate () {
    printf ("\nO comando " AZUL "e" RESET " permite aos jogadores acabar o jogo num empate.\n\n"
            MAGENTA "Nota: " RESET "Este comando só pode ser usado se um mini-jogo estiver aberto.\n\n");
}



// Imprime uma peça
void imprimePeca (char p) {
    if (p == '#') printf ("  ");
    else if (p == 'r') printf ("♚ ");
    else if (p == 'R') printf ("♔ ");
    else if (p == 'b') printf ("♝ ");
    else if (p == 'B') printf ("♗ ");
    else if (p == 'c') printf ("♞ ");
    else if (p == 'C') printf ("♘ ");
    else if (p == 'q') printf ("♛ ");
    else if (p == 'Q') printf ("♕ ");
    else if (p == 'p') printf ("♟ ");
    else if (p == 'P') printf ("♙ ");
    else if (p == 't') printf ("♜ ");
    else printf ("♖ ");
}
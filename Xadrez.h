#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGENTA "\033[38;2;255;0;255m"
#define VERMELHO "\033[38;2;255;0;0m"
#define AZUL "\033[38;2;50;50;255m"
#define VERDE "\033[38;2;0;255;0m"
#define PRETO "\033[38;2;0;0;0m"
#define RESET "\033[0m"

// Informação sobre uma jogada
typedef struct jogada {
    int li; char ci, pi;
    int lf; char cf, pf;
} Jogada;

// Histórico de jogadas do mini-jogo
typedef struct historico {
    Jogada J;
    struct historico *Anterior;
    struct historico *Proximo; 
} HISTORICO, *Historico;

// Informação sobre o mini-jogo
typedef struct info {
    char Tab [8][9];
    int NJogada, UltimoAvanco;
    Historico H;
    int EExplosivo;
    int CastleEsqB, CastleDirB;
    int CastleEsqP, CastleDirP;
} INFO, *Info;





// MiniJogo.c

// Corre um mini-jogo
void miniJogo (Info I);





// Comandos.c

// Realiza o comando 's'
void comandoSair (int NArgs, int *Running);

// Realiza o comando 'p'
void comandoPlay (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024]);

// Realiza o comando 'h'
void comandoHelp (int NArgs, char PrimeiroArg [1024]);

// Realiza o comando 't'
void comandoTemplate (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024]);

// Realiza o comando 'v'
void comandoVisualizar (int NArgs, Info I);

// Realiza o comando 'j'
void comandoJogada (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024], Info I, int *Running);

// Realiza o comando 'm'
void comandoMovimentos (int NArgs, char PrimeiroArg [1024], Info I);

// Realiza o comando 'r'
void comandoResign (int NArgs, char PrimeiroArg [1024], int *Running);

// Realiza o comando 'e'
void comandoEmpate (int NArgs, int *Running);





// Imprime.c

// Imprime uma mensagem inicial
void imprimeMensagemInicial ();

// Imprime a lista de comandos do jogo
void imprimeListaComandos ();

// Explica o comando 's'
void explicaSair ();

// Explica o comando 'p'
void explicaPlay ();

// Explica o comando 't'
void explicaTemplate ();

// Explica o comando 'h'
void explicaHelp ();

// Explica o comado 'v'
void explicaVisualizarTabuleiro ();

// Explica o comando 'j'
void explicaJogada ();

// Explica o comando 'm'
void explicaMovimentos ();

// Explica o comando 'r'
void explicaResign ();

// Explica o comando 'e'
void explicaEmpate ();

// Imprime uma peça
void imprimePeca (char p);





// ComandosRestricoes.c

// Verifica as restrições do comando 's'
int restricoesSair (int NArgs);

// Verifica as restrições do comando 'p'
int restricoesPlay (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024]);

// Verifica as restrições do comando 'h'
int restricoesHelp (int NArgs, char PrimeiroArg [1024]);

// Verifica as restrições do comando 't'
int restricoesTemplate (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024]);

// Verifica as restrições do comando 'v'
int restricoesVisualizar (int NArgs);

// Verifica as restrições do comando 'j'
int restricoesJogada (int NArgs, char PrimeiroArg [1024], char SegundoArg [1024], Info I);

// Verifica as restrições do comando 'm'
int restricoesMovimentos (int NArgs, char PrimeiroArg [1024], char Tab [8][9]);

// Verifica as restrições do comando 'r'
int restricoesResign (int NArgs, char PrimeiroArg [1024]);

// Verifica as restrições do comando 'e'
int restricoesEmpate (int NArgs);





// ComandosLogica.c

// Realiza a lógica do comando 's'
void logicaSair (int *Running);

// Realiza a lógica do comando 'p'
void logicaPlay (int EExplosivo, int ETemplate, int NTemplate);

// Realiza a lógica do comando 't'
void logicaTemplate (int EEdicao, int NTemplate);

// Realiza a lógica do comando 'h'
void logicaHelp (char Comando);

// Realiza a lógica do comando 'v'
void logicaVisualizar (Info I);

// Realiza a lógica do comando 'j'
void logicaJogada (int li, char ci, int lf, char cf, Info I, int *Running);

// Realiza a lógica do comando 'm'
void logicaMovimentos (int l, char c, Info I);

// Realiza a lógica do comando 'r'
void logicaResign (int EBranco, int *Running);

// Realiza a lógica do comando 'e'
void logicaEmpate (int *Running);





// ComandosLogicaA.c

// Encontra as possíveis jogadas de uma peça
int encontraJogadas (int l, char c, int Jogadas [8][8], Info I);

// Imprime o tabuleiro destacando as casas para as quais a peça se pode mover
void imprimeJogadas (int l, char c, char Tab [8][9], int Jogadas [8][8]);

// Encontra os possíveis ataques de uma peça
void encontraAtaques (int l, char c, int Ataques [8][8], Info I);

// Verifica se o jogo já terminou
int fimJogo (Info I);





// Auxiliares.c

// Verifica se um caractere é uma letra maiúscula
int eMaiuscula (char c);

// Verifica se um caractere é uma letra minúscula
int eMinuscula (char c);

// Verifica se uma coordenada é válida
int coordenadaValida (int l, char c);

// Valor absoluto
int abs (int n);

// Verifica se duas peças são da mesma cor
int mesmaCor (char p1, char p2);

// Verifica se um caractere é válido
int caractereValido (char c);

// Verifica se duas jogadas são iguais
int jogadasIguais (Jogada J1, Jogada J2);

// Verifica se houve stalemate ou cheque-mate
int mate (Info I);

// Verifica se houve empate por tripla repetição
int triplaRepeticao (Info I);

// Verifica se há material insuficiente para dar cheque-mate
int materialInsuficiente (Info I);

// Promove um peão
void promovePeao (int lf, char cf, Info I);





// EncontrarJogadas.c

// Verifica se um peão branco pode realizar 'En Passant'
int enPassantB (int l, char c, int Jogadas [8][8], Info I);

// Encontra as jogadas de um peão branco
int encontraJogadasPeaoB (int l, char c, int Jogadas [8][8], Info I);

// Verifica se um peão preto pode realizar 'En Passant'
int enPassantP (int l, char c, int Jogadas [8][8], Info I);

// Encontra as jogadas de um peão preto
int encontraJogadasPeaoP (int l, char c, int Jogadas [8][8], Info I);

// Encontra as jogadas de uma torre
int encontraJogadasTorre (int l, char c, int Jogadas [8][8], Info I);

// Encontra as jogadas de um cavalo
int encontraJogadasCavalo (int l, char c, int Jogadas [8][8], Info I);

// Encontra as jogadas de um bispo
int encontraJogadasBispo (int l, char c, int Jogadas [8][8], Info I);

// Encontra as jogadas de uma rainha
int encontraJogadasRainha (int l, char c, int Jogadas [8][8], Info I);

// Verifica as possibilidades de 'Castle'
int castle (int l, char c, int Jogadas [8][8], Info I);

// Encontra as jogadas de um rei
int encontraJogadasRei (int l, char c, int Jogadas [8][8], Info I);





// EncontrarAtaques.c

// Encontra os ataques de um peão branco
void encontraAtaquesPeaoB (int l, char c, int Ataques [8][8]);

// Encontra os ataques de um peão preto
void encontraAtaquesPeaoP (int l, char c, int Ataques [8][8]);

// Encontra os ataques de uma torre
void encontraAtaquesTorre (int l, char c, int Jogadas [8][8], Info I);

// Encontra os ataques de um cavalo
void encontraAtaquesCavalo (int l, char c, int Ataques [8][8], Info I);

// Encontra os ataques de um bispo
void encontraAtaquesBispo (int l, char c, int Ataques [8][8], Info I);

// Encontra os ataques de uma rainha
void encontraAtaquesRainha (int l, char c, int Jogadas [8][8], Info I);





// Template.c

// Lê um template
int leTemplate (char NomeFicheiro [17], char Tab [8][9]);

// Guarda um template num ficheiro
void guardaTemplate (char NomeFicheiro [17], char Tab [8][9]);

// Imprime um template
int imprimeTemplate (char NomeFicheiro [17]);

// Edita um template
void editaTemplate (char NomeFicheiro [17]);

// Imprime um tabuleiro
void imprimeTabuleiro (char Tab [8][9], int N);





// Cheque.c

// Verifica se o rei branco está em cheque
int reiBrancoCheque (Info I);

// Verifica se o rei preto está em cheque
int reiPretoCheque (Info I);

// Verifica se, ao realizar uma jogada, o rei fica em cheque
int colocaReiCheque (int li, char ci, int lf, char cf, Info I);





// MemoryManagement.c

// Aloca memória para a informação do mini-jogo
Info iniciaMiniJogo (int EExplosivo);

// Liberta a memória alocada para a informação do mini-jogo
void finalizaMiniJogo (Info I);





// Queue.c

// Liberta a memória alocada para o histórico de jogadas
void libertaHistorico (Historico H);

// Adiciona uma jogada ao histórico de jogadas
void addJogada (Historico *H, Jogada J);
#include "../Xadrez.h"

// Aloca memória para a informação do mini-jogo
Info iniciaMiniJogo (int EExplosivo) {

    // Aloca memória para o struct
    Info I = malloc (sizeof (INFO));

    // Define os compontentes do struct
    I -> NJogada = I -> UltimoAvanco = 1;
    I -> EExplosivo = EExplosivo;
    I -> H = NULL;

    // Retorna o struct
    return I;
}



// Liberta a memória alocada para a informação do mini-jogo
void finalizaMiniJogo (Info I) {

    // Liberta a memória alocada para o histórico de jogadas
    libertaHistorico (I -> H);

    // Liberta a memória alocada para o struct
    free (I);

    // Define o struct como NULL
    I = NULL;
}
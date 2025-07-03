#include "../Xadrez.h"

// Liberta a memória alocada para o histórico de jogadas
void libertaHistorico (Historico H) {

    // Liberta os nodos até ao fim da lista
    while (H) {

        // Armazena o nodo
        Historico Temp = H;
        
        // Avança na lista
        H = H -> Proximo;

        // Liberta o nodo
        free (Temp);
    }
}



// Adiciona uma jogada ao histórico de jogadas
void addJogada (Historico *H, Jogada J) {

    // Verifica se é a primeira jogada do mini-jogo
    if (*H == NULL) {

        // Aloca memória para o nodo
        *H = malloc (sizeof (HISTORICO));

        // Define as componentes do struct
        (*H) -> Anterior = (*H) -> Proximo = NULL;
        (*H) -> J = J;
    } else {

        // Percorre a lista até ao fim
        while ((*H) -> Proximo) H = &(*H) -> Proximo;

        // Aloca memória para o nodo
        (*H) -> Proximo = malloc (sizeof (HISTORICO));

        // Define as componentes do struct
        (*H) -> Proximo -> Anterior = *H;
        (*H) -> Proximo -> Proximo = NULL;
        (*H) -> Proximo -> J = J;
    }
}
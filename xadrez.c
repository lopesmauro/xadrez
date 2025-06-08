#include <stdio.h>

/*
 * Função recursiva para movimentação da Torre.
 * Imprime a direção a cada casa até chegar a 0.
 */
void moverTorreRecursivo(int casas, char* direcao) {
    if (casas <= 0) return;
    printf("%s\n", direcao);
    moverTorreRecursivo(casas - 1, direcao);
}

/*
 * Função que utiliza loops aninhados para o movimento diagonal do Bispo.
 * O loop externo controla o movimento vertical, o interno o horizontal.
 * Imprime "Diagonal - Cima Direita" para cada movimento na diagonal.
 */
void moverBispoLoops(int casasVertical, int casasHorizontal) {
    for (int v = 1; v <= casasVertical; v++) {
        for (int h = 1; h <= casasHorizontal; h++) {
            printf("Diagonal - Cima Direita\n");
        }
    }
}

/*
 * Função recursiva para o movimento da Rainha.
 * Imprime todas as direções da Torre e do Bispo.
 * Repete recursivamente para o número de casas desejado.
 */
void moverRainhaRecursivo(int casas) {
    if (casas <= 0) return;
    
    // Movimento Torre
    printf("Cima\n");
    printf("Baixo\n");
    printf("Esquerda\n");
    printf("Direita\n");
    
    // Movimento Bispo (diagonais)
    printf("Cima Direita\n");
    printf("Cima Esquerda\n");
    printf("Baixo Direita\n");
    printf("Baixo Esquerda\n");
    
    moverRainhaRecursivo(casas - 1);
}

/*
 * Função que simula o movimento do Cavalo usando loops aninhados.
 * Movimento "L": 2 casas para cima e 1 para a direita.
 * Usa continue e break para controle do fluxo.
 */
void moverCavaloLoops(int maxMovimentos) {
    int movimentosFeitos = 0;

    for (int i = 0; i < maxMovimentos; i++) {
        int passosCima = 0;
        int passosDireita = 0;

        // Move 2 casas para cima
        while (passosCima < 2) {
            printf("Cima\n");
            passosCima++;
            if (passosCima == 1) continue; // Demonstra continue, pula para a próxima iteração
        }

        // Move 1 casa para direita
        for (int j = 0; j < 1; j++) {
            printf("Direita\n");
            passosDireita++;
            if (passosDireita > 1) break; // Demonstra break (não será executado aqui)
        }

        movimentosFeitos++;
    }
}

int main() {
    int casasTorre = 4;      // Número de casas para mover Torre
    int casasBispo = 3;      // Número de casas para mover Bispo (vertical e horizontal)
    int casasRainha = 5;     // Número de casas para mover Rainha
    int movimentosCavalo = 3;// Quantidade de movimentos do Cavalo

    // Movimentos da Torre - recursivo em 4 direções
    printf("Movimentos da Torre:\n");
    moverTorreRecursivo(casasTorre, "Cima");
    moverTorreRecursivo(casasTorre, "Baixo");
    moverTorreRecursivo(casasTorre, "Esquerda");
    moverTorreRecursivo(casasTorre, "Direita");
    printf("\n");

    // Movimentos do Bispo - loops aninhados para diagonal
    printf("Movimentos do Bispo (com loops aninhados):\n");
    moverBispoLoops(casasBispo, casasBispo);
    printf("\n");

    // Movimentos da Rainha - recursivo combinando Torre e Bispo
    printf("Movimentos da Rainha:\n");
    moverRainhaRecursivo(casasRainha);
    printf("\n");

    // Movimentos do Cavalo - loops complexos para movimento em "L"
    printf("Movimentos do Cavalo (loops complexos):\n");
    moverCavaloLoops(movimentosCavalo);
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Definição das peças do xadrez
typedef enum {
   PEAO,
   TORRE,
   CAVALO,
   BISPO,
   RAINHA,
   REI
} Peca;

// Definição das cores das peças
typedef enum {
   BRANCO,
   PRETO
} Cor;

// Estrutura para representar uma peça no tabuleiro
typedef struct {
   Peca peca;
   Cor cor;
} Casa;

// Estrutura para representar o tabuleiro de xadrez
typedef struct {
   Casa casas[8][8];
} Tabuleiro;

// Função para inicializar o tabuleiro
void inicializarTabuleiro(Tabuleiro *tabuleiro) {
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (i == 1) {
           tabuleiro->casas[i][j].peca = PEAO;
           tabuleiro->casas[i][j].cor = BRANCO;
        } else if (i == 6) {
           tabuleiro->casas[i][j].peca = PEAO;
           tabuleiro->casas[i][j].cor = PRETO;
        } else if (i == 0) {
           if (j == 0 || j == 7) {
              tabuleiro->casas[i][j].peca = TORRE;
              tabuleiro->casas[i][j].cor = BRANCO;
           } else if (j == 1 || j == 6) {
              tabuleiro->casas[i][j].peca = CAVALO;
              tabuleiro->casas[i][j].cor = BRANCO;
           } else if (j == 2 || j == 5) {
              tabuleiro->casas[i][j].peca = BISPO;
              tabuleiro->casas[i][j].cor = BRANCO;
           } else if (j == 3) {
              tabuleiro->casas[i][j].peca = RAINHA;
              tabuleiro->casas[i][j].cor = BRANCO;
           } else if (j == 4) {
              tabuleiro->casas[i][j].peca = REI;
              tabuleiro->casas[i][j].cor = BRANCO;
           }
        } else if (i == 7) {
           if (j == 0 || j == 7) {
              tabuleiro->casas[i][j].peca = TORRE;
              tabuleiro->casas[i][j].cor = PRETO;
           } else if (j == 1 || j == 6) {
              tabuleiro->casas[i][j].peca = CAVALO;
              tabuleiro->casas[i][j].cor = PRETO;
           } else if (j == 2 || j == 5) {
              tabuleiro->casas[i][j].peca = BISPO;
              tabuleiro->casas[i][j].cor = PRETO;
           } else if (j == 3) {
              tabuleiro->casas[i][j].peca = RAINHA;
              tabuleiro->casas[i][j].cor = PRETO;
           } else if (j == 4) {
              tabuleiro->casas[i][j].peca = REI;
              tabuleiro->casas[i][j].cor = PRETO;
           }
        } else {
           tabuleiro->casas[i][j].peca = -1;
           tabuleiro->casas[i][j].cor = -1;
        }
      }
   }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(Tabuleiro *tabuleiro) {
   printf("  a b c d e f g h\n");
   for (int i = 0; i < 8; i++) {
      printf("%d ", 8 - i);
      for (int j = 0; j < 8; j++) {
        if (tabuleiro->casas[i][j].peca == -1) {
           printf("- ");
        } else {
           switch (tabuleiro->casas[i][j].peca) {
              case PEAO:
                printf("P ");
                break;
              case TORRE:
                printf("T ");
                break;
              case CAVALO:
                printf("C ");
                break;
              case BISPO:
                printf("B ");
                break;
              case RAINHA:
                printf("Q ");
                break;
              case REI:
                printf("K ");
                break;
           }
        }
      }
      printf("\n");
   }
}

// Função para mover uma peça
void moverPeca(Tabuleiro *tabuleiro, int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
   Casa peca = tabuleiro->casas[linhaOrigem][colunaOrigem];
   tabuleiro->casas[linhaOrigem][colunaOrigem].peca = -1;
   tabuleiro->casas[linhaOrigem][colunaOrigem].cor = -1;
   tabuleiro->casas[linhaDestino][colunaDestino] = peca;
}

int main() {
   Tabuleiro tabuleiro;
   inicializarTabuleiro(&tabuleiro);

   int linhaOrigem, colunaOrigem, linhaDestino, colunaDestino;
   Cor cor = BRANCO;

   while (1) {
      imprimirTabuleiro(&tabuleiro);

      char posicaoOrigem[3];
      char posicaoDestino[3];

      printf("Jogador %s, digite a posição da peça que deseja mover (ex: a1):\n", cor == BRANCO ? "branco" : "preto");
      scanf("%s", posicaoOrigem);

      printf("Digite a posição de destino (ex: a1):\n");
      scanf("%s", posicaoDestino);

      // Converter as posições para índices
      linhaOrigem = posicaoOrigem[1] - '1';
      colunaOrigem = posicaoOrigem[0] - 'a';
      linhaDestino = posicaoDestino[1] - '1';
      colunaDestino = posicaoDestino[0] - 'a';

      // Mover a peça
if (tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca == PEAO) {
   // Regra de movimento para peões
   if (linhaDestino == linhaOrigem + 1 && colunaDestino == colunaOrigem) {
      // Mover o peão para a frente
      Casa peca = tabuleiro.casas[7 - linhaOrigem][colunaOrigem];
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca = -1;
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].cor = -1;
      tabuleiro.casas[7 - linhaDestino][colunaDestino] = peca;
   } else if (linhaDestino == linhaOrigem + 2 && colunaDestino == colunaOrigem && linhaOrigem == 1) {
      // Mover o peão dois espaços para a frente (apenas na primeira jogada)
      Casa peca = tabuleiro.casas[7 - linhaOrigem][colunaOrigem];
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca = -1;
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].cor = -1;
      tabuleiro.casas[7 - linhaDestino][colunaDestino] = peca;
   } else {
      printf("Movimento inválido para peão!\n");
   }
} else if (tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca == TORRE) {
   // Regra de movimento para torres
   if (linhaDestino == linhaOrigem || colunaDestino == colunaOrigem) {
      // Mover a torre horizontalmente ou verticalmente
      Casa peca = tabuleiro.casas[7 - linhaOrigem][colunaOrigem];
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca = -1;
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].cor = -1;
      tabuleiro.casas[7 - linhaDestino][colunaDestino] = peca;
   } else {
      printf("Movimento inválido para torre!\n");
   }
} else if (tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca == CAVALO) {
   // Regra de movimento para cavalos
   if (abs(linhaDestino - linhaOrigem) == 2 && abs(colunaDestino - colunaOrigem) == 1) {
      // Mover o cavalo em forma de L
      Casa peca = tabuleiro.casas[7 - linhaOrigem][colunaOrigem];
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca = -1;
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].cor = -1;
      tabuleiro.casas[7 - linhaDestino][colunaDestino] = peca;
   } else {
      printf("Movimento inválido para cavalo!\n");
   }
} else if (tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca == BISPO) {
   // Regra de movimento para bispos
   if (abs(linhaDestino - linhaOrigem) == abs(colunaDestino - colunaOrigem)) {
      // Mover o bispo diagonalmente
      Casa peca = tabuleiro.casas[7 - linhaOrigem][colunaOrigem];
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca = -1;
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].cor = -1;
      tabuleiro.casas[7 - linhaDestino][colunaDestino] = peca;
   } else {
      printf("Movimento inválido para bispo!\n");
   }
} else if (tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca == RAINHA) {
   // Regra de movimento para rainhas
   if (linhaDestino == linhaOrigem || colunaDestino == colunaOrigem || abs(linhaDestino - linhaOrigem) == abs(colunaDestino - colunaOrigem)) {
      // Mover a rainha horizontalmente, verticalmente ou diagonalmente
      Casa peca = tabuleiro.casas[7 - linhaOrigem][colunaOrigem];
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca = -1;
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].cor = -1;
      tabuleiro.casas[7 - linhaDestino][colunaDestino] = peca;
   } else {
      printf("Movimento inválido para rainha!\n");
   }
} else if (tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca == REI) {
   // Regra de movimento para reis
   if (abs(linhaDestino - linhaOrigem) <= 1 && abs(colunaDestino - colunaOrigem) <= 1) {
      // Mover o rei para uma posição adjacente
      Casa peca = tabuleiro.casas[7 - linhaOrigem][colunaOrigem];
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].peca = -1;
      tabuleiro.casas[7 - linhaOrigem][colunaOrigem].cor = -1;
      tabuleiro.casas[7 - linhaDestino][colunaDestino] = peca;
   } else {
      printf("Movimento inválido para rei!\n");
   }
}

      moverPeca(&tabuleiro, linhaOrigem - 1, colunaOrigem - 1, linhaDestino - 1, colunaDestino - 1);

      // Trocar de cor
      cor = cor == BRANCO ? PRETO : BRANCO;
   }

   return 0;
}

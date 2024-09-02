#include <stdio.h>
#include <stdlib.h>

int **create_board() {
  int **board = (int **)malloc(3 * sizeof(int *));

  for (int i = 0; i < 3; i++) {
    board[i] = (int *)malloc(3 * sizeof(int));
    for (int j = 0; j < 3; j++) {
      board[i][j] = 0;
    }
  }

  return board;
}

void free_board(int **board) {
  for (int i = 0; i < 3; i++) {
    free(board[i]);
  }

  free(board);
}

void print_board(int **board) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

      if (board[i][j] == 0) {
        printf("- ");
      } else if (board[i][j] == 1) {
        printf("X ");
      } else {
        printf("O ");
      }
    }
    printf("\n");
  }
}

int check_win(int **board) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
        board[i][0] != 0) {
      return board[i][0];
    }

    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
        board[0][i] != 0) {
      return board[0][i];
    }
  }

  if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
       board[0][0] != 0) ||
      (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
       board[0][2] != 0)) {
    return board[1][1];
  }

  return 0;
}

int main() {
  int **board = create_board();

  int player_turn = 0, win = 0, plays = 0;
  while (!(win = check_win(board))) {
    print_board(board);
    if (plays == 9) {
      break;
    }
    printf("Vez de player %d\n", player_turn + 1);

    int row, col;
    do {
      printf("Digite a linha e coluna: ");
      scanf("%d %d", &row, &col);

      if (board[row][col] != 0) {
        printf("Posição já ocupada!\n");
      }
    } while (board[row][col] != 0);

    board[row][col] = player_turn + 1;

    player_turn = !player_turn;
    plays++;
  }

  if (win) {
    printf("Player %d venceu! Parabéns!\n", win);
  } else if (plays == 9) {
    printf("Empate!\n");
  } else {
    printf("Não sei\n");
  }

  free_board(board);
  return 0;
}

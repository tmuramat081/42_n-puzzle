#ifndef N_PUZZLE_H
# define N_PUZZLE_H

typedef struct {
  int size;
  int **board;
} t_board;


#define MAX_LINE 100

t_board *parse_puzzle_board(const char *filename);
void print_puzzle_board(t_board *puzzle_board);
void free_puzzle_board(t_board *puzzle_board);

#endif

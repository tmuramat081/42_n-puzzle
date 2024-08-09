#include "n_puzzle.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int ac, char **av)
{
    t_board *puzzle_board;

    if (ac != 2)
    {
        puts("wrong number of arguments");
        exit(1);
    }
    puzzle_board = parse_puzzle_board(av[1]);
    if (!puzzle_board)
    {
        puts("error reading puzzle");
        exit(1);
    }
    // debug
    print_puzzle_board(puzzle_board);
    free_puzzle_board(puzzle_board);
    return (0);
}

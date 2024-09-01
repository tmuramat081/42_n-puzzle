#include "n_puzzle.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

t_board* parse_puzzle_board(const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        printf("ファイルを開けませんでした: %s\n", filename);
        return NULL;
    }

    t_board *puzzle = malloc(sizeof(t_board));
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), file)) 
    {
        if (line[0] != '#') {
            puzzle->size = atoi(line);
            break;
        }
    }

    puzzle->board = malloc(puzzle->size * sizeof(int*));
    for (int i = 0; i < puzzle->size; i++)
    {
        puzzle->board[i] = malloc(puzzle->size * sizeof(int));
    }

    int row = 0;
    while (fgets(line, sizeof(line), file) && row < puzzle->size) {
        if (line[0] == '#') continue;

        char *token = strtok(line, " #\n");
        for (int col = 0; col < puzzle->size && token != NULL; col++) {
            puzzle->board[row][col] = atoi(token);
            token = strtok(NULL, " #\n");
        }
        row++;
    }

    fclose(file);
    return puzzle;
}

void free_puzzle_board(t_board *puzzle_board) 
{
    if (!puzzle_board || !puzzle_board->board)
        return;
    while (puzzle_board->size--)
    {
        free(puzzle_board->board[puzzle_board->size]);
    }
    free(puzzle_board->board);
    free(puzzle_board);
}

void print_puzzle_board(t_board *puzzle_board)
{
    int i;
    int j;

    if (!puzzle_board || !puzzle_board->board) 
        return;
    i = 0;
    while(i < puzzle_board->size)
    {   
        j = 0;
        while(j < puzzle_board->size)
        {
            printf("%d ", puzzle_board->board[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return;
}

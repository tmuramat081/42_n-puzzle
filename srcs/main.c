#include "n_puzzle.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

t_board* read_puzzle(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("ファイルを開けませんでした: %s\n", filename);
        return NULL;
    }

    t_board *puzzle = malloc(sizeof(t_board));
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] != '#') {
            puzzle->size = atoi(line);
            break;
        }
    }

    // グリッドのメモリ割り当て
    puzzle->board = malloc(puzzle->size * sizeof(int*));
    for (int i = 0; i < puzzle->size; i++) {
        puzzle->board[i] = malloc(puzzle->size * sizeof(int));
    }

    // グリッドの読み込み
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

int main (void)
{

    return (0);
}

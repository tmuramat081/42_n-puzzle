#include "n_puzzle.h"
#include <stdio.h>

t_board* read_puzzle(const char *filename) {
    File *file = fopen(filename, "r");
    if (!file) {
        printf("ファイルを開けませんでした: %s\n", filename);
        return null;
    }
}

int main (void)
{

    return (0);
}

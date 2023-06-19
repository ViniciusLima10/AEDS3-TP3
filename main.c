#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./headers/manipulaArquivos.h"




int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <estrategia> <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    int estrategia = atoi(argv[1]);
    char* fileName = argv[2];

    inputFile(fileName, estrategia);

    return 0;
}
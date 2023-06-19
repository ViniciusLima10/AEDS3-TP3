#include "./headers/shiftAnd.h"

int shiftAnd(char* padrao, char* texto) {
    int m = strlen(padrao);
    int n = strlen(texto);

    __int128 mascaras[TAM_ALFABETO];
    int i, j;

    for (i = 0; i < TAM_ALFABETO; i++) {
        mascaras[i] = (__int128)(0);
    }

    for (i = 0; i < m; i++) {
        mascaras[padrao[i]] |= (__int128)(1) << i;

    }

    __int128 resultado = 0;

    for (i = 0; i < n; i++) {
        resultado = ((resultado << 1) | 1) & mascaras[texto[i]];
        
        if (resultado & (__int128)(1) << (m - 1)) {
            return i - m + 1;
        }
    }
    return -1;
}
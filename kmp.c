#include "./headers/kmp.h"

void compute_prefix_table(char* pattern, int pattern_length, int* prefix_table) {
    int i = 0;
    int j = -1;
    prefix_table[0] = -1;

    while (i < pattern_length) {
        while (j >= 0 && pattern[i] != pattern[j]) {
            j = prefix_table[j];
        }
        i++;
        j++;
        prefix_table[i] = j;
    }
}

int kmp_search(char* pattern, char* text) {
    int pattern_length = strlen(pattern);
    int text_length = strlen(text);
    int* prefix_table = (int*)malloc((pattern_length + 1) * sizeof(int));
    int i = 0;
    int j = 0;

    compute_prefix_table(pattern, pattern_length, prefix_table);

    while (i < text_length) {
        while (j >= 0 && text[i] != pattern[j]) {
            j = prefix_table[j];
        }
        i++;
        j++;

        if (j == pattern_length) {
            free(prefix_table);
            return i - j +1;  // Padrão encontrado no texto
        }
    }

    free(prefix_table);
    return -1;  // Padrão não encontrado no texto
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compute_prefix_table(char* pattern, int pattern_length, int* prefix_table);

int kmp_search(char* pattern, char* text);
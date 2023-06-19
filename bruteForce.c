#include "./headers/bruteForce.h"

int brute_force_search(char* pattern, char* text) {
    int pattern_length = strlen(pattern);
    int text_length = strlen(text);
    
    for (int i = 0; i <= text_length - pattern_length; i++) {
        int j;
        
        for (j = 0; j < pattern_length; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        
        if (j == pattern_length) {
            return i + 1;  // Padrão encontrado no texto
        }
    }
    
    return -1;  // Padrão não encontrado no texto
}
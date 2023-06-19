#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./headers/manipulaArquivos.h"
#include "./headers/kmp.h"
#include "./headers/shiftAnd.h"
#include "./headers/bruteForce.h"


void outputFile(int numeroDeTabuleiros, int *resultados) {

    FILE *file; // ponteiro para arquivo
    file = fopen("saida.txt", "w"); // abre o arquivo em modo de escrita
    
    if (file == NULL) { // verifica se o arquivo foi aberto corretamente
        printf("Couldn't open the output file!\n");
        return;
    }
    for(int i = 0; i < numeroDeTabuleiros; i++){
        if(resultados[i] == -1){
             fprintf(file, "N\n");
             continue;
        }
       fprintf(file, "S %d\n", resultados[i]); // escreve o valor de maiorSequencia no arquivo
    }
    fclose(file); // fecha o arquivo
}

// Função para ler o arquivo de entrada e processar os testes
void inputFile(char* fileName, int estrategia) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Couldn't open file!\n");
        exit(1);
    }

    int Testes;
    fscanf(file, "%d", &Testes);

    int *resultados;
     resultados = malloc(Testes * sizeof(int));

    for (int t = 0; t < Testes; t++) {
        char* palavra = NULL;
        char* texto = NULL;


        fscanf(file, "%ms %ms", &palavra, &texto);

        int tamanhoTextoOriginal = strlen(texto);
        int tamanhoPalavra = strlen(palavra);
        int tamanhoNovoTexto = tamanhoTextoOriginal + tamanhoPalavra +1;

        char* NovoText = malloc(sizeof(char) * (tamanhoNovoTexto));

        for (int i = 0; i < tamanhoNovoTexto; i++) {
            NovoText[i] = texto[i % tamanhoTextoOriginal];
        }

        NovoText[tamanhoNovoTexto] = '\0';

        char* palavraInvertida = malloc(sizeof(char) * (tamanhoPalavra + 1));

        for (int i = tamanhoPalavra - 1, j = 0; i >= 0; i--, j++) {
            palavraInvertida[j] = palavra[i];
        }

        palavraInvertida[tamanhoPalavra] = '\0';


        int resultado;
        if (estrategia == 1) {
            // Lógica para estratégia 1
            resultado = shiftAnd(palavra, NovoText);
            if(resultado == -1){
                resultado = shiftAnd(palavraInvertida, NovoText) ;
                if(resultado == -1){
                    resultados[t] = resultado;  
                    continue;
                }
                resultado = (tamanhoPalavra- 1) - resultado;
            }
           resultados[t] = resultado +1;  
        }
        if (estrategia == 2){
            resultado = kmp_search(palavra, NovoText);
        if(resultado == -1){
                resultado = kmp_search(palavraInvertida, NovoText);
                if(resultado == -1){
                    resultados[t] = resultado;  
                    continue;
                }
                resultado =(tamanhoPalavra +1) -  resultado;
            }
            resultados[t] = resultado;   
        }
        if (estrategia == 3){
            resultado = brute_force_search(palavra, NovoText);
        if(resultado == -1){
                resultado = brute_force_search(palavraInvertida, NovoText);
                if(resultado == -1){
                    resultados[t] = resultado;  
                    continue;
                }
                resultado =(tamanhoPalavra +1) -  resultado;
            }
            resultados[t] = resultado;    
        }


       
        free(palavra);
        free(texto);
        free(NovoText);
    }
    outputFile(Testes, resultados);
    free(resultados);
    fclose(file);
}

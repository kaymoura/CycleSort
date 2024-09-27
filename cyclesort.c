// @author Kaylane Moura
#include <stdio.h>

// Função para executar o Cycle Sort com mensagens
void cycleSort(int arr[], int n) {
    int writes = 0; // Contador de movimentações

    // Percorrer o array para encontrar ciclos
    for (int ciclo_inicial = 0; ciclo_inicial < n - 1; ciclo_inicial++) {
        int item = arr[ciclo_inicial];
        printf("\n=========================== ciclo %d ===========================", ciclo_inicial);
        printf("\n\nEstou analisando o elemento %d na posição %d.\n", item, ciclo_inicial);

        // Encontrar onde o item pertence
        int pos = ciclo_inicial;
        for (int i = ciclo_inicial + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }
        
        printf("Ele tem %d números menores que ele, então a posição correta é %d.\n", pos - ciclo_inicial, pos);

        // Se o item já está na posição correta, continuar
        if (pos == ciclo_inicial) {
            printf("O elemento %d já está na posição correta.\n", item);
            continue;
        }

        // Ignorar elementos duplicados
        while (item == arr[pos]) {
            pos++;
        }

        // Trocar o item com o que está na posição correta
        if (pos != ciclo_inicial) {
            printf("\nTrocando o elemento %d com o elemento %d da posição %d.\n", item, arr[pos], pos);
            int temp = arr[pos]; 
            arr[pos] = item;
            item = temp;  // Atualizar item para continuar o ciclo
            writes++;
        }

        // Girar o resto do ciclo
        while (pos != ciclo_inicial) {
            pos = ciclo_inicial;

            // Encontrar onde o item pertence
            for (int i = ciclo_inicial + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            // Ignorar elementos duplicados
            while (item == arr[pos]) {
                pos++;
            }

            // Trocar
            if (item != arr[pos]) {
                printf("\nTrocando o elemento %d com o elemento %d da posição %d.\n", item, arr[pos], pos);
                int temp = arr[pos];  
                arr[pos] = item;
                item = temp;
                writes++;
            }
        }
        
        // Imprimir o array após o último movimento do ciclo
        printf("\nO array ficou assim após o ciclo %d: [", ciclo_inicial);
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("]\n\n");
    }
    
    printf("\n================================================================");
    printf("\n\nTerminei o Cycle Sort. O array está ordenado.\n");
    printf("Número total de movimentações: %d\n", writes);
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int main() {
    printf("\nEXEMPLO - CYCLE SORT\n\n");
    // Vetor de exemplo
    int arr[] = {7, 8, 1, 6, 14, 9, 2, 10, 3, 4, 13, 5, 0, 11, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    // Chamar o Cycle Sort
    cycleSort(arr, n);

    printf("\nArray ordenado: \n");
    printArray(arr, n);

    return 0;
}

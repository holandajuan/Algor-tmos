#include <iostream>
using namespace std;

void merge_sort(int* arr, int inicio, int fim, int tamanho) {
    int i, j, k, vetor_aux[tamanho];
    if (inicio < fim) {
        // divisão do vetor

        int meio = (inicio + fim) / 2;
        merge_sort(arr, inicio, meio, tamanho);
        merge_sort(arr, meio + 1, fim, tamanho);

        // mesclagem e ordenação dos vetores

        i = inicio; // inicio vetor esquerda
        j = meio + 1; // inicio vetor direita
        k = inicio; // percorre vetor aux

        // compara cada elemento entre os vetores
        while (i <= meio && j <= fim) {

            if (arr[i] < arr[j]) { vetor_aux[k] = arr[i]; i++; }
            else                 { vetor_aux[k] = arr[j]; j++; }
            k++;
        }

        // adiciona os elementos restantes da comparação
        while (i <= meio) { 
            vetor_aux[k] = arr[i];
            i++; k++;
        }
        while (j <= fim) {
            vetor_aux[k] = arr[j];
            j++; k++;
        }

        // copia o vetor_aux(ordenado) para o vetor original
        for (int i = inicio; i <= fim; i++) arr[i] = vetor_aux[i]; 
    }
}

int main() {
    int tamanho = 10;
    int array[tamanho] = {5, 4, 2, 6, 8, 9, 1, 3, 7, 10};

    cout << "Vetor desordenado: ";
    for (int i = 0; i < tamanho; i++) cout << array[i] << " ";

    cout << "\nVetor Ordenado: ";
    merge_sort(array, 0, tamanho - 1, tamanho);
    for (int i = 0; i < tamanho; i++) cout << array[i] << " ";
}
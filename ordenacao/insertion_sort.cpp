#include <iostream>
using namespace std;


void insertionSort(int* arr, int tamanho) {
    for (int i=1; i<tamanho; i++) {
        int temp = arr[i]; // objeto a ser comparado
        int j = i - 1; // indice objeto comparador
        while (arr[j] > temp && j >= 0) {
            arr[j + 1] = arr[j]; // desloca objeto comparador
            j--;
        }
        arr[j + 1] = temp; // insere temp após ao valor que o antecede 
    }
}

int main() {
    int tamanho = 6;
    int array[tamanho] = {2, 4, 8, 1, 3, 5};
    insertionSort(array, tamanho);

    for (int i=0; i<tamanho; i++) {
        cout << array[i] << " ";
    }
};
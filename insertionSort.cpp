#include <iostream>
using namespace std;

// insertionSort implementado.
// Começa sempre no segundo elemento (index 1), assumindo que o primeiro já está em sua posição correta.
// Pega o valor atual e compara com os elementos anteriores.
// Joga os maiores elementos para a direita, inserindo os valores na posição correta.
// Complexidade: Melhor caso O(n), Pior e médio caso: O(n²)
// O algoritmo é estável.

void insertionSort(int arr[], int length){
    for(int i = 1; i < length; i++) {
        int v = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > v) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = v;
    }
}

int main() {
    int length;
    cin >> length;
    int arr[length];

    for (int i = 0; i < length; i++){
        cin >> arr[i];
    }

    insertionSort(arr, length);

    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
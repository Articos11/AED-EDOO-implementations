#include <iostream>
using namespace std;

// Selection Sort implementado.
// Encontra o menor elemento e o troca com sua posição correta na lista.
// Complexidade O(n²), no melhor, pior e caso médio.
// Não é estável, pois pode trocar dois números iguais. Ex [1,1]
void selectionSort(int arr[], int length){
    for (int i = 0; i < length - 1; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int length;
    cin >> length;
    int arr[length];

    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, length);

    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
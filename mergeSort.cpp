#include <iostream>
using namespace std;

// Algoritmo de dividir para coqnuistar. Ordena recursivamente duas metades do array até chegarmos em itens atomicos.
// Junta recursivamente cada metade ordenada.
// Complexidade em todos os casos: O(n log n)

void Merge(int arr[], int left, int mid, int right) {
    // Arrays temporários para auxiliar.
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int larr[n1];
    int rarr[n2];

    // Copiando as metades dos arrays esquerda e direita.
    for (int i = 0; i < n1; i++){
        larr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++){
        rarr[i] = arr[mid + 1 + i];
    }

    // Junção dos dois arrays.
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (larr[i] <= rarr[j]) {
            arr[k] = larr[i];
            i++;
        } else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }

    // Primeira metade do array.
    while (i < n1){
        arr[k] = larr[i];
        i++, k++;
    }

    // Segunda metade do array.
    while (j < n2) {
        arr[k] = rarr[j];
        j++, k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }

}

int main() {
    int length;
    cin >> length;
    int arr[length];

    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, length - 1);

    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

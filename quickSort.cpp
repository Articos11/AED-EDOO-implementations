#include <iostream>
using namespace std;

// Partição de lomuto, escolhendo sempre o último elemento como pivot.
int lomutoPartition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;
    return (i+1);
}

void quickSort(int arr[], int left, int right){
    if (left < right) {
        int pivot = lomutoPartition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int main(){

    int length;
    cin >> length;
    int arr[length];

    for (int i = 0; i < length; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, length - 1);

    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
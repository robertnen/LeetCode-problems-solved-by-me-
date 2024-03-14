int arrXOR(int* arr, int size) {
    int ans = 0;

    for(int i = 0; i < size; i++) ans ^= arr[i];

    return ans;
}

int getXORSum(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    return arrXOR(arr1, arr1Size) & arrXOR(arr2, arr2Size);
}
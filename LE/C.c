#include <stdio.h>
#include <stdlib.h>

void Merge(long long array1[], long long array2[], long long array3[], int tam2, int tam3) {
    int i = 0, j = 0, k = 0;
    while (i < tam2 && j < tam3) {
        if (array2[i] <= array3[j]) {
            array1[k] = array2[i];
            i++;
        } else {
            array1[k] = array3[j];
            j++;
        }
        k++;
    }
    if (i == tam2) {
        for (int l = j; l < tam3; l++) {
            array1[k] = array3[l];
            k++;
        }
    } else {
        for (int l = i; l < tam2; l++) {
            array1[k] = array2[l];
            k++;
        }
    }
}

void mergeSort(long long array[], int tam) {
    if (tam > 1) {
        int n = tam / 2;
        long long *B = (long long *)malloc(n * sizeof(long long));
        long long *C = (long long *)malloc((tam - n) * sizeof(long long));

        for (int i = 0; i < n; i++) {
            B[i] = array[i];
        }
        for (int i = n; i < tam; i++) {
            C[i - n] = array[i];
        }

        mergeSort(B, n);
        mergeSort(C, tam - n);
        Merge(array, B, C, n, tam - n);

        free(B);
        free(C);
    }
}

void preencherArray(long long array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        scanf("%lld", &array[i]);
    }
}

int binarySearch(long long ordenado[], int l, int r, long long k) {
    if (r >= l) {
        int m = (l + r) / 2;
        if (ordenado[m] == k) {
            return m;
        } else if (ordenado[m] > k) {
            return binarySearch(ordenado, l, m - 1, k);
        } else {
            return binarySearch(ordenado, m + 1, r, k);
        }
    } else {
        return -1;
    }
}

int main() {
    // Declaring the variables n and k
    int n;
    long long k;

    // Prompting user input for n and k
    scanf("%d %lld", &n, &k);

    // Creating an array of size n
    long long vetor[n];
    preencherArray(vetor, n);

    // Sorting the array using mergeSort
    mergeSort(vetor, n);

    // Counting pairs with absolute difference equal to k
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (binarySearch(vetor, 0, n - 1, vetor[i] + k) != -1) {
            count++;
        }
    }

    // Displaying the result
    printf("%d", count);

    return 0;
}


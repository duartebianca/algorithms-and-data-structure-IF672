#include <stdio.h>
#include <stdlib.h>

void Merge(int array1[], int array2[], int array3[], int tam1, int tam2, int tam3) {
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

void MergeSort(int array[], int tam) {
    if (tam > 1) {
        int n = tam / 2;
        int *B = (int *)malloc(n * sizeof(int));
        int *C = (int *)malloc((tam - n) * sizeof(int));

        for (int i = 0; i < n; i++) {
            B[i] = array[i];
        }
        for (int i = n; i < tam; i++) {
            C[i - n] = array[i];
        }

        MergeSort(B, n);
        MergeSort(C, tam - n);
        Merge(array, B, C, tam, n, tam - n);

        free(B);
        free(C);
    }
}

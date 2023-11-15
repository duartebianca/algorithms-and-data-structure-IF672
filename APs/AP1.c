#include <stdio.h>

//functions
void preencherArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }
}

void Merge(int array1[], int array2[], int array3[], int tam1, int tam2, int tam3) {
    int i=0, j=0, k=0;
    while (i < tam2 && j < tam3) {
        if (array2[i] <= array3[j]){
            array1[k] = array2[i];
            i++;        
        }
        else {
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
    }
    else {
        for (int l = i; l < tam2; l++) {
            array1[k] = array2[l];
            k++;
        }
    }
}

void mergeSort (int array[], int tam) {
    if (tam > 1) {
        int n = tam/2;
        int B[n], C[tam-n];
        for (int i = 0; i < n; i++) {
            B[i] = array[i];
        }
        for (int i = n; i < tam; i++) {
            C[i-n] = array[i];
        }
        mergeSort(B, n);
        mergeSort(C, tam-n);
        Merge(array, B, C, tam, n, tam-n);
    }
}

int main() {
    //number of cases
    int c = 0;
    printf("How many arrays do you want to sort?\n");
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        printf("Case %d:\n", i+1);
        //size of wich array to order
        int n = 0;
        printf("How many elements do you want to sort in this array?\n");
        scanf("%d", &n);
        //array to sort
        int array[n];
        printf("Enter the elements of the array:\n");
        preencherArray(array, n);
        mergeSort(array, n);
        //display the sorted array
        printf("Sorted array:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}

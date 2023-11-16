#include <stdio.h>
#include <stdlib.h>

// functions
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

int main() {
    // number of chocolate bars
    int n = 0;
    long long sum = 0;
    scanf("%d", &n);
    // which chocolate bar prices.
    long long price_bar[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &price_bar[i]);
        sum += price_bar[i];
    }
    
    // sort prices
    mergeSort(price_bar, n);

    // number of coupons
    int m = 0;
    scanf("%d", &m);

    // number of chocolate bars you have to buy using i-th coupon
    int number_bars_coupon[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &number_bars_coupon[i]);
    }

    // calculate min costs
    for (int i = 0; i < m; i++) { // for which coupon
        int bars_to_buy = number_bars_coupon[i]; 
        long long min = price_bar[n-bars_to_buy];
        printf("%lld\n", sum-min);
    }
    return 0;
}
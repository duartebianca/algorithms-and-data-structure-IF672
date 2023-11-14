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

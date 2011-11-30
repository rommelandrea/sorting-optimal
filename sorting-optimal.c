#include <stdio.h>
#include <stdlib.h>

#include "arrayUtil.h"

void qsort1(int [], int, int);
void quicksort1(int [], int);
void merge(int [], int, int, int);
void msort(int [], int, int);
void mergesort(int [], int);

void merge2(int [], int, int, int);
void msort2(int [], int, int);
void mergesort2(int [], int);

void merge(int a[], int inf, int mid, int sup) {
    int n = sup - inf + 1;
    int c[n];
    int i, j, k, h;
    i = inf;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= sup) {
        if (a[i] <= a[j])
            c[k++] = a[i++];

        else
            c[k++] = a[j++];

    }
    while (i <= mid) c[k++] = a[i++];

    while (j <= sup) c[k++] = a[j++];

    for (h = 0; h < n; h++)
        a[inf + h] = c[h];
}

void msort(int a[], int inf, int sup) {
    if (inf < sup) {
        int mid;
        mid = (inf + sup) / 2;
        msort(a, inf, mid);
        msort(a, mid + 1, sup);
        merge(a, inf, mid, sup);
    }
}

void mergesort(int a[], int length) {
    msort(a, 0, length - 1);
}

void merge2(int a[], int inf, int mid, int sup) {
    if (a[mid] >= a[mid + 1]) {
        //int n = sup - inf + 1;
        int c[sup - inf + 1];
        int i, j, k;
        i = inf;
        j = mid + 1;
        k = 0;
        while (i <= mid && j <= sup) {
            while (a[i] <= a[j] && i <= mid) c[k++] = a[i++];
            
            while (a[i] >= a[j] && j <= sup) c[k++] = a[j++];                
        }
        
        while (i <= mid) c[k++] = a[i++];

        while (j <= sup) c[k++] = a[j++];

        for (k = 0; k < (sup - inf + 1); k++)
            a[inf + k] = c[k];
    }
}

void msort2(int a[], int inf, int sup) {
    if (inf < sup) {
        int mid;
        mid = (inf + sup) / 2;
        msort2(a, inf, mid);
        msort2(a, mid + 1, sup);
        merge2(a, inf, mid, sup);
    }
}

void mergesort2(int a[], int length) {
    msort2(a, 0, length - 1);
}

void qsort1(int a[], int inf, int sup) {
    if (inf < sup) {
        int x = a[inf];
        int i = inf + 1;
        int j = sup;
        while (i <= j) {
            if (a[i] <= x) i++;
            else {
                swap(a, i, j);
                j--;
            }
        }
        swap(a, inf, j);
        qsort1(a, inf, j - 1);
        qsort1(a, j + 1, sup);
    }
}

void quicksort1(int a[], int length) {
    qsort1(a, 0, length - 1);
}

int main(int argc, char** argv) {
    int length, max;
    length = 20;
    max = 20;
    int a[length];

    fillRandomArray(a, length, max);

    //print(a, length);

    mergesort2(a, length);

    print(a, length);

    if (sorted(a, length)) {
        printf("l'array e' ordinato");
    } else {
        printf("l'array NON e' ordinato");
    }

    return (EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>

#include "arrayUtil.h"

void qsort1(int [], int, int);
void quicksort1(int [], int);

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
    length = 100;
    max = 100;
    int a[length];

    fillRandomArray(a, length, max);

    print(a, length);

    quicksort1(a, length);

    print(a, length);
    
    if(sorted){
        printf("l'array e' ordinato");
    }else{
        printf("l'array NON e' ordinato");
    }

    return (EXIT_SUCCESS);
}
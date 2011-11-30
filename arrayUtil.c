/**
 * Varie utility per la creazione modifica e stampa degli array
 */

#include "arrayUtil.h"

/**
 * copia l'array a nell'array b
 * @param a array da copiare
 * @param b array di destinazione
 * @param length lunghezza dell'array
 */
void copyArray(int a[], int b[], int length) {
    int i = 0;

    for (i = 0; i < length; i++)
        b[i] = a[i];
}

/**
 * riempie l'array con elementi casuali tra 0 e max
 * @param a array da riempire
 * @param length lunghezza dell'array
 * @param max valore massimo degli elementi casuali
 */
void fillRandomArray(int a[], int length, int max) {
    srand(time(NULL));
    int i;

    for (i = 0; i < length; i++)
        a[i] = rand() % max;
}

/**
 * stampa l'array
 * @param a array da stampare
 * @param length lunghezza dell'array da stampare
 */
void print(int a[], int length) {
    int i;
    printf("stampo l'array\n");
    for (i = 0; i < length; i++) {
        printf("%d-->", a[i]);
    }
    printf("\n");
}

/**
 * controlla se l'array è ordinato
 * @param a array da controllare
 * @param length lunghezza dell'array
 * @return restituisce 1 se è ordinato, 0 altrimenti
 */
int sorted(int a[], int length) {
    int i;
    for (i = 1; i < length; i++)
        if (a[i - 1] > a[i])
            return 0;

    return 1;
}

/**
 * scambia due valori di un array
 * @param a array che contiene gli elementi da scambiare
 * @param i indice del primo elemento
 * @param j indice del secondo elemento
 */
void swap(int a[], int i, int j) {
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
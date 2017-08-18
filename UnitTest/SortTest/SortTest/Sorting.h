//
//  Sorting.h
//  SortTest
//
//  Created by Enrique Mondragon on 18/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h

#include <iostream>

using namespace std;

class Sorting{
public:
    virtual void Sort(int* unOrderder, int arrSize) = 0;
    virtual ~Sorting(){};
};

class Bubble : public Sorting{
public:
    void Sort(int* unOrderder, int arrSize){
        int* num = unOrderder;
        int i, j, flag = 1;    // set flag to 1 to start first pass
        int temp;             // holding variable
        int numLength = 5;
        for(i = 1; (i <= numLength) && flag; i++)
        {
            flag = 0;
            for (j=0; j < (numLength -1); j++)
            {
                if (num[j+1] > num[j])      // ascending order simply changes to <
                {
                    temp = num[j];             // swap elements
                    num[j] = num[j+1];
                    num[j+1] = temp;
                    flag = 1;               // indicates that a swap occurred.
                }
            }
        }
        return;
    }
};

class Heap : public Sorting{
public:
    void MaxHeapify(int a[], int i, int n){
        int j, temp;
        temp = a[i];
        j = 2*i;
        
        while (j <= n)
        {
            if (j < n && a[j+1] > a[j])
                j = j+1;
            // Break if parent value is already greater than child value.
            if (temp > a[j])
                break;
            // Switching value with the parent node if temp < a[j].
            else if (temp <= a[j])
            {
                a[j/2] = a[j];
                j = 2*j;
            }
        }
        a[j/2] = temp;
        return;
    }
    void Build_MaxHeap(int* a, int n)
    {
        int i;
        for(i = n/2; i >= 1; i--)
            MaxHeapify(a, i, n);
    }

    void Sort(int* a, int n){
        n = n-1;
        Build_MaxHeap(a, n);
        
        int i, temp;
        for (i = n; i >= 2; i--)
        {
            // Storing maximum value at the end.
            temp = a[i];
            a[i] = a[1];
            a[1] = temp;
            // Building max heap of remaining element.
            MaxHeapify(a, 1, i - 1);
        }
        
    }
};

class Quick : public Sorting{
public:
    int divide(int *arrayD, int start, int end) {
        int left;
        int right;
        int pivot;
        int temp;
        
        pivot = arrayD[start];
        left = start;
        right = end;
        
        // Mientras no se cruzen los índices
        while (left < right) {
            while (arrayD[right] > pivot) {
                right--;
            }
            
            while ((left < right) && (arrayD[left] <= pivot)) {
                left++;
            }
            
            // Si todavía no se cruzan los indices seguimos intercambiando
            if (left < right) {
                temp = arrayD[left];
                arrayD[left] = arrayD[right];
                arrayD[right] = temp;
            }
        }
        
        // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
        temp = arrayD[right];
        arrayD[right] = arrayD[start];
        arrayD[start] = temp;
        
        // La nueva posición del pivot
        return right;
    }
    void quicksort(int* arrayT, int start, int end){
        int pivot;
        
        if (start < end) {
            pivot = divide(arrayT, start, end);
            
            // Ordeno la lista de los menores
            quicksort(arrayT, start, pivot - 1);
            
            // Ordeno la lista de los mayores
            quicksort(arrayT, pivot + 1, end);
        }
    }
    void Sort(int * unOrderder,int size){
        quicksort(unOrderder, 0, size-1);
    }
};

#endif /* Sorting_h */

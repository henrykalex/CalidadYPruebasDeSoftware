//
//  main.cpp
//  CircularPrimo
//
//  Created by Enrique Mondragon on 11/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void rotateNumber(int num);
void chkPrime(int n);
void saveMultipleCondition(int n);
int flg;
int count, a, b, c;
int main(int argc, char const *argv[]) {
    int num1;
    int pos;
    printf(" Ingresa un numero: ");
    //scanf("%i",&num1);
    num1 = atoi(argv[1]);
    flg = 0;
    count = 1;
    rotateNumber(num1);
    if(flg==0){
        printf(" Si es circuclar primo.\n");
    }else{
        printf(" No es circular primo.\n");
    }
    printf(" Combinaciones guardadas: %d, %d, %d.\n",a,b,c);
    return 0;
}

void chkPrime(int n){
    long int i;
    i=n-1;
    while(i>=2)
    {
        if(n%i==0)
        {
            saveMultipleCondition(n);
            flg=1;
        }
        i--;
    }
}

void rotateNumber(int num){
    int n1 = num;
    int div = 1;
    int d;
    while ( n1 > 9 ){
        n1 = n1 / 10;
        div = div * 10;
    } // while
    int i = num;
    int n = num;
    while (i != 0) {
        i /= 10;
        d = n % 10;
        n = n / 10;
        n = n + d * div ;
        printf("\n Numero en rotacion es %d",n);
        chkPrime(n);
    }
}

void saveMultipleCondition(int n){
    if(count == 1){
        a = n;
    }else{
        if(count == 2){
            b = n;
        }else{
            if(count == 3){
                c = n;
            }
        }
    }
    count++;
}


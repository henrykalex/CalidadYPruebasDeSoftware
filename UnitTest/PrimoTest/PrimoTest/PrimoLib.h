//
//  PrimoLib.h
//  PrimoTest
//
//  Created by Enrique Mondragon on 15/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#ifndef PrimoLib_h
#define PrimoLib_h

int flg;
int count, a, b, c;

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

void chkPrime(int n){
    long int i;
    i=n-1;
    while(i>=2)
    {
        if(n%i==0)
        {
            //saveMultipleCondition(n);
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
        
        chkPrime(n);
    }
}

bool primo(int i){
    int num1;
    int pos;
    num1 = i;
    flg = 0;
    count = 1;
    rotateNumber(num1);
    if(flg==0){
        printf("Numero: %d",i);
        printf(" Si es circuclar primo.\n");
        return true;
    }else{
//        printf(" No es circular primo.\n");
        return false;
    }
//    printf(" Combinaciones guardadas: %d, %d, %d.\n",a,b,c);
}

#endif /* PrimoLib_h */

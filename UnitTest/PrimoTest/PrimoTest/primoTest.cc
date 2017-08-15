//
//  primoTest.cc
//  PrimoTest
//
//  Created by Enrique Mondragon on 15/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#include "gtest/gtest.h"
#include "PrimoLib.h"

TEST(TestCaseName, TestNameUno){
    int i = 0;
    bool temp;
    int primos [19] ={2, 3, 5, 7, 11, 13, 17, 37, 79, 113, 197, 199, 337, 1193, 3779, 11939, 19937, 193939, 199933};
    while(i >= 0){
        temp = primo(i);
        if(temp){
            for(int j = 0; j < sizeof(primos);j++){
                if(i == primos[j]){
                    std::cout << "..Primo!!!" << i <<"\n";
                }
            }
        }
        i++;
    }
    
}

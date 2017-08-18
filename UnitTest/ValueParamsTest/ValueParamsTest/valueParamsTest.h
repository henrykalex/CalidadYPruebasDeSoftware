//
//  valueParamsTest.h
//  ValueParamsTest
//
//  Created by Enrique Mondragon on 18/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#ifndef valueParamsTest_h
#define valueParamsTest_h

#include <iostream>
using namespace std;

template<class T>
void printValue(T value){
    cout << value << endl;
}

template<class P, class Q>
void printValues(P value1, Q value2){
    cout << value1 << " " << value2 << endl;
}

#endif /* valueParamsTest_h */

//
//  valueParamsTest.cc
//  ValueParamsTest
//
//  Created by Enrique Mondragon on 18/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#include "gtest/gtest.h"
#include "valueParamsTest.h"
#include <iostream>

using ::testing::Range;
using ::testing::ValuesIn;
using ::testing::Values;
using ::testing::Bool;


class FixtureInt : public ::testing::TestWithParam<int>{

};

class FixtureChar : public ::testing::TestWithParam<char>{
    
};

class FixtureBool : public ::testing::TestWithParam<bool>{
    
};

class FixtureComb : public ::testing::TestWithParam<::testing::tuple<int, int>>{
public:
    int value1 = ::testing::get<0>(GetParam());//get<0> primer elemento de la tupla
    int value2 = ::testing::get<1>(GetParam());
};

TEST_P(FixtureInt, testInt){
    printValue(GetParam());
}
TEST_P(FixtureChar, testChar){
    printValue(GetParam());
}
TEST_P(FixtureBool, testBool){
    printValue(GetParam());
}
TEST_P(FixtureComb, testComb){
    printValues(value1,value2);
}

INSTANTIATE_TEST_CASE_P(enteros, FixtureInt, Values(1,2,3,4,5));

char arrayChar[5] = {'a','b','c','d','e'};

INSTANTIATE_TEST_CASE_P(caracteres, FixtureChar, ValuesIn(arrayChar));

INSTANTIATE_TEST_CASE_P(booleanos, FixtureBool, Bool());

INSTANTIATE_TEST_CASE_P(combinaciones, FixtureComb, testing::Combine(Range(1,10,1),Range(1,10,1)));

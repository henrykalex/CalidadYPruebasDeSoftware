//
//  ScannerTest.cc
//  Evaluacion1
//
//  Created by Enrique Mondragon on 25/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#include "ScannerTest.h"
#include "gtest/gtest.h"
#include <stdio.h>


using ::testing::Range;
using ::testing::ValuesIn;

class FixturePorts : public ::testing::TestWithParam<int>{
    
};

class FixturePortsRange : public ::testing::TestWithParam<int>{
    
};
TEST_P(FixturePorts, testPorts){
    testPorts(GetParam());
}

int arrayPorts[5] = {7474,8080,336,80,5344};

INSTANTIATE_TEST_CASE_P(puertos, FixturePorts, ValuesIn(arrayPorts));

INSTANTIATE_TEST_CASE_P(puertos, FixturePortsRange, Range(1,10,1));

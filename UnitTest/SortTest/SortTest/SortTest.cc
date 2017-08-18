//
//  SortTest.cc
//  SortTest
//
//  Created by Enrique Mondragon on 18/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#include "gtest/gtest.h"
#include <iostream>
#include "Sorting.h"

template<class T>
class Fixture : public ::testing::Test{
public:
    T * parent;
    void SetUp(){
        parent = new T;
    }
    
    void TearDown(){
        delete parent;
    }
};
typedef ::testing::Types<Bubble,Heap, Quick> implementations;

TYPED_TEST_CASE(Fixture,implementations);

TYPED_TEST(Fixture, implementations){
    int arrSize = 5;
    int arrayChar[5] = {2,4,3,1,5};
    this->parent->Sort(arrayChar,arrSize);
    for (int i = 0; i<5; i++) {
        std::cout << arrayChar[i] << std::endl;
    }
}

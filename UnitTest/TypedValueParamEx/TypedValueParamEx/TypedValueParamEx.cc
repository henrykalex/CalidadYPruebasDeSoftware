//
//  TypedValueParamEx.cc
//  TypedValueParamEx
//
//  Created by Enrique Mondragon on 18/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#include "gtest/gtest.h"
#include <iostream>

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
typedef ::testing::Types<int, char, std::string> implementations;

TYPED_TEST_CASE(Fixture,implementations);

TYPED_TEST(Fixture, implementations){
    std::cout << *this->parent << std::endl;
}

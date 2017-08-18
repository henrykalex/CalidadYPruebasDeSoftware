//
//  TypedTesst.cc
//  TypedTest
//
//  Created by Enrique Mondragon on 18/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#include "TypedTesst.h"
#include "gtest/gtest.h"
#include "Hierarchie.h"

template<class T>
class Fixture : public ::testing::Test{
public:
    Parent * parent;
    void SetUp(){
        parent = new T;
    }
    
    void TearDown(){
        delete parent;
    }
};
typedef ::testing::Types<Child1, Child2, Child3> implementations;

TYPED_TEST_CASE(Fixture,implementations);

TYPED_TEST(Fixture, implementations){
    this->parent->doSomething();
}

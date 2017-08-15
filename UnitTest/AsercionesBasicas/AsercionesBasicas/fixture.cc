//
//  fixture.cc
//  AsercionesBasicas
//
//  Created by Enrique Mondragon on 15/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

//g++ -isystem ../../googletest/googletest/include -pthread ../../gtest_main.a basictest.cc -o basictest -std=c++11

#include "Pila.h"
#include "gtest/gtest.h"

class TestStack : public ::testing::Test{
public:
    void SetUp(){//Constructor
        myst.push(10);
        myst.push(20);
        myst.push(15);
    }
    void TearDown(){//Destructor
        
    }
    myStack<int> myst;
};

TEST_F(TestStack,pushtest){
    myst.push(30);
    EXPECT_EQ(4,myst.size());
}
TEST_F(TestStack,poptest){
    myst.pop();
    myst.pop();
    EXPECT_EQ(2,myst.size());
}
TEST_F(TestStack,poptestdos){
    myst.pop();
    myst.pop();
    EXPECT_EQ(1,myst.size());
}

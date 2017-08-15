//
//  basictest.cc
//  AsercionesBasicas
//
//  Created by Enrique Mondragon on 15/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//


//g++ -isystem ../../googletest/googletest/include -pthread ../../gtest_main.a basictest.cc -o basictest -std=c++11

#include "gtest/gtest.h"

TEST(TestCaseName, TestNameUno){
    EXPECT_FALSE(true) << "1.-Ex false";
    ASSERT_TRUE(false) << "2.-Ass true";
    SUCCEED() << "3.-SUCCED";
    FAIL() << "4.-FAIL";
    ADD_FAILURE() << "5.-ADD FAILURE";
    std::cout << "Uno finish";
}
TEST(TestCaseName, TestNameDos){
    EXPECT_EQ(56,100) << "6.-Ex ==";
    ASSERT_NE('u','d') << "7.-Ass !=";
    EXPECT_LT(25,30) << "8.-Ex <";
    ASSERT_LE(20,21) << "9.-Ass <=";
    EXPECT_GT(15,20) << "10.-Ex >";
    ASSERT_GE(17,17) << "11.-Ass >=";
    }
TEST(TestCaseName, TestNameTres){
    EXPECT_STREQ("dos","tres") << "12.-Ex ==";
    ASSERT_STRNE("dos","tres") << "13.-Ass !=";
    ASSERT_STRCASEEQ("Dos","DOS") << "14.-Ass != ignore case";
    EXPECT_STRCASENE("dos","Tres") << "15.-Ex == ignore case";
}
TEST(TestCaseName, TestNameCuatro){
//    int testing [5] = {1,2,3,4,5};
    EXPECT_THROW(([](){throw std::out_of_range("dos");})(),std::out_of_range) << "16.-Ex exc type";
    ASSERT_ANY_THROW(([](){throw std::out_of_range("dos");})()) << "17.-Ass any exc";
    EXPECT_NO_THROW(([](){throw std::out_of_range("dos");})()) << "18.-Ex no exc";
    ASSERT_FLOAT_EQ(20678.456,20678.5) << "19.-Ass float eq";
    EXPECT_DOUBLE_EQ(20678.456123456789,20678.457123456789) << "20.-Ex Double eq";
    ASSERT_NEAR(17.56,17.46,0.05) << "21.-Ass near";
}

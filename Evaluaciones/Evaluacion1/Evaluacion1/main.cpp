//
//  main.cpp
//  Evaluacion1
//
//  Created by Enrique Mondragon on 25/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#include "ScannerTest.h"
#include "gtest/gtest.h"
#include <stdio.h>
#include <iostream>
//#include "Scanner.h"
#include "ScannerTest.h"

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using ::testing::TestPartResult;
using ::testing::TestCase;
using ::testing::TestInfo;


using ::testing::Range;
using ::testing::ValuesIn;

class EventListener : public EmptyTestEventListener{
private:
    
public:

};

class FixturePorts : public ::testing::TestWithParam<int>{
    
};

class FixturePortsRange : public ::testing::TestWithParam<int>{
    
};
TEST_P(FixturePorts, testPorts){
    testPorts(GetParam());
}

TEST(TcnUno, tname){
    int i = 0;
    while (i < 999999999) {
        i++;
    }
    EXPECT_EQ(1,0);
}

int arrayPorts[5] = {7474,8080,336,80,5344};

INSTANTIATE_TEST_CASE_P(puertos, FixturePorts, ValuesIn(arrayPorts));

INSTANTIATE_TEST_CASE_P(puertos, FixturePortsRange, Range(1,100,1));

int main(int argc, char * argv[]) {
    PortScanner * ps = new PortScanner;
    std::vector<NetFile> listeningPorts = ps->getListeningPorts();
    for (std::vector<NetFile>::iterator it = listeningPorts.begin(); it != listeningPorts.end(); it++) {
        NetFile nf = (*it);
        std::cout << "Port: " << nf.port << ", Interface: " << nf.host << ", Protocol: " << nf.protocol << ", Command: " << nf.command << ", Status: " << nf.status << std::endl;
    }
    
    InitGoogleTest(&argc,argv);//Inicializa y llama los eventos
    
    TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new EventListener);
    
    return RUN_ALL_TESTS();
}

//
//  testEventListeners.cc
//  TestListeners
//
//  Created by Enrique Mondragon on 22/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "gtest/gtest.h"

using namespace std;
using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using ::testing::TestPartResult;
using ::testing::TestCase;
using ::testing::TestInfo;

class EventListener : public EmptyTestEventListener{
private:
    string logText;
public:
    virtual void OnTestProgramStart(const UnitTest& unt){
        logText = "Mensaje al inicio\n\n";
        fprintf(stdout,"Mensaje al inicio\n\n");
        fflush(stdout);
    }
    
    virtual void OnTestCaseStart(const TestCase& tc){
        printf("TestCase name: %s\n",tc.name());
        logText += "TestCase name: ";
        logText+= tc.name();
        logText+="\n";
    }
    virtual void OnTestStart(const TestInfo& ts){
        printf("Test name: %s\n",ts.name());
        logText += "Test name: ";
        logText += ts.name();
        logText += "\n";
    }
    virtual void OnTestPartResult(const TestPartResult& tpr){
        printf("%s",tpr.failed() ? "Falla. Los detalles son los siguientes:\n" : "Exito\n");
        printf("Linea del error: %d\n",tpr.line_number());
        printf("Resumen:\n%s\n",tpr.summary());
        if(tpr.failed()){
            logText += "Falla. Los detalles son los siguientes:\n";
            logText += "Linea del error: ";
            logText += tpr.line_number();
            logText += "\n";
            logText += tpr.summary();
            logText += "\n";
        }
        
    }
    virtual void OnTestEnd(const TestInfo& ts){
        printf("El tiempo de %s Test: %lld\n",ts.name(),ts.result()->elapsed_time());
        logText += "El tiempo de ";
        logText += ts.name();
        logText += " Test: ";
        logText += ts.result()->elapsed_time();
        logText += "\n";
    }
    virtual void OnTestCaseEnd(const TestCase& tc){
        printf("El tiempo de %s TestCase: %lld\n",tc.name(),tc.elapsed_time());
        logText += "El tiempo de ";
        logText += tc.name();
        logText += " TestCase: ";
        logText += tc.elapsed_time();
        logText += "\n";
    }
    
    virtual void OnTestProgramEnd(const UnitTest& unt){
        printf("UnitTest time: %lld\n",unt.elapsed_time());
        printf("EL # de Test ejecutados fue:: %d\n",unt.total_test_count());
        printf("Correctos: %d\n",unt.successful_test_count());
        printf("Incorrectos: %d\n",unt.failed_test_count());
        
        logText+="UnitTest time: "+to_string(unt.elapsed_time())+"\n";
        logText+="EL # de Test ejecutados fue: "+to_string(unt.total_test_count())+"\n";
        logText+="Correctos: "+to_string(unt.successful_test_count())+"\n";
        logText+="Incorrectos: "+to_string(unt.failed_test_count())+"\n";
        
        fprintf(stdout,"\nMensaje al final\n");
        fflush(stdout);
        
        ofstream myfile;
        myfile.open ("log.txt");
        myfile << logText;
        myfile.close();
    }
};


TEST(TcnUno, tname){
    int i = 0;
    while (i < 999999999) {
        i++;
    }
    EXPECT_EQ(1,0);
}



int main(int argc, char ** argv) {

    InitGoogleTest(&argc,argv);//Inicializa y llama los eventos
    
    TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new EventListener);
    
    return RUN_ALL_TESTS();
}

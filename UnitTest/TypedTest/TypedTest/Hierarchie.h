//
//  Hierarchie.h
//  TypedTest
//
//  Created by Enrique Mondragon on 18/08/17.
//  Copyright © 2017 ealex_mondrat. All rights reserved.
//

#ifndef Hierarchie_h
#define Hierarchie_h

#include <iostream>

using namespace std;

class Parent{
public:
    virtual void doSomething() = 0;
    virtual ~Parent(){};
};

class Child1 : public Parent{
public:
    void doSomething(){
        cout << "Child 1" <<endl;
    }
};

class Child2 : public Parent{
public:
    void doSomething(){
        cout << "Child 2" <<endl;
    }
};

class Child3 : public Parent{
public:
    void doSomething(){
        cout << "Child 2" <<endl;
    }
};

#endif /* Hierarchie_h */
